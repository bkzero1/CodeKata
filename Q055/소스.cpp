#include <iostream>
//==========================================================================
//                            ⭐ 해결 완?료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    auto itr1 = cards1.begin();
    auto itr1End = cards1.end();

    auto itr2 = cards2.begin();
    auto itr2End = cards2.end();

    bool isFinish = std::all_of(goal.begin(), goal.end(), 
        [&itr1, &itr2, itr1End, itr2End](const string& str) {
            if ((itr1 != itr1End) && *itr1 == str)
            {
                ++itr1;
                return true;
            }
            else if ((itr2 != itr2End) && *itr2 == str)
            {
                ++itr2;
                return true;
            }
            else
            {
                return false;
            }
        }
    );

    if (isFinish)
    {
        return "Yes";
    }
    else
    {
        return "No";
    }
}

//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] 문자열 벡터의 원소를 출력하는 보조 함수
void PrintVector(const vector<string>& values)
{
    cout << "[";
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i != 0) cout << ", ";
        cout << '"' << values[i] << '"';
    }
    cout << "]";
}

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, const vector<string>& cards1,
          const vector<string>& cards2, const vector<string>& goal,
          const string& expected)
{
    const string actual = solution(cards1, cards2, goal);
    const bool success = actual == expected;

    cout << "\x1b[38;2;"
         << (success ? "120;230;102" : "230;102;102")
         << "m"
         << (success ? " SUCCESS" : "  FAIL  ")
         << "\x1b[0m"
         << " | " << testName << " | input: cards1=";
    PrintVector(cards1);
    cout << ", cards2=";
    PrintVector(cards2);
    cout << ", goal=";
    PrintVector(goal);
    cout << " | expected: \"" << expected << "\""
         << " | actual: \"" << actual << "\"\n";
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
    // 공식 입출력 예
    Test("official example 1",
         { "i", "drink", "water" }, { "want", "to" },
         { "i", "want", "to", "drink", "water" }, "Yes");
    Test("official example 2",
         { "i", "water", "drink" }, { "want", "to" },
         { "i", "want", "to", "drink", "water" }, "No");

    // Codex가 추가한 경계 테스트
    Test("use one word from each pile",
         { "a" }, { "b" }, { "a", "b" }, "Yes");
    Test("start from second pile",
         { "a" }, { "b" }, { "b", "a" }, "Yes");
    Test("cannot skip the first card",
         { "a", "x" }, { "b" }, { "x", "b" }, "No");
    Test("alternate between piles",
         { "alpha", "beta" }, { "one", "two" },
         { "one", "alpha", "two", "beta" }, "Yes");
    return 0;
}

/* Q055 카드 뭉치 https://school.programmers.co.kr/learn/courses/30/lessons/159994

문제 설명

코니는 영어 단어가 적힌 카드 뭉치 두 개를 선물로 받았습니다. 코니는 다음과 같은 규칙으로 카드에 적힌 단어들을 사용해 원하는 순서의 단어 배열을 만들 수 있는지 알고 싶습니다.

- 원하는 카드 뭉치에서 카드를 순서대로 한 장씩 사용합니다.
- 한 번 사용한 카드는 다시 사용할 수 없습니다.
- 카드를 사용하지 않고 다음 카드로 넘어갈 수 없습니다.
- 기존에 주어진 카드 뭉치의 단어 순서는 바꿀 수 없습니다.

예를 들어 첫 번째 카드 뭉치에 순서대로 ["i", "drink", "water"], 두 번째 카드 뭉치에 순서대로 ["want", "to"]가 적혀있을 때 ["i", "want", "to", "drink", "water"] 순서의 단어 배열을 만들려고 한다면 첫 번째 카드 뭉치에서 "i"를 사용한 후 두 번째 카드 뭉치에서 "want"와 "to"를 사용하고 첫 번째 카드뭉치에 "drink"와 "water"를 차례대로 사용하면 원하는 순서의 단어 배열을 만들 수 있습니다.

문자열로 이루어진 배열 cards1, cards2와 원하는 단어 배열 goal이 매개변수로 주어질 때, cards1과 cards2에 적힌 단어들로 goal을 만들 수 있다면 "Yes"를, 만들 수 없다면 "No"를 return하는 solution 함수를 완성해주세요.

제한사항

- 1 ≤ cards1의 길이, cards2의 길이 ≤ 10
- 1 ≤ cards1[i]의 길이, cards2[i]의 길이 ≤ 10
- cards1과 cards2에는 서로 다른 단어만 존재합니다.
- 2 ≤ goal의 길이 ≤ cards1의 길이 + cards2의 길이
- 1 ≤ goal[i]의 길이 ≤ 10
- goal의 원소는 cards1과 cards2의 원소들로만 이루어져 있습니다.
- cards1, cards2, goal의 문자열들은 모두 알파벳 소문자로만 이루어져 있습니다.

입출력 예

cards1                      cards2          goal                                  result
["i", "drink", "water"]      ["want", "to"]  ["i", "want", "to", "drink", "water"] "Yes"
["i", "water", "drink"]      ["want", "to"]  ["i", "want", "to", "drink", "water"] "No"

입출력 예 설명

입출력 예 #1

본문과 같습니다.

입출력 예 #2

cards1에서 "i"를 사용하고 cards2에서 "want"와 "to"를 사용하여 "i want to"까지는 만들 수 있지만 "water"가 "drink"보다 먼저 사용되어야 하기 때문에 해당 문장을 완성시킬 수 없습니다. 따라서 "No"를 반환합니다.

*/
