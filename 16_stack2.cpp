// 16_stack2.cpp
#include <iostream>
using namespace std;

// 스택의 상태를 전역 변수가 아닌 사용자 정의 타입을 통해
// 캡슐화 합니다.
//  "데이터 캡슐화"

struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s) { s->top = 0; }

void push(Stack* s, int n)
{
    s->buff[(s->top)++] = n;
}

int pop(Stack* s)
{
    return s->buff[--(s->top)];
}

int main()
{
    Stack s1;
    init(&s1);

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}
