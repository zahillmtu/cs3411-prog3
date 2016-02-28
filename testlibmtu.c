#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "libmtu.h"

#define FOPEN 1
#define OPEN 0

void test_mtu_countUTF8() {

    printf("\n");
    printf("Running test for mtu_countUTF8\n");

    char filename[] = "utf_8_test.txt";
    char utfchars[] = "n → ∞, ∑ f(i) = ∏ g(i)\n";
    int delret;
    int charCount;
    int numOfChars = 22;

    // create a file for testing
    FILE* fp = fopen(filename, "w+");
    if (fp == NULL) {
        printf("Error creating a file for testing - Exiting\n");
        exit(EXIT_FAILURE);
    }

    // place the chars into the file
    fputs(utfchars, fp);
    fclose(fp);

    // call the test function
    charCount = mtu_countUTF8(filename);
    if (charCount == numOfChars) {
        printf("mtu_countUTF8 returns with %d, returned with: %d. Success.\n", numOfChars, charCount);
    }
    else {
        printf("mtu_countUTF8 returns with %d, returned with: %d. Failure.\n", numOfChars, charCount);
    }

    // delete the file
    delret = remove(filename);
    if (delret == -1) {
        printf("Error deleting file - Exiting\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void test_mtu_writeOpen(int openType) {

    char* filename;
    char fileData[] = "Print this line to the file just to take up space.";
    int retval;
    char string1[] = "string1";
    char string2[] = "string2";
    int seekamt = 2;
    int delret;

    printf("\n");
    if (openType == OPEN) {
        printf("Running test for mtu_writeFileOpen\n");
    } else {
        printf("Running test for mtu_writeFileFopen\n");
    }

    if (openType == OPEN) {
        filename = "openTestFile.txt";
    } else {
        filename = "fopenTestFile.txt";
    }

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

    // call mtu_writeOpen functions
    if (openType == OPEN) {
        retval = mtu_writeFileOpen(filename, string1, seekamt, string2);
    } else {
        retval = mtu_writeFileFopen(filename, string1, seekamt, string2);
    }

    if (retval == 0) {
        if (openType == OPEN) {
            printf("mtu_writeFileOpen returns 1. It returned with %d. Failure.\n", retval);
        } else {
            printf("mtu_writeFileFopen returns 1. It returned with %d. Failure.\n", retval);
        }
    }
    else {
        if (openType == OPEN) {
            printf("mtu_writeFileOpen return %d. Success.\n", retval);
        } else {
            printf("mtu_writeFileFopen return %d. Success.\n", retval);
        }
    }

    // delete the file
    delret = remove(filename);
    if (delret == -1) {
        printf("Error deleting file - Exiting\n");
        exit(EXIT_FAILURE);
    }
    return;
}

void test_mtu_popen() {

    printf("\n");
    printf("Running test for mtu_popen\n");

    unsigned int testpopen;

    testpopen = mtu_popen();
    if (testpopen > 4000000000) {
        // There was an error
        printf("mtu_popen returned %u. Failure.\n", testpopen);
    }
    else {
        printf("mtu_popen returned %u. Success.\n", testpopen);
    }
    return;
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
        printf("mtu_canDivide(%d, %d) returned with: %d. Success\n", diva, divb, divans);
    }
    else {
        printf("mtu_canDivide(%d, %d) returns 1. It returned with: %d. Failure\n", diva, divb, divans);
    }
    return;
}

void test_mtu_qsort() {

    printf("\n");
    printf("Running test for mtu_qsort\n");
    int listSize = 6;
    int sortedFailed = 0;
    printf("Starting array = 1.2, 1.1, 6.0, 9.3, 7.8, 2.2}\n");
    float sortedList[] = {1.1, 1.2, 2.2, 6.0, 7.8, 9.3}; // array for testing
    float list[] = {1.2, 1.1, 6.0, 9.3, 7.8, 2.2}; // array to be sorted
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

    // Test for mtu_countUTF8
    test_mtu_countUTF8();

    // Test for mtu_writeFileOpen
    test_mtu_writeOpen(OPEN);

    // Test for mtu_writeFileFopen
    test_mtu_writeOpen(FOPEN);

    // Test for mtu_popen
    test_mtu_popen();

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
