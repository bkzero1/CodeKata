#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> arr) {
    // 배열 길이가 1일땐 그냥 리턴
    if (arr.size() == 1)
    {
        arr[0] = -1;
        return arr;
    }

    int minIndex = 0;
    for (int i = 1; i < arr.size(); ++i)
    {
        // 여기서 가장 작은 인덱스를 찾고 for문 밖에서 제거
        if (arr[i] < arr[minIndex])
        {
            minIndex = i;
        }
    }
    std::cout << "minIndex: " << minIndex << endl;

    arr.erase(arr.begin() + minIndex);

    return arr;
}

int main() {
    std::vector<int> b = { 1, 2, 4, 5, 3, 0, 1 };
    //std::cout << '\n' << "original: " << b << "\tsolution: " << solution(b) << '\n';

    vector<int> result = solution(b);
    for (int number : result)
    {
        std::cout << number << " ";
    }

    return 0;
}

/* Q29 제일 작은 수 제거하기

문제 설명
정수를 저장한 배열, arr 에서 가장 작은 수를 제거한 배열을 리턴하는 함수, solution을 완성해주세요. 단, 리턴하려는 배열이 빈 배열인 경우엔 배열에 -1을 채워 리턴하세요. 예를들어 arr이 [4,3,2,1]인 경우는 [4,3,2]를 리턴 하고, [10]면 [-1]을 리턴 합니다.

제한 조건
arr은 길이 1 이상인 배열입니다.
인덱스 i, j에 대해 i ≠ j이면 arr[i] ≠ arr[j] 입니다.
입출력 예
arr	return
[4,3,2,1]	[4,3,2]
[10]	[-1]


*/