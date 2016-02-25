#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// new file to test the library


#include "libmtu.h"

void test_mtu_writeFileOpen() {

    char filename[] = "openTestFile.txt";
    char fileData[] = "Print this line to the file just to take up space.\n";
    int retval;
    char string1[] = "string1";
    char string2[] = "string2";
    int seekamt = 30;
    int delret;

    printf("\n");
    printf("Running test for mtu_writeFileOpen\n");

    // create a file to write to
    FILE* fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error creating a file for testing - Exiting\n");
        exit(EXIT_FAILURE);
    }

    // write a bunch of stuff to the file
    for (int i = 0; i < 15; i++) {
        fputs(fileData, fp);
    }
    // close the file to allow function to access it
    fclose(fp);

    // call mtu_writeFileOpen
    retval = mtu_writeFileOpen(filename, string1, seekamt, string2);
    if (retval == 0) {
        printf("mtu_writeFileOpen returns 1. It returned with %d. Failure.\n", retval);
    }
    else {
        printf("mtu_writeFileOpen return %d. Success.\n", retval);
    }

    // delete the file
    delret = remove(filename);
    if (delret == -1) {
        printf("Error deleting file - Exiting\n");
        exit(EXIT_FAILURE);
    }
}

void test_mtu_canNegate() {

    int a = 1;

    printf("\n");
    printf("Running test for mtu_canNegate\n");
    int result = mtu_canNegate(a);
    if (result == 1) {
        printf("mtu_canNegate(1) returned with: %d. Success\n", result);
    }
    else {
        printf("mtu_canNegate(1) returns 1. It returned with: %d. Failure\n", result);
    }

    return;
}

void test_mtu_canDivide() {

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
    return;
}

void test_mtu_qsort() {

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

    return;
}

void test_mtu_lang() {

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

    return;
}

void test_mtu_pairSum(){

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
    return;
}

void test_mtu_printFiles() {

    printf("\n");
    printf("Running test for mtu_printFiles\n");

    int fileNumber;
    fileNumber = mtu_printFiles();
    printf("printFiles returned with %d\n", fileNumber);

    return;
}

int main (void) {

    // test function to make sure library is working
    testfunc();

    // Test for mtu_writeFileOpen
    test_mtu_writeFileOpen();

    // Test for mtu_canNegate
    test_mtu_canNegate();

    // Test for mtu_canDivide
    test_mtu_canDivide();

    // Test for mtu_qsort
    test_mtu_qsort();

    // Test for mtu_lang
    test_mtu_lang();

    // Test for mtu_pairSum
    test_mtu_pairSum();

    // Test for mtu_printFiles(), still may need some work testing
    test_mtu_printFiles();

    return 0;
}
