#include <iostream>
//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;

    for (int i = 0; i + 1 < numbers.size(); ++i)
    {
        for (int j = i + 1; j < numbers.size(); ++j)
        {
            int sum = numbers[i] + numbers[j];
    
            // 중복허용하게 저장하고 나중에 정리
            answer.push_back(sum);
        }
    }

    // unique는 연속된 중복만 정리하므로, 같은 값이 서로 붙도록 합들을 오름차순으로 정렬
    std::sort(answer.begin(), answer.end());

    // 중복을 정리한 뒤 새로운 논리적 끝을 받음
    auto newEnd = std::unique(answer.begin(), answer.end());

    // 논리적 끝 이후의 원소를 벡터에서 실제로 제거
    answer.erase(newEnd, answer.end());

    return answer;
}


//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] vector의 원소를 출력하는 보조 함수
void PrintVector(const vector<int>& values)
{
    cout << '[';

    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
            cout << ", ";

        cout << values[i];
    }

    cout << ']';
}

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, const vector<int>& numbers, const vector<int>& expected)
{
    vector<int> actual = solution(numbers);
    bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m" : "\x1b[38;2;230;102;102m");
    cout << (success ? " SUCCESS" : "  FAIL  ");
    cout << "\x1b[0m";
    cout << " | " << testName << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
    // 공식 예제 테스트
    Test("official example 1", { 2, 1, 3, 4, 1 }, { 2, 3, 4, 5, 6, 7 });
    Test("official example 2", { 5, 0, 2, 7 }, { 2, 5, 7, 9, 12 });

    // 추가 경계 테스트
    Test("two zeroes", { 0, 0 }, { 0 });
    Test("two maximum values", { 100, 100 }, { 200 });
    Test("all values equal", { 1, 1, 1 }, { 2 });
    Test("sums are not generated in sorted order", { 1, 2, 3, 100 }, { 3, 4, 5, 101, 102, 103 });

    return 0;
}

/* Q049 두 개 뽑아서 더하기 https://school.programmers.co.kr/learn/courses/30/lessons/68644

문제 설명
정수 배열 numbers가 주어집니다. numbers에서 서로 다른 인덱스에 있는 두 개의 수를 뽑아 더해서 만들 수 있는 모든 수를 배열에 오름차순으로 담아 return 하도록 solution 함수를 완성해주세요.

제한사항
- numbers의 길이는 2 이상 100 이하입니다.
- numbers의 모든 수는 0 이상 100 이하입니다.

입출력 예
numbers       result
[2,1,3,4,1]  [2,3,4,5,6,7]
[5,0,2,7]    [2,5,7,9,12]

입출력 예 설명
입출력 예 #1
- 2 = 1 + 1 입니다. (1이 numbers에 두 개 있습니다.)
- 3 = 2 + 1 입니다.
- 4 = 1 + 3 입니다.
- 5 = 1 + 4 = 2 + 3 입니다.
- 6 = 2 + 4 입니다.
- 7 = 3 + 4 입니다.
- 따라서 [2,3,4,5,6,7] 을 return 해야 합니다.

입출력 예 #2
- 2 = 0 + 2 입니다.
- 5 = 5 + 0 입니다.
- 7 = 0 + 7 = 5 + 2 입니다.
- 9 = 2 + 7 입니다.
- 12 = 5 + 7 입니다.
- 따라서 [2,5,7,9,12] 를 return 해야 합니다.

*/
