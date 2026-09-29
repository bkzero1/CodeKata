#include <iostream>
//==========================================================================
//                         ⭐ AI 도움 받아서 해결 완료, 다시 풀어볼 것 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    const std::vector<std::string> allowedSounds = { "aya", "ye", "woo", "ma" };

    // 입력된 단어를 하나씩 검사
    for (const std::string& babblingWord : babbling)
    {
        std::string previousSound{};
        int currentPosition = 0;

        // 현재 위치부터 허용된 발음을 찾으며 단어 끝까지 해석
        while (currentPosition < babblingWord.size())
        {
            bool matchedDuringPass = false;  // 이번 후보 순회에서 발음을 하나 이상 처리했는지 기록
            for (const std::string& allowedSound : allowedSounds) // 갱신되는 현재 위치와 허용 발음을 차례대로 비교
            {
                if (babblingWord.compare(currentPosition, allowedSound.size(), allowedSound) == 0)
                {
                    // 직전 발음과 같으면 연속 발음이므로 후보 순회를 중단
                    if (previousSound == allowedSound)
                    {
                        break;
                    }

                    // 허용 발음을 찾았으므로 위치와 직전 발음을 갱신
                    matchedDuringPass = true;
                    currentPosition += allowedSound.size();
                    previousSound = allowedSound;
                }
                
                // 단어 끝까지 해석했으면 정답으로 세고 후보 순회를 중단
                if (currentPosition >= babblingWord.size())
                {
                    ++answer;
                    break;
                }
            }

            // 이번 순회에서 발음을 하나도 찾지 못했다면 현재 단어는 해석 불가
            if (!matchedDuringPass)
            {
                break;
            }
        }
    }

    return answer;
}

void PrintVector(const vector<string>& values)
{
    cout << '[';
    for (int i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << '"' << values[i] << '"';
    }
    cout << ']';
}

void Test(const string& name, const vector<string>& babbling, int expected)
{
    const int actual = solution(babbling);
    const bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: babbling = ";
    PrintVector(babbling);
    cout << " | expected: " << expected
        << " | actual: " << actual << '\n';
}

int main()
{
    Test("official example 1", { "aya", "yee", "u", "maa" }, 1);
    Test("official example 2", { "ayaye", "uuu", "yeye", "yemawoo", "ayaayaa" }, 2);
    Test("single allowed sound", { "aya" }, 1);
    Test("same sound repeated", { "ayaaya" }, 0);
    Test("invalid remaining sound", { "woowo" }, 0);
    Test("all sounds without repetition", { "ayawoomaye" }, 1);
    return 0;
}

/* Q062 옹알이 (2) https://school.programmers.co.kr/learn/courses/30/lessons/133499

문제 설명

머쓱이는 태어난 지 11개월 된 조카를 돌보고 있습니다. 조카는 아직 "aya", "ye", "woo", "ma" 네 가지 발음과 네 가지 발음을 조합해서 만들 수 있는 발음밖에 하지 못하고 연속해서 같은 발음을 하는 것을 어려워합니다. 문자열 배열 babbling이 매개변수로 주어질 때, 머쓱이의 조카가 발음할 수 있는 단어의 개수를 return하도록 solution 함수를 완성해주세요.

제한사항

- 1 ≤ babbling의 길이 ≤ 100
- 1 ≤ babbling[i]의 길이 ≤ 30
- 문자열은 알파벳 소문자로만 이루어져 있습니다.

입출력 예

babbling                                      result
["aya", "yee", "u", "maa"]                    1
["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"] 2

입출력 예 설명

입출력 예 #1

- ["aya", "yee", "u", "maa"]에서 발음할 수 있는 것은 "aya"뿐입니다. 따라서 1을 return합니다.

입출력 예 #2

- ["ayaye", "uuu", "yeye", "yemawoo", "ayaayaa"]에서 발음할 수 있는 것은 "aya" + "ye" = "ayaye", "ye" + "ma" + "woo" = "yemawoo"로 2개입니다. "yeye"는 같은 발음이 연속되므로 발음할 수 없습니다. 따라서 2를 return합니다.

유의사항

- 네 가지를 붙여 만들 수 있는 발음 이외에는 어떤 발음도 할 수 없는 것으로 규정합니다. 예를 들어 "woowo"는 "woo"는 발음할 수 있지만 "wo"를 발음할 수 없기 때문에 할 수 없는 발음입니다.

※ 공지 - 2024년 2월 20일 문제 지문의 오탈자가 수정되었습니다.

*/
