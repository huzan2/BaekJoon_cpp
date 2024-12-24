#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;
/*
앞면 / 옆면 / 윗면의 넓이(칸수)를 각각 저장
1. 보유한 큐브 중 가장 큰 큐브부터 넣을 수 있는지 판별 후 채우기
-> 나눗셈 연산 후 몫 구하면 될듯? 1보다 작으면 불가능으로
2. 남은 변의 길이 중 가장 짧은 걸 기준으로 1의 작업 반복
3.
*/

int arr[21];
int cnt = 0;

void solv(int l, int w, int h, int n)
{
    if (l <= 0 || w <= 0 || h <= 0)
    {
        return;
    }
    bool flag = false;
    int lownum = min(min(l, w), h);
    int x = 0;
    int nn = 0;
    for (int j = n; j >= 0; j--)
    {
        int i = pow(2, j);
        if (i <= lownum && arr[j] >= 1)
        {
            arr[j]--;
            cnt++;
            flag = true;
            x = i;
            nn = j;
            break;
        }
    }
    if (!flag)
    {
        cout << -1;
        exit(0);
    }
    solv(l, w - x, h, nn);
    solv(l, x, h - x, nn);
    solv(l - x, x, x, nn);
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int l, w, h, n;
    cin >> l >> w >> h >> n;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        cin >> arr[temp];
    }

    solv(l, w, h, n - 1);
    cout << cnt;
}