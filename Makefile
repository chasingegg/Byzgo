curdir=$(dir $(abspath $(lastword $(MAKEFILE_LIST))))
all:
	@cd ${curdir}/bft/sfslite-1.2; \
	autoreconf -i; \
	sh -x setup.gnu -f -i -s; \
	mkdir install; \
	export SFSHOME=${curdir}/bft/sfslite-1.2; \
	./configure --prefix=$${SFSHOME}/install; \
	make CFLAGS="-Werror=strict-aliasing" CXXFLAGS="-fpermissive -DHAVE_GMP_CXX_OPS"; \
	make install; \
	cd ${curdir}/bft; \
	ln -s sfslite-1.2/install sfs; \
	ln -s /usr/lib gmp; \
	cd ${curdir}/bft/libbyz; \
	sed -i '418s/^.*$/  th_assert(sizeof(t.tv_sec) <= sizeof(long), "tv_sec is too big");/' Node.cc; \
	sed -i '420s/^.*$/  long int_bits = sizeof(long)*8;/' Node.cc; \
	make CPPFLAGS="-I../gmp -I../sfs/include/sfslite -g -Wall -DRECOVERY -fpermissive -DHAVE_GMP_CXX_OPS"

