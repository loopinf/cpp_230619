// 16_stack6.cpp
#include <iostream>
using namespace std;

// * 사용자가 원하는 크기의 스택을 생성하고 싶습니다.
//  => 생성자는 오버로딩이 가능합니다.
//  "객체를 생성하는 다양한 방법을 제공할 수 있습니다."

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
