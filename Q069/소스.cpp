#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> survey, vector<int> choices) {
    string answer = "";
    const int neutralChoiceValue = 4;  // 선택값에서 빼서 -3 ~ 3으로 변환
    const int reverseMultiplier = -1;  // 유형 순서가 반대면 점수 방향을 뒤집음

    // TODO: "RTCFJMAN" 한 문자열의 문자 위치로 지표와 점수 방향을 찾는 풀이 완성해보기
    //const std::string personalityString = {"RT" "CF" "JM" "AN"};
    const std::string personalityString = "RT" "CF" "JM" "AN";
    
    // 각 지표의 앞 유형과 뒤 유형 사이의 점수 차이 / 사전순 RT, CF, JM, AN
    std::vector<int> indicatorScores(4, 0);


    // 점수 계산
    //for (int i = 0; i < survey.size(); ++i)
    //{
    //    int adjustedChoice = choices[i] - neutralChoiceValue; // -3 ~ 3 범위로 변경

    //    for (int indicatorIndex = 0; indicatorIndex < indicatorScores.size(); ++indicatorIndex)
    //    {
    //        const auto positionInPair = personalityPairs[indicatorIndex].find(survey[i].front());
    //        if (positionInPair == std::string::npos)
    //        {
    //            continue;
    //        }

    //        if (positionInPair == 1)
    //        {
    //            adjustedChoice *= reverseMultiplier;
    //        }

    //        indicatorScores[indicatorIndex] += adjustedChoice;
    //        break;
    //    }
    //}

    //// 점수 차이에 따라 각 지표의 최종 유형 결정
    //for (int i = 0; i < indicatorScores.size(); i + 2)
    //{
    //    if (indicatorScores[i] <= 0)
    //    {
    //        answer += personalityPairs[i].front();
    //    }
    //    else
    //    {
    //        answer += personalityPairs[i].back();
    //    }
    //}

    return answer;
}

// 문자열 벡터를 입력값 그대로 표시합니다.
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

// 정수 벡터를 입력값 그대로 표시합니다.
void PrintIntVector(const vector<int>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << values[i];
    }
    cout << ']';
}

// 입력과 기대값, 실제값을 한 줄에서 비교합니다.
void Test(const string& name, const vector<string>& survey,
    const vector<int>& choices, const string& expected)
{
    const string actual = solution(survey, choices);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: survey = ";
    PrintStringVector(survey);
    cout << ", choices = ";
    PrintIntVector(choices);
    cout << " | expected: " << '"' << expected << '"'
        << " | actual: " << '"' << actual << '"' << '\n';
}

int main()
{
    // 공식 예제
    Test("official example 1", { "AN", "CF", "MJ", "RT", "NA" }, { 5, 3, 2, 7, 5 }, "TCMA");
    Test("official example 2", { "TR", "RT", "TR" }, { 7, 1, 3 }, "RCJA");

    // 추가 검증 사례
    Test("all neutral", { "RT" }, { 4 }, "RCJA");
    Test("all disagreement", { "RT", "CF", "JM", "AN" }, { 1, 1, 1, 1 }, "RCJA");
    Test("all agreement", { "RT", "CF", "JM", "AN" }, { 7, 7, 7, 7 }, "TFMN");
    Test("reversed survey order", { "TR" }, { 1 }, "TCJA");
    Test("score tie", { "RT", "RT" }, { 1, 7 }, "RCJA");
    return 0;
}

/* Q069 성격 유형 검사하기 https://school.programmers.co.kr/learn/courses/30/lessons/118666

문제 설명

나만의 카카오 성격 유형 검사지를 만들려고 합니다.
성격 유형 검사는 다음과 같은 4개 지표로 성격 유형을 구분합니다. 성격은 각 지표에서 두 유형 중 하나로 결정됩니다.

지표 번호   성격 유형
1번 지표    라이언형(R), 튜브형(T)
2번 지표    콘형(C), 프로도형(F)
3번 지표    제이지형(J), 무지형(M)
4번 지표    어피치형(A), 네오형(N)

4개의 지표가 있으므로 성격 유형은 총 16(=2 x 2 x 2 x 2)가지가 나올 수 있습니다. 예를 들어, "RFMN"이나 "TCMA"와 같은 성격 유형이 있습니다.

검사지에는 총 n개의 질문이 있고, 각 질문에는 아래와 같은 7개의 선택지가 있습니다.
- 매우 비동의
- 비동의
- 약간 비동의
- 모르겠음
- 약간 동의
- 동의
- 매우 동의

각 질문은 1가지 지표로 성격 유형 점수를 판단합니다.
매우 동의나 매우 비동의 선택지를 선택하면 3점을 얻습니다.
동의나 비동의 선택지를 선택하면 2점을 얻습니다.
약간 동의나 약간 비동의 선택지를 선택하면 1점을 얻습니다.
모르겠음 선택지를 선택하면 점수를 얻지 않습니다.

검사 결과는 모든 질문의 성격 유형 점수를 더하여 각 지표에서 더 높은 점수를 받은 성격 유형이라고 판단합니다.
단, 하나의 지표에서 각 성격 유형 점수가 같으면 두 성격 유형 중 사전 순으로 빠른 성격 유형을 선택합니다.

질문마다 판단하는 지표를 담은 1차원 문자열 배열 survey와 검사자가 각 질문마다 선택한 선택지를 담은 1차원 정수 배열 choices가 매개변수로 주어집니다.
검사자의 성격 유형 검사 결과를 지표 번호 순서대로 return 하도록 solution 함수를 완성해주세요.

제한사항

- 1 ≤ survey의 길이 (= n) ≤ 1,000
- survey의 원소는 "RT", "TR", "FC", "CF", "MJ", "JM", "AN", "NA" 중 하나입니다.
- survey[i]의 첫 번째 캐릭터는 i+1번 질문의 비동의 관련 선택지를 선택하면 받는 성격 유형입니다.
- survey[i]의 두 번째 캐릭터는 i+1번 질문의 동의 관련 선택지를 선택하면 받는 성격 유형입니다.
- choices의 길이 = survey의 길이
- choices[i]는 검사자가 선택한 i+1번째 질문의 선택지입니다.
- 1 ≤ choices의 원소 ≤ 7

choices   뜻
1         매우 비동의
2         비동의
3         약간 비동의
4         모르겠음
5         약간 동의
6         동의
7         매우 동의

입출력 예

survey                          choices          result
["AN", "CF", "MJ", "RT", "NA"] [5, 3, 2, 7, 5] "TCMA"
["TR", "RT", "TR"]               [7, 1, 3]       "RCJA"

입출력 예 설명

입출력 예 #1
- 각 질문의 점수를 합산하면 T, C, M의 점수가 더 높습니다.
- A와 N은 1점으로 같으므로 사전 순으로 빠른 A를 선택하여 "TCMA"를 반환합니다.

입출력 예 #2
- R의 점수가 T보다 높습니다.
- 나머지 지표는 모두 동점이므로 사전 순으로 빠른 C, J, A를 선택하여 "RCJA"를 반환합니다.

*/
