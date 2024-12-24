#include <iostream>
#include <cmath>

using namespace std;

int arr[21];
int cnt = 0;

void func(int l, int w, int h, int n)
{
    bool flag = false;
    int num = 0;
    if (l == 0 && w == 0 && h == 0)
    {
        cout << cnt;
        cout << "finish" << '\n';
        return;
    }
    // if (l == 0 || w == 0 || h == 0)
    // {
    //     cout << "pass" << '\n';
    //     return;
    // }
    for (int j = n; j >= 0; j--)
    {
        int i = pow(2, j);
        if (arr[j] >= 1 && i <= min(min(l, w), h))
        {
            arr[j]--;
            cnt++;
            flag = true;
            num = i;
            break;
        }
    }
    if (!flag)
    {
        cout << -1;
        return;
    }
    func(l, w - num, h, n);
    func(l - num, num, num, n);
    func(l, num, h - num, n);
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
    func(l, w, h, n);
    /*
    앞면 / 옆면 / 윗면의 넓이(칸수)를 각각 저장
    1. 보유한 큐브 중 가장 큰 큐브부터 넣을 수 있는지 판별 후 채우기
    -> 나눗셈 연산 후 몫 구하면 될듯? 1보다 작으면 불가능으로
    2. 남은 변의 길이 중 가장 짧은 걸 기준으로 1의 작업 반복
    3.
    */
}