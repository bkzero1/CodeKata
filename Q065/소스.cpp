#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

struct CharacterCounts
{
    int xCount = 0;
    int otherCount = 0;

    char xCharacter;
};

int solution(string s) {
    int answer = 0;

    // 종료조건 
    // 1. x와 other의 숫자가 같아졌을 때 answer++
    // 2. 같아지기 전이라도 문자열의 끝에 도달했을 때 answer++
    for (int i = 0; i < s.size(); ++i)
    {
        CharacterCounts counts;
        counts.xCharacter = s[i];
        counts.xCount = 1;

        std::string currentPart(1, counts.xCharacter);  // 현재 묶음 확인용
        
        while (true)
        {
            ++i;
            if (i >= s.size())
            {
                ++answer;
                break;
            }

            currentPart += s[i];

            // x 다음 첫문자 읽어서 같으면 x카운팅 증가, 아니면 다른 카운팅 증가
            if (s[i] != counts.xCharacter)
            {
                ++counts.otherCount;
            }
            else
            {
                ++counts.xCount;
            }

            if (counts.xCount == counts.otherCount)
            {
                ++answer;
                break;
            }
        }
    }

    return answer;
}

void Test(const string& name, const string& s, int expected)
{
    const int actual = solution(s); 
    const bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name
        << " | input: s = \"" << s << "\""
        << " | expected: " << expected
        << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 예제
    Test("official example 1", "banana", 3);
    Test("official example 2", "abracadabra", 6);
    Test("official example 3", "aaabbaccccabba", 3);

    // 추가 경계 테스트
    Test("single character", "a", 1);
    Test("all same characters", "aaaa", 1);
    Test("balanced at the end", "aabb", 1);
    Test("remaining characters form the last part", "abcc", 2);

    return 0;
}

/* Q065 문자열 나누기 https://school.programmers.co.kr/learn/courses/30/lessons/140108

문제 설명

문자열 s가 입력되었을 때 다음 규칙을 따라서 이 문자열을 여러 문자열로 분해하려고 합니다.

- 먼저 첫 글자를 읽습니다. 이 글자를 x라고 합시다.
- 이제 이 문자열을 왼쪽에서 오른쪽으로 읽어나가면서, x와 x가 아닌 다른 글자들이 나온 횟수를 각각 셉니다. 처음으로 두 횟수가 같아지는 순간 멈추고, 지금까지 읽은 문자열을 분리합니다.
- s에서 분리한 문자열을 빼고 남은 부분에 대해서 이 과정을 반복합니다. 남은 부분이 없다면 종료합니다.
- 만약 두 횟수가 다른 상태에서 더 이상 읽을 글자가 없다면, 역시 지금까지 읽은 문자열을 분리하고, 종료합니다.

문자열 s가 매개변수로 주어질 때, 위 과정과 같이 문자열들로 분해하고, 분해한 문자열의 개수를 return 하는 함수 solution을 완성하세요.

제한사항

- 1 <= s의 길이 <= 10,000
- s는 영어 소문자로만 이루어져 있습니다.

입출력 예

s                  result
"banana"           3
"abracadabra"      6
"aaabbaccccabba"   3

입출력 예 설명

입출력 예 #1

- s="banana"인 경우 ba - na - na와 같이 분해됩니다.

입출력 예 #2

- s="abracadabra"인 경우 ab - ra - ca - da - br - a와 같이 분해됩니다.

입출력 예 #3

- s="aaabbaccccabba"인 경우 aaabbacc - ccab - ba와 같이 분해됩니다.

*/
