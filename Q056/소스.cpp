#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    // 점수를 인덱스로 사용하고, 각 원소에 해당 점수의 사과 개수를 저장
    std::vector<int> scoreCounts(k + 1, 0);

    for (int appleScore : score)
    {
        ++scoreCounts[appleScore];
    }

    int applesInBox = 0;
    // 높은 점수부터 해당 점수의 사과와 이전 단계에서 남은 사과를 함께 처리
    // 이번 단계에서 완성되는 상자는 currentScore를 최저 점수로 사용
    for (int currentScore = k; currentScore >= 1; --currentScore)
    {
        // 이전에 남은 사과와 현재 점수의 사과를 합쳐 묶음으로 처리
        int availableApples = applesInBox + scoreCounts[currentScore];
        
        // 한 세트 가격 * 몇 묶음인지
        answer += (currentScore * m) * (availableApples / m) ;
        
        // 남은 사과 이월
        applesInBox = availableApples % m;
    }

    return answer;
}

//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] 정수 벡터의 원소를 출력하는 보조 함수
void PrintVector(const vector<int>& values)
{
    cout << "[";
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i != 0) cout << ", ";
        cout << values[i];
    }
    cout << "]";
}

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, int k, int m,
    const vector<int>& score, int expected)
{
    const int actual = solution(k, m, score);
    const bool success = actual == expected;

    cout << "\x1b[38;2;"
        << (success ? "120;230;102" : "230;102;102")
        << "m"
        << (success ? " SUCCESS" : "  FAIL  ")
        << "\x1b[0m"
        << " | " << testName
        << " | input: k=" << k
        << ", m=" << m
        << ", score=";
    PrintVector(score);
    cout << " | expected: " << expected
        << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 입출력 예
    Test("official example 1", 3, 4,
        { 1, 2, 3, 1, 2, 3, 1 }, 8);
    Test("official example 2", 4, 3,
        { 4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2 }, 33);

    // Codex가 추가한 경계 테스트
    Test("not enough apples for one box", 3, 10,
        { 1, 2, 3, 1, 2, 3, 1 }, 0);
    Test("discard apples left after full boxes", 5, 3,
        { 5, 5, 5, 5 }, 15);
    Test("choose profitable groups and discard one", 4, 2,
        { 1, 4, 4, 2, 3 }, 12);

    Test("complete a partially filled box with the next score", 4, 3,
        { 4, 4, 3, 3, 2, 2, 2 }, 15);

    return 0;
}

/* Q056 과일 장수 https://school.programmers.co.kr/learn/courses/30/lessons/135808

문제 설명

과일 장수가 사과 상자를 포장하고 있습니다. 사과는 상태에 따라 1점부터 k점까지의 점수로 분류하며, k점이 최상품의 사과이고 1점이 최하품의 사과입니다. 사과 한 상자의 가격은 다음과 같이 결정됩니다.

- 한 상자에 사과를 m개씩 담아 포장합니다.
- 상자에 담긴 사과 중 가장 낮은 점수가 p (1 ≤ p ≤ k)점인 경우, 사과 한 상자의 가격은 p * m 입니다.

과일 장수가 가능한 많은 사과를 팔았을 때, 얻을 수 있는 최대 이익을 계산하고자 합니다. (사과는 상자 단위로만 판매하며, 남는 사과는 버립니다.)

예를 들어, k = 3, m = 4, 사과 7개의 점수가 [1, 2, 3, 1, 2, 3, 1]이라면, 다음과 같이 [2, 3, 2, 3]으로 구성된 사과 상자 1개를 만들어 판매하여 최대 이익을 얻을 수 있습니다.

- (최저 사과 점수) x (한 상자에 담긴 사과 개수) x (상자의 개수) = 2 x 4 x 1 = 8

사과의 최대 점수 k, 한 상자에 들어가는 사과의 수 m, 사과들의 점수 score가 주어졌을 때, 과일 장수가 얻을 수 있는 최대 이익을 return하는 solution 함수를 완성해주세요.

제한사항

- 3 ≤ k ≤ 9
- 3 ≤ m ≤ 10
- 7 ≤ score의 길이 ≤ 1,000,000
  - 1 ≤ score[i] ≤ k
- 이익이 발생하지 않는 경우에는 0을 return 해주세요.

입출력 예

k   m   score                                      result
3   4   [1, 2, 3, 1, 2, 3, 1]                    8
4   3   [4, 1, 2, 2, 4, 4, 4, 4, 1, 2, 4, 2]     33

입출력 예 설명

입출력 예 #1

- 문제의 예시와 같습니다.

입출력 예 #2

- 다음과 같이 사과 상자를 포장하여 모두 팔면 최대 이익을 낼 수 있습니다.

사과 상자   가격
[1, 1, 2]   1 x 3 = 3
[2, 2, 2]   2 x 3 = 6
[4, 4, 4]   4 x 3 = 12
[4, 4, 4]   4 x 3 = 12

따라서 (1 x 3 x 1) + (2 x 3 x 1) + (4 x 3 x 2) = 33을 return합니다.

*/
