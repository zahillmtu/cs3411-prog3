#include <stdio.h>
#include <stdlib.h>

unsigned int BYTEINDEX = 0;

unsigned int readOnes(char* bytes, unsigned int intialCount) {

    unsigned char mask = 1;
    unsigned char temp = 0;
    unsigned char byte = 0;
    unsigned int count = intialCount;

    // Check the first value, if 0 return 1
    byte = (unsigned char) bytes[BYTEINDEX];
    if (byte == 0) {
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
            return(1);
        }
    }
    // if all ones than read in the next byte
    return readOnes(bytes, count);
}

unsigned int mtu_countUTF8(char* bytes) {

    unsigned int numOfOnes = 0;
    unsigned int count = 0;

    while (1) {
        // Find the number of 1's at the beginning of the byte
        numOfOnes = readOnes(bytes, 0);
        // if it returns 0 then read new line
        if (numOfOnes == 0) {
            break;
        }

        // skip that number of bytes, subtract off one for the byte intially read in readOnes
        if (numOfOnes > 0) {
            BYTEINDEX = BYTEINDEX + numOfOnes;
        }

        // increment the count
        count = count + 1;
    }

    // return the count
    return count;

}
