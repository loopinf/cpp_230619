// 16_stack10.cpp
#include <iostream>
using namespace std;

// C++ 표준라이브러리(STL, Standard Template Library)에
// 스택이 있습니다.
// 1) 컨테이너(자료구조)
//    vector: 동적 배열, 연속된 메모리
//      list: 연결 리스트
//     deque: vector 와 list의 절충형 자료구조
//---------
//     map / unordered_map: 사전 자료구조
//     set / unordered_set: 집합 자료구조
//---------
//     stack / queue

#if 0
#include <stack>

int main()
{
    stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);

    // 데이터를 제거하는 연산과 참조하는 연산이 분리되어 있습니다.
    // => 반환용 임시 객체의 복사 생성 비용을 제거하기 위한 설계
    // - 데이터 제거: s.pop()
    // - 데이터 참조: s.top()
    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();

    cout << s.top() << endl;
    s.pop();
}
#endif

#if 1
#include <vector>

int main()
{
    vector<int> v = { 10, 20, 30 };
    cout << v.size() << endl;

    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    v.push_back(100);
    cout << v.size() << endl;

    cout << v[0] << endl;
    cout << v[3] << endl;

    cout << v.back() << endl;
    v.pop_back();

    for (auto e : v) {
        cout << e << endl;
    }
}
#endif
