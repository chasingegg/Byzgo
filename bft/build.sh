#!/bin/sh

cd libbyz
make CPPFLAGS="-I../gmp -I../sfs/include/sfslite -g -Wall -DRECOVERY -fpermissive -DHAVE_GMP_CXX_OPS"
cd ..

cd bft-simple
make CPPFLAGS="-I../gmp -I../libbyz -I../sfs/include/sfslite -O3 -fno-exceptions -DNDEBUG"
cd ..