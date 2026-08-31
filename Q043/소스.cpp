#include <iostream>
#include <string>

using namespace std;

int solution(string t, string p)
{
    int answer = 0;
    long long numP = stoll(p);  // p를 숫자로 변환 / 최대 18자리이므로 int 범위를 넘어 long long 사용

    for (int i = 0; i + p.size() <= t.size(); ++i)  // i부터 p 길이만큼 잘랐을 때 t의 범위를 벗어나지 않는 동안 반복
    {
        long long currentRefNum = stoll(t.substr(i, p.size())); // t에서 i부터 p 길이만큼 잘라낸 부분 문자열을 숫자로 변환
        
        if (numP >= currentRefNum)
        {
            ++answer;
        }
    }

    return answer;
}

void Test(const string& t, const string& p, int expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    int result = solution(t, p);
    bool success = (result == expected);

    cout << "t: \"" << t << "\""
        << " | p: \"" << p << "\""
        << " | Expected: " << expected
        << " | Result: " << result
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test("3141592", "271", 2);      // 문제 예제
    Test("500220839878", "7", 8);   // 문제 예제
    Test("10203", "15", 3);         // 문제 예제

    Test("1", "1", 1);              // 최소 길이
    Test("10", "10", 1);            // t와 p의 길이가 같음
    Test("999", "9", 3);            // 모든 부분문자열이 조건을 만족함
    Test("1000", "100", 2);         // 부분문자열이 0으로 시작할 수 있음
    Test("123456", "18", 1);        // 첫 부분문자열만 조건을 만족함

    return 0;
}

/* Q043 크기가 작은 부분문자열 https://school.programmers.co.kr/learn/courses/30/lessons/147355

문제 설명
숫자로 이루어진 문자열 t와 p가 주어질 때, t에서 p와 길이가 같은 부분문자열 중에서,
이 부분문자열이 나타내는 수가 p가 나타내는 수보다 작거나 같은 것이 나오는 횟수를
return하는 함수 solution을 완성하세요.

예를 들어, t="3141592"이고 p="271"인 경우, t의 길이가 3인 부분문자열은
314, 141, 415, 159, 592입니다. 이 문자열이 나타내는 수 중 271보다 작거나 같은 수는
141, 159로 2개입니다.

제한사항
1 <= p의 길이 <= 18
p의 길이 <= t의 길이 <= 10,000
t와 p는 숫자로만 이루어진 문자열이며, 0으로 시작하지 않습니다.

입출력 예
t               p       result
"3141592"       "271"   2
"500220839878"  "7"     8
"10203"         "15"    3

입출력 예 설명
입출력 예 #1
본문과 같습니다.

입출력 예 #2
p의 길이가 1이므로 t의 부분문자열을 한 글자씩 확인합니다.
이 중 7보다 작거나 같은 숫자는 8개입니다.

입출력 예 #3
p의 길이가 2이므로 t의 부분문자열은 "10", "02", "20", "03"입니다.
이 중 15보다 작거나 같은 것은 "10", "02", "03"으로 3개입니다.
"02"와 "03"은 각각 2와 3에 해당한다는 점에 주의하세요.
*/
