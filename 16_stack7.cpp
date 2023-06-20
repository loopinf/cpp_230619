// 16_stack8.cpp
#include <iostream>
using namespace std;

// * 객체 내부에서 메모리 할당한다면, 반드시 객체가 파괴될 때,
//   해지되어야 합니다.
// * 객체가 파괴되기 전에 자동으로 호출되는 약속된 멤버 함수가
//   있습니다.
//    => 소멸자(Destructor) 함수

// 소멸자
// 1) ~클래스이름() 형태입니다.
// 2) 인자가 없습니다.
//    오버로딩도 불가능합니다.
// 3) 반환값도 없고, 명시하지도 않습니다.
// 4) 소멸자는 오직 1개만 제공 가능합니다.
// 핵심: 객체가 생성자를 통해 자원을 할당한다면, 반드시
//      소멸자를 통해 정리해야 합니다.

class Stack {
private:
    int* buff;
    int top;

public:
    // Stack s(100);
    // Stack s{100};

    // Stack s;  // s(10)
    // 파라미터 기본값은 불필요한 오버로딩을 제거할 수 있습니다.
    Stack(int size = 10)
    {
        buff = new int[size];
        top = 0;
    }

    ~Stack()
    {
        cout << "~Stack()" << endl;
        delete[] buff;
    }

#if 0
    Stack()
    {
        buff = new int[10];
        top = 0;
    }
#endif

    void push(int n)
    {
        buff[top++] = n;
    }

    int pop()
    {
        return buff[--top];
    }
};

int main()
{
    Stack s1(100);

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
