#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>


int mtu_writeFileOpen(char* filename, char* string1, int seek, char *string2) {

    int fd;
    int nbytes;
    int bytesWritten;
    int lreturn;
    int creturn;

    // open the file to write, if exists truncate, if not there create
    fd = open(filename, (O_WRONLY | O_CREAT | O_TRUNC));
    if (fd == -1) {
        return 0; // There was an error
    }

    // write string1 to the file
    nbytes = strlen(string1);
    bytesWritten = write(fd, string1, nbytes);
    if (bytesWritten != nbytes) {
        return 0; // There was an error
    }

    // Seek to seek
    lreturn = lseek(fd, seek, SEEK_SET);
    if (lreturn == -1) {
        return 0; // There was an error
    }

    // write string2 to the file
    nbytes = strlen(string2);
    bytesWritten = write(fd, string2, nbytes);
    if (bytesWritten != nbytes) {
        return 0; // There was an error
    }

    // Close the file
    creturn = close(fd);
    if (creturn == -1) {
        return 0; // There was an error
    }

    return 1;

}
