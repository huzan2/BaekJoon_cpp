#include <iostream>

using namespace std;

int lcm(int a, int b);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n, x, y, t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        cin >> m >> n >> x >> y;
        int last = lcm(m, n);
        bool isright = false;
        int a = 1, b = 1, cnt = 1;
        while (cnt <= last)
        {
            if (a == x && b == y)
            {
                cout << cnt << '\n';
                isright = true;
                break;
            }
            else
            {
                if (a == m)
                {
                    a = 1;
                }
                else
                {
                    a++;
                }
                if (b == n)
                {
                    b = 1;
                }
                else
                {
                    b++;
                }
                cnt++;
            }
        }
        if (!isright)
        {
            cout << -1 << '\n';
        }
    }
}

int lcm(int a, int b)
{
    int num1 = a, num2 = b;
    int c;
    while (b != 0)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return (num1 * num2) / a;
}