#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> answers) {
	std::vector<int> answer;
	const std::vector<std::vector<int>> answerPatterns = {
		{1, 2, 3, 4, 5},
		{2, 1, 2, 3, 2, 4, 2, 5},
		{3, 3, 1, 1, 2, 2, 4, 4, 5, 5}
	};
	
	std::vector<int> correctCounts(answerPatterns.size(), 0);

	for (int questionIndex = 0; questionIndex < answers.size(); ++questionIndex)
	{
		for (int studentIndex = 0; studentIndex < answerPatterns.size(); ++studentIndex)
		{
			const std::vector<int>& studentPattern = answerPatterns[studentIndex];

			if (studentPattern[questionIndex % studentPattern.size()] == answers[questionIndex])
			{
				++correctCounts[studentIndex];
			}
		}
	}

	auto maxCountItr = std::max_element(correctCounts.begin(), correctCounts.end());

	for (int i = 0; i < correctCounts.size(); ++i)
	{
		if (*maxCountItr == correctCounts[i])
		{
			answer.push_back(i + 1);
		}
	}

	return answer;
}

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

void Test(const string& name, const vector<int>& answers, const vector<int>& expected)
{
	const vector<int> actual = solution(answers);
	const bool success = actual == expected;

	cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
		<< "\x1b[0m | " << name << " | input: answers = ";
	PrintVector(answers);
	cout << " | expected: ";
	PrintVector(expected);
	cout << " | actual: ";
	PrintVector(actual);
	cout << '\n';
}

int main()
{
	Test("official example 1", { 1, 2, 3, 4, 5 }, { 1 });
	Test("official example 2", { 1, 3, 2, 4, 2 }, { 1, 2, 3 });

	Test("one question - first student", { 1 }, { 1 });
	Test("one question - second student", { 2 }, { 2 });
	Test("one question - third student", { 3 }, { 3 });
	Test("one question - nobody correct", { 4 }, { 1, 2, 3 });

	return 0;
}

/* Q057 모의고사 https://school.programmers.co.kr/learn/courses/30/lessons/42840

문제 설명

수포자는 수학을 포기한 사람의 준말입니다. 수포자 삼인방은 모의고사에 수학 문제를 전부 찍으려 합니다. 수포자는 1번 문제부터 마지막 문제까지 다음과 같이 찍습니다.

- 1번 수포자가 찍는 방식: 1, 2, 3, 4, 5, 1, 2, 3, 4, 5, ...
- 2번 수포자가 찍는 방식: 2, 1, 2, 3, 2, 4, 2, 5, 2, 1, 2, 3, 2, 4, 2, 5, ...
- 3번 수포자가 찍는 방식: 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, 3, 3, 1, 1, 2, 2, 4, 4, 5, 5, ...

1번 문제부터 마지막 문제까지의 정답이 순서대로 들은 배열 answers가 주어졌을 때, 가장 많은 문제를 맞힌 사람이 누구인지 배열에 담아 return 하도록 solution 함수를 작성해주세요.

제한 조건

- 시험은 최대 10,000 문제로 구성되어있습니다.
- 문제의 정답은 1, 2, 3, 4, 5중 하나입니다.
- 가장 높은 점수를 받은 사람이 여럿일 경우, return하는 값을 오름차순 정렬해주세요.

입출력 예

answers       return
[1,2,3,4,5]   [1]
[1,3,2,4,2]   [1,2,3]

입출력 예 설명

입출력 예 #1

- 수포자 1은 모든 문제를 맞혔습니다.
- 수포자 2는 모든 문제를 틀렸습니다.
- 수포자 3은 모든 문제를 틀렸습니다.

따라서 가장 문제를 많이 맞힌 사람은 수포자 1입니다.

입출력 예 #2

- 모든 사람이 2문제씩을 맞췄습니다.

*/
