#include <stdio.h>

int main() {
    char number[] = {'H', 'i', '!', '\0'};
    char *str;

    char *msg1 = "Hi!";
    char *msg2 = "Hello, World!";

    str = msg1;
    printf("%s\n", str);

    str = msg2;
    printf("%s\n", str);

    printf("%s\n", number);
    
    // different from a pointer like char *str that we can reassign to it, for arrays, we cannot. So, the below code would fail if uncommented.
    // number = msg1;

    return 0;
}