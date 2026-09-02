#include <iostream>

//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <cctype>

using namespace std;

string solution(string s, int n) {
    //string answer = "";

    for (char& ch : s)
    {
        if (ch == ' ')  // 공백문자는 건너뜀
        {
            continue;
        }

        // a로부터 위치를 구하기 위해 우선 소문자로 변경
        char lowerCh = std::tolower(ch);

        // a부터의 거리
        int offsetFromA = lowerCh - 'a';

        // offset + n 이 z(25)를 넘어가는가?
        if (offsetFromA + n > 25)
        {
            if (std::islower(ch))
            {
                ch = 'a' + (offsetFromA + n) - 26;
            }
            else
            {
                ch = 'A' + (offsetFromA + n) - 26;
            }
        }
        else
        {
            ch += n;
        }
    }

    return s;
}

void Test(const string& s, int n, const string& expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    string result = solution(s, n);
    bool success = (result == expected);

    cout << "s: \"" << s << "\""
        << " | n: " << n
        << " | Expected: \"" << expected << "\""
        << " | Result: \"" << result << "\""
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    // 공식 예제
    Test("AB", 1, "BC");
    Test("z", 1, "a");
    Test("a B z", 4, "e F d");

    // 추가 경계 테스트
    Test("Zz", 1, "Aa");       // 대문자와 소문자가 함께 순환하는 경우
    Test("a z", 25, "z y");    // 최대 이동 거리와 공백
    Test(" ", 13, " ");        // 공백만 있는 문자열

    Test("ABC", 2, "CDE");

    // 대문자가 서로 다른 위치에서 순환하는 경우
    Test("XYZ", 4, "BCD");

    // 소문자가 서로 다른 위치에서 순환하는 경우
    Test("xyz", 4, "bcd");

    // 대문자·소문자·순환이 섞인 경우
    Test("AzZ", 2, "CbB");

    // 공백의 위치가 유지되는지 확인
    Test("Hello World", 1, "Ifmmp Xpsme");

    // 최대 이동 거리
    Test("AaZz", 25, "ZzYy");

    return 0;
}

/* Q045 시저 암호 https://school.programmers.co.kr/learn/courses/30/lessons/12926
문제 설명
어떤 문장의 각 알파벳을 일정한 거리만큼 밀어서 다른 알파벳으로 바꾸는 암호화 방식을
시저 암호라고 합니다. 예를 들어 "AB"는 1만큼 밀면 "BC"가 되고, 3만큼 밀면 "DE"가
됩니다. "z"는 1만큼 밀면 "a"가 됩니다. 문자열 s와 거리 n을 입력받아 s를 n만큼 민
암호문을 만드는 함수, solution을 완성해 보세요.

제한 조건
공백은 아무리 밀어도 공백입니다.
s는 알파벳 소문자, 대문자, 공백으로만 이루어져 있습니다.
s의 길이는 8000이하입니다.
n은 1 이상, 25이하인 자연수입니다.

입출력 예
s         n    result
"AB"      1    "BC"
"z"       1    "a"
"a B z"   4    "e F d"
*/
