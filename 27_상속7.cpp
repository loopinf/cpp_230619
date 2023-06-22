// 27_상속7.cpp
#include <iostream>
#include <vector>
using namespace std;

// Stack을 만들고 싶습니다.
// 이미 잘 만들어진 동적 배열인 vector가 있습니다.
//  => 데이터를 한쪽으로 집어넣고, 한쪽으로 빼면
//     스택입니다.

// class Derived : public Base
//     부모           자식
// protected        protected
// public           public

// class Derived : protected Base
//     부모           자식
// protected        protected
// public           protected

// class Derived : private Base
//     부모           자식
// protected        private
// public           private

// protected 상속 / private 상속
// => 부모의 기능은 자식 클래스가 이용하지만,
//    외부에는 공개하지 않겠다.
//    "부모의 인터페이스는 물려받지 않겠다."

#if 0
template <typename TYPE>
class Stack : private vector<TYPE> {
public:
    void push(const TYPE& v)
    {
        vector<TYPE>::push_back(v);
    }

    TYPE& top()
    {
        return vector<TYPE>::back();
    }

    void pop()
    {
        vector<TYPE>::pop_back();
    }
};
#endif

// 상속을 재사용의 목적으로 사용하는 것은 좋지 않습니다.
// 기존 클래스의 재사용은 포함을 사용해야 합니다.

// Adapter Pattern
//  => 기존 클래스의 인터페이스를 변경해서, 새로운 클래스처럼
//     사용할 수 있습니다.

// C++에서는 Stack Adapter라고 합니다.
#include <list>
#include <deque>
#include <stack>

template <typename TYPE, typename C = deque<TYPE>>
class Stack {
private:
    C c;

public:
    void push(const TYPE& v)
    {
        c.push_back(v);
    }

    TYPE& top()
    {
        return c.back();
    }

    void pop()
    {
        c.pop_back();
    }
};

int main()
{
    Stack<int, list<int>> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // s.push_back(100); // 부모의 기능

    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
    cout << s.top() << endl;
    s.pop();
}
