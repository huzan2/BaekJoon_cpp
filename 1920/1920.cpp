#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    long long a[100001] = {
        0,
    };
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    cin >> m;
    long long b[100001] = {
        0,
    };
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < m; i++)
    {
        if (binary_search(a, a + n, b[i]))
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }
        cout << '\n';
    }
}