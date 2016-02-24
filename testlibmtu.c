#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
    if (divans == 1) {
        printf("mtu_canDivide(20, 4) returned with: %d. Success\n", divans);
    }
    else {
        printf("mtu_canDivide(20, 4) returns 1. It returned with: %d. Failure\n", divans);
    }

    // Test for mtu_qsort
    printf("\n");
    printf("Running test for mtu_qsort\n");
    int listSize = 5;
    int sortedFailed = 0;
    printf("Starting array = 1.0, 6.0, 9.3, 7.8, 2.2}\n");
    float sortedList[] = {1.0, 2.2, 6.0, 7.8, 9.3}; // array for testing
    float list[] = {1.0, 6.0, 9.3, 7.8, 2.2}; // array to be sorted
    mtu_qsort(list, listSize);
    printf("Sorted array = ");
    for (int i = 0; i < listSize; i++) {
        printf("%f ", list[i]);
        if (list[i] != sortedList[i]) {
            // There was a failure
            sortedFailed = 1;
        }
    }
    printf("\n");
    if (sortedFailed == 1) {
        printf("Array is not sorted. Failure.\n");
    }
    else {
        printf("Array is sorted. Success.\n");
    }

    // Test for mtu_lang
    printf("\n");
    printf("Running test for mtu_lang\n");

    char langCheck[] = "en_US.UTF-8";
    char* lang;
    if ((lang = mtu_lang()) == NULL) {
        printf("Error reading lang variable - Exiting\n");
        exit(1);
    }
    if (strcmp(langCheck, lang) == 0) {
        printf("LANG variable is %s. Success.\n", lang);
    }
    else {
        printf("LANG variable should be %s, but was %s. Failure.\n", langCheck, lang);
    }

    // Test for mtu_pairSum
    printf("\n");
    printf("Running test for mtu_pairSum\n");

    int pairsFailed = 0;
    int* pairs;
    pairs = mtu_pairSum(1, 1, 2, 2, 3, 3, 0, 0);
    for (int i = 0; i < 3; i++) {
        printf("Summed pair, index: %d value: %d\n", i, pairs[i]);
        if (pairs[i] != ((i + 1) * 2) && pairs[i] != 0) {
            pairsFailed = 1;
        }
    }
    if (pairsFailed == 1) {
        printf("Summing did not return correctly. Failure.\n");
    }
    else {
        printf("Summing returned correctly. Success.\n");
    }
    free(pairs);

    // Test for mtu_printFiles(), still may need some work testing
    printf("\n");
    printf("Running test for mtu_printFiles\n");

    fileNumber = mtu_printFiles();
    printf("printFiles returned with %d\n", fileNumber);

    return 0;
}
