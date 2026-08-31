#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    //string answer;    // s가 이미 복사본이므로 s를 그대로 사용하여도 무방
    int index = 0;

    for (char& ch : s)  // ch가 레퍼런스가 아니라면 복사본이 되므로 수정사항 반영이 안됨
    {
        if (ch == ' ')
        {
            index = 0;
            continue;
        }
        //else
        //{
         
        //여기까지 왔다는것은 이미 공백이 아닌 상태이므로 else 필요 없음
        if (index % 2 == 0)
        {
            ch = std::toupper(ch);
        }
        else
        {
            // 입력이 모두 소문자라고 보장된다면 생략 가능
            ch = std::tolower(ch);  
        }
        ++index;
        //}
    }

    return s;
}

void Test(string s, string expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    string result = solution(s);
    bool success = (result == expected);

    cout << "s: \"" << s << "\""
        << " | Expected: \"" << expected << "\""
        << " | Result: \"" << result << "\""
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test("try hello world", "TrY HeLlO WoRlD"); // 문제 예제

    Test("a", "A");                             // 한 글자
    Test("ab", "Ab");                           // 짝수 길이 단어
    Test("abc", "AbC");                         // 홀수 길이 단어
    Test("hello", "HeLlO");                     // 단일 단어

    Test("a b c", "A B C");                     // 한 글자 단어 여러 개
    Test("ab cd ef", "Ab Cd Ef");               // 공백마다 인덱스 초기화 확인

    Test("  try", "  TrY");                     // 앞쪽 연속 공백
    Test("try  hello", "TrY  HeLlO");           // 단어 사이 연속 공백
    Test("try ", "TrY ");                       // 마지막 공백
    Test("tRY hELLo", "TrY HeLlO");
    return 0;
}

/* Q41 이상한 문자 만들기

문제 설명
문자열 s는 한 개 이상의 단어로 구성되어 있습니다. 각 단어는 하나 이상의 공백문자로 구분되어 있습니다.
각 단어의 짝수번째 알파벳은 대문자로, 홀수번째 알파벳은 소문자로 바꾼 문자열을 리턴하는 함수, solution을 완성하세요.

제한 사항
문자열 전체의 짝/홀수 인덱스가 아니라, 단어(공백을 기준)별로 짝/홀수 인덱스를 판단해야합니다.
첫 번째 글자는 0번째 인덱스로 보아 짝수번째 알파벳으로 처리해야 합니다.

입출력 예
s                    return
"try hello world"    "TrY HeLlO WoRlD"

입출력 예 설명
"try hello world"는 세 단어 "try", "hello", "world"로 구성되어 있습니다.
각 단어의 짝수번째 문자를 대문자로, 홀수번째 문자를 소문자로 바꾸면 "TrY", "HeLlO", "WoRlD"입니다.
따라서 "TrY HeLlO WoRlD" 를 리턴합니다.

*/