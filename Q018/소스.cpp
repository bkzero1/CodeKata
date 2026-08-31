#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
//#include <string>
// 
// 파라미터로 주어지는 문자열은 const로 주어집니다. 변경하려면 문자열을 복사해서 사용하세요.
int solution(const char* s) {
    //return std::stoi(s);

    int answer = 0;
    int sign = 1;
    int startIndex = 0;

    // 포인터 만들기 -> s로 바로 접근해도 됨, write가 아니기 때문
    // s[0]가 부호인지 아닌지 확인하기 아닐 경우 인덱트를 s[1] 부터 시작 부호가 -일 경우 기억해둘것
    // s[0]이 '+' 인지 '-' 확인해서 -일 경우 -1 값을 저장해둠
    if (s[0] == '-')
    {
        sign = -1;
        startIndex = 1;
    }
    else if (s[0] == '+')
    {
        startIndex = 1;
    }
    for (int i = 0 + startIndex; s[i] != '\0'; i++) // for문으로 해당 숫자를 '0'(아스키코드 만큼 빼기 위해) 을 뺌
    {
        // 반복 할 때마다 기존의 숫자를 *10 하고 현재 숫자를 더함
        answer *= 10;   // 자릿수 올림
        answer += (s[i] - '0'); // 현재 수 더함
        //std::cout << "answer : " << answer << "\t s[i] : " << s[i] << '\n';
    }
    
    // 마지막에 부호를 붙여서 -일 경우에는 -1을 곱해서 반환
    return answer *= sign;
}

int main() {
    
    std::cout << solution("-1234") << '\n';

    return 0;
}

/* 문제 설명
문자열 s를 숫자로 변환한 결과를 반환하는 함수, solution을 완성하세요.

제한 조건
s의 길이는 1 이상 5이하입니다.
s의 맨앞에는 부호(+, -)가 올 수 있습니다.
s는 부호와 숫자로만 이루어져있습니다.
s는 "0"으로 시작하지 않습니다.
입출력 예
예를들어 str이 "1234"이면 1234를 반환하고, "-1234"이면 -1234를 반환하면 됩니다.
str은 부호(+,-)와 숫자로만 구성되어 있고, 잘못된 값이 입력되는 경우는 없습니다.
*/