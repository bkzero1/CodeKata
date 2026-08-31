#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool isDigit(char ch)
{
    if (ch > '9' || ch < '0')
    {
        return false;
    }

    return true;
}
bool solution(string s) {
    bool answer = true;
    // 4나 6이 아니면 조기종료 -> 4가 아니고, 동시에 6도 아니면 조기 종료
    if (s.size() != 4 && s.size() != 6)
        return answer = false;
    // all_of
    return answer = std::all_of(s.cbegin(), s.cend(), isDigit);

    //// find if 사용
    //if (std::find_if_not(s.begin(), s.end(), isDigit) != s.end())
    //{
    //    return answer = false;
    //}

    // 직접 구현
    //for (char ch : s)
    //{
    //    // 제한사항에서 숫자 or 알파벳이므로 '0'보다 작은 조건은 사실 이 문제에서는 없어도 됨
    //    if (ch > '9' || ch < '0')
    //    {
    //        return answer = false;
    //    }
    //}
    //return answer;
}

void Test(string s, bool expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m";   // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";      // Red
    const char* RESET_COLOR = "\033[0m";

    bool result = solution(s);
    bool success = (result == expected);

    cout << "s: \"" << s << "\""
        << " | Expected: " << boolalpha << expected
        << " | Result: " << result
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test("a234", false);    // 문제 예제
    Test("1234", true);     // 문제 예제
    Test("123456", true);   // 숫자 6자리
    Test("12345", false);   // 숫자지만 길이가 5
    Test("12A456", false);  // 길이 6이지만 문자 포함

    return 0;
}

/* Q36 문자열 다루기 기본

문제 설명
문자열 s의 길이가 4 혹은 6이고, 숫자로만 구성돼있는지 확인해주는 함수, solution을 완성하세요. 예를 들어 s가 "a234"이면 False를 리턴하고 "1234"라면 True를 리턴하면 됩니다.

제한 사항
s는 길이 1 이상, 길이 8 이하인 문자열입니다.
s는 영문 알파벳 대소문자 또는 0부터 9까지 숫자로 이루어져 있습니다.
입출력 예
s	return
"a234"	false
"1234"	true
문제가 잘 안풀린다면😢
힌트가 필요한가요? [코딩테스트 연습 힌트 모음집]으로 오세요! → 클릭

공지 - 2022년 7월 22일 테스트케이스가 추가되었습니다.
공지 - 2022년 7월 22일 제한 사항이 추가되었습니다.

*/