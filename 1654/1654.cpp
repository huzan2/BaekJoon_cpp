#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int k, n;
    unsigned int line[10001] = {
        0,
    };
    unsigned int maxi = 0;
    cin >> k >> n;
    for (int i = 0; i < k; i++)
    {
        cin >> line[i];
        maxi = max(maxi, line[i]);
    }
    unsigned int left = 1, right = maxi, mid, cnt = 0, target = 0;
    while (left <= right)
    {
        mid = (left + right) / 2;
        cnt = 0;
        for (int i = 0; i < k; i++)
        {
            cnt += line[i] / mid;
        }
        if (cnt >= n)
        {
            target = max(target, mid);
        }
        if (cnt < n)
        {
            right = mid - 1;
        }
        else if (cnt >= n)
        {
            left = mid + 1;
        }
    }
    cout << target;
}