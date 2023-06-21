// 22_복사생성자4.cpp
#include <iostream>
using namespace std;

class Sample {
public:
    Sample() { cout << "Sample()" << endl; }
    ~Sample() { cout << "~Sample()" << endl; }

    Sample(const Sample&) { cout << "Sample(const Sample&)" << endl; }

    // Rvalue reference
    // Move Constructor
    Sample(Sample&&) { cout << "Sample(Sample&&)" << endl; }
};

int main()
{
    Sample s = Sample();
}
// 1) g++ 22_복사생성자4.cpp -fno-elide-constructors -std=c++98
// > 복사 생성자
/*
Sample()
Sample(const Sample&)
~Sample()
~Sample()
*/

// 2) g++ 22_복사생성자4.cpp -fno-elide-constructors -std=c++11
// > 이동 생성자
/*
Sample()
Sample(Sample&&)
~Sample()
~Sample()
*/

// 3) g++ 22_복사생성자4.cpp -fno-elide-constructors -std=c++17
// > 복사(이동) 생성자 제거가 "최적화" 레벨이 아니라 "언어" 표준이 되었습니다.
//  => mandatory copy ellison
/*
Sample()
~Sample()
*/
