package replica

// #cgo CFLAGS: -I../bft/gmp -I../bft/libbyz -I../bft/sfs/include/sfslite -O3 -fno-exceptions -DNDEBUG
// #cgo LDFLAGS: -L../bft/gmp -L../bft/libbyz -L../bft/sfs/lib/sfslite -lbyz -lsfscrypt -lasync -lgmp -lstdc++
// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<signal.h>
// #include<unistd.h>
// #include<sys/param.h>
// #include"libbyz.h"
// int exec_command_cgo(Byz_req *inb, Byz_rep *outb, Byz_buffer *non_det, int client, bool ro);
// void dump_handler();
// typedef int (*service)(Byz_req *inb, Byz_rep *outb, Byz_buffer *non_det, int client, bool ro);
import "C"
import (
	"unsafe"
)

// ByzInitReplica : register the replica  
func ByzInitReplica(configPath string) {
	var configPrivPath = "./bft/config_private/template"
	config := C.CString(configPath)
	configPriv := C.CString(configPrivPath)
	defer C.free(unsafe.Pointer(config))
	defer C.free(unsafe.Pointer(configPriv))

	C.dump_handler()
	var memSize  = 205 * 8192
	cMem := (*C.char)(C.malloc(C.ulong(memSize)))
	for i := 0; i < memSize; i++ {
		*(*C.char)(unsafe.Pointer(uintptr(unsafe.Pointer(cMem)) + uintptr(i))) = C.char(0)
	}
	defer C.free(unsafe.Pointer(cMem))

	C.Byz_init_replica(config, configPriv, cMem, C.uint(memSize), (C.service)(unsafe.Pointer(C.exec_command_cgo)), nil, 0)
}

// ByzRunReplica : receive req from client and reply
func ByzRunReplica() {
	C.Byz_replica_run()
}