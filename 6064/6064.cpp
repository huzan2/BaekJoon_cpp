#include <iostream>

using namespace std;

int lcm(int a, int b);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    for (int T = 0; T < t; T++)
    {
        int m, n, x, y;
        int result = -1;
        cin >> m >> n >> x >> y;
        int maxi = lcm(m, n);
        for (int i = x; i <= maxi; i += m)
        {
            int tempy = i % n;
            if (tempy == 0)
            {
                tempy = n;
            }
            if (tempy == y)
            {
                result = i;
                break;
            }
        }
        cout << result << '\n';
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