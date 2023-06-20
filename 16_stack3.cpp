// 16_stack3.cpp
#include <iostream>
using namespace std;

// 멤버 데이터와 멤버 함수를 하나의 타입으로 만들 수 있습니다.
//  => 캡슐화: 데이터(상태) + 함수(행위)
//  => 상태와 행위를 가지는 구조체 변수 => 객체(상태 + 행위)

struct Stack {
    // 멤버 데이터: 상태 / property
    int buff[10];
    int top;

    // 멤버 함수: 상태를 조작하는 행위 / method
    void init() { top = 0; }

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
    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
