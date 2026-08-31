#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";

    for (size_t i = 0; i < seoul.size(); ++i)
    {
        if (seoul[i] == "Kim")
        {
            return answer = "김서방은 " + std::to_string(i) + "에 있다";
            //break;
        }
    }
    //int index = 0;

    //for (const std::string& item : seoul)
    //{
    //    //std::cout << item << std::endl;
    //    if (item == "Kim")
    //    {
    //        break;
    //    }
    //    ++index;
    //}
    //answer = "김서방은 " + std::to_string(index) + "에 있다";
    return answer;  // for문에서 못찾았을때를 대비해서 기본 return 필요
}


int main() {
    std::vector<std::string> seoul = { "Jane", "Kim" };
    std::cout << "\n" << "solution: " << solution(seoul) << '\n';
    

    return 0;
}

/* Q24 서울에서 김서방 찾기

문제 설명
String형 배열 seoul의 element중 "Kim"의 위치 x를 찾아, "김서방은 x에 있다"는 String을 반환하는 함수, solution을 완성하세요. 
seoul에 "Kim"은 오직 한 번만 나타나며 잘못된 값이 입력되는 경우는 없습니다.

제한 사항
seoul은 길이 1 이상, 1000 이하인 배열입니다.
seoul의 원소는 길이 1 이상, 20 이하인 문자열입니다.
"Kim"은 반드시 seoul 안에 포함되어 있습니다.
입출력 예
seoul	return
["Jane", "Kim"]	"김서방은 1에 있다"


*/