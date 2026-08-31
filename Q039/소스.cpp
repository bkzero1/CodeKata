#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <numeric>  // std::gcd, std::lcm

using namespace std;

vector<int> solution(int n, int m) {
    
    return { std::gcd(n, m), std::lcm(n, m) };

    /*vector<int> answer;

    // stl
    answer.push_back(std::gcd(n, m));
    answer.push_back(std::lcm(n, m));

    return answer;*/

    /* 직접 구현
    // 유클리드 호제법을 이용한 최대공약수
    if (n < m)  // n을 큰 수로 만듦
    {
        int temp = n;
        n = m;
        m = temp;
    }

    // gcd(a, b) = gcd(b, r)
    int a = n;
    int b = m;

    // 큰 수를 작은 수로 나누며, 나머지가 0이 될 때 b가 최대공약수
    while (a % b != 0)
    {
        int r = a % b; // remainder
        a = b;
        b = r;
    }

    int gcd = b;
    answer.push_back(gcd);
    
    // 최대공약수를 이용한 최소공배수
    answer.push_back(1LL * n * m / gcd);

    return answer;
    */
}

void PrintVector(const vector<int>& v)
{
    cout << "[";

    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i];

        if (i + 1 < v.size())
        {
            cout << ", ";
        }
    }

    cout << "]";
}

void Test(int n, int m, const vector<int>& expected)
{
    const char* SUCCESS_COLOR = "\033[38;2;120;230;102m"; // #78E666
    const char* FAIL_COLOR = "\033[38;2;230;102;102m";    // #E66666
    const char* RESET_COLOR = "\033[0m";

    vector<int> result = solution(n, m);
    bool success = (result == expected);

    cout << "n: " << n
        << ", m: " << m
        << " | Expected: ";

    PrintVector(expected);

    cout << " | Result: ";

    PrintVector(result);

    cout << " | "
        << (success ? SUCCESS_COLOR : FAIL_COLOR)
        << (success ? "SUCCESS" : "FAIL")
        << RESET_COLOR << '\n';
}

int main()
{
    Test(48, 18, { 6, 144 });
    Test(4, 6, { 2, 12 });
    Test(4, 6, { 2, 12 });
    Test(3, 12, { 3, 12 });                // 문제 예제
    Test(2, 5, { 1, 10 });                 // 문제 예제
    Test(10, 10, { 10, 10 });              // 같은 수
    Test(1, 7, { 1, 7 });                  // 한쪽이 1
    Test(9, 1, { 1, 9 });                  // 한쪽이 1
    Test(4, 20, { 4, 20 });                // 한 수가 다른 수의 배수
    Test(8, 15, { 1, 120 });               // 서로소
    Test(12, 3, { 3, 12 });                // 입력 순서 반대
    Test(1000000, 1000000,
        { 1000000, 1000000 });            // 제한사항 최대값

    return 0;
}

/* Q39 최대공약수와 최소공배수

문제 설명
두 수를 입력받아 두 수의 최대공약수와 최소공배수를 반환하는 함수, solution을 완성해 보세요.
배열의 맨 앞에 최대공약수, 그다음 최소공배수를 넣어 반환하면 됩니다.
예를 들어 두 수 3, 12의 최대공약수는 3, 최소공배수는 12이므로 solution(3, 12)는 [3, 12]를 반환해야 합니다.

제한 사항
두 수는 1이상 1000000이하의 자연수입니다.

입출력 예
n	m	return
3	12	[3, 12]
2	5	[1, 10]

입출력 예 설명
입출력 예 #1
위의 설명과 같습니다.

입출력 예 #2
자연수 2와 5의 최대공약수는 1, 최소공배수는 10이므로 [1, 10]을 리턴해야 합니다.

*/