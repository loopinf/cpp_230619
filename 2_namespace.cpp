// 2_namespace.cpp

// 1. C에서는 이름 충돌을 방지하기 위해서,
//    접두어를 약속하는 경우가 많습니다.
//  => C++은 이름 공간(namespace)의 문법을 이용해서,
//     이름 충돌 문제를 해결할 수 있습니다.
#if 0
// a.c
void audio_foo(void) { }
// b.c
void video_foo(void) { }
#endif

// 2. namespace
//   > 소문자로 사용해야 합니다.
//   1) 이름 충돌을 해결할 수 있습니다.
//   2) 프로그램의 각 요소를 관련된 요소끼리 그룹화할 수 있습니다.
//   3) C++ 표준의 모든 요소는 std 이름 공간안에 존재합니다.
namespace audio {

void foo() { }

namespace mp3 {
    void play() { }
}

namespace mp4 {
    void play() { }
}

}

namespace video {
void foo() { }
}

// mp3.h
namespace mp3 {
void play();
}

namespace mp3 {
void play()
{
    // ....
}
}
// mp3.cpp

int main()
{
    audio::foo();
    video::foo();

    audio::mp3::play();
    audio::mp4::play();
}
