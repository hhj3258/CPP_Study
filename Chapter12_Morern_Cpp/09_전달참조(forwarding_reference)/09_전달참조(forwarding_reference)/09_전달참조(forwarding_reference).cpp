#include <iostream>
using namespace std;

// 오늘의 주제 : 전달 참조(forwarding reference)

class Knight
{
public:
    Knight() { cout << "기본 생성자" << endl; }

    Knight(const Knight&) { cout << "복사 생성자" << endl; }

    Knight(Knight&&) noexcept { cout << "이동 생성자" << endl; }

    Knight& operator=(const Knight& rhs) 
    { 
        cout << rhs.hp << endl;
        return *this; 
    }

    int hp = 1;
};

void Test_RValueRef(Knight&& k) // 오른값 참조
{

}

void Test_Copy(Knight k)
{

}

// T&& param : 들어오는 매개변수 타입에 따라 두가지 의미
// 1) 오른값 참조가 들어오면 오른값 참조로
// 2) 전달 참조가 들어오면 전달 참조로
// 두 가지 형식으로 컴파일러가 추론한다.
template<typename T>
void Test_ForwardingRef(T&& param)
{
    // param은 여기서 무조건 lvalue 이다. 단일식을 넘어서서 사용 가능하니까.
    // 그러므로 Test_Copy() 에서 복사생성자가 아닌, 이동생성자를 호출하고 싶다면
    // std::move(param)을 매개변수로 넣어주어야 한다.
    //Test_Copy(std::move(param));

    // 하지만 param이 lvalue ref라면 위와 같이 move()하는 것은 
    // 원본 훼손의 우려가 생긴다.
    
    // 해결방법 : std::forward<T>(param)
    // 1. 왼값 참조라면 복사생성자
    // 2. 오른값 참조라면 이동생성자
    Test_Copy(std::forward<T>(param));
}

int main()
{
    // 보편 참조(universal reference)   <- C++17 이전까지 이름
    // 전달 참조(forwarding reference)  <- C++17 이후

    // && 는 두가지 의미로 쓸 수 있다.
    // 1) 오른값 참조
    // 2) 전달 참조

    Knight k1;
    Test_RValueRef(std::move(k1));      // 오른값 참조


    Test_ForwardingRef(std::move(k1));  // 오른값 참조
    Test_ForwardingRef(k1);             // 전달 참조

    auto&& k2 = k1;                     // 전달 참조
    auto&& k3 = std::move(k1);          // 오른값 참조
    k2 = k3;

    // 공통점 : 형식 연역 (type deduction)이 일어날 때
    // 즉, auto, template 등을 써서 컴파일러가 '추론'을 해야 할 때
    // '오른값 참조 or 전달 참조'가 된다.


    // ------------------------------------------------------------

    Knight& k4 = k1;    // 왼값 참조
    Knight&& k5 = std::move(k1);    // 오른값 참조

    //Test_RValueRef(k5); //Error! k5는 오른값이 아니다!?
    // 오른값 : 왼값이 아니다, 단일식에서 벗어나면 사용 불가한 녀석들
    // 오른값 참조 : 오른값만 참조할 수 있는 참조 타입
    // 
    // k5는 '오른값 참조' 이긴 하지만, '오른값'은 아니다.
    // 엄연히 단일식을 벗어나도 사용할 수 있는 '왼값'이다.
    // 즉, k5는 'rvalue reference' 이자 'lvalue' 인 것이다.
    // 따라서 '왼값'인 k5를 'std::move'로 '오른값' 으로 바꿔주면 된다.
    Test_RValueRef(std::move(k5));
    
    // std::forward 사용
    Test_ForwardingRef(k5);
    Test_ForwardingRef(std::move(k5));
    
    return 0;
}