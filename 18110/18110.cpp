#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, result;
    int rank[300001] = {
        0,
    };
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    double ex = ((double)n / 100) * 15;
    ex = floor(ex + 0.5);
    for (int i = 0; i < n; i++)
    {
        cin >> rank[i];
    }
    sort(rank, rank + n);
    double sum = 0;
    for (int i = ex; i < n - ex; i++)
    {
        sum += (double)rank[i];
    }
    result = floor(sum / (n - ex * 2) + 0.5);
    cout << result;
}