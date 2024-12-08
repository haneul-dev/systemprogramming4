#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *data;
    int length;
} vec;


vec *new_vec(int length) {
    vec *v = (vec *)malloc(sizeof(vec));
    v->data = (int *)malloc(sizeof(int) * length);
    v->length = length;
    for (int i = 0; i < length; i++) {
        v->data[i] = i + 1; 
    }
    return v;
}


int combine4(vec *v) {
    int result = 0;
    int length = v->length;
    int *data = v->data;

    int i;
    for (i = 0; i <= length - 4; i += 4) {
        result += data[i] + data[i + 1] + data[i + 2] + data[i + 3];
    }
    for (; i < length; i++) {
        result += data[i];
    }
    return result;
}

int main() {
    vec *v = new_vec(1000000); 
    int result = combine4(v);
    printf("Combine4 Result: %d\n", result);


    free(v->data);
    free(v);
    return 0;
}   
