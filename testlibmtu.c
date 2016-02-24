#include <stdio.h>
#include <stdlib.h>
// new file to test the library


#include "libmtu.h"

int main (void) {
    int fileNumber;

    // test function to make sure library is working
    testfunc();

    // Test for mtu_lang
    char* lang;
    if ((lang = mtu_lang()) == NULL) {
        printf("Error reading lang variable - Exiting\n");
        exit(1);
    }
    printf("LANG variable is %s\n", lang);

    // Test for mtu_pairSum
    int* pairs;
    pairs = mtu_pairSum(1, 1, 2, 2, 3, 3, 0, 0);
    for (int i = 0; i < 3; i++) {
        printf("Summed pair, index: %d value: %d\n", i, pairs[i]);
    }

    // Test for mtu_printFiles(), still may need some work testing
    fileNumber = mtu_printFiles();
    printf("printFiles returned with %d\n", fileNumber);

    return 0;
}
