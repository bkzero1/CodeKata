#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s, string skip, int index) {
	//string answer = "";

	// 각 알파벳이 건너뛸 문자인지 바로 확인할 수 있도록 미리 표시
	std::vector<bool> skipTable(26, false);
	for (char ch : skip)
	{
		skipTable[ch - 'a'] = true;
	}

	// 문자열의 각 문자를 알파벳 인덱스로 변환해 한 글자씩 이동
	for (int characterIndex = 0; characterIndex < s.size(); ++characterIndex)
	{
		int alphabetIndex = s[characterIndex] - 'a';
		int remainingMoveCount = index;

		// skip 문자는 위치만 지나가고 실제 이동 횟수에서는 제외
		while (remainingMoveCount > 0)
		{
			alphabetIndex = (alphabetIndex + 1) % 26;

			if (skipTable[alphabetIndex])
			{
				continue;
			}

			--remainingMoveCount;
		}

		// 최종 알파벳 인덱스를 다시 문자로 변환해 결과에 추가
		s[characterIndex] = 'a' + alphabetIndex;
		//answer.push_back(s[characterIndex]);
	}
	return s;
}

// 입력과 기대값, 실제값을 한 줄에서 비교합니다.
void Test(const string& name, const string& s, const string& skip,
	int index, const string& expected)
{
	const string actual = solution(s, skip, index);
	const bool success = actual == expected;
	cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
		<< "\x1b[0m | " << name
		<< " | input: s = \"" << s << "\", skip = \"" << skip
		<< "\", index = " << index
		<< " | expected: " << '"' << expected << '"' << " | actual: " << '"' << actual << '"' << '\n';
}

int main()
{
	// 공식 예제
	Test("official example 1", "aukks", "wbqd", 5, "happy");

	// 추가 검증 사례
	Test("additional case 1", "abcde", "z", 1, "bcdef");
	Test("additional case 2", "vwxyz", "a", 1, "wxyzb");
	Test("additional case 3", "aaaaa", "bcdefghijk", 1, "lllll");
	Test("additional case 4", "zzzzz", "abcdefghij", 20, "nnnnn");
	Test("additional case 5", string(50, 'a'), "z", 20, string(50, 'u'));
	return 0;
}

/* Q067 둘만의 암호 https://school.programmers.co.kr/learn/courses/30/lessons/155652

문제 설명

두 문자열 s와 skip, 그리고 자연수 index가 주어질 때, 다음 규칙에 따라 문자열을 만들려 합니다. 암호의 규칙은 다음과 같습니다.

- 문자열 s의 각 알파벳을 index만큼 뒤의 알파벳으로 바꿔줍니다.
- index만큼의 뒤의 알파벳이 z를 넘어갈 경우 다시 a로 돌아갑니다.
- skip에 있는 알파벳은 제외하고 건너뜁니다.

예를 들어 s = "aukks", skip = "wbqd", index = 5일 때, a에서 5만큼 뒤에 있는 알파벳은 f지만 [b, c, d, e, f]에서 'b'와 'd'는 skip에 포함되므로 세지 않습니다. 따라서 'b', 'd'를 제외하고 'a'에서 5만큼 뒤에 있는 알파벳은 [c, e, f, g, h] 순서에 의해 'h'가 됩니다. 나머지 "ukks" 또한 위 규칙대로 바꾸면 "appy"가 되며 결과는 "happy"가 됩니다.

두 문자열 s와 skip, 그리고 자연수 index가 매개변수로 주어질 때 위 규칙대로 s를 변환한 결과를 return하도록 solution 함수를 완성해주세요.

제한사항

- 5 ≤ s의 길이 ≤ 50
- 1 ≤ skip의 길이 ≤ 10
- s와 skip은 알파벳 소문자로만 이루어져 있습니다.
  - skip에 포함되는 알파벳은 s에 포함되지 않습니다.
- 1 ≤ index ≤ 20

입출력 예

s         skip      index    result
"aukks"   "wbqd"    5        "happy"

입출력 예 설명

입출력 예 #1
본문 내용과 일치합니다.

*/
