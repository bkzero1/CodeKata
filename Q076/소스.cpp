#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s) {

    // 문자열 시작과 공백 다음을 단어의 첫 문자로 처리
    bool isWordStart = true;
    for (char& ch : s)
    {
        if (ch == ' ')
        {
            isWordStart = true;
            continue;
        }
        
        // 첫 문자는 대문자로, 나머지는 소문자로 변환하며 공백은 유지
        if (isWordStart)
        {
            ch = std::toupper(ch);
            isWordStart = false;
        }
        else
        {
            ch = std::tolower(ch);
        }
    }

    return s;
}

// 공백을 포함한 입력 전체와 기대값, 실제값을 한 줄에서 비교
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
    Test("official example 1", "3people unFollowed me", "3people Unfollowed Me");
    Test("official example 2", "for the last week", "For The Last Week");
    Test("additional case 1", "a", "A");
    Test("additional case 2", "HELLO WORLD", "Hello World");
    Test("additional case 3", "  heLLo   wORLD  ", "  Hello   World  ");
    Test("additional case 4", "3aBC 2DEf", "3abc 2def");
    Test("additional case 5", " ", " ");
    Test("additional case 6 - single leading space", " hello", " Hello");
    return 0;
}

/* Q076 JadenCase 문자열 만들기 https://school.programmers.co.kr/learn/courses/30/lessons/12951

문제 설명

JadenCase란 모든 단어의 첫 문자가 대문자이고, 그 외의 알파벳은 소문자인 문자열입니다. 단, 첫 문자가 알파벳이 아닐 때에는 이어지는 알파벳은 소문자로 쓰면 됩니다. (첫 번째 입출력 예 참고)
문자열 s가 주어졌을 때, s를 JadenCase로 바꾼 문자열을 리턴하는 함수, solution을 완성해주세요.

제한 조건

- s는 길이 1 이상 200 이하인 문자열입니다.
- s는 알파벳과 숫자, 공백문자(" ")로 이루어져 있습니다.
  - 숫자는 단어의 첫 문자로만 나옵니다.
  - 숫자로만 이루어진 단어는 없습니다.
  - 공백문자가 연속해서 나올 수 있습니다.

입출력 예

s                         return
"3people unFollowed me"    "3people Unfollowed Me"
"for the last week"        "For The Last Week"

※ 공지 - 2022년 1월 14일 제한 조건과 테스트 케이스가 추가되었습니다.

*/
