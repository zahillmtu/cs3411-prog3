#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <limits.h>

int* mtu_pairSum(int a, ...) {

    int first;
    int second;
    int count = 0;
    int* summedPairs = NULL;
    int* temp;

    va_list params;

    va_start(params, a);
    first = a;
    second = va_arg(params, int);
    while (!((first == 0) &&
            (second == 0))) {

        count = count + 1;

        // Create a new array to place the paired values into
        temp = (int*) calloc(count, sizeof(int));
        if (temp == NULL) {
            printf("Error allocating memory - Exiting\n");
            return(NULL);
        }

        // place everything into the new array
        if (summedPairs != NULL) {
            for (int i = 0; i < count - 1; i++) {
                temp[i] = summedPairs[i];
            }
        }

        // test to check undefined behavior
        if (((first > 0) && (second > (INT_MAX - first))) ||
            ((first < 0) && (second < (INT_MIN - first)))) {
                // There is an error
                printf("Addition would cause undefined behavior - Exiting\n");
                return(NULL);
        } else {
            temp[count - 1] = first + second;
        }
        free(summedPairs);
        summedPairs = temp;

        // get the next values
        first = va_arg(params, int);
        second = va_arg(params, int);
    }
    // do it one more time to place zero at the end
    temp = (int*) calloc(count + 1, sizeof(int));
    if (temp == NULL) {
        printf("Error allocating memory - Exiting\n");
        exit(1);
    }

    // place everything into the new array
    if (summedPairs != NULL) {
        for (int i = 0; i < count; i++) {
            temp[i] = summedPairs[i];
        }
    }
    // set the final value in the array to be zero
    temp[count] = 0;
    // set the new array to be summedPairs
    free(summedPairs);
    summedPairs = temp;

    va_end(params);

    return summedPairs;
}

//References
//  https://en.wikipedia.org/wiki/Stdarg.h
