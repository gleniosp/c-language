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
    unsigned char id;
    char name[20];
    enum sensor_type type;
    enum sensor_state state;
    union sensor_data data;
} __attribute__((packed));

int main()
{
    printf("size of struct sensor: %ld\n", sizeof(struct sensor));
    return 0;
}