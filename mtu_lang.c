#define _GNU_SOURCE

#include<stdlib.h>

char* mtu_lang(void) {

    char* lang;

    lang = getenv("LANG");
    if (lang == NULL) {
        return NULL;
    }

    return lang;
}
