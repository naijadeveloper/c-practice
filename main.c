#include <stdio.h>


void bubble_sort(int array[], int length) {
    // ascending sort
    for(int i = 0; i < length - 1; i++) {
        for(int j = 0; j < length - 1 - i; j++) {
            if(array[j+1] < array[j]) { // for ascending use <, for descending use >
                // swap
                // printf("found match betw: %d and %d", array[j], array[j+1]);
                int save_val_1 = array[j];
                int save_val_2 = array[j+1];
                array[j+1] = save_val_1;
                array[j] = save_val_2;
            }
        }
    }

    // print out sorted array
    for(int i = 0; i < length; i++) {
        printf("%d, ", array[i]);
    }
    puts("");
}

int find_min_array(int array[], int length) {
    int min = array[0];

    for(int i = 1; i < length; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

int find_max_array(int array[], int length) {
    int max = array[0];

    for(int i = 1; i < length; i++) {
        if(array[i] > max) {
            max = array[i];
        }
    }

    return max;
}


int main(void) {
    int array[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};
    int length = sizeof(array)/sizeof(array[0]);

    // 3) int res = find_max_array(array, length);
    // printf("res: %d\n", res);

    // 2) int res = find_min_array(array, length);
    // printf("res: %d\n", res);

    // 1) bubble_sort(array, length);

    //
    return 0;
}