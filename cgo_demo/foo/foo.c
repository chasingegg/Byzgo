#include <stdio.h>
#include <stdlib.h>
#include "foo.h"

int add(int x, int y) {
    return x+y;
}

int pass_array_pointer(int *in, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += in[i];
        printf("%d\n", in[i]);
    }
    return sum;
}

int *return_array_pointer(int n) {
    int *out;
    out = (int *)(calloc(3, sizeof(int)));
    for (int i = 0; i < n; i++) {
        out[i] = i * 2;
    }
    return out;
}

void some_c_func(callback_fcn callback) {
    int arg = 2;
    struct Byz_req bb;
    bb.len = 3;
    printf("C.some_c_func(): calling callback with arg = %d\n", arg);
    int response = callback(2, &bb);
    printf("C.some_c_func(): callback responded with %d\n", response);
}

void Hello(struct Byz_req* req) {
    req->len = 2;
    printf("%d\n", req->len);
    printf("%s\n", req->s);
}