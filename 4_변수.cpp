// 4_변수.cpp
#include <iostream>
using namespace std;

union Job {
    char school[32];
    char company[32];
};

struct Point {
    int x;
    int y;
};

enum TaskState {
    TASK_RUNNING,
    TASK_STOPPED
};

typedef union Job JOB;
typedef struct Point POINT;
typedef enum TaskState TASK_STATE;

// 1. C++에서 struct/union/enum 태그를 타입으로 인식합니다.
//   > 더이상 struct/union/enum을 명시할 필요가 없습니다.

// 2. typedef를 통해서, 사용자 정의 타입을 편리하게 사용하는 방법을
//    더 이상 사용할 필요가 없습니다.

int main()
{
    union Job job;
    struct Point pt;
    enum TaskState st;

    JOB job2;
    POINT pt2;
    TASK_STATE st2;

    Job job3;
    Point pt3;
    TaskState st3;
}
