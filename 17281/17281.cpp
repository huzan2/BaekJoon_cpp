#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int n; // 주어진 이닝 수
int player[51][10] = {
    // 각 타자의 결과를 저장할 배열
    0,
};
int order[10] = {
    // 선수 라인업을 저장할 배열
    0,
};
bool base[4] = {
    // 각 베이스 주자 정보를 저장할 배열
    false,
};

int playGame(int *order); // 야구 게임 시뮬레이션 함수

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            cin >> player[i][j]; // 배열에 각 선수별, 이닝별 결과 저장
        }
    }
    int arr[8] = {2, 3, 4, 5, 6, 7, 8, 9}; // 순열 적용을 위한 임시 배열
    // 4번 타자가 이미 정해져 있기 때문에, 나머지 선수들로 이루어진 배열의 순열 nPn을 구해 선수 라인업에 반영
    int maxScore = 0; // 최다득점 경우에서의 점수 정보 저장
    order[4] = 1;     // 이미 정해져 있는 4번타자
    do
    {
        copy(arr + 3, arr + 8, order + 5);         // 5번부터 9번까지 타자 정보 반영
        copy(arr, arr + 3, order + 1);             // 1번부터 3번까지 타자 정보 반영
        maxScore = max(maxScore, playGame(order)); // 주어진 라인업으로 게임 시뮬레이션 후 득점 정보 갱신
    } while (next_permutation(arr, arr + 8));      // STL algorithm 헤더의 순열 함수
    cout << maxScore;
}

int playGame(int *order)
{
    int lastIndex = 1, score = 0, innings = 1; // lastIndex = 이닝 종료시 다음 이닝에서 선두타자로 나올 선수의 번호
    while (innings <= n)                       // n이닝 동안 반복
    {
        int outCount = 0, i = lastIndex;   // order[i]가 현재 타석에 있는 타자 번호. 즉 i는 라인업 중 현재 타석에 선 선수의 인덱스 번호
        memset(base, false, sizeof(base)); // 베이스 정보 초기화
        while (outCount < 3)               // 아웃카운트가 3이 될 때까지 반복
        {
            switch (player[innings][order[i]]) // 해당 이닝과 선수에 따른 정해진 결과 각각 실행
            {
            case 0: // 아웃
                outCount++;
                break;
            case 1: // 안타
                if (base[3])
                {
                    score++;
                    base[3] = false;
                }
                if (base[2])
                {
                    base[2] = false;
                    base[3] = true;
                }
                if (base[1])
                {
                    base[2] = true;
                }
                base[1] = true;
                break;
            case 2: // 2루타
                if (base[3])
                {
                    score++;
                    base[3] = false;
                }
                if (base[2])
                {
                    score++;
                }
                if (base[1])
                {
                    base[1] = false;
                    base[3] = true;
                }
                base[2] = true;
                break;
            case 3: // 3루타
                if (base[3])
                {
                    score++;
                }
                if (base[2])
                {
                    score++;
                    base[2] = false;
                }
                if (base[1])
                {
                    score++;
                    base[1] = false;
                }
                base[3] = true;
                break;
            case 4: // 홈런
                if (base[1])
                {
                    score++;
                }
                if (base[2])
                {
                    score++;
                }
                if (base[3])
                {
                    score++;
                }
                score++;
                memset(base, false, sizeof(base));
                break;
            }
            if (outCount == 3) // 아웃카운트 3 달성시 while문 탈출
            {
                if (i == 9) // 9번 타자까지 타석에 선 상태로 이닝이 끝나면, 다음 이닝에서는 1번 타자부터 시작해야 함
                {
                    lastIndex = 1;
                }
                else // 다음 이닝에서 선두타자로 나설 선수 정보 저장
                {
                    lastIndex = i + 1;
                }
                break;
            }
            if (i == 9) // 9번 타자 다음은 1번
            {
                i = 1;
            }
            else
            {
                i++;
            }
        }
        innings++;
    }
    return score;
}