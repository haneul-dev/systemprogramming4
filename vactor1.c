#include <stdio.h>
#include <stdlib.h>

/
void init_vector(double *vec, int n) {
    for (int i = 0; i < n; i++) {
        vec[i] = i * 0.01;
    }
}

double vector1(double *a, double *b, int n) {
    double result = 0.0;
    for (int i = 0; i < n; i++) {
        result += a[i] * b[i];
    }
    return result;
}

int main() {
    int n = 1000000; 
    double *a = (double *)malloc(n * sizeof(double));
    double *b = (double *)malloc(n * sizeof(double));

 
    init_vector(a, n);
    init_vector(b, n);


    double result = vector1(a, b, n);
    printf("vector1 Result: %.2f\n", result);

    free(a);
    free(b);
    return 0;
}
