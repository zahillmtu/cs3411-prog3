#include <stdio.h>
// new file to test the library


#include "libmtu.h"

int main (void) {
    int fileNumber;

    // test function to make sure library is working
    testfunc();

    // Test for mtu_printFiles(), still may need some work testing
    fileNumber = mtu_printFiles();
    printf("printFiles returned with %d\n", fileNumber);

    return 0;
}
