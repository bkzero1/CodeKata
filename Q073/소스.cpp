#include <iostream>
//==========================================================================
//              ⭐ 해결 완료 ⭐ ✔ ✅ | AI 코칭 리팩터링
//==========================================================================

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int currentY = 0;
    int currentX = 0;

    // 공원 전체를 탐색해 시작 지점의 좌표를 찾음
    bool foundStart = false;
    const int parkHeight = static_cast<int>(park.size());
    const int parkWidth = static_cast<int>(park[0].size());
    for (int y = 0; y < parkHeight; ++y)
    {
        for (int x = 0; x < parkWidth; ++x)
        {
            if (park[y][x] == 'S')
            {
                currentY = y;
                currentX = x;
                
                foundStart = true;
                break;
            }
        }

        if (foundStart)
        {
            break;
        }
    }

    // 각 명령의 방향을 한 칸 이동할 때의 좌표 변화량으로 변환
    for (const std::string& order : routes)
    {
        const char direction = order.front();
        const int distance = order.back() - '0';
        
        int stepY = 0;
        int stepX = 0;
        switch (direction)
        {
        case 'N':
            stepY = -1;
            break;
        case 'S':
            stepY = 1;
            break;
        case 'E':
            stepX = 1;
            break;
        case 'W':
            stepX = -1;
            break;
        }

        // 목적지가 공원 범위를 벗어나는지 확인
        const int targetY = currentY + stepY * distance;
        const int targetX = currentX + stepX * distance;
        bool canMove = true;

        if (targetY < 0 || targetY >= parkHeight)
        {
            canMove = false;
        }
        if (targetX < 0 || targetX >= parkWidth)
        {
            canMove = false;
        }

        // 목적지가 범위 안이면 이동 경로와 목적지에 장애물이 있는지 확인
        if (canMove)
        {
            for (int stepCount = 1; stepCount <= distance; ++stepCount)
            {
                const int checkY = currentY + stepY * stepCount;
                const int checkX = currentX + stepX * stepCount;

                if (park[checkY][checkX] == 'X')
                {
                    canMove = false;
                    break;
                }
            }
        }

        // 모든 검사를 통과한 명령만 현재 위치에 반영
        if (canMove)
        {
            currentY = targetY;
            currentX = targetX;
        }
    }

    return { currentY, currentX };
}

// 문자열 벡터를 입력값 그대로 표시
void PrintStringVector(const vector<string>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << '"' << values[i] << '"';
    }
    cout << ']';
}

// 반환된 좌표와 기대 좌표 표시
void PrintVector(const vector<int>& values)
{
    cout << '[';
    for (size_t i = 0; i < values.size(); ++i)
    {
        if (i > 0) cout << ", ";
        cout << values[i];
    }
    cout << ']';
}

// 입력과 기대값, 실제값을 한 줄에서 비교
void Test(const string& name, const vector<string>& park,
    const vector<string>& routes, const vector<int>& expected)
{
    const vector<int> actual = solution(park, routes);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: park = ";
    PrintStringVector(park);
    cout << ", routes = ";
    PrintStringVector(routes);
    cout << " | expected: ";
    PrintVector(expected);
    cout << " | actual: ";
    PrintVector(actual);
    cout << '\n';
}

int main()
{
    Test("official example 1", { "SOO", "OOO", "OOO" },
        { "E 2", "S 2", "W 1" }, { 2, 1 });
    Test("official example 2", { "SOO", "OXX", "OOO" },
        { "E 2", "S 2", "W 1" }, { 0, 1 });
    Test("official example 3", { "OSO", "OOO", "OXO", "OOO" },
        { "E 2", "S 3", "W 1" }, { 0, 0 });
    Test("additional case 1", { "OOO", "OSO", "OOO" },
        { "N 9", "W 9", "S 9", "E 9" }, { 1, 1 });
    Test("additional case 2", { "SOXO", "OOOO", "OOOO" },
        { "E 3", "S 1" }, { 1, 0 });
    Test("additional case 3", { "SOOO", "OOOO", "OOOO" },
        { "S 2", "E 3", "N 2", "W 3" }, { 0, 0 });
    Test("additional case 4", { "OOO", "OSO", "OOO" },
        { "E 1", "W 1", "N 1" }, { 0, 1 });
    return 0;
}

/* Q073 공원 산책 https://school.programmers.co.kr/learn/courses/30/lessons/172928

문제 설명

지나다니는 길을 'O', 장애물을 'X'로 나타낸 직사각형 격자 모양의 공원에서 로봇 강아지가 산책을 하려합니다. 산책은 로봇 강아지에 미리 입력된 명령에 따라 진행하며, 명령은 다음과 같은 형식으로 주어집니다.

- ["방향 거리", "방향 거리" … ]

예를 들어 "E 5"는 로봇 강아지가 현재 위치에서 동쪽으로 5칸 이동했다는 의미입니다. 로봇 강아지는 명령을 수행하기 전에 다음 두 가지를 먼저 확인합니다.

- 주어진 방향으로 이동할 때 공원을 벗어나는지 확인합니다.
- 주어진 방향으로 이동 중 장애물을 만나는지 확인합니다.

위 두 가지중 어느 하나라도 해당된다면, 로봇 강아지는 해당 명령을 무시하고 다음 명령을 수행합니다.
공원의 가로 길이가 W, 세로 길이가 H라고 할 때, 공원의 좌측 상단의 좌표는 (0, 0), 우측 하단의 좌표는 (H - 1, W - 1) 입니다.

공원을 나타내는 문자열 배열 park, 로봇 강아지가 수행할 명령이 담긴 문자열 배열 routes가 매개변수로 주어질 때, 로봇 강아지가 모든 명령을 수행 후 놓인 위치를 [세로 방향 좌표, 가로 방향 좌표] 순으로 배열에 담아 return 하도록 solution 함수를 완성해주세요.

제한사항

- 3 ≤ park의 길이 ≤ 50
- 3 ≤ park[i]의 길이 ≤ 50
- park[i]는 다음 문자들로 이루어져 있으며 시작지점은 하나만 주어집니다.
  - S : 시작 지점
  - O : 이동 가능한 통로
  - X : 장애물
- park는 직사각형 모양입니다.
- 1 ≤ routes의 길이 ≤ 50
- routes의 각 원소는 로봇 강아지가 수행할 명령어를 나타냅니다.
- 로봇 강아지는 routes의 첫 번째 원소부터 순서대로 명령을 수행합니다.
- routes의 원소는 "op n"과 같은 구조로 이루어져 있으며, op는 이동할 방향, n은 이동할 칸의 수를 의미합니다.
- op는 다음 네 가지중 하나로 이루어져 있습니다.
  - N : 북쪽으로 주어진 칸만큼 이동합니다.
  - S : 남쪽으로 주어진 칸만큼 이동합니다.
  - W : 서쪽으로 주어진 칸만큼 이동합니다.
  - E : 동쪽으로 주어진 칸만큼 이동합니다.
- 1 ≤ n ≤ 9

입출력 예

park                          routes                   result
["SOO", "OOO", "OOO"]         ["E 2", "S 2", "W 1"]    [2, 1]
["SOO", "OXX", "OOO"]         ["E 2", "S 2", "W 1"]    [0, 1]
["OSO", "OOO", "OXO", "OOO"]  ["E 2", "S 3", "W 1"]    [0, 0]

입출력 예 설명

입출력 예 #1
입력된 명령대로 동쪽으로 2칸, 남쪽으로 2칸, 서쪽으로 1칸 이동하면 [0,0] -> [0,2] -> [2,2] -> [2,1]이 됩니다.

입출력 예 #2
입력된 명령대로라면 동쪽으로 2칸, 남쪽으로 2칸, 서쪽으로 1칸 이동해야하지만 남쪽으로 2칸 이동할 때 장애물이 있는 칸을 지나기 때문에 해당 명령을 제외한 명령들만 따릅니다. 결과적으로는 [0,0] -> [0,2] -> [0,1]이 됩니다.

입출력 예 #3
처음 입력된 명령은 공원을 나가게 되고 두 번째로 입력된 명령 또한 장애물을 지나가게 되므로 두 입력은 제외한 세 번째 명령만 따르므로 결과는 다음과 같습니다. [0,1] -> [0,0]

*/
