#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//bool compare(const string& s1, const string& s2, int n)
//{
//    bool bIsFirst = false;
//
//    // 인덱스 기준 1차 사전순 정렬
//        // 같을 때 2차 사전순 정렬
//
//    return bIsFirst;
//}

vector<string> solution(vector<string> strings, int n) {
	vector<string> answer = strings;
	
	// n번째 문자를 비교 기준으로 사용하기 위해 n을 값으로 캡처
	auto compare = [n](const string& s1, const string& s2)
		{
			if (s1[n] == s2[n])	// n번째 문자가 같으면 전체 문자열을 사전순 비교
			{
				return s1 < s2;
			}
			else // n번째 문자가 다르면 해당 문자끼리 비교
			{
				return s1[n] < s2[n];
			}
		};

	std::sort(answer.begin(), answer.end(), compare);
	return answer;
}

void PrintVector(const vector<string>& values)
{
	cout << "[";

	for (int i = 0; i < values.size(); ++i)
	{
		if (i > 0)
		{
			cout << ", ";
		}

		cout << '"' << values[i] << '"';
	}

	cout << "]";
}

void Test(const vector<string>& strings, int n, const vector<string>& expected)
{
	const char* SUCCESS_COLOR = "\033[38;2;120;230;102m";
	const char* FAIL_COLOR = "\033[38;2;230;102;102m";
	const char* RESET_COLOR = "\033[0m";

	vector<string> result = solution(strings, n);
	bool success = (result == expected);

	// 성공 여부를 줄의 맨 앞에 고정해서 테스트 결과를 빠르게 훑어봄
	cout << (success ? SUCCESS_COLOR : FAIL_COLOR)
		<< (success ? " SUCCESS" : "  FAIL  ")
		<< RESET_COLOR
		<< " | strings: ";
	PrintVector(strings);
	cout << " | n: " << n << " | Expected: ";
	PrintVector(expected);
	cout << " | Result: ";
	PrintVector(result);
	cout << '\n';
}

int main()
{
	// 공식 예제
	Test({ "sun", "bed", "car" }, 1, { "car", "bed", "sun" });
	Test({ "abce", "abcd", "cdx" }, 2, { "abcd", "abce", "cdx" });

	// 추가 경계 테스트
	Test({ "a" }, 0, { "a" });
	Test({ "ba", "ab", "aa" }, 0, { "aa", "ab", "ba" });
	Test({ "za", "aa", "az" }, 1, { "aa", "za", "az" });

	return 0;
}

/* Q047 문자열 내 마음대로 정렬하기 https://school.programmers.co.kr/learn/courses/30/lessons/12915

문제 설명
문자열로 구성된 리스트 strings와, 정수 n이 주어졌을 때, 각 문자열의 인덱스 n번째 글자를 기준으로 오름차순 정렬하려 합니다. 예를 들어 strings가 ["sun", "bed", "car"]이고 n이 1이면 각 단어의 인덱스 1의 문자 "u", "e", "a"로 strings를 정렬합니다.

제한 조건
- strings는 길이 1 이상, 50이하인 배열입니다.
- strings의 원소는 소문자 알파벳으로 이루어져 있습니다.
- strings의 원소는 길이 1 이상, 100이하인 문자열입니다.
- 모든 strings의 원소의 길이는 n보다 큽니다.
- 인덱스 n의 문자가 같은 문자열이 여럿일 경우, 사전순으로 앞선 문자열이 앞쪽에 위치합니다.

입출력 예
strings                       n  return
["sun", "bed", "car"]       1  ["car", "bed", "sun"]
["abce", "abcd", "cdx"]    2  ["abcd", "abce", "cdx"]

입출력 예 설명
입출력 예 1
- "sun", "bed", "car"의 1번째 인덱스 값은 각각 "u", "e", "a"입니다. 이를 기준으로 strings를 정렬하면 ["car", "bed", "sun"]입니다.

입출력 예 2
- "abce"와 "abcd", "cdx"의 2번째 인덱스 값은 "c", "c", "x"입니다. 따라서 정렬 후에는 "cdx"가 가장 뒤에 위치합니다. "abce"와 "abcd"는 사전순으로 정렬하면 "abcd"가 우선하므로, 답은 ["abcd", "abce", "cdx"]입니다.
*/
