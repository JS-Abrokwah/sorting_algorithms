#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void bubble_sort(int *array, size_t size) {
    int swapped = 1;

    while(swapped) {
        swapped = 0;
        for(size_t i = 0; i < size - 1; i++) {
            if(array[i] > array[i+1]) {
                int temp = array[i];
                array[i] = array[i+1];
                array[i+1] = temp;
                }
                
             swapped = 1;
            }
        }
    }
}
