#include <iostream>
//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>

using namespace std;

// 이용자의 ID가 담긴 문자열 배열 id_list, 
// 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report
// 정지 기준이 되는 신고 횟수 k
vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    // id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수
    vector<int> answer;

    // 키 - 신고받은 사람 / 값 - 신고한 사람 / 값의 원소갯수가 k보다 크면 answer + 1
    std::unordered_map<std::string, std::unordered_set<std::string>> reportersByReportedUser;

    for (const std::string& reportEntry : report)
    {
        const auto spacePosition = reportEntry.find(' ');

        // 공백 앞: 신고한 사람
        const std::string reporter = reportEntry.substr(0, spacePosition);

        // 공백 뒤부터 끝까지: 신고당한 사람
        const std::string reportedUser = reportEntry.substr(spacePosition + 1);

        reportersByReportedUser[reportedUser].insert(reporter);
    }

    //for (const auto& reporter : reportersByReportedUser)
    //{
    //    cout << reporter.first << ": ";
    //    for (const auto& str : reporter.second)
    //    {
    //        cout << str << " ";
    //    }
    //    cout << endl;
    //    cout << "reporter.second.size(): " << reporter.second.size() << endl;
    //}
    
    for (const std::string& reporter : id_list)
    {
        int reportedCount = reportersByReportedUser[reporter].size();
        if (reportedCount >= k)
        {
            answer.push_back(reportedCount);
        }
    }
  

    return answer;
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

// 정수 벡터의 기대값과 실제값 표시
void PrintVector(const vector<int>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << values[i];
    }
    cout << ']';
}

// 입력과 기대값, 실제값을 한 줄에서 비교
void Test(const string& name, const vector<string>& id_list,
    const vector<string>& report, int k, const vector<int>& expected)
{
    const vector<int> actual = solution(id_list, report, k);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: id_list = ";
    PrintStringVector(id_list);
    cout << ", report = ";
    PrintStringVector(report);
    cout << ", k = " << k << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

int main()
{
    Test("official example 1", { "muzi", "frodo", "apeach", "neo" },
        { "muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi" },
        2, { 2, 1, 1, 0 });
    Test("official example 2", { "con", "ryan" },
        { "ryan con", "ryan con", "ryan con", "ryan con" }, 3, { 0, 0 });
    Test("additional case 1", { "a", "b" }, { "a b" }, 1, { 1, 0 });
    Test("additional case 2", { "a", "b", "c" },
        { "a c", "a c", "b c" }, 2, { 1, 1, 0 });
    Test("additional case 3", { "a", "b", "c" },
        { "a b", "b c", "c a" }, 1, { 1, 1, 1 });
    Test("additional case 4", { "c", "a", "b" },
        { "a b", "c b", "b a" }, 2, { 1, 1, 0 });
    Test("additional case 5", { "a", "b", "c" },
        { "a b", "a c", "b c", "c b" }, 2, { 2, 1, 1 });
    return 0;
}

/* Q074 신고 결과 받기 https://school.programmers.co.kr/learn/courses/30/lessons/92334

문제 설명

신입사원 무지는 게시판 불량 이용자를 신고하고 처리 결과를 메일로 발송하는 시스템을 개발하려 합니다. 무지가 개발하려는 시스템은 다음과 같습니다.

- 각 유저는 한 번에 한 명의 유저를 신고할 수 있습니다.
  - 신고 횟수에 제한은 없습니다. 서로 다른 유저를 계속해서 신고할 수 있습니다.
  - 한 유저를 여러 번 신고할 수도 있지만, 동일한 유저에 대한 신고 횟수는 1회로 처리됩니다.
- k번 이상 신고된 유저는 게시판 이용이 정지되며, 해당 유저를 신고한 모든 유저에게 정지 사실을 메일로 발송합니다.
  - 유저가 신고한 모든 내용을 취합하여 마지막에 한꺼번에 게시판 이용 정지를 시키면서 정지 메일을 발송합니다.

다음은 전체 유저 목록이 ["muzi", "frodo", "apeach", "neo"]이고, k = 2(즉, 2번 이상 신고당하면 이용 정지)인 경우의 예시입니다.

유저 ID     유저가 신고한 ID    설명
"muzi"      "frodo"            "muzi"가 "frodo"를 신고했습니다.
"apeach"    "frodo"            "apeach"가 "frodo"를 신고했습니다.
"frodo"     "neo"              "frodo"가 "neo"를 신고했습니다.
"muzi"      "neo"              "muzi"가 "neo"를 신고했습니다.
"apeach"    "muzi"             "apeach"가 "muzi"를 신고했습니다.

각 유저별로 신고당한 횟수는 다음과 같습니다.

유저 ID     신고당한 횟수
"muzi"      1
"frodo"     2
"apeach"    0
"neo"       2

위 예시에서는 2번 이상 신고당한 "frodo"와 "neo"의 게시판 이용이 정지됩니다. 이때, 각 유저별로 신고한 아이디와 정지된 아이디를 정리하면 다음과 같습니다.

유저 ID     유저가 신고한 ID       정지된 ID
"muzi"      ["frodo", "neo"]       ["frodo", "neo"]
"frodo"     ["neo"]                ["neo"]
"apeach"    ["muzi", "frodo"]      ["frodo"]
"neo"       없음                   없음

따라서 "muzi"는 처리 결과 메일을 2회, "frodo"와 "apeach"는 각각 처리 결과 메일을 1회 받게 됩니다.

이용자의 ID가 담긴 문자열 배열 id_list, 각 이용자가 신고한 이용자의 ID 정보가 담긴 문자열 배열 report, 정지 기준이 되는 신고 횟수 k가 매개변수로 주어질 때, 각 유저별로 처리 결과 메일을 받은 횟수를 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

- 2 ≤ id_list의 길이 ≤ 1,000
- 1 ≤ id_list의 원소 길이 ≤ 10
- id_list의 원소는 이용자의 id를 나타내는 문자열이며 알파벳 소문자로만 이루어져 있습니다.
- id_list에는 같은 아이디가 중복해서 들어있지 않습니다.
- 1 ≤ report의 길이 ≤ 200,000
- 3 ≤ report의 원소 길이 ≤ 21
- report의 원소는 "이용자id 신고한id"형태의 문자열입니다.
- 예를 들어 "muzi frodo"의 경우 "muzi"가 "frodo"를 신고했다는 의미입니다.
- id는 알파벳 소문자로만 이루어져 있습니다.
- 이용자id와 신고한id는 공백(스페이스)하나로 구분되어 있습니다.
- 자기 자신을 신고하는 경우는 없습니다.
- 1 ≤ k ≤ 200, k는 자연수입니다.
- return 하는 배열은 id_list에 담긴 id 순서대로 각 유저가 받은 결과 메일 수를 담으면 됩니다.

입출력 예

id_list                             report                                                                k    result
["muzi", "frodo", "apeach", "neo"]   ["muzi frodo", "apeach frodo", "frodo neo", "muzi neo", "apeach muzi"]   2    [2, 1, 1, 0]
["con", "ryan"]                     ["ryan con", "ryan con", "ryan con", "ryan con"]                         3    [0, 0]

입출력 예 설명

입출력 예 #1
문제의 예시와 같습니다.

입출력 예 #2
"ryan"이 "con"을 4번 신고했으나, 주어진 조건에 따라 한 유저가 같은 유저를 여러 번 신고한 경우는 신고 횟수 1회로 처리합니다. 따라서 "con"은 1회 신고당했습니다. 3번 이상 신고당한 이용자는 없으며, "con"과 "ryan"은 결과 메일을 받지 않습니다. 따라서 [0, 0]을 return 합니다.

제한시간 안내

- 정확성 테스트 : 10초

*/