#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅ 
//==========================================================================

#include <string>
#include <vector>

using namespace std;

long long solution(long long n) {
    long long answer = 0;
    long long remain = n;   // 자릿수 분리에 사용할 작업용 복사본
    int number[10] = {};    // 숫자 기록용
    int count = 0;  // 자릿수 기록용

    //std::cout <<"원본: " << n << std::endl;

    for (int i = 0; i < 10; ++i)
    {
        number[i] = remain % 10;
        //std::cout << number[i] << " ";

        remain /= 10;
        ++count;    // 자릿수 카운트
        
        if (remain == 0)    // 10으로 나눈 숫자가 0이 되면 자릿수 카운트가 끝난것이므로 반복문 종료
            break;

    } // 여기까지 한자리씩 분리해서 저장 완료
    
    //std::cout << std::endl;

    // 인접한 두 원소를 비교하여 큰 숫자가 앞으로 오도록 정렬
    // 근데 언제까지? -> 전체 비교 구간에서 교환이 한 번도 발생하지 않을 때까지
    for (int j = 0; j < count - 1; ++j) // 자릿수 -1만큼 반복
    {
        //static int count = 0;
        //std::cout << "\t\t\tcount: " << count << "/ j: " << j << std::endl;
        bool isSwapped = false;

        // 처음에는 count - 1이 최악이라고 생각했고,
        // 한 번 돌 때마다 뒤쪽 원소 하나가 확정되는 것을 확인해서
        // count - 1 - j로 줄임
        for (int i = 0; i < count - 1 - j; ++i) // 한 회차마다 뒤쪽 원소 하나가 정렬되므로 비교 범위를 줄임
        {
            if (number[i] < number[i + 1])  // 앞 원소가 작으면, 뒤의 원소를 앞 원소와 교체 -> 큰걸 앞으로
            {
                int temp = number[i];   // 앞 원소를 임시저장
                number[i] = number[i + 1];  // 큰 숫자를 앞으로 이동
                number[i + 1] = temp;   // 기존 앞 원소인 작은 숫자를 뒤로 이동

                isSwapped = true;   // 교환이 한번이라도 있었다면 true로 세팅
            }
        }
        if (!isSwapped) // bool 타입은 true / false만 가지므로 !isSwapped도 가능
        {               // 교환이 한번이라도 일어나지 않았으면 정렬이 끝난것이므로 for문 종료
            break;  
        }
        //for (int i = 0; i < 10 - 1; ++i)
        //{
        //    if (number[i] > number[i + 1])  // 앞 원소가 크면
        //    {
        //        int temp = number[i];   // 앞 원소를 임시저장
        //        number[i] = number[i + 1];  // 앞 원소를 뒤 원소로 저장
        //        number[i + 1] = temp;   // 뒤 원소를 앞 원소로 저장
        //    }
        //}
        //for (int i = 0; i < count; ++i)// 확인용
        //{

        //    std::cout << number[i] << " ";
        //}
        //std::cout << std::endl;
    }
    
    //std::cout << std::endl;

    //// 원소 확인용 for
    //for (int i = 0; i < 10; ++i)
    //{
    //    std::cout << number[i] << " ";
    //}
    //std::cout << std::endl;

    //결과 저장 부분
    for (int i = 0; i < count; ++i)
    {
        answer *= 10;
        answer += number[i];
    }
    return answer;
}

int main() {
    /*
    접근방법
    v   10칸 배열 생성 
    v   자릿수(또는 저장 개수)를 나타내는 변수 생성
        %10 으로 한 자리씩 꺼내 배열에 저장
        /10 으로 다음 자릿수로 이동
        여기까지라면 숫자를 한 자리씩 분리해서 저장
    */
    std::cout << "\n" << "solution: " << solution(9823018372) << '\n';

    return 0;
}

/*

문제 설명
함수 solution은 정수 n을 매개변수로 입력받습니다.n의 각 자릿수를 큰것부터 작은 순으로 정렬한 새로운 정수를 리턴해주세요.예를들어 n이 118372면 873211을 리턴하면 됩니다.

제한 조건
n은 1이상 8000000000 이하인 자연수입니다.
입출력 예
n	return
118372	873211

*/