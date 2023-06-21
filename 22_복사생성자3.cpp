// ----
// 22_복사생성자3.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }
};

// 1) 지역 객체는 반드시 값으로 반환해야 합니다.
#if 0
Sample() // 지역 객체의 기본 생성자 호출
Sample(const Sample&) // 반환용 임시 객체 복사 생성자 호출
~Sample() // 반환용 임시 객체 소멸자 호출
~Sample() // 지역 객체의 소멸자
#endif

// 2) RVO(Return Value Optimization, 반환값 최적화)
//  => 반환용 임시 객체의 복사 생성 비용을 제거하는 컴파일러 최적화
#if 0
Sample foo()
{
    Sample s;
    return s;
}
#endif

// - 객체가 지역 객체를 값으로 반환할 때, 임시 객체를 반환하면 최적화합니다.
#if 0
Sample foo()
{
    return Sample();
}
#endif

// - 최신 컴파일러는 NRVO를 지원합니다.
//   Named RVO
Sample foo()
{
    Sample s;
    return s;
}

// 3) RVO / NRVO는 지역 객체를 값으로 반환할 때,
//    수행됩니다.

int main()
{
    foo();
}
