#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <vector>
#include <iostream>
using namespace std;

bool isPrime(int num)
{
	// 이번 문제에서는 세 자연수의 합이 최소 6이므로 필요 없지만,
	// 일반적인 소수 판별 함수로 사용할 수 있도록 2 미만의 수를 제외
	if (num < 2)
	{
		return false;
	}

	for (int i = 2; i * i <= num; ++i)
	{
		if (num % i == 0)
		{
			return false;
		}
	}

	return true;
}

int solution(vector<int> nums) {
	int answer = 0;

	for (int i = 0; i + 2 < nums.size(); ++i)
	{
		for (int j = i + 1; j + 1 < nums.size(); ++j)
		{
			for (int k = j + 1; k < nums.size(); ++k)
			{
				int sum = nums[i] + nums[j] + nums[k];
				answer += isPrime(sum);
			}
		}
	}
	return answer;
}

void PrintVector(const vector<int>& values)
{
	cout << "[";

	for (int i = 0; i < values.size(); ++i)
	{
		if (i > 0)
		{
			cout << ", ";
		}

		cout << values[i];
	}

	cout << "]";
}

void Test(const string& name, const vector<int>& nums, int expected)
{
	const int actual = solution(nums);
	const bool success = actual == expected;

	cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
		<< "\x1b[0m | " << name << " | input: nums = ";
	PrintVector(nums);
	cout << " | expected: " << expected
		<< " | actual: " << actual << '\n';
}

int main()
{
	Test("official example 1", { 1, 2, 3, 4 }, 1);
	Test("official example 2", { 1, 2, 7, 6, 4 }, 4);

	Test("minimum input with a prime sum", { 1, 2, 4 }, 1);
	Test("minimum input with a composite sum", { 1, 2, 3 }, 0);
	Test("all combinations are prime", { 1, 3, 7, 9 }, 4);
	Test("larger values with no prime sum", { 990, 992, 994, 996, 998 }, 0);

	return 0;
}

/* Q058 소수 만들기 https://school.programmers.co.kr/learn/courses/30/lessons/12977

문제 설명

주어진 숫자 중 3개의 수를 더했을 때 소수가 되는 경우의 개수를 구하려고 합니다.
숫자들이 들어있는 배열 nums가 매개변수로 주어질 때, nums에 있는 숫자들 중 서로 다른
3개를 골라 더했을 때 소수가 되는 경우의 개수를 return 하도록 solution 함수를 완성해주세요.

제한사항

- nums에 들어있는 숫자의 개수는 3개 이상 50개 이하입니다.
- nums의 각 원소는 1 이상 1,000 이하의 자연수이며, 중복된 숫자가 들어있지 않습니다.

입출력 예

nums              result
[1,2,3,4]         1
[1,2,7,6,4]       4

입출력 예 설명

입출력 예 #1
[1,2,4]를 이용해서 7을 만들 수 있습니다.

입출력 예 #2
[1,2,4]를 이용해서 7을 만들 수 있습니다.
[1,4,6]을 이용해서 11을 만들 수 있습니다.
[2,4,7]을 이용해서 13을 만들 수 있습니다.
[4,6,7]을 이용해서 17을 만들 수 있습니다.
*/
