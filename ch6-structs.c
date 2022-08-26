#include <stdio.h>
#include <ctype.h>
#include "utils.h"

void *binsearch(void *object, void *arr, int length, int (*compare)(void *, void *)) {
    // printf("%d", ( *compare )(object, arr+1));
    // void *low = arr;
    // void *high = arr + length - 1;
    // void *mid;
    // int cond;
    //
    // printf("%d\t%d", *(int *)low, *(int *)high);
    //
    // while(low < high) {
    //     mid = low + (high - low) / 2;
    //
    //     if((cond = ( *compare )(object, mid)) < 0) 
    //         high = mid;
    //     else if(cond > 0)
    //         low = mid + 1;
    //     else
    //         return mid;
    // }
    //
    return NULL;
}

int compareInt(int *x, int *y) {
    return *x - *y;
}

int main (int argc, char *argv[])
{
    int arr[] = {1,2,3,4};
    int x = 2;

    printf("%d", *( (int *)( binsearch(&x, arr, 4, NULL) ) ) );
    // printf("%d", *(int *)( binsearch(&x, arr, 4, (int (*)(void *, void *))compareInt) ) );
}

