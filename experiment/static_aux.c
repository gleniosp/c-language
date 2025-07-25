// to be compiled with static.c

#include <stdio.h>

// if we do "a" and "foo" static, they will be available only in this file and not in other files like static.c, even if we use `extern` to reference them there.

static int a = 10;

static void foo() {
    a = a + 1;
    printf("foo: %d\n", a);
    return;
}

// however, the bar function can access "foo" here and as "bar" is not static, we can't use it in static.c

void bar() {
    static char b = 3;
    b = b + 1;

    foo();
}