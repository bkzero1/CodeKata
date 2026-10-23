#include <iostream>
//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

unsigned long long fibonacci(unsigned long long n, int divisor = 1234567) {
    if (n <= 1)
    {
        return n; // n이 1보다 작을 때는 해당 값을 그대로 반환한다.
    }
    else
    {
        return fibonacci(n - 2) % divisor + fibonacci(n - 1) % divisor;
    }
}

int solution(int n) {
    int answer = fibonacci(n);
    //cout << "fibonacci(100000): " << fibonacci(100000) << endl;
    return answer;
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
