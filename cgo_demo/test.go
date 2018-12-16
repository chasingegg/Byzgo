package main

// #cgo CFLAGS: -I./foo -I./fplus -std=c99
// #cgo LDFLAGS: -L./foo -L./fplus -lfoo -lfplus -lstdc++
// #include<stdlib.h>
// #include<stdio.h>
// #include<string.h>
// #include<signal.h>
// #include<sys/param.h>
// #include<unistd.h>
// #include "foo.h"
// #include "bridge.h"
// int callOnMeGo_cgo(int in, struct Byz_req* ii);
import "C"

import (
	"fmt"
	"reflect"
	"unsafe"
)

type Byz struct {
	len int
}

func pass() {
	in := []C.int{1, 2, 3, 4}
	inPointer := unsafe.Pointer(&in[0]) // 先转换成unsafe.Pointer再转成c指针
	inC := (*C.int)(inPointer)

	value := C.pass_array_pointer(inC, 4)
	fmt.Println(value)
}

//函数返回值是数组
func get() {
	n := 4
	outC := C.return_array_pointer(4)
	defer C.free(unsafe.Pointer(outC))

	sh := reflect.SliceHeader{uintptr(unsafe.Pointer(outC)), n, n}
	out := *(*[]C.int)(unsafe.Pointer(&sh))
	for _, v := range out {
		fmt.Println(v)
	}
}

//坑在于下面这句注释不可缺少的
//export callOnMeGo
func callOnMeGo(in int, ii *C.struct_Byz_req) int {
	fmt.Println(ii.len + 1)
	fmt.Printf("Go.callOnMeGo(): called with arg = %d\n", in)
	return in + 1
}

func main() {
	fmt.Println("Hello World!")

	ret := 0
	//var x int = 4
	a := C.int(1)
	b := C.int(2)
	fmt.Println(C.add(a, b))
	//fmt.Println(C.add(x, b))
	if ret != 0 {
		fmt.Println("1111")
	} else {
		fmt.Println("2222")
	}

	pass()
	get()
	C.bar()

	fmt.Printf("Go.main(): calling C function with callback to us\n")
	C.some_c_func((C.callback_fcn)(unsafe.Pointer(C.callOnMeGo_cgo)))

	name := C.CString("fffff")
	defer C.free(unsafe.Pointer(name))

	len := C.int(2018)

	g := C.struct_Byz_req{
		s:   name,
		len: len,
	}
	C.Hello(&g)
}
