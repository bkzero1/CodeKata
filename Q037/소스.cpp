#include <iostream>

//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================
// TODO
// 1. Matrix 클래스 + operator+로 a + b 구현해보기
// 2. bool AddMatrix(a, b, result) 방식과 비교해보기
// 3. 여유 있으면 Matrix<T> 템플릿으로 확장

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> solution(vector<vector<int>> arr1, vector<vector<int>> arr2) {
    vector<vector<int>> answer(arr1.size(), vector<int>(arr1[0].size())); // = arr1;
    
    for (int i = 0; i < arr1.size(); ++i)
    {
        for (int j = 0; j < arr1[i].size(); ++j)
        {
            //std::cout << arr1[i][j] << " ";
            answer[i][j] = arr1[i][j] + arr2[i][j];
        }
    }

    return answer;
}

void Test(
    const vector<vector<int>>& arr1,
    const vector<vector<int>>& arr2,
    const vector<vector<int>>& expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m"; // #E66666
    const char* RESET_COLOR = "\033[0m";

    vector<vector<int>> actual = solution(arr1, arr2);
    bool success = (actual == expected);

    cout << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR
        << " | Expected: ";

    for (const auto& row : expected)
    {
        cout << "[ ";
        for (int value : row)
        {
            cout << value << ' ';
        }
        cout << "] ";
    }

    cout << "| Actual: ";

    for (const auto& row : actual)
    {
        cout << "[ ";
        for (int value : row)
        {
            cout << value << ' ';
        }
        cout << "] ";
    }

    cout << '\n';
}

int main()
{
    // 문제 제공 예제
    Test({ {1, 2}, {2, 3} },
        { {3, 4}, {5, 6} },
        { {4, 6}, {7, 9} });

    Test({ {1}, {2} },
        { {3}, {4} },
        { {4}, {6} });

    // 추가 테스트
    Test({ {0} },
        { {0} },
        { {0} });

    Test({ {1, 2, 3} },
        { {4, 5, 6} },
        { {5, 7, 9} });

    Test({ {1, 2}, {3, 4}, {5, 6} },
        { {6, 5}, {4, 3}, {2, 1} },
        { {7, 7}, {7, 7}, {7, 7} });

    return 0;
}

/* Q37 행렬의 덧셈

문제 설명
행렬의 덧셈은 행과 열의 크기가 같은 두 행렬의 같은 행, 같은 열의 값을 서로 더한 결과가 됩니다. 2개의 행렬 arr1과 arr2를 입력받아, 행렬 덧셈의 결과를 반환하는 함수, solution을 완성해주세요.

제한 조건
행렬 arr1, arr2의 행과 열의 길이는 500을 넘지 않습니다.
입출력 예
arr1	arr2	return
[[1,2],[2,3]]	[[3,4],[5,6]]	[[4,6],[7,9]]
[[1],[2]]	[[3],[4]]	[[4],[6]]

*/