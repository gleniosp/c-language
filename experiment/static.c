// compile this with: gcc static.c static_aux.c

#include <stdio.h>

void bar();

void main() {
    bar(); // b = 4 here
    bar(); // b = 5 here, because b will keep its previous state within the bar function across function calls
    return;
}