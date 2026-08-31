#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
using namespace std;
//변환 알고리즘
//변환할 10진수 N을 3으로 나눈다.
//나머지를 기록한다. (이 값이 3진수의 한 자리)
//몫이 0이 될 때까지 1~2 과정을 반복한다.
//기록한 나머지를 역순으로 읽으면 3진수 결과가 된다.
int solution(int n) {
    int answer = 0;
    while (n > 0)
    {
        answer *= 3;        // 기존 답을 한칸 쉬프트
        answer += n % 3;    // 나머지를 누적
        //answer = answer * 3 + n % 3;  // 위 두 줄을 한줄로
        n /= 3;             // 다음 루프를 위한 나눗셈
    }

    return answer;
}

void Test(int n, int expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    int result = solution(n);
    bool success = (result == expected);

    cout << "n: " << n
        << " | Expected: " << expected
        << " | Result: " << result
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test(11, 19);             // 문제 예제
    Test(45, 7);             // 문제 예제
    Test(125, 229);          // 문제 예제
    Test(1, 1);              // 제한사항 최소값
    Test(3, 1);              // 작은 입력
    Test(9, 1);              // 작은 입력
    Test(10, 10);            // 추가 검증
    Test(100000000, 56480240); // 제한사항 최대값

    return 0;
}

/* Q40 3진법 뒤집기

문제 설명
자연수 n이 매개변수로 주어집니다.
n을 3진법 상에서 앞뒤로 뒤집은 후, 이를 다시 10진법으로 표현한 수를 return 하도록 solution 함수를 완성해주세요.

제한사항
n은 1 이상 100,000,000 이하인 자연수입니다.

입출력 예
n          result
45         7
125        229

입출력 예 설명
입출력 예 #1
답을 도출하는 과정은 다음과 같습니다.

n (10진법)    n (3진법)    앞뒤 반전(3진법)    10진법으로 표현
45            1200         0021               7

따라서 7을 return 해야 합니다.

입출력 예 #2
답을 도출하는 과정은 다음과 같습니다.

n (10진법)    n (3진법)    앞뒤 반전(3진법)    10진법으로 표현
125           11122        22111              229

따라서 229를 return 해야 합니다.

*/