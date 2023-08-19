#include <iostream>

using namespace std;
int n;
char arr[51][51];

int check();

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }
    int res1 = 0, res2 = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                continue;
            }
            else
            {
                swap(arr[i][j], arr[i][j + 1]);
                res1 = max(res1, check());
                swap(arr[i][j], arr[i][j + 1]);
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i][j] == arr[i + 1][j])
            {
                continue;
            }
            else
            {
                swap(arr[i][j], arr[i + 1][j]);
                res2 = max(res2, check());
                swap(arr[i][j], arr[i + 1][j]);
            }
        }
    }
    int result = max(res1, res2);
    cout << result;
}

int check()
{
    int row, col, rtemp = 0, ctemp = 0, res = 1;
    for (int i = 0; i < n; i++)
    {
        row = 1;
        for (int j = 0; j < n; j++)
        {
            if (arr[i][j] == arr[i][j + 1])
            {
                row++;
            }
            else
            {
                rtemp = max(rtemp, row);
                row = 1;
            }
        }
    }
    for (int j = 0; j < n; j++)
    {
        col = 1;
        for (int i = 0; i < n; i++)
        {
            if (arr[i][j] == arr[i + 1][j])
            {
                col++;
            }
            else
            {
                ctemp = max(ctemp, col);
                col = 1;
            }
        }
    }
    res = max(ctemp, rtemp);
    return res;
}
