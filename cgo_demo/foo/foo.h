int add(int x, int y);
int pass_array_pointer(int *in, int n);
int *return_array_pointer(int n);

struct Byz_req {
    int len;
    char *s;
};

typedef int (*callback_fcn)(int, struct Byz_req*);
void some_c_func(callback_fcn);
void Hello(struct Byz_req* req);