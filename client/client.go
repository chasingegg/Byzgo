package main

// #cgo CFLAGS: -I../bft/gmp -I../bft/libbyz -I../bft/sfs/include/sfslite -O3 -fno-exceptions -DNDEBUG
// #cgo LDFLAGS: -L../bft/gmp -L../bft/libbyz -L../bft/sfs/lib/sfslite -lbyz -lsfscrypt -lasync -lgmp -lstdc++
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<signal.h>
// #include<unistd.h>
// #include<sys/param.h>
// #include"libbyz.h"
import "C"
import (
	"log"
	"unsafe"
)
const Simple_size int = 8192
var option = 0
var num_iter = 100

func main() {
	var config = "../bft/config"
	var config_priv = "./bft/config_private/template"
	var port = 0
	c_config := C.CString(config)
	c_config_priv := C.CString(config_priv)
	defer C.free(unsafe.Pointer(c_config))
	defer C.free(unsafe.Pointer(c_config_priv))

	C.Byz_init_client(c_config, c_config_priv, C.short(port))

	read_only := 0
	req := C.struct__Byz_buffer{}
	rep := C.struct__Byz_buffer{}
	C.Byz_alloc_request(&req, C.int(Simple_size))
	for i := 0; i < Simple_size; i++ {
		*(*C.char)(unsafe.Pointer(uintptr(unsafe.Pointer(req.contents)) + uintptr(i))) = C.char(option)
	}
	if option != 2 {
		req.size = 8
	} else {
		req.size = C.int(Simple_size)
	}
	
	for i := 0; i < num_iter; i++ {
		// invoke request
		C.Byz_invoke(&req, &rep, C.ulong(read_only))

		// check reply
		if !(((option == 2 || option == 0) && rep.size == 8) || (option == 1 && rep.size == C.int(Simple_size))) {
			log.Fatal("invalid reply")
		}

		// free reply
		C.Byz_free_reply(&rep)
	}

	C.Byz_free_request(&req)
}