#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;
int GetDivisorCount(int number);

int solution(int left, int right) {
    int answer = 0;
    for (int i = left; i <= right; ++i)
    {
        if (GetDivisorCount(i) % 2 == 0) // 짝수일때 더하고
            answer += i;
        else
            answer -= i;
    }
    return answer;
}

#include <cmath>

using namespace std;

// gpt 풀이 - 홀짝만 구할거라면 제곱수 = 홀수, 아닐 때 = 짝수임을 이용한 풀이
//int solution(int left, int right)
//{
//    int answer = 0;
//
//    for (int number = left; number <= right; ++number)
//    {
//        int root = sqrt(number);
//
//        if (root * root == number)
//        {
//            answer -= number;
//        }
//        else
//        {
//            answer += number;
//        }
//    }
//
//    return answer;
//}
int GetDivisorCount(int number)
{
    int count = 0;

    for (int i = 1; i * i <= number; ++i)
    {
        if (number % i == 0)
        {
            if (i * i == number)
                ++count;    // 제곱수일땐 +1
            else
                count += 2; // 약수 쌍이므로 +2
        }
    }
    
    return count;
}

int main() {
    std::vector<int> a = { 24, -3 };
    std::vector<int> b = { 27, 9 };
    std::cout << '\n' << "original: " << "b" << "\tsolution: " << solution(a[0], b[0]) << '\n';

    std::cout << '\n' << "original: " << "b" << "\tsolution: " << solution(a[0], b[0]) << '\n';


    return 0;
}

/* Q33 약수의 개수와 덧셈

문제 설명
두 정수 left와 right가 매개변수로 주어집니다.
left부터 right까지의 모든 수들 중에서, 약수의 개수가 짝수인 수는 더하고, 약수의 개수가 홀수인 수는 뺀 수를 return 하도록 

solution 함수를 완성해주세요.

제한사항
1 ≤ left ≤ right ≤ 1,000
입출력 예
left	right	result
13	17	43
24	27	52
입출력 예 설명
입출력 예 #1

다음 표는 13부터 17까지의 수들의 약수를 모두 나타낸 것입니다.
수	약수	약수의 개수
13	1, 13	2
14	1, 2, 7, 14	4
15	1, 3, 5, 15	4
16	1, 2, 4, 8, 16	5
17	1, 17	2
따라서, 13 + 14 + 15 - 16 + 17 = 43을 return 해야 합니다.
입출력 예 #2

다음 표는 24부터 27까지의 수들의 약수를 모두 나타낸 것입니다.
수	약수	약수의 개수
24	1, 2, 3, 4, 6, 8, 12, 24	8
25	1, 5, 25	3
26	1, 2, 13, 26	4
27	1, 3, 9, 27	4
따라서, 24 - 25 + 26 + 27 = 52를 return 해야 합니다.

*/