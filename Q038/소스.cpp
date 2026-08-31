#include <iostream>
#include <vector>

//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================


using namespace std;

int main(void) {
    int width;  // 가로
    int height;  // 세로
    
    cin >> width >> height;
    
    //std::vector<std::string> answer(height, std::string(width, '*'));
    //for (const std::string& row : answer)
    //{
    //    std::cout << row << std::endl;
    //}
    
    // string 생성자를 이용한 구현
    std::string row(width, '*');
    for (int i = 0; i < height; ++i)
    {
        std::cout << row << '\n';
    }

    /* for문 구현
    int col;
    int row;

    cin >> col >> row;

    for (int i = 0; i < row; ++i)
    {
        for (int j = 0; j < col; ++j)
        {
            std::cout << '*';
        }
        std::cout << '\n';
    }*/

    return 0;
}

/* Q38 직사각형 별찍기

문제 설명
이 문제에는 표준 입력으로 두 개의 정수 n과 m이 주어집니다.
별(*) 문자를 이용해 가로의 길이가 n, 세로의 길이가 m인 직사각형 형태를 출력해보세요.

제한 조건
n과 m은 각각 1000 이하인 자연수입니다.
예시
입력

5 3
출력

*****
*****
*****

*/