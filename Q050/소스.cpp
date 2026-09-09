#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    std::map<char, int> charPosition;

    for (int i = 0; i < s.size(); ++i)
    {
        char ch = s[i];

        auto findedch = charPosition.find(ch);

        if (findedch != charPosition.end()) // 찾음
        {
            // answer에 거리값을 넣기 위해 저장
            int distance = i - charPosition[ch];
            
            // 마지막 위치로 갱신
            charPosition[ch] = i;
            answer.push_back(distance);

            continue;
        }

        // 처음 만남
        charPosition.insert({ ch, i });
        answer.push_back(-1);
    }

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
void Test(const string& testName, const string& s, const vector<int>& expected)
{
    vector<int> actual = solution(s);
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
    Test("official example 1: banana", "banana", { -1, -1, -1, 2, 2, 2 });
    Test("official example 2: foobar", "foobar", { -1, -1, 1, -1, -1, -1 });

    // 추가 경계 테스트
    Test("one character: a", "a", { -1 });
    Test("all same characters: aaaa", "aaaa", { -1, 1, 1, 1 });
    Test("same character after a gap: abca", "abca", { -1, -1, -1, 3 });
    Test("several repeated characters: abacada", "abacada", { -1, -1, 2, -1, 2, -1, 2 });

    return 0;
}

/* Q050 가장 가까운 같은 글자 https://school.programmers.co.kr/learn/courses/30/lessons/142086

문제 설명
문자열 s가 주어졌을 때, s의 각 위치마다 자신보다 앞에 나왔으면서 자신과 가장 가까운 곳에 있는 같은 글자가 어디 있는지 구합니다.

예를 들어 s = "banana"라면 각 글자를 왼쪽부터 읽으며 다음과 같이 처리합니다.
- 처음 나온 글자는 앞에 같은 글자가 없으므로 -1로 표현합니다.
- 앞에 같은 글자가 있다면 현재 위치와 가장 가까운 같은 글자 사이의 거리를 표현합니다.
- 따라서 결과는 [-1, -1, -1, 2, 2, 2]가 됩니다.

문자열 s가 주어질 때 위 연산의 결과를 담은 배열을 return 하도록 solution 함수를 완성해주세요.

제한사항
- 1 <= s의 길이 <= 10,000
- s는 영어 소문자로만 이루어져 있습니다.

입출력 예
s         result
"banana"  [-1, -1, -1, 2, 2, 2]
"foobar"  [-1, -1, 1, -1, -1, -1]

입출력 예 설명
입출력 예 #1
- 문제 설명과 같습니다.

입출력 예 #2
- 설명 생략

*/
