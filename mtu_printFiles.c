#define _SVID_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>


int mtu_printFiles(void) {

    int numOfFiles;
    struct dirent **namelist;

    numOfFiles = scandir(".", &namelist, NULL, alphasort);
    if (numOfFiles == -1) {
        printf("There was an error reading the directory - Exiting\n");
        exit(1);
    }

    struct stat fileInfo;

    for (int i = 0; i < numOfFiles; i++) {

        if (stat(namelist[i]->d_name, &fileInfo) == -1) {
            perror("stat");
            exit(EXIT_FAILURE);
        }
        printf("%s %lld\n", namelist[i]->d_name, (long long) fileInfo.st_size);
        free(namelist[i]);
    }
    free(namelist);

    return numOfFiles;

}
