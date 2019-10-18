#include <stdio.h>
#include <time.h>


void quickSelect_Median(double *array, int size, double *result) {
    printf("size: %d\n", size);


    recquickSelect_Median(0, size-1, array, size, result);
}

void recquickSelect_Median(int left, int right, double array[],int size, double *result) {
    printf("\nleft: %lf,   right: %lf\n",   array[left], array[right]);
    if(right - left <= 0) {
        *result = array[right];
        return;
    }
    else {
        double pivot = array[right];
        int part = partition(array, left, right, pivot);
        printf("part = %d\n", part);
        if(part > (int)(size/2))
            recquickSelect_Median(left, part-1, array,size, result);
        if(part < (int) (size/2))
            recquickSelect_Median(part+1, right, array,size, result);
        if(part == (int) (size/2)) {
            *result = array[part];
            return;
        }


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

    printf("the pivot is %0.1lf: ,   ", pivot);
    for ( i = 0; i < 10; i++) {
        printf(" %0.1lf ", array[i]);
    }
    printf("\nleftPtr: %d\n", leftPtr);
    return leftPtr;
}

void swap(int val1, int val2, double array[]) {
    double temp = array[val1];
    array[val1] = array[val2];
    array[val2] = temp;
}

int main(int argc, char const *argv[]) {
    int i=0;
    int size = 10;
    double array[size];
    double result = 0.0;
    srand(time(NULL));


    for (i = 0; i < size; i++) {
        array[i] = (double) (rand()%100);
    }

    for (i = 0; i < size; i++) {
        printf(" %2.1lf ", array[i]);
    }
    printf("\n" );

    quickSelect_Median(array,size, &result);

    for (i = 0; i < size; i++) {
        printf(" %2.1lf ", array[i]);
    }
    printf("\n\n##### THE RESULT IS:  %lf  #####\n", result);

    return 0;
}
