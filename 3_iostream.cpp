// 3_iostream.cpp
#include <iostream>
using namespace std;

// 1. 서식을 지정하지 않아도, 변수의 타입에 따라
//    입출력이 수행됩니다.
// 2. 주소를 전달하지 않아도, 변수의 값을 변경할 수 있습니다.
// 3. std::cout ??
//    std::cin ??
//    std::endl ??

int main()
{
    double n;

#if 0
    scanf("%d", &n);
    printf("%d\n", n);
#endif

    cin >> n;
    cout << n << endl;
}
