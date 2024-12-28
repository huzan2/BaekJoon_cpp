#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    int n, m, t;
    cin >> n >> m >> t;
    int mx = max(n, m), mn = min(n, m);
    // 먹는데 시간이 오래 걸리는 버거를 mx, 적게 걸리는 버거를 mn
    if (t < mn) // 햄버거를 먹지 못하는 경우 핸들링
    {
        cout << 0 << ' ' << t << '\n';
    }
    for (int i = t; i > 0; i--) // 콜라를 먹는 시간을 0부터 1씩 증가
    {
        int coke = t - i;
        for (int j = 0; j <= (i / mx); j++) // mx버거를 먹는 개수를 0부터 증가
        {
            int temp = i - (j * mx); // mx버거를 j개 먹고 남은 시간
            if (temp % mn == 0)      // 남은 시간을 mn버거로 모두 채울 수 있으면
            {
                int bg = (temp / mn) + j;
                cout << bg << ' ' << coke << '\n';
                return 0;
            }
        }
    }
}