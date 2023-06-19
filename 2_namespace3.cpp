// 2_namespace3.cpp
#include <iostream>
// 1) namespace 전체를 명시하는 방법
//   std::cout

#if 0
int main()
{
    std::cout << "Hello, C++" << std::endl;
}
#endif

// 헤더에 작성하면 안됩니다.
// 2) using 선언(declaration)
#if 0
using std::cout;
using std::endl;

int main()
{
    cout << "Hello, C++" << endl;
}
#endif

// 3) using 지시어(directive)
#if 0
using namespace std;
// std 안에 모든 것을 암묵적으로 접근할 수 있습니다.
// > 현업에서 쓰면 안됩니다.

int main()
{
    cout << "Hello, C++" << endl;
}
#endif

#if 0

using std::cout;
using std::endl;
// std::count 라는 함수가 있습니다.

int count = 0;

int main()
{
    count++;

    cout << count << endl;
}
#endif

#if 0
namespace audio {
void play() { }
}

namespace video {
void play() { }
}
using audio::play;
// using video::play;

int main()
{
    play();

    video::play();
}
#endif

using namespace std;

void play() { cout << "play" << endl; }

namespace audio {
void play() { cout << "audio::play" << endl; }

void foo()
{
    cout << "audio::foo" << endl;
    ::play();
    // ::play(); => 명시적으로 전역 함수를 호출합니다.
}
}

int cnt = 0;

// :: 전역 이름 공간을 의미합니다.
//  ::play()   -> 전역 함수 play 호출
//  ::cnt = 0; -> 전역 변수 cnt

int main()
{
    int cnt = 42;
    cout << cnt << endl;
    cout << ::cnt << endl;

    audio::foo();
}
