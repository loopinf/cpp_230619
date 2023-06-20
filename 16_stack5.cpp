// 16_stack6.cpp
#include <iostream>
using namespace std;

// * 객체를 메모리에 생성하면, 바로 사용할 수 있어야 합니다.
// * 객체가 메모리에 생성되었을 때, 자동으로 호출되는 약속된
//   멤버 함수가 있습니다.
//   => 생성자(Constructor) 함수

// 생성자 함수
//  : 클래스이름()
// => 반환값도 없고, 명시하지도 않습니다.

class Stack {
private:
    int buff[10];
    int top;

public:
    // 초기화 목적: 객체를 생성하였을 때, 바로 사용할 수 있습니다.
    Stack()
    {
        cout << "Stack()" << endl;
        top = 0;
    }

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
    Stack s1;

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
