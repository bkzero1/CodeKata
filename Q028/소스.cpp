
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    // 0~9 다 더하면 45임
    int answer = 45;

    for (int number : numbers)
    {
        answer -= number;
    }

    return answer;
}