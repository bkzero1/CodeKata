#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    std::unordered_map<int, int> countBySize;

    // 일단 순회하면서 map에 원소를 넣음
    for (int tangerineSize : tangerine)
    {
        ++countBySize[tangerineSize];
    }
    
    // 크기는 상관없으므로 개수 벡터를 만들어서 내림차순으로 정렬 후 숫자가 큰 것부터 k가 만족할때까지 사용
    std::vector<int> countOfSize;
    for (auto p : countBySize)
    {
        countOfSize.push_back(p.second);
    }

    std::sort(countOfSize.begin(), countOfSize.end(), [](int a, int b) {
        return a > b;
        });
    
    for (int num : countOfSize)
    {
        k -= num;
        ++answer;

        if (k <= 0)
        {
            break;
        }
    }

    return answer;
}

void PrintVector(const vector<int>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i != 0) cout << ", ";
        cout << values[i];
    }
    cout << ']';
}

void Test(const char* name, int k, const vector<int>& tangerine, int expected)
{
    const int actual = solution(k, tangerine);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: k = " << k << ", tangerine = ";
    PrintVector(tangerine);
    cout << " | expected: " << expected;
    cout << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 예제
    Test("Official 1", 6, {1, 3, 2, 5, 4, 5, 2, 3}, 3);
    Test("Official 2", 4, {1, 3, 2, 5, 4, 5, 2, 3}, 2);
    Test("Official 3", 2, {1, 1, 1, 1, 2, 2, 2, 3}, 1);

    // 추가 테스트
    Test("Additional 1", 1, {1}, 1);
    Test("Additional 2", 4, {9, 9, 9, 9}, 1);
    Test("Additional 3", 3, {1, 2, 3}, 3);
    Test("Additional 4", 1, {10000000, 1, 2}, 1);
    Test("Additional 5", 5, {7, 7, 7, 8, 8}, 2);
    return 0;
}

/* Q083 귤 고르기 https://school.programmers.co.kr/learn/courses/30/lessons/138476

문제 설명
경화는 과수원에서 귤을 수확했습니다. 경화는 수확한 귤 중 'k'개를 골라 상자 하나에 담아 판매하려고 합니다. 그런데 수확한 귤의 크기가 일정하지 않아 보기에 좋지 않다고 생각한 경화는 귤을 크기별로 분류했을 때 서로 다른 종류의 수를 최소화하고 싶습니다.

예를 들어, 경화가 수확한 귤 8개의 크기가 [1, 3, 2, 5, 4, 5, 2, 3] 이라고 합시다. 경화가 귤 6개를 판매하고 싶다면, 크기가 1, 4인 귤을 제외한 여섯 개의 귤을 상자에 담으면, 귤의 크기의 종류가 2, 3, 5로 총 3가지가 되며 이때가 서로 다른 종류가 최소일 때입니다.

경화가 한 상자에 담으려는 귤의 개수 k와 귤의 크기를 담은 배열 tangerine이 매개변수로 주어집니다. 경화가 귤 k개를 고를 때 크기가 서로 다른 종류의 수의 최솟값을 return 하도록 solution 함수를 작성해주세요.

제한사항
- 1 ≤ k ≤ tangerine의 길이 ≤ 100,000
- 1 ≤ tangerine의 원소 ≤ 10,000,000

입출력 예
k  tangerine                 result
6  [1, 3, 2, 5, 4, 5, 2, 3]  3
4  [1, 3, 2, 5, 4, 5, 2, 3]  2
2  [1, 1, 1, 1, 2, 2, 2, 3]  1

입출력 예 설명
입출력 예 #1
- 본문에서 설명한 예시입니다.

입출력 예 #2
- 경화는 크기가 2인 귤 2개와 3인 귤 2개 또는 2인 귤 2개와 5인 귤 2개 또는 3인 귤 2개와 5인 귤 2개로 귤을 판매할 수 있습니다. 이때의 크기 종류는 2가지로 이 값이 최소가 됩니다.

입출력 예 #3
- 경화는 크기가 1인 귤 2개를 판매하거나 2인 귤 2개를 판매할 수 있습니다. 이때의 크기 종류는 1가지로, 이 값이 최소가 됩니다.

*/
