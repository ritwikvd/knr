#include <stdio.h>
#include <string.h>
#include <math.h>
#include "utils.h"

// 2-5
int strindex(char a[], char b[]){
    for(int i = 0; a[i] != NULL_CHAR; i++){
        if(a[i] == b[0]){
            int matched = 1;

            for(int j = i + 1, k = 1; b[k] != NULL_CHAR; j++,k++){
                if(a[j] != b[k]){
                    matched = 0;
                    break;
                }
            }

            if(matched)
                return i;
        } 
    }

    return -1;
}

// 2.9
int getbits(x, p, n){
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

int get1mask(p, n){
    return (int)(pow(2, n) - 1) << (p + 1 - n);
}

int get0mask(p, n){
    return ~get1mask(p, n);
}

// 2-6
int setbits(x, p, n, y){
    int xshifted = x >> (p + 1 - n);
    // int restofx = ~(~0 << (p + 1 - n)) & x;
    int restofx = get1mask(p + 1 - n, p + 1 - n) & x;
    int getylast2bits = getbits(y, 1, 2);

    // int anded = (xshifted & (~0 << n)) | getylast2bits;
    int anded = (xshifted & get0mask(n-1, n)) | getylast2bits;
    anded = anded << (p + 1 - n);

    return anded | restofx;
}

// 2-7
int invert(x, p ,n) {
    return x ^ get1mask(p, n);
}

// 2-9
int countbits(x){
    int count = 1;
    while((x &= x - 1) != 0)
        count++;

    // for(count = 1; (x &= x - 1) != 0; count++);

    return count;
}

int recbinsearch(int x[], int v, int i, int j){
    if(i > j)
        return -1;

    int mid = (i + j) / 2;

    if(x[mid] == v)
        return mid;

    if(x[mid] < v)
        return recbinsearch(x, v, mid + 1, j);
    else
        return recbinsearch(x, v, i, mid - 1);
}

// 3.3
int binsearch(int v, int x[], int n)
{
    // return recbinsearch(x, v, 0, n - 1); 
    int low = 0;
    int high = n - 1;

    while(low <= high) {
        int mid = (low + high)/ 2;

        if(x[mid] < v)
            low = mid + 1;
        else if(x[mid] > v)
            high = mid - 1;
        else
            return mid;
    }

    return -1;
}

int main (int argc, char *argv[])
{
    int x[] = {1,2,3,4};
    printf("%d\n", binsearch(3, x, 4));
    return 0;
}
