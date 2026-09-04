#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <utility>

using namespace std;

// 모든 숫자 영단어는 앞의 두 글자만으로 구별할 수 있음
// pair는 구조체를 만들어서도 해결가능. 구조적 바인딩(c++17 이상)을 사용하지 않고도 first, second에 의미 부여 가능
//                                     ex) auto [digit, skipCount] = getDigitInfoFromPrefix(s, i);
std::pair<int, int> getDigitInfoFromPrefix(const std::string& s, int index) 
{
    //static const로 한번만 메모리에 생성
    static const std::map<std::string, std::pair<int, int>> numberInfoByPrefix = {
        {"ze", {0, 4 - 1}}, // 0
        {"on", {1, 3 - 1}}, // 1
        {"tw", {2, 3 - 1}}, // 2
        {"th", {3, 5 - 1}}, // 3
        {"fo", {4, 4 - 1}}, // 4
        {"fi", {5, 4 - 1}}, // 5
        {"si", {6, 3 - 1}}, // 6
        {"se", {7, 5 - 1}}, // 7
        {"ei", {8, 5 - 1}}, // 8
        {"ni", {9, 4 - 1}}  // 9
    };

    std::string prefix = s.substr(index, 2);

    return numberInfoByPrefix.at(prefix);
}

int solution(string s) {
    int answer = 0;

    //std::string text = "11zero";
    //std::cout << getDigitInfoFromPrefix(text , 2).second << " \n";

    for (int i = 0; i < s.size(); ++i)
    {
        // 숫자 한 자리를 추가할 공간을 만듦
        answer *= 10;

        if (std::isdigit(s[i]))
        {
            answer += s[i] - '0';
        }
        else
        {
            std::pair<int, int> numberInfo = getDigitInfoFromPrefix(s, i);
            answer += numberInfo.first;
            i += numberInfo.second;
        }
    }

    return answer;
}

void Test(const string& s, int expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m";
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";
    const char* RESET_COLOR = "\033[0m";

    int result = solution(s);
    bool success = (result == expected);

    cout << "s: \"" << s << "\""
        << " | Expected: " << expected
        << " | Result: " << result
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    // 공식 예제
    Test("one4seveneight", 1478);
    Test("23four5six7", 234567);
    Test("2three45sixseven", 234567);
    Test("123", 123);

    // 추가 경계 테스트
    Test("one", 1);                 // 영단어 하나만 있는 경우
    Test("onezero", 10);            // 결과 중간에 0이 포함되는 경우
    Test("9nineeight", 998);        // 숫자와 연속된 영단어가 섞인 경우

    return 0;
}

/* Q046 숫자 문자열과 영단어 https://school.programmers.co.kr/learn/courses/30/lessons/81301

문제 설명
네오와 프로도가 숫자놀이를 하고 있습니다. 네오가 프로도에게 숫자를 건넬 때 일부 자릿수를
영단어로 바꾼 카드를 건네주면 프로도는 원래 숫자를 찾는 게임입니다.

다음은 숫자의 일부 자릿수를 영단어로 바꾸는 예시입니다.
- 1478 -> "one4seveneight"
- 234567 -> "23four5six7"
- 10203 -> "1zerotwozero3"

숫자의 일부 자릿수가 영단어로 바뀌어졌거나, 혹은 바뀌지 않고 그대로인 문자열 s가
매개변수로 주어집니다. s가 의미하는 원래 숫자를 return 하도록 solution 함수를 완성해주세요.

숫자와 영단어
0 zero
1 one
2 two
3 three
4 four
5 five
6 six
7 seven
8 eight
9 nine

제한사항
- 1 <= s의 길이 <= 50
- s가 "zero" 또는 "0"으로 시작하는 경우는 주어지지 않습니다.
- return 값이 1 이상 2,000,000,000 이하의 정수가 되는 올바른 입력만 s로 주어집니다.

입출력 예
s                       result
"one4seveneight"        1478
"23four5six7"           234567
"2three45sixseven"      234567
"123"                   123
*/
