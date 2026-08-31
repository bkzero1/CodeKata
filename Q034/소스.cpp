#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//// 템플릿 함수는 선언+구현까지 보통 마침
//template <typename T>
//void Swap(T& a, T& b)
//{
//    T temp = a;
//    a = b;
//    b = temp;
//}

// sort 함수 사용 시 오름차순을 결정하기 위한 함수
bool descending(int a, int b) {
    return a > b;
}
string solution(string s) {
    string answer = s;

    std::sort(answer.begin(), answer.end(), descending);
    // // 바깥쪽 반복문, 교환이 일어났는지 체크하는 변수 하나 필요
    //for (int i = 0; i < answer.size() - 1; ++i)
    //{
    //    bool isSwap = false;

    //    // 안쪽 반복문, 인접한 원소 하나 대소를 통해 교환
    //    for (int j = 0; j + 1 < answer.size() - i; ++j)
    //    {
    //        if (answer[j] < answer[j + 1])    // 뒤의 원소가 크면 순서 교환
    //        {
    //            Swap(answer[j], answer[j + 1]);
    //            //char temp = answer[j];
    //            //answer[j] = answer[j + 1];
    //            //answer[j + 1] = temp;

    //            isSwap = true;
    //        }
    //    }
    //    if (!isSwap)
    //    {
    //        break;
    //    }
    //}
    return answer;
}

int main() {
    std::string a = "Zbcdefg";
    std::cout << '\n' << "original: " << a << "\tsolution: " << solution(a) << '\n';



    return 0;
}

/* Q34 문자열 내림차순으로 배치하기

문제 설명
문자열 s에 나타나는 문자를 큰것부터 작은 순으로 정렬해 새로운 문자열을 리턴하는 함수, solution을 완성해주세요.
s는 영문 대소문자로만 구성되어 있으며, 대문자는 소문자보다 작은 것으로 간주합니다.

제한 사항
str은 길이 1 이상인 문자열입니다.
입출력 예
s	return
"Zbcdefg"	"gfedcbZ"

*/