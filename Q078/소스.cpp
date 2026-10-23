#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <array>

using namespace std;

int solution(int n) {
    static std::array<int, 100000 + 1> fibonacciRemainders;
    static int lastComputedIndex = 0;
    
    const int divisor = 1234567;
    
    int sentinel = -1;
    if (lastComputedIndex == 0)
    {
        fibonacciRemainders.fill(sentinel);

        fibonacciRemainders.at(0) = 0;
        fibonacciRemainders.at(1) = 1;

        lastComputedIndex = 1;
    }

    // 타뷸레이션
    for (int i = lastComputedIndex + 1; i <= n; ++i)
    {
        if(fibonacciRemainders.at(i) == sentinel)
        {
            fibonacciRemainders.at(i) = (fibonacciRemainders.at(i - 2) % divisor + fibonacciRemainders.at(i - 1) % divisor) % divisor;
        }
    }

    if (n > lastComputedIndex)
    {
        lastComputedIndex = n;
    }

    return fibonacciRemainders.at(n);
}

void Test(const string& name, int n, int expected)
{
    const int actual = solution(n);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: n = " << n;
    cout << " | expected: " << expected;
    cout << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 예제
    Test("Official 1", 3, 2);
    Test("Official 2", 5, 5);

    // 추가 테스트: 작은 입력과 서로 다른 크기의 입력
    Test("Additional 1", 2, 1);
    Test("Additional 2", 4, 3);
    Test("Additional 3", 6, 8);
    Test("Additional 4", 10, 55);
    Test("Additional 5", 20, 6765);
    // 나누는 값보다 작은 경계와, 실제 나머지 처리가 필요한 입력
    Test("Additional 6 (before modulus boundary)", 30, 832040);
    Test("Additional 7 (first modulus boundary)", 31, 111702);
    Test("Additional 8 (multiple modulus ranges)", 34, 764619);

    // 재호출 시 기존 계산 결과 재사용과 필요한 구간의 추가 계산 확인
    Test("Additional 9 (extend cache)", 100, 963606);
    Test("Additional 10 (reuse smaller input)", 50, 1093027);
    Test("Additional 11 (extend cache again)", 1000, 138544);
    Test("Additional 12 (reuse earlier input)", 100, 963606);

    // 최대 입력 계산 후 작은 입력, 최대 직전 및 동일 입력 재호출 확인
    Test("Additional 13 (maximum input)", 100000, 1168141);
    Test("Additional 14 (minimum after maximum)", 2, 1);
    Test("Additional 15 (just below maximum)", 99999, 539935);
    Test("Additional 16 (repeat maximum)", 100000, 1168141);
    return 0;
}

/* Q078 피보나치 수 https://school.programmers.co.kr/learn/courses/30/lessons/12945

문제 설명
피보나치 수는 F(0) = 0, F(1) = 1일 때, 1 이상의 n에 대하여 F(n) = F(n-1) + F(n-2) 가 적용되는 수 입니다.

예를들어
- F(2) = F(0) + F(1) = 0 + 1 = 1
- F(3) = F(1) + F(2) = 1 + 1 = 2
- F(4) = F(2) + F(3) = 1 + 2 = 3
- F(5) = F(3) + F(4) = 2 + 3 = 5

와 같이 이어집니다.

2 이상의 n이 입력되었을 때, n번째 피보나치 수를 1234567으로 나눈 나머지를 리턴하는 함수, solution을 완성해 주세요.

제한 사항
- n은 2 이상 100,000 이하인 자연수입니다.

입출력 예
n    return
3    2
5    5

입출력 예 설명
피보나치수는 0번째부터 0, 1, 1, 2, 3, 5, ... 와 같이 이어집니다.

*/
