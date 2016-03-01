#define _SVID_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

/*
 * Return -1, 0, or 1 if a is <, =, or > b
 */
int sizeSort(const struct dirent ** a, const struct dirent ** b) {

    struct stat aInfo;
    struct stat bInfo;

    stat((*a)->d_name, &aInfo);
    stat((*b)->d_name, &bInfo);

    if (aInfo.st_size > bInfo.st_size) {
        return 1;
    }
    else if (aInfo.st_size < bInfo.st_size) {
        return -1;
    }
    else {
        return 0;
    }

}

int mtu_printFiles(void) {

    int numOfFiles;
    struct dirent **namelist;

    numOfFiles = scandir(".", &namelist, NULL, sizeSort);
    if (numOfFiles == -1) {
        printf("There was an error reading the directory - Exiting\n");
        return(1);
    }

    struct stat fileInfo;

    for (int i = 0; i < numOfFiles; i++) {

        if (stat(namelist[i]->d_name, &fileInfo) == -1) {
            perror("stat");
            return(1);
        }
        printf("%s %lld\n", namelist[i]->d_name, (long long) fileInfo.st_size);
        free(namelist[i]);
    }
    free(namelist);

    return numOfFiles;

}
