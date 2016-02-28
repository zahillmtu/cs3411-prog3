#include<stdlib.h>

/**
 * Method to compare two floats
 * returns an integer less than, equal to, or greater than zero if the first argument
 * is considered to be respectively less than, equal to, or greater than the second.
 */
static int compFloat(const void* pa, const void* pb) {

    float a = *(const float*)pa;
    float b = *(const float*)pb;

    if (a < b) {
        return -1;
    }
    else if (a > b) {
        return 1;
    }
    else {
        return 0;
    }
}

void mtu_qsort(float* list, int n) {

    qsort(list, n, sizeof(float), compFloat);

    return;
}
