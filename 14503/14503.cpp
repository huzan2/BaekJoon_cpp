#include <iostream>

using namespace std;

int arr[51][51];
int n, m;

bool check(int r, int c);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int r, c, d, cnt = 0;
    cin >> n >> m;
    cin >> r >> c >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
    }
    bool con = true;
    while (con)
    {
        if (arr[r][c] == 0)
        {
            arr[r][c] = -1;
            cnt++;
        }
        if (!check(r, c))
        {
            bool temp = false;
            if (d == 0 && arr[r + 1][c] != 1)
            {
                temp = true;
                r++;
            }
            else if (d == 1 && arr[r][c - 1] != 1)
            {
                temp = true;
                c--;
            }
            else if (d == 2 && arr[r - 1][c] != 1)
            {
                temp = true;
                r--;
            }
            else if (d == 3 && arr[r][c + 1] != 1)
            {
                temp = true;
                c++;
            }
            if (!temp)
            {
                con = false;
                cout << cnt;
                return 0;
            }
        }
        else
        {
            if (d == 0)
            {
                d = 3;
            }
            else
            {
                d--;
            }
            if (d == 0 && arr[r - 1][c] == 0)
            {
                r--;
            }
            else if (d == 1 && arr[r][c + 1] == 0)
            {
                c++;
            }
            else if (d == 2 && arr[r + 1][c] == 0)
            {
                r++;
            }
            else if (d == 3 && arr[r][c - 1] == 0)
            {
                c--;
            }
        }
    }
}

bool check(int r, int c)
{
    bool temp = false;
    if (arr[r - 1][c] == 0)
    {
        temp = true;
    }
    if (arr[r][c - 1] == 0)
    {
        temp = true;
    }
    if (arr[r + 1][c] == 0)
    {
        temp = true;
    }
    if (arr[r][c + 1] == 0)
    {
        temp = true;
    }
    return temp;
}
