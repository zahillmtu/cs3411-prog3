#include <stdio.h>
#include <stdlib.h>
// new file to test the library


#include "libmtu.h"

int main (void) {
    int fileNumber;

    // test function to make sure library is working
    testfunc();

    // Test for mtu_canDivide
    printf("\n");
    printf("Running test for mtu_canDivide\n");
    int diva = 20;
    int divb = 5;
    int divans = mtu_canDivide(diva, divb);
    printf("mtu_canDivide returned with: %d\n", divans);

    // Test for mtu_qsort
    printf("\n");
    printf("Running test for mtu_qsort\n");
    int listSize = 5;
    float list[] = {1.0, 6.0, 9.3, 7.8, 2.2};
    mtu_qsort(list, listSize);
    for (int i = 0; i < listSize; i++) {
        printf("%f ", list[i]);
    }
    printf("\n");

    // Test for mtu_lang
    printf("\n");
    printf("Running test for mtu_lang\n");

    char* lang;
    if ((lang = mtu_lang()) == NULL) {
        printf("Error reading lang variable - Exiting\n");
        exit(1);
    }
    printf("LANG variable is %s\n", lang);

    // Test for mtu_pairSum
    printf("\n");
    printf("Running test for mtu_pairSum\n");

    int* pairs;
    pairs = mtu_pairSum(1, 1, 2, 2, 3, 3, 0, 0);
    for (int i = 0; i < 3; i++) {
        printf("Summed pair, index: %d value: %d\n", i, pairs[i]);
    }
    free(pairs);

    // Test for mtu_printFiles(), still may need some work testing
    printf("\n");
    printf("Running test for mtu_printFiles\n");

    fileNumber = mtu_printFiles();
    printf("printFiles returned with %d\n", fileNumber);

    return 0;
}
