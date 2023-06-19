// 10_if.cpp
#include <iostream>
using namespace std;

// 성공 0을 반환합니다.
int OpenFile(const char* filename) { return 1; }

// 실패하였을 때, NULL을 반환합니다.
int* AllocMemory() { return NULL; }

#if 0
int main()
{
    for (int i = 0; i < 10; i++) {
    }
    for (int i = 0; i < 10; i++) {
    }

    int ret = OpenFile("a.txt");
    if (ret != 0) {
        // 오류 처리
    }
    // ..
    int* ret2 = AllocMemory();
    if (ret2 == NULL) {
        // 오류 처리
    }
}
#endif

// If statement with Initializer, C++17
int main()
{
    if (int ret = OpenFile("a.txt"); ret != 0) {
        // 오류 처리
    }

    if (int* ret = AllocMemory(); ret == NULL) {
        // 오류 처리
    }
}
