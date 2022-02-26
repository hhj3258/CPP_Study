#include <iostream>
using namespace std;

//오늘의 주제: 함수 마무리

// 오버로딩(중복 정의: 함수 이름의 재사용)
// - 매개변수 갯수가 다르거나
// - 매개변수 타입이 다르거나(순서가 다른걸 포함)
int Add(int a, int b)
{
    return a + b;
}

float Add(float a, float b)
{
    float result = a + b;
    return result;
}

// 기본 인자값
void SetPlayerInfo(int hp, int mp, int attack, int guildId = 0)
{

}

int main()
{
    float result = Add(1.5f, 2.1f);
    cout << result << endl;

    SetPlayerInfo(100, 40, 10);

    return 0;
}
