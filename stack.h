// stack.h
#ifndef STACK_H
#define STACK_H

class Stack {
private:
    int* buff;
    int top;

public:
    Stack(int size = 10);

    inline void push(int n);
    inline int pop();
};

// 인라인 함수의 구현은 헤더를 통해 제공되어야 합니다.
void Stack::push(int n)
{
    buff[top++] = n;
}

int Stack::pop()
{
    return buff[--top];
}

#endif
