#include <stdlib.h>
#include "stdio.h"
#include "stdlib.h"

#define SIZE sizeof(node)

int main(int argc, char const *argv[]) {
    int num;
    int count;
    int start;
    int i;

    scanf("%d%d%d", &num, &count, &start);

    int monkey[100] = {0};

    for (i = 0; i < num; ++i) {
        monkey[i] = 1;
    }

    int counter = 0;
    i = start - 1;
    int sum = num;

    while (num-- > 1) {
        counter = 0;
        while (1) {
            while (monkey[i] == 0 && i < sum) {
                i++;
                if (i > sum - 1) {
                    i = i - sum;
                }
            }
            counter++;
            if (counter == count) {
                monkey[i] = 0;
                i++;
                if (i > sum - 1){
                    i = 0;
                }
                break;
            }
            if (i > sum - 2) {
                i = 0;
            } else{
                i++;
            }
        }
    }
    for (i = 0; i < sum; ++i) {
        if (monkey[i] != 0) {
            printf("%d", i+1);
            break;
        }
    }
}