#include <stdio.h>
#include <stdlib.h>

unsigned int readOnes(FILE* fp, unsigned int intialCount) {

    unsigned char mask = 1;
    unsigned char temp = 0;
    unsigned char byte = 0;
    unsigned int count = intialCount;
    int readCheck = 0;

    // Check the first value, if 0 return 1
    readCheck = fread(&byte, sizeof(unsigned char), 1, fp);
    if (readCheck != 1) {
        printf("Error reading file - Exiting\n");
        exit(1);
    }
    if (byte == '\n') {
        return 0;
    }
    if ((mask & (byte >> 7)) == 0) {
        return 1;
    }
    else { // found a 1 increment count
        count = count + 1;
    }

    // Count the ones until you find a zero int the byte
    for (int i = 6; i >= 0; i--) {
        temp = (mask & (byte >> i));
        if (temp == 1) {
            count = count + 1;
        }
        else if (temp == 0) {
            return count;
        }
        else {
            printf("There was an error, stream may not be UTF-8 compliant\n");
            exit(1);
        }
    }
    // if all ones than read in the next byte
    return readOnes(fp, count);
}

unsigned int mtu_countUTF8(char* bytes) {

    unsigned int numOfOnes = 0;
    unsigned int count = 0;

    FILE* fp = fopen(bytes, "r");
    if (fp == NULL) {
        printf("Error reading from file - Exiting\n");
        exit(1);
    }

    while (1) {
        // Find the number of 1's at the beginning of the byte
        numOfOnes = readOnes(fp, 0);
        // if it returns 0 then read new line
        if (numOfOnes == 0) {
            break;
        }

        // skip that number of bytes, subtract off one for the byte intially read in readOnes
        if (numOfOnes > 1) {
            fseek(fp, numOfOnes - 1, SEEK_CUR);
        }

        // increment the count
        count = count + 1;
    }
    fclose(fp);

    // return the count
    return count;

}
