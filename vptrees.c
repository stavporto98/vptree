#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100
#define D 2

int *using_points = (int*) malloc(N * sizeof(int)) ; //points using as vp, size N,

struct vptree {
    double **data;
    double *vp[1];
    double mu;
    struct node *inside;
    struct node *outside;
} vptree;

double **generate_points() {
    int i = 0;
    int j = 0;
    srand(time(NULL));

    double **points = (double **) malloc(N * sizeof(double*));
    for (i = 0; i < N; i++) {
        points[i] = (double *) malloc(D * sizeof(double));
    }

    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            points[i][j] = (double) rand() / RAND_MAX;
        }
    }

    return points;
}

vptree *buildvp(double **X, int n, int d) {

}

vptree *getInner(vptree *T) {
    return T->inside
}

double *getVP(vptree *T) {
    double *array;



}



int main(int argc, char const *argv[]) {
    double **array;
    int i=0;
    int j=0;
    int counter = 0;

    array = generate_points();


    for (i = 0; i < N; i++) {
        for (j = 0; j < D; j++) {
            printf(" %8.6lf ", array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
