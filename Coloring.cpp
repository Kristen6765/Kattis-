//
//https://open.kattis.com/problems/color
//


#include <iostream>


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int num_of_socks;
int capacity;
int max_color_diff;
char line1[102400];
char line2[1024000];
int color[102400];
int count = 0;
char* p;
char* refrence;
int compare(const void* a, const void* b)
{
    return (*(int*)a - *(int*)b);
}

int main()
{
    refrence = fgets(line1, sizeof(line1), stdin);//get the number of socks, the capacity of a laundry machine and the maximum color difference
    refrence = fgets(line2, sizeof(line2), stdin);//get color values

    num_of_socks = atoi(strtok(line1, " "));
    capacity = atoi(strtok(NULL, " "));
    max_color_diff = atoi(strtok(NULL, " "));

    int i = 0;
    color[i] = atoi(strtok(line2, " "));
    i++;
    p = strtok(NULL, " ");
    while (p != NULL) {
        color[i] = atoi(p);
        p = strtok(NULL, " ");
        i++;
    }
    num_of_socks = i;
    qsort(color, (i), sizeof(int), compare);
    int w;
    w = 1;//counter for capacity
    int int_i=color[0];
    int count = 0;
    for (int i = 1; i < num_of_socks; i++) {
        if (w == capacity) {
            count++;
            w = 0;
            int_i = color[i];
        }
        if (color[i] - int_i > max_color_diff) {
            count++;
            w = 0;
            int_i = color[i];
        }
        w++;
    }

    count++;
    printf("%d", count);


    return 0;
}
