#include <stdio.h>

// // this won't compile because "a" is only available within main because of the auto keyword
// void foo() {
//     print("foo: %d\n", a);

//     return;
// }

void main() {
    auto int a = 10;
    printf("main: %d\n", a);

    return;
}