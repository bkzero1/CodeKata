#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> players, vector<string> callings) {
    for (const std::string& callingPlayer : callings)
    {
        auto it = std::find(players.begin(), players.end(), callingPlayer);
        // 문제 조건에서 1등은 불리지 않는다고 했으므로 항상 it - 1 접근 가능
        std::swap(*it, *(it - 1));
    }

    return players;
}

// 문자열 벡터를 입력값 그대로 표시
void PrintStringVector(const vector<string>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << '"' << values[i] << '"';
    }
    cout << ']';
}

// 입력과 기대값, 실제값을 한 줄에서 비교
void Test(const string& name, const vector<string>& players,
    const vector<string>& callings, const vector<string>& expected)
{
    const vector<string> actual = solution(players, callings);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: players = ";
    PrintStringVector(players);
    cout << ", callings = ";
    PrintStringVector(callings);
    cout << " | expected: ";
    PrintStringVector(expected);
    cout << " | actual: ";
    PrintStringVector(actual);
    cout << '\n';
}

int main()
{
    Test("official example 1", { "mumu", "soe", "poe", "kai", "mine" },
        { "kai", "kai", "mine", "mine" }, { "mumu", "kai", "mine", "soe", "poe" });
    Test("additional case 1", { "aaa", "bbb", "ccc", "ddd", "eee" },
        { "bbb", "ccc" }, { "bbb", "ccc", "aaa", "ddd", "eee" });
    Test("additional case 2", { "aaa", "bbb", "ccc", "ddd", "eee" },
        { "eee", "eee" }, { "aaa", "bbb", "eee", "ccc", "ddd" });
    Test("additional case 3", { "aaa", "bbb", "ccc", "ddd", "eee" },
        { "eee", "eee", "eee", "eee" }, { "eee", "aaa", "bbb", "ccc", "ddd" });
    Test("additional case 4", { "aaa", "bbb", "ccc", "ddd", "eee" },
        { "bbb", "aaa" }, { "aaa", "bbb", "ccc", "ddd", "eee" });
    Test("additional case 5", { "aaa", "bbb", "ccc", "ddd", "eee" },
        { "ccc", "ddd", "ccc" }, { "ccc", "aaa", "ddd", "bbb", "eee" });
    return 0;
}

/* Q072 달리기 경주 https://school.programmers.co.kr/learn/courses/30/lessons/178871

문제 설명

얀에서는 매년 달리기 경주가 열립니다. 해설진들은 선수들이 자기 바로 앞의 선수를 추월할 때 추월한 선수의 이름을 부릅니다. 예를 들어 1등부터 3등까지 "mumu", "soe", "poe" 선수들이 순서대로 달리고 있을 때, 해설진이 "soe"선수를 불렀다면 2등인 "soe" 선수가 1등인 "mumu" 선수를 추월했다는 것입니다. 즉 "soe" 선수가 1등, "mumu" 선수가 2등으로 바뀝니다.

선수들의 이름이 1등부터 현재 등수 순서대로 담긴 문자열 배열 players와 해설진이 부른 이름을 담은 문자열 배열 callings가 매개변수로 주어질 때, 경주가 끝났을 때 선수들의 이름을 1등부터 등수 순서대로 배열에 담아 return 하는 solution 함수를 완성해주세요.

제한사항

- 5 ≤ players의 길이 ≤ 50,000
- players[i]는 i번째 선수의 이름을 의미합니다.
- players의 원소들은 알파벳 소문자로만 이루어져 있습니다.
- players에는 중복된 값이 들어가 있지 않습니다.
- 3 ≤ players[i]의 길이 ≤ 10
- 2 ≤ callings의 길이 ≤ 1,000,000
- callings는 players의 원소들로만 이루어져 있습니다.
- 경주 진행중 1등인 선수의 이름은 불리지 않습니다.

입출력 예

players                                  callings                       result
["mumu", "soe", "poe", "kai", "mine"]    ["kai", "kai", "mine", "mine"]   ["mumu", "kai", "mine", "soe", "poe"]

입출력 예 설명

입출력 예 #1

4등인 "kai" 선수가 2번 추월하여 2등이 되고 앞서 3등, 2등인 "poe", "soe" 선수는 4등, 3등이 됩니다. 5등인 "mine" 선수가 2번 추월하여 4등, 3등인 "poe", "soe" 선수가 5등, 4등이 되고 경주가 끝납니다. 1등부터 배열에 담으면 ["mumu", "kai", "mine", "soe", "poe"]이 됩니다.

*/
