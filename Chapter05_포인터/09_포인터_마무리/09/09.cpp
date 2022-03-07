#include <iostream>
using namespace std;

// 오늘의 주제: 포인터 마무리

// 1) 포인터 vs 배열 2탄
// 2) 주의사항 (마음가짐?)


int main()
{
    // 주소를 담는 바구니
    // 진퉁은 저~ 멀리 어딘가에 있음
    // p는 단지 그 곳으로 워프하는 포탈
    int* p;

    // 진짜배기! 원조 데이터
    // 닭장처럼 데이터의 묶음 (엄청 많고 거대함)
    int arr[10] = { 1,2,3,4,5,6,7,8 };

    // 그런데 상당히 많은 사람들이 [배열 = 포인터]라 착각하는 경향이 있음!

    // - [배열의 이름]은 배열의 시작 주소값을 가리키는 TYPE* 포인터로 변환 가능!
    p = arr;

    // - [TYPE형 1차원 배열]과 [TYPE* 형 포인터]는 완전히 호환이 된다
    cout << p[0] << endl;
    cout << arr[0] << endl;
    cout << p[5] << endl;
    cout << arr[5] << endl;

    cout << *p << endl; // p[0]
    cout << *arr << endl;   // arr[0]
    cout << *(p + 3) << endl;
    cout << *(arr + 3) << endl;


    return 0;
}