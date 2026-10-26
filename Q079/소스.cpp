#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================
// 수식 풀이: AI가 설명한 합·곱과 근의 공식 아이디어를 참고하여 구현

#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<int> solution(int brown, int yellow) {
    // 갈색 테두리는 가로 두 줄과 세로 두 줄에서 중복된 모서리 4칸을 뺀 개수
    // brown = 2 * (가로 + 세로) - 4이므로, 4를 더하고 2로 나누면 두 길이의 합
    // 두 길이의 곱은 갈색과 노란색을 합한 전체 넓이
    const int sideSum = (brown + 4) / 2;
    const int totalTiles = brown + yellow;

    // 가로와 세로를 두 근으로 갖는 식: x² - sideSum * x + totalTiles = 0
    // 근의 공식에서 큰 근은 가로, 작은 근은 세로 (가로 >= 세로)
    const int width = static_cast<int>((sideSum + std::sqrt(sideSum * sideSum - 4 * totalTiles)) / 2);
    //const int height = (sideSum - std::sqrt(sideSum * sideSum - 4 * totalTiles)) / 2;
    const int height = totalTiles / width;

    return { width, height };
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

void Test(const string& name, int brown, int yellow, const vector<int>& expected)
{
    const vector<int> actual = solution(brown, yellow);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: brown = " << brown << ", yellow = " << yellow;
    cout << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

int main()
{
    // 공식 예제
    Test("Official 1", 10, 2, {4, 3});
    Test("Official 2", 8, 1, {3, 3});
    Test("Official 3", 24, 24, {8, 6});

    // 추가 테스트: 서로 다른 크기와 큰 입력
    Test("Additional 1", 12, 4, {4, 4});
    Test("Additional 2", 14, 4, {6, 3});
    Test("Additional 3", 18, 6, {8, 3});
    Test("Additional 4", 4004, 1000000, {1002, 1002});
    Test("Additional 5", 5000, 1560000, {1252, 1250});
    // 전체 넓이는 완전제곱수지만 주어진 색상 개수에 맞는 카펫은 직사각형
    Test("Additional 6 (square total, rectangular carpet)", 22, 14, {9, 4});
    return 0;
}

/* Q079 카펫 https://school.programmers.co.kr/learn/courses/30/lessons/42842

문제 설명
Leo는 카펫을 사러 갔다가 아래 그림과 같이 중앙에는 노란색으로 칠해져 있고 테두리 1줄은 갈색으로 칠해져 있는 격자 모양 카펫을 봤습니다.

[그림: 중앙은 노란색, 바깥쪽 테두리 1줄은 갈색인 직사각형 격자 카펫]

Leo는 집으로 돌아와서 아까 본 카펫의 노란색과 갈색으로 색칠된 격자의 개수는 기억했지만, 전체 카펫의 크기는 기억하지 못했습니다.

Leo가 본 카펫에서 갈색 격자의 수 brown, 노란색 격자의 수 yellow가 매개변수로 주어질 때 카펫의 가로, 세로 크기를 순서대로 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한사항
- 갈색 격자의 수 brown은 8 이상 5,000 이하인 자연수입니다.
- 노란색 격자의 수 yellow는 1 이상 2,000,000 이하인 자연수입니다.
- 카펫의 가로 길이는 세로 길이와 같거나, 세로 길이보다 깁니다.

입출력 예
brown    yellow    return
10       2         [4, 3]
8        1         [3, 3]
24       24        [8, 6]

출처
https://hsin.hr/coci/archive/2010_2011/contest4_tasks.pdf

※ 공지 - 2020년 2월 3일 테스트케이스가 추가되었습니다.
※ 공지 - 2020년 5월 11일 웹접근성을 고려하여 빨간색을 노란색으로 수정하였습니다.

*/
