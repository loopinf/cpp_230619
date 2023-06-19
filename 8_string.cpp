// 8_string.cpp
#include <iostream>
using namespace std;

#include <cstring> // string.h

// 1. C 문자열
//  - '\0' 문자로 종료되는 char 배열

// 문제점
// 1) 문자열 연산을 함수를 이용해야 합니다.
// 2) 사용자가 직접 메모리를 관리해야 합니다.

#if 0
int main()
{
    char str[32] = "hello";
    const char* p = "hello";

    if (strcmp(str, p) == 0) {
        cout << "같은 문자열" << endl;
    }

    // char str2[32] = str; // 에러!
    char str2[32];
    strcpy(str2, str);
    cout << str2 << endl;

    strcat(str2, " world");
    cout << str2 << endl;
}
#endif

// C++ 문자열: std::string
// 1) 문자열 연산을 연산자를 통해 수행할 수 있습니다.
// 2) 메모리 관리의 책임이 표준 라이브러리에 있습니다.

int main()
{
    std::string s1 = "hello";
    std::string s2 = "hello";

    if (s1 == s2) {
        cout << "같은 문자열" << endl;
    }

    std::string s3 = s1;
    cout << s3 << endl;

    s3 += " world";
    cout << s3 << endl;
}
