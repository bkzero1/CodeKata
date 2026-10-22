#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 2로 나눈 나머지를 낮은 자리부터 모은 뒤 순서를 뒤집어 이진수 문자열 생성
std::string decToBin(int number)
{
    if (number <= 0)
    {
        return "0";
    }
    
    std::string binary{};
    while (number > 0)
    {
        binary += (number % 2) + '0';
        number /= 2;
    }

    std::reverse(binary.begin(), binary.end());
    return binary;
}

// {이진 변환 횟수, 제거한 0의 누적 개수} 반환
vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    // 반환 배열의 각 원소에 역할을 나타내는 이름을 붙여 직접 누적
    int& conversionCount = answer.front();
    int& totalRemovedZeroCount = answer.back();
    
    while (s != "1")
    {
        // 이번 문자열에서 제거될 0의 개수를 확인
        int currentLength = s.size();
        int removedZeroCount = 0;
        for (int i = 0; i < currentLength; ++i)
        {
            if (s[i] == '0')
            {
                ++removedZeroCount;
            }
        }

        // 변환 횟수와 제거한 0을 누적하고, 남은 길이를 이진수 문자열로 변환
        ++conversionCount;
        totalRemovedZeroCount += removedZeroCount;

        s = decToBin(currentLength - removedZeroCount);
    }

    return answer;
}

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

// 입력 전체와 기대값, 실제값을 한 줄에서 비교
void Test(const string& name, const string& s, const vector<int>& expected)
{
    const vector<int> actual = solution(s);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: s = ";
    // 긴 입력은 앞부분과 전체 길이만 출력하여 테스트 결과를 읽기 쉽게 유지
    if (s.size() > 80)
    {
        cout << '"' << s.substr(0, 40) << "...\" (length: " << s.size() << ')';
    }
    else
    {
        cout << '"' << s << '"';
    }
    cout << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

int main()
{
    Test("official example 1", "110010101001", { 3, 8 });
    Test("official example 2", "01110", { 3, 3 });
    Test("official example 3", "1111111", { 4, 1 });
    Test("additional case 1", "1", { 0, 0 });
    Test("additional case 2", "10", { 1, 1 });
    Test("additional case 3", "01", { 1, 1 });
    Test("additional case 4", "11", { 2, 1 });
    Test("additional case 5", "1000", { 1, 3 });
    // 최대 길이에서 0이 없는 경우와 1이 하나뿐인 경우를 각각 검증
    Test("additional case 6 (maximum length, all ones)", string(150000, '1'), { 3, 13 });
    Test("additional case 7 (maximum length, one one)", "1" + string(149999, '0'), { 1, 149999 });
    return 0;
}

/* Q077 이진 변환 반복하기 https://school.programmers.co.kr/learn/courses/30/lessons/70129

문제 설명

0과 1로 이루어진 어떤 문자열 x에 대한 이진 변환을 다음과 같이 정의합니다.

1. x의 모든 0을 제거합니다.
2. x의 길이를 c라고 하면, x를 "c를 2진법으로 표현한 문자열"로 바꿉니다.

예를 들어, x = "0111010" 이라면, x에 이진 변환을 가하면 x = "0111010" -> "1111" -> "100" 이 됩니다.

0과 1로 이루어진 문자열 s가 매개변수로 주어집니다. s가 "1"이 될 때까지 계속해서 s에 이진 변환을 가했을 때, 이진 변환의 횟수와 변환 과정에서 제거된 모든 0의 개수를 각각 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

- s의 길이는 1 이상 150,000 이하입니다.
- s에는 '1'이 최소 하나 이상 포함되어 있습니다.

입출력 예

s                 result
"110010101001"    [3,8]
"01110"           [3,3]
"1111111"         [4,1]

입출력 예 설명

입출력 예 #1

- "110010101001"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차  이진 변환 이전    제거할 0의 개수  0 제거 후 길이  이진 변환 결과
1     "110010101001"   6                6               "110"
2     "110"            1                2               "10"
3     "10"             1                1               "1"

- 3번의 이진 변환을 하는 동안 8개의 0을 제거했으므로, [3,8]을 return 해야 합니다.

입출력 예 #2

- "01110"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차  이진 변환 이전  제거할 0의 개수  0 제거 후 길이  이진 변환 결과
1     "01110"        2                3               "11"
2     "11"           0                2               "10"
3     "10"           1                1               "1"

- 3번의 이진 변환을 하는 동안 3개의 0을 제거했으므로, [3,3]을 return 해야 합니다.

입출력 예 #3

- "1111111"이 "1"이 될 때까지 이진 변환을 가하는 과정은 다음과 같습니다.

회차  이진 변환 이전  제거할 0의 개수  0 제거 후 길이  이진 변환 결과
1     "1111111"      0                7               "111"
2     "111"          0                3               "11"
3     "11"           0                2               "10"
4     "10"           1                1               "1"

- 4번의 이진 변환을 하는 동안 1개의 0을 제거했으므로, [4,1]을 return 해야 합니다.

*/
