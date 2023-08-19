#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int h, w;
    cin >> h >> w;
    bool map[501][501];
    int arr[501];
    for (int i = 1; i <= w; i++)
    {
        cin >> arr[i];
        if (arr[i] == 0)
        {
            for (int j = 1; j <= h; j++)
            {
                map[i][j] = false;
            }
        }
        else
        {
            for (int j = 1; j <= h; j++)
            {
                if (j <= arr[i])
                {
                    map[i][j] = true;
                }
                else
                {
                    map[i][j] = false;
                }
            }
        }
    }
    int cnt = 0;
    for (int y = 1; y <= h; y++)
    {
        bool pre = false;
        int temp = 0;
        for (int x = 1; x <= w; x++)
        {
            if (map[x][y])
            {
                pre = true;
                cnt += temp;
                temp = 0;
            }
            else
            {
                if (pre)
                {
                    temp++;
                }
            }
        }
    }
    cout << cnt;
}