//
// https://open.kattis.com/problems/flexible
//

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int l = 0;
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}
int main() {
    int w, p, i, j, k, z;
    int arr[204800];
    scanf("%d %d", &w, &p);
    int input[p + 2];
    for (i = 1; i < (p + 1); i++) {
        scanf("%d", input+i);
    }
    input[0] = 0; //left most num is 0
    //store w to input[p+1]
    //arr[l] stores the width
    input[p + 1] = w;
    if(p==0){
        printf("0");
        return 0;}
    for (j = 0; j < p + 2; j++) {
        for (k = 0; k < j; k++) {
            arr[l] = (input[j] - input[k]);
            l++;
        }
    }
    //sort the array and print the unique number
    qsort(arr, (l), sizeof(int), compare);
    printf("%d ",arr[0]);
    for (z = 1; z <l; z++) {
        if ( (arr[z - 1] != arr[z])) {
            printf("%d ", arr[z]);

        }

    }
}
