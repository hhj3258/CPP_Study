#include <iostream>
using namespace std;

// 오늘의 주제 : 로또 번호 생성기

void Swap(int& a, int& b) 
{
    int temp = a;
    a = b;
    b = temp;
}

void Sort(int numbers[], int count) 
{
    for (int i = 0; i < count - 1; i++) 
    {
        for (int j = i + 1; j < count; j++)
        {
            if (numbers[i] > numbers[j]) 
            {
                Swap(numbers[i], numbers[j]);
            }
        }
    }
}

// 3) 로또 번호 생성
void ChooseLotto(int numbers[])
{
    // TODO : 랜덤으로 1~45 사이의 숫자 6개를 골라주세요! (단, 중복이 없어야 함)

    srand((unsigned)time(0));   //랜덤 시드 설정


    for (int i = 0; i < 6; i++)
    {
        int now_num = (rand() % 45) + 1; 

        for (int j = 0; j < i; j++)
        {
            if (numbers[j] == now_num)
            {
                i--;
                continue;
            }
        }

        numbers[i] = now_num;
    }

    Sort(numbers, 6);

    for (int i = 0; i < 6; i++)
    {
        cout << numbers[i] << ' ';
    }
}

int main()
{
    // 1) Swap 함수 만들기
    int a = 1;
    int b = 2;
    Swap(a, b);
    
    cout << a << " " << b << endl;

    // 2) 정렬 함수 만들기(작은 숫자가 먼저 오도록 정렬)
    int numbers[] = { -1,-1,-1,-1,-1,-1 };
    
    Sort(numbers, sizeof(numbers) / sizeof(int));

    // 3) 로또 번호 생성기
    ChooseLotto(numbers);

    // 행운의 로또 앱 완성
    for (int i = 0; i < 6; i++)
        cout << numbers[i] << endl;

    return 0;
}
