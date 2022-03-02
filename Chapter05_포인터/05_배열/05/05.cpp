#include <iostream>
using namespace std;

// 오늘의 주제 : 배열

struct StatInfo
{
    int hp      = 0xAAAAAAAA;
    int attack  = 0xBBBBBBBB;
    int defence = 0xDDDDDDDD;
};

int main()
{
    // 근데 몬스터가 최대 1만마리!

    // 배열의 크기는 상수여야 함(VC컴파일러 기준)
    const int monsterCount = 10;
    StatInfo monsters[monsterCount];

    // 여태껏 변수들의 [이름]은 바구니의 이름이었음
    int a = 10;
    a = 3;
    // 그런데 배열은 [이름] 조금 다르게 동작한다.
    // StatInfo players[10];
    // players = monsters;  -> 불가능

    // 그럼 배열의 이름은 뭐지?
    // 배열의 이름은 곧 배열의 시작 주소
    // 정확히는 시작 위치를 가리키는 TYPE* 포인터
    auto WhoAmI = monsters;
    WhoAmI[0].attack = 1;
    // StatInfo[] StatInfo[] StatInfo[] ... 총 10개
    // 12byte * 10
    StatInfo* monster_0 = monsters;
    monster_0->hp = 100;
    monster_0->attack = 10;
    monster_0->defence = 1;

    // 포인터의 덧셈! 진짜 1을 더하라는게 아니라, StatInfo 타입 바구니 한 개씩 이동하라는 의미
    // StatInfo[] 주소[ (200, 20, 2) ] StatInfo[] ...
    // monster_1[주소]
    StatInfo* monster_1 = monsters+1;
    monster_1->hp = 200;
    monster_1->attack = 20;
    monster_1->defence = 2;

    // 포인터와 참조는 자유자재로 변환 가능하다
    // StatInfo[] StatInfo[(200, 20, 2)] 주소[] ...
    // monster_2[주소]
    StatInfo& monster_2 = *(monsters + 2);
    monster_2.hp = 300;
    monster_2.attack = 30;
    monster_2.defence = 3;

    // [주의] 이거는 완전 다른 의미다
    // 아래는 StatInfo 타입의 temp에 *(monsters + 2)의 값을 단순히 복사해서 넣어주는 것이다(monsters 배열을 조작하는 것이 아님!)
    StatInfo temp = *(monsters + 2);
    temp.hp = 300;
    temp.attack = 30;
    temp.defence = 3;

    for (int i = 0; i < 10; i++)
    {
        StatInfo& monster = *(monsters + i);
        monster.hp = 100 * (i + 1);
        monster.attack = 10 * (i + 1);
        monster.defence = (i + 1);
    }

    // 배열 초기화 문법 몇가지
    int numbers[5] = {};    // 모두 0
    int numbers1[10] = { 1,2,3,4,5 };   // 설정한 애들은 설정한 값들로, 나머지 값들은 0으로 초기화
    int numbers2[] = { 1,2,3,4,11,23,120 }; // 데이터 개수만큼의 크기에 해당하는 배열로 만들어준다.
    int numbers3[5];
    for (int i = 0; i < 5; i++)
        numbers3[i] = 1;
    char helloStr[] = { 'H','e','l','l','o','\0' };

    return 0;
}
