#include <iostream>

using namespace std;

// dfs 공부하고 다시 풀어보기

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    int arr[500][500];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    int res = 0, temp = 0, temp2 = 0, temp3 = 0, temp4 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m - 3; j++)
        {
            temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i][j + 3];
            res = max(res, temp);
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            temp = arr[i][j] + arr[i + 1][j] + arr[i][j + 1] + arr[i + 1][j + 1];
            res = max(res, temp);
        }
    }
    for (int i = 0; i < n - 2; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            temp = arr[i][j] + arr[i + 1][j] + arr[i + 1][j + 1] + arr[i + 2][j + 1];
            temp2 = arr[i][j] + arr[i + 1][j] + arr[i + 2][j] + arr[i + 2][j + 1];
            temp3 =
                res = max({res, temp, temp2});
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 2; j++)
        {
            temp = arr[i][j] + arr[i][j + 1] + arr[i][j + 2] + arr[i + 1][j + 1];
            res = max(res, temp);
        }
    }
    cout << res;
}