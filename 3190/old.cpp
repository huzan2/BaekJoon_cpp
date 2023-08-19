#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l;
    int arr[101][101];
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> y >> x;
        arr[x][y] = 2;
    }
    cin >> l;
    int t[101];
    char c[101];
    for (int i = 0; i < l; i++)
    {
        cin >> t[i] >> c[i];
    }
    int time = 0, a = 1, b = 1, turni = 0, da = 0, db = 0, len = 1;
    vector<int> dela;
    vector<int> delb;
    char heading = 'R';
    bool con = true;
    arr[1][1] = 1;
    while (con)
    {
        time++;
        if (heading == 'R')
        {
            if (a + 1 > n)
            {
                cout << time;
                con = false;
                return 0;
            }
            else if (arr[a + 1][b] == 1)
            {
                cout << time;
                con = false;
                return 0;
            }
            else
            {
                if (arr[a + 1][b] == 2)
                {
                    dela.push_back(a);
                    delb.push_back(b);
                    arr[a + 1][b] = 1;
                    a++;
                    len++;
                }
                else
                {
                    if (len == 1)
                    {
                        arr[a][b] = 0;
                    }
                    else
                    {
                        arr[dela[da]][delb[db]] = 0;
                        da++;
                        db++;
                    }
                    arr[a + 1][b] = 1;
                    a++;
                }
            }
        }
        /////////////////////////////
        if (time == t[turni])
        {
            if (c[turni] == 'L')
            {
                switch (heading)
                {
                case 'R':
                    heading = 'U';
                    break;
                case 'L':
                    heading = 'D';
                    break;
                case 'U':
                    heading = 'L';
                    break;
                case 'D':
                    heading = 'R';
                    break;
                }
            }
            else if (c[turni] == 'D')
            {
                switch (heading)
                {
                case 'R':
                    heading = 'D';
                    break;
                case 'L':
                    heading = 'U';
                    break;
                case 'U':
                    heading = 'R';
                    break;
                case 'D':
                    heading = 'L';
                    break;
                }
            }
            if (turni != l - 1)
            {
                turni++;
            }
        }
    }
}