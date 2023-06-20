// 16_stack.cpp
#include <iostream>
using namespace std;

// LIFO(Last In First Out)

// 1. 전역 변수
//   문제점: 하나의 프로그램에 여러개의 스택을 제공하기 어렵습니다.

int buff[10];
int top = 0;

void push(int n)
{
    buff[top++] = n;
}

int pop()
{
    return buff[--top];
}

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
