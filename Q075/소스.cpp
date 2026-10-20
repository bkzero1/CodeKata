#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    int minValue;
    int maxValue;

    // 첫 번째 정수로 최솟값과 최댓값을 초기화
    auto spacePosition = s.find(' ');
    minValue = std::stoi(s.substr(0, spacePosition));
    maxValue = minValue;

    // 원본은 유지하고 공백 위치를 옮기며 각 정수 구간만 변환
    // 마지막 구간은 다음 공백이 없어도 substr가 문자열 끝까지만 가져옴
    while (spacePosition != std::string::npos)
    {
        const auto nextSpacePosition = s.find(' ', spacePosition + 1);
        int number = std::stoi(s.substr(spacePosition + 1, nextSpacePosition - (spacePosition + 1)));

        minValue = std::min(minValue, number);
        maxValue = std::max(maxValue, number);

        spacePosition = nextSpacePosition;
    }

    return { std::to_string(minValue) + ' ' + std::to_string(maxValue) };
}

// 입력 문자열과 기대값, 실제값을 한 줄에서 비교
void Test(const string& name, const string& s, const string& expected)
{
    const string actual = solution(s);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: s = " << '"' << s << '"';
    cout << " | expected: " << '"' << expected << '"';
    cout << " | actual: " << '"' << actual << '"' << '\n';
}

int main()
{
    Test("official example 1", "1 2 3 4", "1 4");
    Test("official example 2", "-1 -2 -3 -4", "-4 -1");
    Test("official example 3", "-1 -1", "-1 -1");
    Test("additional case 1", "0 0", "0 0");
    Test("additional case 2", "9 2", "2 9");
    Test("additional case 3", "-10 0 7 -3", "-10 7");
    Test("additional case 4", "10 2 100", "2 100");
    return 0;
}

/* Q075 최댓값과 최솟값 https://school.programmers.co.kr/learn/courses/30/lessons/12939

문제 설명

문자열 s에는 공백으로 구분된 숫자들이 저장되어 있습니다. str에 나타나는 숫자 중 최소값과 최대값을 찾아 이를 "(최소값) (최대값)"형태의 문자열을 반환하는 함수, solution을 완성하세요.
예를들어 s가 "1 2 3 4"라면 "1 4"를 리턴하고, "-1 -2 -3 -4"라면 "-4 -1"을 리턴하면 됩니다.

제한 조건

- s에는 둘 이상의 정수가 공백으로 구분되어 있습니다.

입출력 예

s                 return
"1 2 3 4"         "1 4"
"-1 -2 -3 -4"     "-4 -1"
"-1 -1"           "-1 -1"

*/
