#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <numeric>

using namespace std;

string solution(int a, int b) {
    static const std::vector<int> daysInMonth = {
        31, 29, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };
    static const std::vector<string> weekdays = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };

    const int weekdayOffset = 4; // 1월 1일이 금요일 인덱스 5가 되도록 보정
    
    const int daysBeforeMonth = std::accumulate(
        daysInMonth.begin(), 
        daysInMonth.begin() + (a - 1), 
        0
    );
    
    return weekdays[(daysBeforeMonth + b + weekdayOffset) % 7];
}


//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, int a, int b, const string& expected)
{
    const string actual = solution(a, b);
    const bool success = actual == expected;

    cout << "\x1b[38;2;"
         << (success ? "120;230;102" : "230;102;102")
         << "m"
         << (success ? " SUCCESS" : "  FAIL  ")
         << "\x1b[0m"
         << " | " << testName
         << " | input: a=" << a << ", b=" << b
         << " | expected: \"" << expected << "\""
         << " | actual: \"" << actual << "\"\n";
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
    // 공식 예제 테스트
    Test("official example 1", 5, 24, "TUE");

    // 추가 경계 테스트
    Test("first day of the year", 1, 1, "FRI");
    Test("leap day", 2, 29, "MON");
    Test("last day of the year", 12, 31, "SAT");

    return 0;
}

/* Q054 2016년 https://school.programmers.co.kr/learn/courses/30/lessons/12901

문제 설명

2016년 1월 1일은 금요일입니다. 2016년 a월 b일은 무슨 요일일까요? 두 수 a, b를 입력받아 2016년 a월 b일이 무슨 요일인지 리턴하는 함수, solution을 완성하세요. 요일의 이름은 일요일부터 토요일까지 각각 "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"입니다.

예를 들어 a=5, b=24라면 5월 24일은 화요일이므로 문자열 "TUE"를 반환하세요.

제한 조건

- 2016년은 윤년입니다.
- 2016년 a월 b일은 실제로 있는 날입니다. (13월 26일이나 2월 45일 같은 날짜는 주어지지 않습니다.)

입출력 예

a  b   result
5  24  "TUE"

*/
