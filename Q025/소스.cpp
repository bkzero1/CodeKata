#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;
bool Compare(const int& a, const int& b);

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    // 원소 일단 나눠지는거만 담고
    for (int arrTemp : arr) {
        if (arrTemp % divisor == 0) // disisor가 1이면 어차피 나누면 나머지 0
        {
            answer.push_back(arrTemp);
        }
    }
    if (answer.empty())
        answer.push_back(-1);

    // sort로 정렬
    sort(answer.begin(), answer.end(), Compare);
    //for (int arrTemp : answer) {
    //    std::cout << arrTemp << " ";
    //}
 
    return answer;  // divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.
}
bool Compare(const int& a, const int& b)
{
    return a < b;   // 오름차순. 내림차순은 a > b
}

int main() {
    vector<int> arr = { 2, 36, 1, 3 };
    int divisor = 2;
    //std::cout << '\n' << "solution: " << solution(arr, 2) << '\n';
    std::cout << '\n' << "original: ";
    for (int number : arr)
    {
        std::cout << number << " ";

    }

    std::cout << '\n' << "solution: ";
    vector<int> arr2 = solution(arr, divisor);
    for (int number : arr2)
    {
        std::cout << number << " ";

    }
    std::cout <<"\t divisor: " << divisor;

    return 0;
}

/* Q25 나누어 떨어지는 숫자 배열

array의 각 element 중 divisor로 나누어 떨어지는 값을 오름차순으로 정렬한 배열을 반환하는 함수, solution을 작성해주세요.
divisor로 나누어 떨어지는 element가 하나도 없다면 배열에 -1을 담아 반환하세요.

제한사항
arr은 자연수를 담은 배열입니다.
정수 i, j에 대해 i ≠ j 이면 arr[i] ≠ arr[j] 입니다.
divisor는 자연수입니다.
array는 길이 1 이상인 배열입니다.
입출력 예
arr	divisor	return
[5, 9, 7, 10]	5	[5, 10]
[2, 36, 1, 3]	1	[1, 2, 3, 36]
[3,2,6]	10	[-1]
입출력 예 설명
입출력 예#1
arr의 원소 중 5로 나누어 떨어지는 원소는 5와 10입니다. 따라서 [5, 10]을 리턴합니다.

입출력 예#2
arr의 모든 원소는 1으로 나누어 떨어집니다. 원소를 오름차순으로 정렬해 [1, 2, 3, 36]을 리턴합니다.

입출력 예#3
3, 2, 6은 10으로 나누어 떨어지지 않습니다. 나누어 떨어지는 원소가 없으므로 [-1]을 리턴합니다.


*/