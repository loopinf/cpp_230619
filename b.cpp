// b.cpp

int n = 100;
// 외부 연결: External linkage를 갖습니다.

static int s = 42;
// 내부 연결: Internal linkage, 다른 파일에서 접근이 불가능합니다.

void foo() { }

static void goo() { }

// const int c = 100;
// C: external linkage
// C++: internal linkage
