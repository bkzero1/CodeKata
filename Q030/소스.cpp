#include <iostream>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    int mid = s.size() / 2;

    // 홀수일때
    if (s.size() % 2 == 1)
    {
        answer = s[mid];
    }
    else // 짝수일때
    {
        answer = s[mid - 1];
        answer += s[mid];
    }
    return answer;
}

int main() {
    std::string b = "abcde";
    std::cout << '\n' << "original: " << b << "\tsolution: " << solution(b) << '\n';
    
    b = "qwer";
    std::cout << '\n' << "original: " << b << "\tsolution: " << solution(b) << '\n';
    

    return 0;
}

/* Q30 가운데 글자 가져오기

문제 설명
단어 s의 가운데 글자를 반환하는 함수, solution을 만들어 보세요. 단어의 길이가 짝수라면 가운데 두글자를 반환하면 됩니다.

재한사항
s는 길이가 1 이상, 100이하인 스트링입니다.
입출력 예
s	return
"abcde"	"c"
"qwer"	"we"


*/