#include <iostream>
#include <cmath>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int rise = 1, length = 1, cnt = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == rise * 10)
        {
            rise *= 10;
            length++;
        }
        cnt += length;
    }
    cout << cnt;
}