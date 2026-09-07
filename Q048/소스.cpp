#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    //cout << "t " << *(commands[0].begin()+2) << endl;

    // 커맨드 수만큼 반복
    for (int i = 0; i < commands.size(); ++i)
    {
        std::vector<int> subArray;
        const vector<int>& command = commands[i];   // 가독성을 위해 현재 커맨드를 읽기 전용 참조로 지정

        // 현재 명령이 지정한 구간을 임시 배열에 복사
        // 처음에는 현재 이터레이터와 구간 끝을 < 로 비교했지만, 구간 끝에 도달할 때까지라는 의미가 명확한 !=로 변경
        for (auto it = array.begin() + command[0] - 1; it != array.begin() + command[1]; ++it)
        {
            //std::cout << array[j - 1];

            subArray.push_back(*it);
        }

        // 선택한 구간을 오름차순으로 정렬
        std::sort(subArray.begin(), subArray.end());

        // 정렬된 구간에서 지정된 위치의 숫자를 결과에 추가
        int selectedNumber = subArray[command[2] - 1];
        answer.push_back(selectedNumber);
    }
    
    return answer;
}

void PrintVector(const vector<int>& values)
{
    cout << "[";

    for (int i = 0; i < values.size(); ++i)
    {
        if (i > 0)
        {
            cout << ", ";
        }

        cout << values[i];
    }

    cout << "]";
}

void Test(const vector<int>& array, const vector<vector<int>>& commands, const vector<int>& expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m";
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";
    const char* RESET_COLOR = "\033[0m";

    vector<int> result = solution(array, commands);
    bool success = (result == expected);

    // 성공 여부를 줄의 맨 앞에 고정해서 테스트 결과를 빠르게 훑어봄
    cout << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? " SUCCESS" : "  FAIL  ")
        << RESET_COLOR
        << " | Expected: ";
    PrintVector(expected);
    cout << " | Result: ";
    PrintVector(result);
    cout << '\n';
}

int main()
{
    // 공식 예제
    Test(
        { 1, 5, 2, 6, 3, 7, 4 },
        { { 2, 5, 3 }, { 4, 4, 1 }, { 1, 7, 3 } },
        { 5, 6, 3 }
    );

    // 추가 경계 테스트
    Test({ 1 }, { { 1, 1, 1 } }, { 1 });
    Test({ 4, 2, 1, 3 }, { { 1, 4, 1 }, { 1, 4, 4 } }, { 1, 4 });
    Test({ 3, 3, 3 }, { { 1, 3, 2 } }, { 3 });

    return 0;
}

/* Q048 K번째수 https://school.programmers.co.kr/learn/courses/30/lessons/42748

문제 설명
배열 array의 i번째 숫자부터 j번째 숫자까지 자르고 정렬했을 때, k번째에 있는 수를 구하려 합니다.

예를 들어 array가 [1, 5, 2, 6, 3, 7, 4], i = 2, j = 5, k = 3이라면
1. array의 2번째부터 5번째까지 자르면 [5, 2, 6, 3]입니다.
2. 1에서 나온 배열을 정렬하면 [2, 3, 5, 6]입니다.
3. 2에서 나온 배열의 3번째 숫자는 5입니다.

배열 array, [i, j, k]를 원소로 가진 2차원 배열 commands가 매개변수로 주어질 때, commands의 모든 원소에 대해 앞서 설명한 연산을 적용했을 때 나온 결과를 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
- array의 길이는 1 이상 100 이하입니다.
- array의 각 원소는 1 이상 100 이하입니다.
- commands의 길이는 1 이상 50 이하입니다.
- commands의 각 원소는 길이가 3입니다.

입출력 예
array                      commands                                  return
[1, 5, 2, 6, 3, 7, 4]     [[2, 5, 3], [4, 4, 1], [1, 7, 3]]       [5, 6, 3]

입출력 예 설명
- [1, 5, 2, 6, 3, 7, 4]를 2번째부터 5번째까지 자른 후 정렬합니다. [2, 3, 5, 6]의 세 번째 숫자는 5입니다.
- [1, 5, 2, 6, 3, 7, 4]를 4번째부터 4번째까지 자른 후 정렬합니다. [6]의 첫 번째 숫자는 6입니다.
- [1, 5, 2, 6, 3, 7, 4]를 1번째부터 7번째까지 자릅니다. [1, 2, 3, 4, 5, 6, 7]의 세 번째 숫자는 3입니다.

*/
