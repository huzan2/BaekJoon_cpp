#include <iostream>

using namespace std;

int main(void)
{
    double n, b, m;
    while (cin >> n >> b >> m)
    {
        int cnt = 0;
        while (n < m)
        {
            n *= (1 + (b * 0.01));
            cnt++;
        }
        cout << cnt << '\n';
    }
}