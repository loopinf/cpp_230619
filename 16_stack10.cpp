// 16_stack10.cpp
#include <iostream>
using namespace std;

// C++ 표준라이브러리에 스택이 있습니다.
#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 제거하는 연산과 참조하는 연산이 분리되어 있습니다.
    // - 데이터 제거: s.pop()
    // - 데이터 참조: s.top()
    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
