#include <iostream>
//==========================================================================
//                            ⭐ 해결 완료 ⭐ ✔ ✅
//==========================================================================

#include <string>
#include <vector>
#include <array>

using namespace std;

int convertDateToDays(const std::string& date)
{
    constexpr int monthsPerYear = 12;
    constexpr int daysPerMonth = 28;
    constexpr int daysPerYear = monthsPerYear * daysPerMonth;

    int year = std::stoi(date.substr(0, 4));
    int month = std::stoi(date.substr(5, 2));
    int day = std::stoi(date.substr(8, 2));

    return (year * daysPerYear) + (month * daysPerMonth) + day;
}
int calculateDaysBetween(const std::string& today, const std::string& collectionDate)
{
    return convertDateToDays(today) - convertDateToDays(collectionDate);
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    constexpr int daysPerMonth = 28;
    constexpr int alphabetSize = 26;
    std::array<int, alphabetSize> termsTable{};
    for (const std::string& term : terms)
    {
        int typeIndex = term.front() - 'A';
        
        termsTable[typeIndex] = daysPerMonth * std::stoi(term.substr(2));
        //cout << static_cast<char>(typeIndex + 'A') << ":" << termsTable[typeIndex] << " ";
    }

    for (int i = 0; i < privacies.size(); ++i)
    {
        std::string& privacy = privacies[i];
        char typeIndex = privacies[i].back() - 'A';

        // 뒤의 문자 두개 제거
        //privacy.resize(privacy.size() - 2);
        privacy.erase(privacy.size() - 2);

        if (calculateDaysBetween(today, privacy) >= termsTable[typeIndex])
        {
            answer.push_back(i + 1);
        }
    }
    return answer;
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

// 정수 벡터를 입력값 그대로 표시
void PrintIntVector(const vector<int>& values)
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
void Test(const string& name, const string& today, const vector<string>& terms,
    const vector<string>& privacies, const vector<int>& expected)
{
    const vector<int> actual = solution(today, terms, privacies);
    const bool success = actual == expected;
    cout << (success ? "\x1b[38;2;120;230;102m SUCCESS" : "\x1b[38;2;230;102;102m  FAIL  ")
        << "\x1b[0m | " << name << " | input: today = " << '"' << today << '"' << ", terms = ";
    PrintStringVector(terms);
    cout << ", privacies = ";
    PrintStringVector(privacies);
    cout << " | expected: ";
    PrintIntVector(expected);
    cout << " | actual: ";
    PrintIntVector(actual);
    cout << '\n';
}

int main()
{
    // 공식 예제
    Test("official example 1", "2022.05.19", { "A 6", "B 12", "C 3" },
        { "2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C" }, { 1, 3 });
    Test("official example 2", "2020.01.01", { "Z 3", "D 5" },
        { "2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z" }, { 1, 4, 5 });

    // 추가 검증 사례
    Test("one month boundary", "2022.02.01", { "A 1" },
        { "2022.01.01 A", "2022.01.02 A" }, { 1 });
    Test("year boundary", "2022.01.01", { "Z 1" },
        { "2021.12.01 Z", "2021.12.02 Z" }, { 1 });
    Test("day 28 boundary", "2022.02.28", { "B 1" },
        { "2022.01.28 B", "2022.02.01 B" }, { 1 });
    Test("long term", "2022.05.01", { "A 100" },
        { "2014.01.01 A", "2014.01.02 A" }, { 1 });
    Test("ascending privacy numbers", "2022.03.01", { "C 1", "A 12" },
        { "2022.01.01 A", "2022.02.01 C", "2021.01.01 A", "2022.02.02 C" }, { 2, 3 });
    return 0;
}

/* Q071 개인정보 수집 유효기간 https://school.programmers.co.kr/learn/courses/30/lessons/150370

문제 설명

고객의 약관 동의를 얻어서 수집된 1~n번으로 분류되는 개인정보 n개가 있습니다. 약관 종류는 여러 가지 있으며 각 약관마다 개인정보 보관 유효기간이 정해져 있습니다. 당신은 각 개인정보가 어떤 약관으로 수집됐는지 알고 있습니다. 수집된 개인정보는 유효기간 전까지만 보관 가능하며, 유효기간이 지났다면 반드시 파기해야 합니다.

예를 들어, A라는 약관의 유효기간이 12 달이고, 2021년 1월 5일에 수집된 개인정보가 A약관으로 수집되었다면 해당 개인정보는 2022년 1월 4일까지 보관 가능하며 2022년 1월 5일부터 파기해야 할 개인정보입니다.
당신은 오늘 날짜로 파기해야 할 개인정보 번호들을 구하려 합니다.

모든 달은 28일까지 있다고 가정합니다.

다음은 오늘 날짜가 2022.05.19일 때의 예시입니다.

약관 종류   유효기간
A           6 달
B           12 달
C           3 달

번호   개인정보 수집 일자   약관 종류
1      2021.05.02            A
2      2021.07.01            B
3      2022.02.19            C
4      2022.02.20            C

- 첫 번째 개인정보는 A약관에 의해 2021년 11월 1일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
- 두 번째 개인정보는 B약관에 의해 2022년 6월 28일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
- 세 번째 개인정보는 C약관에 의해 2022년 5월 18일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
- 네 번째 개인정보는 C약관에 의해 2022년 5월 19일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.

따라서 파기해야 할 개인정보 번호는 [1, 3]입니다.

오늘 날짜를 의미하는 문자열 today, 약관의 유효기간을 담은 1차원 문자열 배열 terms와 수집된 개인정보의 정보를 담은 1차원 문자열 배열 privacies가 매개변수로 주어집니다. 이때 파기해야 할 개인정보의 번호를 오름차순으로 1차원 정수 배열에 담아 return 하도록 solution 함수를 완성해 주세요.

제한사항

- today는 "YYYY.MM.DD" 형태로 오늘 날짜를 나타냅니다.
- 1 ≤ terms의 길이 ≤ 20
- terms의 원소는 "약관 종류 유효기간" 형태의 약관 종류와 유효기간을 공백 하나로 구분한 문자열입니다.
- 약관 종류는 A~Z중 알파벳 대문자 하나이며, terms 배열에서 약관 종류는 중복되지 않습니다.
- 유효기간은 개인정보를 보관할 수 있는 달 수를 나타내는 정수이며, 1 이상 100 이하입니다.
- 1 ≤ privacies의 길이 ≤ 100
- privacies[i]는 i+1번 개인정보의 수집 일자와 약관 종류를 나타냅니다.
- privacies의 원소는 "날짜 약관 종류" 형태의 날짜와 약관 종류를 공백 하나로 구분한 문자열입니다.
- 날짜는 "YYYY.MM.DD" 형태의 개인정보가 수집된 날짜를 나타내며, today 이전의 날짜만 주어집니다.
- privacies의 약관 종류는 항상 terms에 나타난 약관 종류만 주어집니다.
- today와 privacies에 등장하는 날짜의 YYYY는 연도, MM은 월, DD는 일을 나타내며 점(.) 하나로 구분되어 있습니다.
- 2000 ≤ YYYY ≤ 2022
- 1 ≤ MM ≤ 12
- MM이 한 자릿수인 경우 앞에 0이 붙습니다.
- 1 ≤ DD ≤ 28
- DD가 한 자릿수인 경우 앞에 0이 붙습니다.
- 파기해야 할 개인정보가 하나 이상 존재하는 입력만 주어집니다.

입출력 예

- today = "2022.05.19", terms = ["A 6", "B 12", "C 3"], privacies = ["2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"] -> [1, 3]
- today = "2020.01.01", terms = ["Z 3", "D 5"], privacies = ["2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"] -> [1, 4, 5]

입출력 예 설명

입출력 예 #1
- 문제 예시와 같습니다.

입출력 예 #2

약관 종류   유효기간
Z           3 달
D           5 달

번호   개인정보 수집 일자   약관 종류
1      2019.01.01            D
2      2019.11.15            Z
3      2019.08.02            D
4      2019.07.01            D
5      2018.12.28            Z

오늘 날짜는 2020년 1월 1일입니다.

- 첫 번째 개인정보는 D약관에 의해 2019년 5월 28일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
- 두 번째 개인정보는 Z약관에 의해 2020년 2월 14일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
- 세 번째 개인정보는 D약관에 의해 2020년 1월 1일까지 보관 가능하며, 유효기간이 지나지 않았으므로 아직 보관 가능합니다.
- 네 번째 개인정보는 D약관에 의해 2019년 11월 28일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.
- 다섯 번째 개인정보는 Z약관에 의해 2019년 3월 27일까지 보관 가능하며, 유효기간이 지났으므로 파기해야 할 개인정보입니다.

*/
