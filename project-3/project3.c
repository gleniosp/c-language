// The Project-3.pdf might have more readable code that you can also reuse and complement the rest of the functions.
// For now, this is the code for Project 3 as followed along with the classes in the course.

#include <stdio.h>

enum sensor_type
{
    TEMPERATURE,
    HUMIDITY,
    PRESSURE
};

enum sensor_state
{
    ACTIVE,
    INACTIVE,
    ERROR
};

struct temperature_data
{
    short int min;
    short int max;
    float reading;
} __attribute__((packed)); // to force the removal of any potential padding added by the OS so we can see the actual structs size

struct humidity_data
{
    float calibration;
    float reading;
} __attribute__((packed));

struct pressure_data
{
    short int altitude;
    float reading;
} __attribute__((packed));

// as at each point in time we'll have either temperature, humidity or pressure being read, it is better to use an union than struct, so we can save memory space
union sensor_data
{
    struct temperature_data temperature;
    struct humidity_data humidity;
    struct pressure_data pressure;
};

struct sensor
{
    short int id;
    char name[20];
    enum sensor_type type;
    enum sensor_state state;
    union sensor_data data;
} __attribute__((packed));

int main()
{
    struct sensor sensor_list[10];
    unsigned int sensor_count = 0;
    unsigned int init_sensor;

    while (1)
    {
        if (sensor_count >= 10)
        {
            printf("No slots to add more sensors!\n");
            break;
        }

        init_sensor = 0;
        printf("Want to add sensor? enter 1 to add, 0 to skip: ");
        scanf("%u", &init_sensor);
        scanf("%*c"); // to force scanf to flush the buffer so we don't run into any quirk with scanf

        if (init_sensor == 0)
        {
            break;
        }

        unsigned int sensor_idx = sensor_count;
        sensor_count = sensor_count + 1;

        printf("ID: ");
        scanf("%hd", &sensor_list[sensor_idx].id);
        scanf("%*c");

        printf("Name: ");
        scanf("%s", (char *)&sensor_list[sensor_idx].name);
        scanf("%*c");

        char type;
        printf("Type (t, h, p): ");
        scanf("%c", &type);
        scanf("%*c");

        switch (type)
        {
        case 't':
            sensor_list[sensor_idx].type = TEMPERATURE;
            break;
        case 'h':
            sensor_list[sensor_idx].type = HUMIDITY;
            break;
        case 'p':
            sensor_list[sensor_idx].type = PRESSURE;
            break;
        }

        sensor_list[sensor_idx].state = INACTIVE;

        switch (sensor_list[sensor_idx].type)
        {
        case TEMPERATURE:
            printf("min: ");
            scanf("%hd", &sensor_list[sensor_idx].data.temperature.min);
            scanf("%*c");

            printf("max: ");
            scanf("%hd", &sensor_list[sensor_idx].data.temperature.max);
            scanf("%*c");

            printf("reading: ");
            scanf("%f", &sensor_list[sensor_idx].data.temperature.reading);
            scanf("%*c");
            break;
        case HUMIDITY:
            printf("calibration: ");
            scanf("%f", &sensor_list[sensor_idx].data.humidity.calibration);
            scanf("%*c");

            printf("reading: ");
            scanf("%f", &sensor_list[sensor_idx].data.humidity.reading);
            scanf("%*c");
            break;
        case PRESSURE:
            printf("altitude: ");
            scanf("%hd", &sensor_list[sensor_idx].data.pressure.altitude);
            scanf("%*c");

            printf("reading: ");
            scanf("%f", &sensor_list[sensor_idx].data.pressure.reading);
            scanf("%*c");
            break;
        }

        sensor_list[sensor_idx].state = ACTIVE;
    }

    for (int i = 0; i < sensor_count; i = i + 1)
    {
        printf("Printing sensor data for sensor %d\n", i);
        printf("-- ID: %hd\n", sensor_list[i].id);
        printf("-- Name: %s\n", sensor_list[i].name);
        printf("-- Type: %u\n", sensor_list[i].type);

        switch (sensor_list[i].type)
        {
        case TEMPERATURE:
            printf("-- -- min: %hd\n", sensor_list[i].data.temperature.min);
            printf("-- -- max: %hd\n", sensor_list[i].data.temperature.max);
            printf("-- -- reading: %f\n", sensor_list[i].data.temperature.reading);
            break;
        case HUMIDITY:
            printf("-- -- calibration: %f\n", sensor_list[i].data.humidity.calibration);
            printf("-- -- reading: %f\n", sensor_list[i].data.humidity.reading);
            break;
        case PRESSURE:
            printf("-- -- altitude: %hd\n", sensor_list[i].data.pressure.altitude);
            printf("-- -- reading: %f\n", sensor_list[i].data.pressure.reading);
            break;
        }
    }

    return 0;
}