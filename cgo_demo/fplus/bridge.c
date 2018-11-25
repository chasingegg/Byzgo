#include "fplus.h"
#include "bridge.h"

void bar() {
    Foo* foo = new Foo();
    foo -> bar();
}