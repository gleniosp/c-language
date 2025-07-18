#include <stdio.h>

enum weekday_t {
    sunday = -2,
    monday,
    tuesday,
    wednesday = 7,
    thursday,
    friday,
    saturday
};

void main() {
    enum weekday_t random_day;

    random_day = saturday;

    printf("%d\n", random_day);
}
