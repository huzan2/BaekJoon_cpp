#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, cnt = 0;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    for (int i = 1; i <= n; i++)
    {
        if (i >= 5 && i % 5 == 0)
        {
            cnt++;
        }
        if (i >= 25 && i % 25 == 0)
        {
            cnt++;
        }
        if (i >= 125 && i % 125 == 0)
        {
            cnt++;
        }
    }
    cout << cnt;
}