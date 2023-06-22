// 16_stack8.cpp
#include <iostream>
#include <string>
using namespace std;

// 클래스도 템플릿으로 만들 수 있습니다.
#if 1
template <typename TYPE>
class Stack {
private:
    TYPE* buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new TYPE[size];
        top = 0;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

    void push(TYPE n)
    {
        buff[top++] = n;
    }

    TYPE pop()
    {
        return buff[--top];
    }
};
#endif
// * 템플릿은 소스와 헤더파일로 분리할 수 없습니다.
// => 헤더를 통해서만 제공되어야 합니다.
//   stack.hpp(.h + .cpp) / Boost

#include "stack.hpp"

// 질문????
template <typename T1, typename T2>
class AAA { };

// 클래스 템플릿은 타입 추론이 불가능합니다.
// 명시적으로 타입을 지정해야 합니다.

int main()
{
    Stack<string> s;
    s.push("hello");
    s.push("world");
    s.push("money");

    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
}

#if 0
int main()
{
    Stack<int> s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif
