
#ifndef STACK_HPP
#define STACK_HPP

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

    void push(TYPE n);
    TYPE pop();
};

//       Stack: 클래스 템플릿
// Stack<TYPE>: 클래스
template <typename TYPE>
void Stack<TYPE>::push(TYPE n)
{
    buff[top++] = n;
}

template <typename TYPE>
TYPE Stack<TYPE>::pop()
{
    return buff[--top];
}

#endif
