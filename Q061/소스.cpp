#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
    const vector<int> ranksByMatchCount = { 6, 6, 5, 4, 3, 2, 1 };
    int zeroCount = 0;
    int correctCount = 0;

    for (int num : lottos)
    {
        if (num == 0)
        {
            ++zeroCount;
            
            continue;
        }

        if (std::find(win_nums.begin(), win_nums.end(), num) != win_nums.end())
        {
            ++correctCount;
        }
    }

    return { ranksByMatchCount[correctCount + zeroCount], ranksByMatchCount[correctCount] };
}

void PrintVector(const vector<int>& values)
{
    cout << '[';
    for (int i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << values[i];
    }
    cout << ']';
}

void Test(const string& name, const vector<int>& lottos,
    const vector<int>& winNums, const vector<int>& expected)
{
    const vector<int> actual = solution(lottos, winNums);
    const bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: lottos = ";
    PrintVector(lottos);
    cout << ", win_nums = ";
    PrintVector(winNums);
    cout << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

int main()
{
    Test("official example 1", { 44, 1, 0, 0, 31, 25 }, { 31, 10, 45, 1, 6, 19 }, { 3, 5 });
    Test("official example 2", { 0, 0, 0, 0, 0, 0 }, { 38, 19, 20, 40, 15, 25 }, { 1, 6 });
    Test("official example 3", { 45, 4, 35, 20, 3, 9 }, { 20, 9, 3, 45, 4, 35 }, { 1, 1 });
    Test("no matching numbers", { 1, 2, 3, 4, 5, 6 }, { 7, 8, 9, 10, 11, 12 }, { 6, 6 });
    Test("one unknown and two matches", { 0, 1, 2, 10, 11, 12 }, { 1, 2, 20, 21, 22, 23 }, { 4, 5 });
    return 0;
}

/* Q061 로또의 최고 순위와 최저 순위 https://school.programmers.co.kr/learn/courses/30/lessons/77484

문제 설명

로또 6/45는 1부터 45까지의 숫자 중 6개를 찍어서 맞히는 대표적인 복권입니다. 아래는 로또의 순위를 정하는 방식입니다.

순위    당첨 내용
1       6개 번호가 모두 일치
2       5개 번호가 일치
3       4개 번호가 일치
4       3개 번호가 일치
5       2개 번호가 일치
6       그 외

로또를 구매한 민우는 당첨 번호 발표일을 학수고대하고 있었습니다. 하지만, 민우의 동생이 로또에 낙서를 하여 일부 번호를 알아볼 수 없게 되었습니다. 당첨 번호 발표 후, 민우는 자신이 구매했던 로또로 당첨이 가능했던 최고 순위와 최저 순위를 알아보고 싶어졌습니다.

알아볼 수 없는 번호를 0으로 표기하기로 하고, 민우가 구매했던 로또 번호가 [44, 1, 0, 0, 31, 25]라고 가정하겠습니다. 당첨 번호가 [31, 10, 45, 1, 6, 19]라면, 알아볼 수 없는 두 번호에 따라 최고 3등부터 최저 5등까지 당첨될 수 있습니다.

- 순서와 상관없이 구매한 로또에 당첨 번호와 일치하는 번호가 있으면 맞힌 것으로 인정됩니다.

민우가 구매한 로또 번호를 담은 배열 lottos와 당첨 번호를 담은 배열 win_nums가 매개변수로 주어집니다. 당첨 가능한 최고 순위와 최저 순위를 차례대로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

- lottos는 길이 6인 정수 배열입니다.
- lottos의 모든 원소는 0 이상 45 이하인 정수입니다.
- 0은 알아볼 수 없는 숫자를 의미합니다.
- 0을 제외한 다른 숫자들은 lottos에 2개 이상 담겨있지 않습니다.
- lottos의 원소들은 정렬되어 있지 않을 수도 있습니다.
- win_nums는 길이 6인 정수 배열입니다.
- win_nums의 모든 원소는 1 이상 45 이하인 정수입니다.
- win_nums에는 같은 숫자가 2개 이상 담겨있지 않습니다.
- win_nums의 원소들은 정렬되어 있지 않을 수도 있습니다.

입출력 예

lottos                   win_nums                   result
[44, 1, 0, 0, 31, 25]   [31, 10, 45, 1, 6, 19]   [3, 5]
[0, 0, 0, 0, 0, 0]      [38, 19, 20, 40, 15, 25] [1, 6]
[45, 4, 35, 20, 3, 9]   [20, 9, 3, 45, 4, 35]    [1, 1]

입출력 예 설명

입출력 예 #1

문제 예시와 같습니다.

입출력 예 #2

알아볼 수 없는 번호가 모두 당첨 번호라면 1등, 모두 당첨 번호가 아니라면 6등입니다.

입출력 예 #3

민우가 구매한 로또 번호와 당첨 번호가 모두 일치하므로 최고 순위와 최저 순위는 모두 1등입니다.

*/
