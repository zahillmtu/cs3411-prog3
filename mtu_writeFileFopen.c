#include <stdio.h>
#include <string.h>

int mtu_writeFileFopen(char *filename, char *string1, int seek, char *string2) {

    int nbytes;
    int bytesWritten;
    int sreturn;
    int creturn;

    // open the file to write
    FILE* fp = fopen(filename, "w+");
    if (fp == NULL) {
        return 0; // There was an error
    }

    // write string1 to the file
    nbytes = strlen(string1);
    bytesWritten = fwrite(string1, 1, nbytes, fp);
    if (bytesWritten != nbytes) {
        printf("There was an error with fwrite\n");
        fclose(fp);
        return 0; // There was an error
    }

    // Seek to seek
    sreturn = fseek(fp, seek, SEEK_SET);
    if (sreturn == -1) {
        printf("There was an error with fseek\n");
        fclose(fp);
        return 0; // There was an error
    }

    // write string2 to the file
    nbytes = strlen(string2);
    bytesWritten = fwrite(string2, 1, nbytes, fp);
    if (bytesWritten != nbytes) {
        printf("There was an error with fwrite\n");
        fclose(fp);
        return 0; // There was an error
    }

    // Close the file
    creturn = fclose(fp);
    if (creturn != 0) {
        printf("There was an error with fclose\n");
        return 0; // There was an error
    }

    return 1;
}
