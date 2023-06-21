// 16_stack11.cpp - 총정리
#include <iostream>
using namespace std;

#if 0
int buff[10];
int top = 0;

void push(int n) { buff[top++] = n; }
int pop() { return buff[--top]; }

int main()
{
    push(10);
    push(20);
    push(30);

    cout << pop() << endl;
    cout << pop() << endl;
    cout << pop() << endl;
}
#endif

#if 0
struct Stack {
    int buff[10];
    int top;
};

void init(Stack* s)
{
    s->top = 0;
}

void push(Stack* s, int n)
{
    s->buff[s->top++] = n;
}

int pop(Stack* s)
{
    return s->buff[--s->top];
}

int main()
{
    Stack s1, s2;

    push(&s1, 10);
    push(&s1, 20);
    push(&s1, 30);

    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
    cout << pop(&s1) << endl;
}
#endif

// C++ 캡슐화: 상태 + 행위
// - 변수가 상태와 행위를 가진다면, 객체 라고 합니다.

// - 객체의 상태는 메소드를 통해 수정되거나 접근할 수 있어야 합니다.
// - 정보 은닉(Information Hiding)
//  => 접근 지정자
//     1) private: 외부에서 접근이 불가능합니다.
//                 오직 멤버 함수를 통해서 접근이 가능합니다.
//     2) public: 외부에서 접근이 가능합니다.

// => struct: 기본 접근 지정자가 public 입니다.
//     class: 기본 접근 지정자가 private 입니다.
#if 0
class Stack {
private:
    // 멤버 데이터 - 상태 / 속성(property)
    int buff[10];
    int top;

public:
    // 멤버 함수 - 상태를 조작하는 함수(행위) / method
    void init()
    {
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
    Stack s1, s2;
    // cout << s1.top << endl;
    s1.init();

    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
    cout << s1.pop() << endl;
}
#endif

// 객체가 메모리에 생성되는 시점에 호출되는 약속된 멤버 함수
// => 생성자 함수
//  1) 클래스 이름과 동일한 이름의 멤버 함수
//  2) 반환값은 존재하지 않고, 명시하지도 않습니다.
//  3) 생성자는 인자 정보가 다를 경우 여러개를 제공할 수 있습니다.
//    => 생성자 오버로딩이 가능합니다.
//    => 객체를 초기화하는 다양한 방법을 제공할 수 있습니다.

// 객체가 메모리에서 해지되는 시점에 호출되는 약속된 멤버 함수
// => 소멸자 함수
// 객체가 내부에서 자원을 할당한다면, 반드시 소멸자를 통해 자원을 해지해야 합니다.
// 1) ~클래스이름 형태입니다.
// 2) 인자는 없습니다. 오버로딩도 불가능합니다.
//    오직 1개만 제공할 수 있습니다.
#if 0
class Stack {
private:
    // 멤버 데이터 - 상태 / 속성(property)
    int* buff;
    int top;

public:
    Stack(int size = 10)
    {
        buff = new int[size];
        top = 0;
    }

    ~Stack()
    {
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
#endif

template <typename T>
class Stack {
private:
    // 멤버 데이터 - 상태 / 속성(property)
    T* buff;
    int top_;

public:
    Stack(int size = 10)
    {
        buff = new T[size];
        top_ = 0;
    }

    ~Stack()
    {
        delete[] buff;
    }

    void push(const T& n)
    {
        buff[top_++] = n;
    }

#if 0
    T pop()
    {
        return buff[--top_];
    }
#endif
    // C++ STL의 컨테이너는 데이터를 참조하는 연산과 제거하는 연산을
    // 분리하였습니다.
    T& top() { return buff[top_ - 1]; }
    void pop() { --top_; }
};

class Sample {
public:
    Sample() { }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
    ~Sample() { }
};

// void push(T n)
// stack<int>       ----> void push(int n)
// stack<Sample>    ----> void push(Sample n)

// void push(const T& n)
// stack<int>       ----> void push(const int& n)
// stack<Sample>    ----> void push(const Sample& n)

int main()
{
    Sample s;

    Stack<Sample> s1;
    // cout << "----------" << endl;
    s1.push(s);
    // cout << "----------" << endl;

    cout << "----------" << endl;
    s1.top();
    s1.pop();

    cout << "----------" << endl;
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
