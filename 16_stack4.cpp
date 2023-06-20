// 16_stack4.cpp
#include <iostream>
using namespace std;

// * 객체의 상태는 멤버 함수를 통해 조작되어야 합니다.
//   "정보 은닉(Information Hiding)"
//   => 접근 지정자
//   - private: 외부에서 접근이 불가능합니다.
//   -  public: 외부에서 접근이 가능합니다.

// * struct
//  => 기본 접근 지정자가 public 입니다.
//   class
//  => 기본 접근 지정자가 private 입니다.

class Stack {
private:
    // 멤버 데이터: 상태 / property
    int buff[10];
    int top;

public:
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

// 객체를 메모리에 생성하면, 바로 사용할 수 있어야 합니다.
int main()
{
    Stack s1;
    s1.init();

    // s1.top = -1; // !!!

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
