#include <stdio.h>
#include <string.h>


int find_min_array(int array[], int length) {
    int min = array[0];

    for(int i = 0; i < length; i++) {
        if(array[i] < min) {
            min = array[i];
        }
    }

    return min;
}

void bubble_sort() {
    int array[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};
    int size_of_array = sizeof(array)/sizeof(array[0]);

    // ascending sort
    for(int i = 0; i < size_of_array - 1; i++) {
        for(int j = 0; j < size_of_array - 1 - i; j++) {
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
    for(int i = 0; i < size_of_array; i++) {
        printf("%d, ", array[i]);
    }
    puts("");
}


int main(void) {
    // bubble_sort();

    int array[] = {5, 9, 10, 11, 4, 3, 8, 6, 7};
    int length = sizeof(array)/sizeof(array[0]);
    int res = find_min_array(array, length);
    printf("res: %d\n", res);

    //
    return 0;
}