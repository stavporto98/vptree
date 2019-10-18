#include <stdio.h>

/*
double quickSelect(double array[]) {
    int size = sizeof(array) / sizeof(double);
    int right = size - 1;
    int i = -1;
    int j = 0;

    pivot = array[right];




}
*/

void quickSort(double array[], int size) {
    //int size = sizeof(array) / sizeof(double);
    printf("size: %d\n", size);

    recQuickSort(0, size-1, array, size);
}

void recQuickSort(int left, int right, double array[],int size) {
    if(right - left <= 0) {
        return;
    }
    else {
        double pivot = array[right];

        int part = partition(array, left, right, pivot);

        recQuickSort(left, part-1, array,size);
        recQuickSort(part+1, right, array,size);
    }
}

int partition(double array[],int left, int right, double pivot) {
    int leftPtr = left-1;
    int rightPtr = right;
    int i=0;

    while(1) {
        while(array[++leftPtr] < pivot) {
            continue;
        }
        while(right > 0 && array[--rightPtr] > pivot) {
            continue;
        }

        if(leftPtr >= rightPtr) {
            break;
        }
        else {
            swap(leftPtr, rightPtr, array);
        }
    }
    swap(leftPtr, right, array);

    for ( i = 0; i < 5; i++) {
        printf(" %lf ", array[i]);
    }
    printf("\n%d\n", leftPtr);
    return leftPtr;
}

void swap(int val1, int val2, double array[]) {
    double temp = array[val1];
    array[val1] = array[val2];
    array[val2] = temp;
}

int main(int argc, char const *argv[]) {
    int i=0;
    double array[5];

    for (i = 0; i < 5; i++) {
        array[i] = 5.0 - (double) i;
    }

    for (i = 0; i < 5; i++) {
        printf(" %2.1lf ", array[i]);
    }
    printf("\n" );

    quickSort(array,5);

    for (i = 0; i < 5; i++) {
        printf(" %2.1lf ", array[i]);
    }


    return 0;
}
