#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <numeric>

using namespace std;

// 배열에 담긴 모든 수의 최소공배수를 반환
int solution(vector<int> arr) {
    // 첫 원소로 누적 최소공배수의 시작값을 설정
    int accumulatedLcm = arr.at(0);

    // 이미 반영한 첫 원소를 제외하고 인덱스 1부터 나머지 원소를 누적
    // 원소가 하나면 반복 조건이 거짓이므로 추가 접근 없이 반환
    for (int index = 1; index < arr.size(); ++index)
    {
        accumulatedLcm = std::lcm(accumulatedLcm, arr.at(index));
    }

    return accumulatedLcm;
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

void Test(const char* name, const vector<int>& arr, int expected)
{
    const int actual = solution(arr);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: arr = ";
    PrintVector(arr);
    cout << " | expected: " << expected;
    cout << " | actual: " << actual << '\n';
}

int main()
{
    // 공식 예제
    Test("Official 1", {2, 6, 8, 14}, 168);
    Test("Official 2", {1, 2, 3}, 6);

    // 추가 테스트
    Test("Additional 1", {1}, 1);
    Test("Additional 2", {100}, 100);
    Test("Additional 3", {5, 5, 5}, 5);
    Test("Additional 4", {3, 4}, 12);
    Test("Additional 5", {2, 4, 8}, 8);
    Test("Additional 6", {100, 1, 25, 50}, 100);
    Test("Additional 7", {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}, 1);
    return 0;
}

/* Q081 N개의 최소공배수 https://school.programmers.co.kr/learn/courses/30/lessons/12953

문제 설명
두 수의 최소공배수(Least Common Multiple)란 입력된 두 수의 배수 중 공통이 되는 가장 작은 숫자를 의미합니다. 예를 들어 2와 7의 최소공배수는 14가 됩니다. 정의를 확장해서, n개의 수의 최소공배수는 n 개의 수들의 배수 중 공통이 되는 가장 작은 숫자가 됩니다. n개의 숫자를 담은 배열 arr이 입력되었을 때 이 수들의 최소공배수를 반환하는 함수, solution을 완성해 주세요.

제한 사항
- arr은 길이 1이상, 15이하인 배열입니다.
- arr의 원소는 100 이하인 자연수입니다.

입출력 예
arr            result
[2, 6, 8, 14]  168
[1, 2, 3]      6

*/
