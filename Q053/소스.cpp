#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(int k, vector<int> score) {
	vector<int> answer;
	std::multiset<int> hallOfFame;

	for (int num : score)
	{
		if (hallOfFame.size() < k)
		{
			hallOfFame.insert(num);
		}
		else if (num > *hallOfFame.begin())	// 현재 커트라인보다 높은 점수라면
		{
			// 점수 추가
			hallOfFame.insert(num);	

			// 기존 최저 점수를 제거하여 상위 k개의 점수만 유지
			hallOfFame.erase(hallOfFame.begin());
			
		}
		// 오늘 점수를 반영한 명예의 전당에서 현재 최저 점수를 기록
		answer.push_back(*hallOfFame.begin());
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
		{
			cout << ", ";
		}

		cout << values[i];
	}

	cout << ']';
}

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, int k, const vector<int>& score, const vector<int>& expected)
{
	vector<int> actual = solution(k, score);
	bool success = actual == expected;

	cout << (success ? "\x1b[38;2;120;230;102m" : "\x1b[38;2;230;102;102m");
	cout << (success ? " SUCCESS" : "  FAIL  ");
	cout << "\x1b[0m";
	cout << " | " << testName << " | input: k=" << k << ", score=";
	PrintVector(score);
	cout << " | expected: ";
	PrintVector(expected);
	cout << " | actual: ";
	PrintVector(actual);
	cout << '\n';
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
	// 공식 예제 테스트
	Test("official example 1", 3, { 10, 100, 20, 150, 1, 100, 200 }, { 10, 10, 10, 20, 20, 100, 100 });
	Test("official example 2", 4, { 0, 300, 40, 300, 20, 70, 150, 50, 500, 1000 }, { 0, 0, 0, 0, 20, 40, 70, 70, 150, 300 });

	// 추가 경계 테스트
	Test("same scores", 3, { 50, 50, 50, 50, 50, 50, 50 }, { 50, 50, 50, 50, 50, 50, 50 });
	Test("cutoff changes", 3, { 100, 90, 80, 70, 110, 60, 95 }, { 100, 90, 80, 80, 90, 90, 95 });
	Test("all zero", 3, { 0, 0, 0, 0, 0, 0, 0 }, { 0, 0, 0, 0, 0, 0, 0 });

	return 0;
}

/* Q053 명예의 전당 (1) https://school.programmers.co.kr/learn/courses/30/lessons/138477

문제 설명
"명예의 전당"이라는 TV 프로그램에서는 매일 1명의 가수가 노래를 부르고, 시청자들의 문자 투표수로 가수에게 점수를 부여합니다. 매일 출연한 가수의 점수가 지금까지 출연 가수들의 점수 중 상위 k번째 이내이면 해당 가수의 점수를 명예의 전당이라는 목록에 올려 기념합니다.

프로그램 시작 이후 초기 k일까지는 모든 출연 가수의 점수가 명예의 전당에 오르게 됩니다. k일 다음부터는 출연 가수의 점수가 기존 명예의 전당 목록의 k번째 순위보다 더 높으면 새 점수가 올라가고, 기존 k번째 순위의 점수는 내려옵니다.

이 프로그램에서는 매일 명예의 전당의 최하위 점수를 발표합니다. 명예의 전당 목록의 점수 개수 k와 1일부터 마지막 날까지 출연한 가수들의 점수 score가 주어질 때, 매일 발표된 명예의 전당의 최하위 점수를 return하도록 solution 함수를 완성해주세요.

제한사항
- 3 <= k <= 100
- 7 <= score의 길이 <= 1,000
- 0 <= score[i] <= 2,000

입출력 예
k  score                                      result
3  [10, 100, 20, 150, 1, 100, 200]           [10, 10, 10, 20, 20, 100, 100]
4  [0, 300, 40, 300, 20, 70, 150, 50, 500, 1000]  [0, 0, 0, 0, 20, 40, 70, 70, 150, 300]

입출력 예 설명
입출력 예 #1
- 문제의 예시와 같습니다.

입출력 예 #2
- [0, 0, 0, 0, 20, 40, 70, 70, 150, 300]을 return합니다.

*/
