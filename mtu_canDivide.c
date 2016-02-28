#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int mtu_canDivide(int a, int b) {

    if (b == 0) {
        // behavior will be undefined
        return 0;
    }
    else if (a == INT_MIN && b == -1) {
        // behavior will be undefined
        return 0;
    }
    else {
        // behavior will be defined
        return 1;
    }
}

/*
 * References
 *      http://stackoverflow.com/questions/3599160/unused-parameter-warnings-in-c-code
 */
