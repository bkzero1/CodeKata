#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

long long solution(int a, int b) {
    long long answer = 0;   // 두 수 사이의 합은 int 범위를 넘을 수 있으므로 long long 사용

    if(a > b) // a가 크면 순서 바꿈 -> ab 대소의 구분 없이 공식의 일반화를 위해
    {
        int temp = a;
        a = b;
        b = temp;
    }
    answer = 1LL * (a + b) * (b - a + 1) / 2;           // 등차수열의 합 공식 (first + last) × n / 2 -> n은 항의 개수
    // 1LL을 먼저 곱해서 숫자를 long long 으로 변환하거나  // 등차수열의 합 = 항의 개수 × 양 끝값의 평균
     
    // 아니면 gpt 답변으로
    /*
    곱셈 전에 먼저 2로 나누는 방법도 있음.
    둘 중 하나는 반드시 짝수
        (a + b)가 짝수이거나,
        (항의 개수)가 짝수
    짝수인 쪽을 먼저 2로 나눈 뒤 곱할 수 있음.

    if ((a + b) % 2 == 0)
        result = ((a + b) / 2) * count;
    else
        result = (count / 2) * (a + b);
    
    다만 중간 계산을 줄이는 방법일 뿐,
    최종 결과가 int 범위를 넘을 수 있으므로 결과 자료형은 long long을 사용해야 함.
    */
     
    // 가장 기본적인 풀이 
    //for (int i = a; i <= b; ++i)
    //{
    //    answer += i;
    //}
    return answer;
}


int main() {

    std::cout << "\n" << "solution: " << solution(5, -2) << '\n';

    return 0;
}

/* Q22 두 정수 사이의 합

문제 설명
두 정수 a, b가 주어졌을 때 a와 b 사이에 속한 모든 정수의 합을 리턴하는 함수, solution을 완성하세요.
예를 들어 a = 3, b = 5인 경우, 3 + 4 + 5 = 12이므로 12를 리턴합니다.

제한 조건
a와 b가 같은 경우는 둘 중 아무 수나 리턴하세요.
a와 b는 -10,000,000 이상 10,000,000 이하인 정수입니다.
a와 b의 대소관계는 정해져있지 않습니다.
입출력 예
a	b	return
3	5	12
3	3	3
5	3	12

*/