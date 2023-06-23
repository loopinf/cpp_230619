// 33_STL.cpp
#include <iostream>
using namespace std;

// STL(Standard Template Library) 구성 요소
// 1) 컨테이너: 데이터를 저장하기 위한 자료구조
//   선형: vector, list, array, deque
//   탐색: map, set, unordered_map, unordered_set ...

// 2) 알고리즘
//   컨테이너에 요소를 검색, 정렬, 탐색, 이진 탐색 등의 알고리즘을 제공합니다.
//    "일반 함수"

// 3) 반복자
//   컨테이너의 요소를 열거하기 위해, 배열에서 포인터의 역활을 수행하는
//   객체
//----------

// 1) 컨테이너
//  - 템플릿 기반입니다.
//    다양한 타입에 대해서 사용할 수 있습니다.

// 2) 멤버 함수의 이름이 유사합니다.
//  => 데이터를 제거하는 연산과 참조하는 연산이 분리되어 있습니다.
//   |---------------|
// push_front      push_back
//  pop_front       pop_back
//   front            back

// 3) vector
//  => 임의 접근이 가능합니다.
//    push_front 연산을 지원하지 않습니다.

//    list
//  => 임의 접근이 불가능합니다.
//    v[0] <- ERROR

#include <vector> // 연속된 메모리
#include <list> // 연결리스트

int main()
{
    vector<int> v = { 1, 2, 3, 4, 5 };
    // list<int> v = { 1, 2, 3, 4, 5 };

    // cout << v[3] << endl;
    // v.push_front(1000);

    v.push_back(10);
    v.push_back(20);
    v.push_back(30);

    for (auto e : v) {
        cout << e << endl;
    }
}
