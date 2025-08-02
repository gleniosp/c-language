#include <stdio.h>

void main() {
    int v1 = 2;
    int v2 = 3, ans;

    float f1 = 2, fans;

    ans = v1 + v2;
    printf("+ %d\n", ans);

    ans = v1 - v2;
    printf("- %d\n", ans);

    ans = v1 * v2;
    printf("* %d\n", ans);

    ans = v1 / v2;
    printf("(int) / %d\n", ans);

    fans = f1 / v2;
    printf("(float) / %f\n", fans);

    ans = v1 % v2;
    printf("%% %d\n", ans); // %% to escape %

    int i = 10;

    i++;
    printf("i++ = %d\n", i);

    i--;
    printf("i-- = %d\n", i);

    --i;
    printf("--i = %d\n", i);

    ++i;
    printf("++i = %d\n", i);
}