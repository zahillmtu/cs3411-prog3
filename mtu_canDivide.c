#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>

int mtu_canDivide(int a, int b) {

    UNUSED(a); // Not needed

    if (b == 0) {
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
