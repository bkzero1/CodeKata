#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    string answer = "";

    // 두 선수에게 동일하게 배분한 음식으로 한쪽 배치를 구성
    for (int i = 1; i < food.size(); ++i)
    {
        // 정수 나눗셈으로 한 선수가 먹을 개수를 계산
        // 홀수로 남는 음식 하나는 나머지와 함께 자연스럽게 제외됨
        food[i] /= 2;

        // 현재 음식 번호를 한쪽에 배치할 개수만큼 이어 붙임
        char foodCharacter = i + '0';

        answer.append(food[i], foodCharacter);
    }
    
    // 반대편 배치를 위해 한쪽 문자열을 역순으로 복사
    string opponentSide(answer.rbegin(), answer.rend());

    // 두 선수 사이에 물을 놓고 반대편 배치를 연결
    //answer.push_back('0');
    //answer.append(opponentSide);
    
    return answer + '0' + opponentSide;
}


//==========================================================================
// 아래 코드는 로컬 실행과 검증을 위해 Codex가 작성한 코드입니다.
// Programmers에서 기본 제공한 코드에는 포함되지 않습니다.
//==========================================================================

// [Codex 작성] vector의 원소를 출력하는 보조 함수
void PrintVector(const vector<int>& values)
{
    cout << '[';

    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0)
            cout << ", ";

        cout << values[i];
    }

    cout << ']';
}

// [Codex 작성] 예상 결과와 실제 결과를 비교하는 테스트 함수
void Test(const string& testName, const vector<int>& food, const string& expected)
{
    string actual = solution(food);
    bool success = actual == expected;

    cout << (success ? "\x1b[38;2;120;230;102m" : "\x1b[38;2;230;102;102m");
    cout << (success ? " SUCCESS" : "  FAIL  ");
    cout << "\x1b[0m";
    cout << " | " << testName << " | input: ";
    PrintVector(food);
    cout << " | expected: \"" << expected
         << "\" | actual: \"" << actual << "\"\n";
}

// [Codex 작성] 준비된 테스트를 실행하는 진입점
int main()
{
    // 공식 예제 테스트
    Test("official example 1", { 1, 3, 4, 6 }, "1223330333221");
    Test("official example 2", { 1, 7, 1, 2 }, "111303111");

    // 추가 경계 테스트
    Test("one food for each player", { 1, 2 }, "101");
    Test("one unused food", { 1, 3 }, "101");
    Test("unused food type", { 1, 1, 2 }, "202");
    Test("several food types", { 1, 2, 2 }, "12021");

    return 0;
}

/* Q051 푸드 파이트 대회 https://school.programmers.co.kr/learn/courses/30/lessons/134240

문제 설명
수웅이는 매달 주어진 음식을 빨리 먹는 푸드 파이트 대회를 개최합니다. 이 대회에서 선수들은 1대 1로 대결하며, 매 대결마다 음식의 종류와 양이 바뀝니다. 대결은 준비된 음식들을 일렬로 배치한 뒤, 한 선수는 제일 왼쪽에 있는 음식부터 오른쪽으로, 다른 선수는 제일 오른쪽에 있는 음식부터 왼쪽으로 순서대로 먹는 방식으로 진행됩니다. 중앙에는 물을 배치하고, 물을 먼저 먹는 선수가 승리하게 됩니다.

이때, 대회의 공정성을 위해 두 선수가 먹는 음식의 종류와 양이 같아야 하며, 음식을 먹는 순서도 같아야 합니다. 또한, 이번 대회부터는 칼로리가 낮은 음식을 먼저 먹을 수 있게 배치하여 선수들이 음식을 더 잘 먹을 수 있게 하려고 합니다. 이번 대회를 위해 수웅이는 음식을 주문했는데, 대회의 조건을 고려하지 않고 음식을 주문하여 몇 개의 음식은 대회에 사용하지 못하게 되었습니다.

예를 들어, 3가지의 음식이 준비되어 있으며, 칼로리가 적은 순서대로 1번 음식을 3개, 2번 음식을 4개, 3번 음식을 6개 준비했으며, 물을 편의상 0번 음식이라고 칭한다면, 두 선수는 1번 음식 1개, 2번 음식 2개, 3번 음식 3개씩을 먹게 되므로 음식의 배치는 "1223330333221"이 됩니다. 따라서 1번 음식 1개는 대회에 사용하지 못합니다.

수웅이가 준비한 음식의 양을 칼로리가 적은 순서대로 나타내는 정수 배열 food가 주어졌을 때, 대회를 위한 음식의 배치를 나타내는 문자열을 return 하는 solution 함수를 완성해주세요.

제한사항
- 2 <= food의 길이 <= 9
- 1 <= food의 각 원소 <= 1,000
- food에는 칼로리가 적은 순서대로 음식의 양이 담겨 있습니다.
- food[i]는 i번 음식의 수입니다.
- food[0]은 수웅이가 준비한 물의 양이며, 항상 1입니다.
- 정답의 길이가 3 이상인 경우만 입력으로 주어집니다.

입출력 예
food          result
[1, 3, 4, 6] "1223330333221"
[1, 7, 1, 2] "111303111"

입출력 예 설명
입출력 예 #1
- 문제 예시와 같습니다.

입출력 예 #2
- 두 선수는 1번 음식 3개, 3번 음식 1개를 먹게 되므로 음식의 배치는 "111303111"입니다.

*/
