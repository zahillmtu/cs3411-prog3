#include<limits.h>

int mtu_canNegate(int a) {
    if (a == INT_MIN) {
        return 0;
    }
    else {
        return 1;
    }
}
