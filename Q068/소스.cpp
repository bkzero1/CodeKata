#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

// ingredient 1 - 빵 / 2 - 야채 / 3 - 고기
int solution(vector<int> ingredient) {
    int answer = 0;
    static const std::array<int, 4> burgerPattern{ 1, 2, 3, 1 };
    auto patternIt = ingredient.begin();

    // 남은 재료에서 햄버거 패턴을 찾고, 찾으면 개수를 늘리고 해당 재료 삭제
    // 삭제하면 앞뒤 재료가 이어지니까 처음부터 다시 검색
    while (patternIt != ingredient.end())
    {
        patternIt = std::search(patternIt, ingredient.end(), burgerPattern.begin(), burgerPattern.end());
        if (patternIt != ingredient.end())
        {
            // 사용한 재료 삭제 후 반환된 이터레이터를 저장
            ++answer;
            patternIt = ingredient.erase(patternIt, patternIt + burgerPattern.size());

            const int rewindDistance = burgerPattern.size() - 1;
            if (patternIt - ingredient.begin() > rewindDistance)
            {
                patternIt -= rewindDistance;
            }
            else
            {
                patternIt = ingredient.begin();
            }
        }
    }

    return answer;
}

// 입력 배열을 생략하지 않고 표시합니다.
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

// 입력과 기대값, 실제값을 한 줄에서 비교합니다.
void Test(const string& name, const vector<int>& ingredient, int expected)
{
    const int actual = solution(ingredient);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: ingredient = ";
    PrintVector(ingredient);
    cout << " | expected: " << expected << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 예제
    Test("official example 1", {2, 1, 1, 2, 3, 1, 2, 3, 1}, 2);
    Test("official example 2", {1, 3, 2, 1, 2, 1, 3, 1, 2}, 0);

    // 추가 검증 사례
    Test("additional case 1", {1}, 0);
    Test("additional case 2", {1, 2, 3}, 0);
    Test("additional case 3", {1, 2, 3, 1}, 1);
    Test("additional case 4", {1, 2, 3, 1, 1, 2, 3, 1}, 2);
    Test("additional case 5", {1, 2, 1, 2, 3, 1, 3, 1}, 2);
    Test("additional case 6", {3, 2, 1, 1, 1}, 0);
    return 0;
}

/* Q068 햄버거 만들기 https://school.programmers.co.kr/learn/courses/30/lessons/133502

문제 설명

햄버거 가게에서 일을 하는 상수는 햄버거를 포장하는 일을 합니다. 함께 일을 하는 다른 직원들이 햄버거에 들어갈 재료를 조리해 주면 조리된 순서대로 상수의 앞에 아래서부터 위로 쌓이게 되고, 상수는 순서에 맞게 쌓여서 완성된 햄버거를 따로 옮겨 포장을 하게 됩니다. 상수가 일하는 가게는 정해진 순서(아래서부터, 빵 – 야채 – 고기 - 빵)로 쌓인 햄버거만 포장을 합니다. 상수는 손이 굉장히 빠르기 때문에 상수가 포장하는 동안 속 재료가 추가적으로 들어오는 일은 없으며, 재료의 높이는 무시하여 재료가 높이 쌓여서 일이 힘들어지는 경우는 없습니다.

예를 들어, 상수의 앞에 쌓이는 재료의 순서가 [야채, 빵, 빵, 야채, 고기, 빵, 야채, 고기, 빵]일 때, 상수는 여섯 번째 재료가 쌓였을 때, 세 번째 재료부터 여섯 번째 재료를 이용하여 햄버거를 포장하고, 아홉 번째 재료가 쌓였을 때, 두 번째 재료와 일곱 번째 재료부터 아홉 번째 재료를 이용하여 햄버거를 포장합니다. 즉, 2개의 햄버거를 포장하게 됩니다.

상수에게 전해지는 재료의 정보를 나타내는 정수 배열 ingredient가 주어졌을 때, 상수가 포장하는 햄버거의 개수를 return 하도록 solution 함수를 완성하시오.

제한사항

- 1 ≤ ingredient의 길이 ≤ 1,000,000
- ingredient의 원소는 1, 2, 3 중 하나의 값이며, 순서대로 빵, 야채, 고기를 의미합니다.

입출력 예

ingredient                     result
[2, 1, 1, 2, 3, 1, 2, 3, 1]    2
[1, 3, 2, 1, 2, 1, 3, 1, 2]    0

입출력 예 설명

입출력 예 #1
- 문제 예시와 같습니다.

입출력 예 #2
- 상수가 포장할 수 있는 햄버거가 없습니다.

*/