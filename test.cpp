

int foo() { }
// 0000000000000000 T __Z3foov

double foo(int x)
{
}
// 0000000000000004 T __Z3fooi

char foo(int a, int b, char c, double d) { }
// 0000000000000014 T __Z3fooiicd

// extern "C"

extern "C" int add(int a, int b) { return a + b; }
// 0000000000000044 T __Z3addii
