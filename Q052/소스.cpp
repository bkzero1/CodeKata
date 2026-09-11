#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;

    while (n >= a)
    {
        int rest = n % a;
        int receivedCola = n / a * b;

        answer += receivedCola;

        n = receivedCola + rest;
    }
    return answer;
}


//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, int a, int b, int n, int expected)
{
    int actual = solution(a, b, n);
    bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m" : "\x1b[38;2;230;102;102m");
    cout << (success ? " SUCCESS" : "  FAIL  ");
    cout << "\x1b[0m";
    cout << " | " << testName
         << " | input: a=" << a << ", b=" << b << ", n=" << n
         << " | expected: " << expected
         << " | actual: " << actual << '\n';
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
    // 공식 예제 테스트
    Test("official example 1", 2, 1, 20, 19);
    Test("official example 2", 3, 1, 20, 9);

    // 추가 경계 테스트
    Test("one exchange", 3, 1, 3, 1);
    Test("remaining bottles reused", 3, 2, 10, 16);
    Test("large exchange unit", 10, 1, 100, 11);

    return 0;
}

/* Q052 콜라 문제 https://school.programmers.co.kr/learn/courses/30/lessons/132267

문제 설명
빈 병 a개를 가져다주면 콜라 b병을 주는 마트가 있습니다. 가지고 있는 빈 병이 a개 미만이면 더 이상 콜라를 받을 수 없습니다.

마트에 주어야 하는 빈 병 수 a, 교환으로 받는 콜라 병 수 b, 처음 가지고 있는 빈 병 수 n이 주어질 때, 받을 수 있는 콜라의 총 병 수를 return 하도록 solution 함수를 완성해주세요.

제한사항
- 1 <= b < a <= n <= 1,000,000
- 정답은 항상 int 범위를 넘지 않습니다.

입출력 예
a  b  n   result
2  1  20  19
3  1  20  9

입출력 예 설명
입출력 예 #1
- 빈 병 2개를 콜라 1병으로 계속 교환하면 총 19병을 받을 수 있습니다.

입출력 예 #2
- 20병에서 6병, 8병에서 2병, 4병에서 1병을 차례로 받아 총 9병을 받을 수 있습니다.

*/
