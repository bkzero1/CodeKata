#include <iostream>
//==========================================================================
//                            ⭐  ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";
    std::vector<int> digitCounts(10, 0);
    // 공통 숫자 벡터에 누적
    // 스트링 하나를 기준을 잡고 해당 스트링의 문자 하나가 X Y에서 몇번 등장하는지 확인 후 적은 값을 등록
    for (int i = 0; i <= 9; ++i)
    {
        const int countX = std::count(X.begin(), X.end(), i + '0');
        const int countY = std::count(Y.begin(), Y.end(), i + '0');
        digitCounts[i] = std::min(countX, countY);
    }
    
    // 벡터 숫자 큰값부터 꺼내서 스트링에 이어붙이기
    for (int i = 9; i >= 0; --i)
    {
        if (digitCounts[i] == 0)
        {
            continue;
        }
        
        answer.append(digitCounts[i], i + '0');
    }

    if (answer.empty())
    {
        return "-1";
    }

    if (!answer.empty() && answer.front() == '0')
    {
        return "0";
    }

    return answer;
}

void Test(const string& name, const string& X, const string& Y, const string& expected)
{
    const string actual = solution(X, Y);
    const bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name
        << " | input: X = \"" << X << "\", Y = \"" << Y << '"'
        << " | expected: " << '"' << expected << '"'
        << " | actual: " << '"' << actual << '"' << '\n';
}

int main()
{
    Test(
        "large common number",
        "99999999999",
        "99999999999",
        "99999999999"
    );
    Test("official example 1", "100", "2345", "-1");
    Test("official example 2", "100", "203045", "0");
    Test("official example 3", "100", "123450", "10");
    Test("official example 4", "12321", "42531", "321");
    Test("official example 5", "5525", "1255", "552");
    Test("same digits in descending result", "987654321", "123456789", "987654321");
    Test("repeated common digits", "111222333", "122233344", "3332221");
    return 0;
}

/* Q063 숫자 짝꿍 https://school.programmers.co.kr/learn/courses/30/lessons/131128

문제 설명

두 정수 X, Y의 임의의 자리에서 공통으로 나타나는 정수 k(0 ≤ k ≤ 9)들을 이용하여 만들 수 있는 가장 큰 정수를 두 수의 짝꿍이라 합니다(단, 공통으로 나타나는 정수 중 서로 짝지을 수 있는 숫자만 사용합니다). X, Y의 짝꿍이 존재하지 않으면, 짝꿍은 -1입니다. X, Y의 짝꿍이 0으로만 구성되어 있다면, 짝꿍은 0입니다.

예를 들어, X = 3403이고 Y = 13203이라면, X와 Y의 짝꿍은 X와 Y에서 공통으로 나타나는 3, 0, 3으로 만들 수 있는 가장 큰 정수인 330입니다. 다른 예시로 X = 5525이고 Y = 1255이면 X와 Y의 짝꿍은 X와 Y에서 공통으로 나타나는 2, 5, 5로 만들 수 있는 가장 큰 정수인 552입니다(X에는 5가 3개, Y에는 5가 2개 나타나므로 남는 5 한 개는 짝 지을 수 없습니다).

두 정수 X, Y가 주어졌을 때, X, Y의 짝꿍을 return하는 solution 함수를 완성해주세요.

제한사항

- 3 ≤ X, Y의 길이(자릿수) ≤ 3,000,000입니다.
- X, Y는 0으로 시작하지 않습니다.
- X, Y의 짝꿍은 상당히 큰 정수일 수 있으므로, 문자열로 반환합니다.

입출력 예

X       Y         result
"100"   "2345"    "-1"
"100"   "203045"  "0"
"100"   "123450"  "10"
"12321" "42531"   "321"
"5525"  "1255"    "552"

입출력 예 설명

입출력 예 #1

- X, Y의 짝꿍은 존재하지 않습니다. 따라서 "-1"을 return합니다.

입출력 예 #2

- X, Y의 공통된 숫자는 0으로만 구성되어 있기 때문에, 두 수의 짝꿍은 정수 0입니다. 따라서 "0"을 return합니다.

입출력 예 #3

- X, Y의 짝꿍은 10이므로, "10"을 return합니다.

입출력 예 #4

- X, Y의 짝꿍은 321입니다. 따라서 "321"을 return합니다.

입출력 예 #5

- 지문에 설명된 예시와 같습니다.

*/
