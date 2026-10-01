#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n;
    constexpr int usedReserveMarker = -1;

    // 도난 학생을 번호순으로 처리해 체육복 대여 순서를 일정하게 유지
    std::sort(lost.begin(), lost.end());

    // 도난과 여벌 명단에 모두 있는 학생은 자신의 여벌을 사용한 것으로 처리
    for (int& lostStudent : lost)
    {
        const auto reserveItr = std::find(reserve.begin(), reserve.end(), lostStudent);

        if (reserveItr != reserve.end())
        {
            *reserveItr = usedReserveMarker;
            lostStudent = usedReserveMarker;
            continue;
        }
    }

    // 처리되지 않은 도난 학생에게 왼쪽 학생부터 여벌 체육복을 빌림
    for (int lostStudent : lost)
    {
        if (lostStudent == usedReserveMarker)
        {
            continue;
        }

        const auto reserveLeftItr = std::find(reserve.begin(), reserve.end(), lostStudent - 1);
        const auto reserveRightItr = std::find(reserve.begin(), reserve.end(), lostStudent + 1);

        if (reserveLeftItr != reserve.end())
        {
            *reserveLeftItr = usedReserveMarker;
        }
        else if (reserveRightItr != reserve.end())
        {
            *reserveRightItr = usedReserveMarker;
        }
        else
        {
            --answer;
        }
    }
    
    return answer;
}
void PrintVector(const vector<int>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }
        cout << values[i];
    }
    cout << ']';
}

void Test(const string& name, int n, const vector<int>& lost, const vector<int>& reserve, int expected)
{
    const int actual = solution(n, lost, reserve);
    const bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name
        << " | input: n = " << n << ", lost = ";
    PrintVector(lost);
    cout << ", reserve = ";
    PrintVector(reserve);
    cout << " | expected: " << expected
        << " | actual: " << actual << '\n';
}

int main()
{
    Test("official example 1", 5, { 2, 4 }, { 1, 3, 5 }, 5);
    Test("official example 2", 5, { 2, 4 }, { 3 }, 4);
    Test("official example 3", 3, { 3 }, { 1 }, 2);
    Test("lost input order", 5, { 4, 2 }, { 3, 5 }, 5);
    Test("adjacent boundary", 2, { 1 }, { 2 }, 2);
    Test("student in both lists", 5, { 2 }, { 2 }, 5);
    Test("overlap changes lending", 5, { 1, 2 }, { 2, 3 }, 4);
    return 0;
}

/* Q064 체육복 https://school.programmers.co.kr/learn/courses/30/lessons/42862

문제 설명

점심시간에 도둑이 들어, 일부 학생이 체육복을 도난당했습니다. 다행히 여벌 체육복이 있는 학생이 이들에게 체육복을 빌려주려 합니다. 학생들의 번호는 체격 순으로 매겨져 있어, 바로 앞번호의 학생이나 바로 뒷번호의 학생에게만 체육복을 빌려줄 수 있습니다. 예를 들어, 4번 학생은 3번 학생이나 5번 학생에게만 체육복을 빌려줄 수 있습니다. 체육복이 없으면 수업을 들을 수 없기 때문에 체육복을 적절히 빌려 최대한 많은 학생이 체육수업을 들어야 합니다.

전체 학생의 수 n, 체육복을 도난당한 학생들의 번호가 담긴 배열 lost, 여벌의 체육복을 가져온 학생들의 번호가 담긴 배열 reserve가 매개변수로 주어질 때, 체육수업을 들을 수 있는 학생의 최댓값을 return 하도록 solution 함수를 작성해주세요.

제한사항

- 전체 학생의 수는 2명 이상 30명 이하입니다.
- 체육복을 도난당한 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
- 여벌의 체육복을 가져온 학생의 수는 1명 이상 n명 이하이고 중복되는 번호는 없습니다.
- 여벌 체육복이 있는 학생만 다른 학생에게 체육복을 빌려줄 수 있습니다.
- 여벌 체육복을 가져온 학생이 체육복을 도난당했을 수 있습니다. 이때 이 학생은 체육복을 하나만 도난당했다고 가정하며, 남은 체육복이 하나이기에 다른 학생에게는 체육복을 빌려줄 수 없습니다.

입출력 예

n  lost    reserve    return
5  [2, 4]  [1, 3, 5]  5
5  [2, 4]  [3]        4
3  [3]     [1]        2

입출력 예 설명

입출력 예 #1

- 1번 학생이 2번 학생에게 체육복을 빌려주고, 3번 학생이나 5번 학생이 4번 학생에게 체육복을 빌려주면 학생 5명이 체육수업을 들을 수 있습니다.

입출력 예 #2

- 3번 학생이 2번 학생이나 4번 학생에게 체육복을 빌려주면 학생 4명이 체육수업을 들을 수 있습니다.

*/
