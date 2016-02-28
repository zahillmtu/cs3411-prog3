#define _POSIX_C_SOURCE 2

#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>


unsigned int mtu_popen() {

    char cmd[1024];
    unsigned int retNum;
    FILE* pout;
    // Get the pid number
    pid_t pidNum = getpid();

    snprintf(cmd, sizeof(cmd), "ps -p %d -o rss=", pidNum);
    printf("cmd: %s\n", cmd);

    pout = popen(cmd, "r");
    if (pout == NULL) {
        printf("Error using popen() - Exiting");
        exit(1);
    }

    fscanf(pout, "%u", &retNum);

    return retNum;
}

/*
 * References
 *      http://stackoverflow.com/questions/4881937/building-strings-from-variables-in-c
 */
