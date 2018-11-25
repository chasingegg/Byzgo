package main

/*
#include <stdio.h>
#include "foo/foo.h"

// The gateway function
int callOnMeGo_cgo(int in, struct Byz_req* ii)
{
	printf("C.callOnMeGo_cgo(): called with arg = %d\n", in);
	int callOnMeGo(int, struct Byz_req*);
	return callOnMeGo(in, ii);
}
*/
import "C"