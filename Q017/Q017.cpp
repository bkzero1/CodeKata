// 아직 작성중
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int* solution(long long n) {
    // 리턴할 값은 메모리를 동적 할당해주세요.
    long long temp = n; // 자릿수 구하는 용도
    // 배열 하나 만들고 % 10 으로 마지막 자릿수 저장
    int sizeofarray = 0;

    while (temp) // 먼저 자릿수만 구하고
    {
        // temp %= 10;  // 일단 1의자릿수 저장
        temp /= 10;
        sizeofarray++;
    }
    //cout << sizeofarray << endl;
    // 동적 할당 하고
    int* answer = new int[sizeofarray];
    for (int i = 0; i < sizeofarray; i++)
    {
        answer[i] = n % 10;
        n /= 10;
        cout << answer[i] << endl;
    }
        

    //cout << sizeof(arr) / sizeof(arr[0]) << endl; // 포인터니까 2가 나옴


    // 다시 구한 자릿수만큼 반복해서 저장할것 -> 저장 끝나면 배열 뒤집을것 -> 안뒤집어도 됨

    //int* answer = (int*)malloc(sizeofarray * sizeof(int));   // 배열의 자료형 크기만큼 곱함
    // 값을 복사해서 넣을것
    
    // int* answer = (int*)malloc(...); // 원본

    return answer;   // 임시 배열 주소 전달 은 하면 안될듯 나가면 없어져서
}

int main() {
    solution(12345);
    return 0;
}