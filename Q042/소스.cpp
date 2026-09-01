#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> number) {
    int answer = 0;

    // 세 수의 합만 확인하므로 원소 순서를 정렬해도 결과에는 영향 없음
    // equal_range는 정렬된 범위를 전제로 이진 탐색을 사용함
    std::sort(number.begin(), number.end());
    
    for (int i = 0; i + 2 < number.size(); ++i)
    {
        for (int j = i + 1; j + 1 < number.size(); ++j)
        {
            auto range = std::equal_range(
                number.begin() + j + 1,
                number.end(), 
                -(number[i] + number[j])
            );

            // 필요한 세 번째 값과 같은 학생의 수만큼 누적
            answer += range.second - range.first;
        }
    }
    // 직접구현 nC3
    /*
    for (int i = 0; i + 2 < number.size(); ++i)
    {
        for (int j = i + 1; j + 1 < number.size(); ++j)
        {
            for (int k = j + 1; k < number.size(); ++k)
            {
                int sum = number[i] + number[j] + number[k];
                if (sum == 0)
                    ++answer;

                //if (int sum = number[i] + number[j] + number[k]; sum == 0)    // requires C++17
                //    ++answer;
            }
        }
    }
    */
    return answer;
}

void PrintVector(const vector<int>& v)
{
    cout << "[";

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];

        if (i + 1 < v.size())
        {
            cout << ", ";
        }
    }

    cout << "]";
}

void Test(const vector<int>& number, int expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    int result = solution(number);
    bool success = (result == expected);

    cout << "number: ";
    PrintVector(number);

    cout << " | Expected: " << expected
        << " | Result: " << result
        << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test({ -2, 3, 0, 2, -5 }, 2);              // 문제 예제
    Test({ -3, -2, -1, 0, 1, 2, 3 }, 5);      // 문제 예제
    Test({ -1, 1, -1, 1 }, 0);                 // 문제 예제

    Test({ 0, 0, 0 }, 1);                       // 최소 길이, 한 가지 조합
    Test({ 1, 1, -2 }, 1);                      // 같은 번호를 가진 서로 다른 학생
    Test({ 0, 0, 0, 0 }, 4);                    // 같은 값이 여러 개일 때 조합 수 확인
    Test({ 1, 2, 3 }, 0);                       // 가능한 조합 없음
    Test({ -1000, 0, 1000 }, 1);                // 원소 경계값 활용
    Test({ -1, -1, -1, 1, 1, 1 }, 0);          // 중복값 다수

    return 0;
}

/* Q42 삼총사

문제 설명
한국중학교에 다니는 학생들은 각자 정수 번호를 갖고 있습니다.
이 학교 학생 3명의 정수 번호를 더했을 때 0이 되면 3명의 학생은 삼총사라고 합니다.
예를 들어, 5명의 학생이 있고, 각각의 정수 번호가 순서대로 -2, 3, 0, 2, -5일 때,
첫 번째, 세 번째, 네 번째 학생의 정수 번호를 더하면 0이므로 세 학생은 삼총사입니다.
또한, 두 번째, 네 번째, 다섯 번째 학생의 정수 번호를 더해도 0이므로 세 학생도 삼총사입니다.
따라서 이 경우 한국중학교에서는 두 가지 방법으로 삼총사를 만들 수 있습니다.

한국중학교 학생들의 번호를 나타내는 정수 배열 number가 매개변수로 주어질 때,
학생들 중 삼총사를 만들 수 있는 방법의 수를 return 하도록 solution 함수를 완성하세요.

제한사항
3 ≤ number의 길이 ≤ 13
-1,000 ≤ number의 각 원소 ≤ 1,000
서로 다른 학생의 정수 번호가 같을 수 있습니다.

입출력 예
number                         result
[-2, 3, 0, 2, -5]             2
[-3, -2, -1, 0, 1, 2, 3]      5
[-1, 1, -1, 1]                 0

입출력 예 설명
입출력 예 #1
문제 예시와 같습니다.

입출력 예 #2
학생들의 정수 번호 쌍 (-3, 0, 3), (-2, 0, 2), (-1, 0, 1),
(-2, -1, 3), (-3, 1, 2) 이 삼총사가 될 수 있으므로, 5를 return 합니다.

입출력 예 #3
삼총사가 될 수 있는 방법이 없습니다.

*/