#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned int n, m, b;
    cin >> n >> m >> b;
    int map[500][500];
    int soltime[500];
    int solhigh[500];
    int solnum = 0;
    int maxhigh = 0;
    int minhigh = 256;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> map[i][j];
            maxhigh = max(maxhigh, map[i][j]);
            minhigh = min(minhigh, map[i][j]);
        }
    }
    for (int i = minhigh; i <= maxhigh; i++)
    {
        int fill = 0, take = 0;
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < m; y++)
            {
                if (map[x][y] == i)
                {
                    continue;
                }
                else
                {
                    if (map[x][y] > i)
                    {
                        int maptemp = map[x][y];
                        while (maptemp > i)
                        {
                            take++;
                            maptemp--;
                            // map[x][y]--;
                        }
                    }
                    if (map[x][y] < i)
                    {
                        int maptemp = map[x][y];
                        while (maptemp < i)
                        {
                            fill++;
                            maptemp++;
                            // map[x][y]++;
                        }
                    }
                }
            }
        }
        if (fill <= (b + take))
        {
            solnum++;
            solhigh[solnum] = i;
            soltime[solnum] = (take * 2) + fill;
        }
    }
    if (solnum == 1)
    {
        cout << soltime[1] << " " << solhigh[1];
        return 0;
    }
    int time = soltime[1], high = solhigh[1];
    vector<int> res;
    for (int i = 1; i <= solnum; i++)
    {
        time = min(time, soltime[i]);
    }
    for (int i = 1; i <= solnum; i++)
    {
        if (soltime[i] == time)
        {
            res.push_back(i);
        }
    }
    if (res.size() == 1)
    {
        cout << soltime[res[0]] << " " << solhigh[res[0]];
        return 0;
    }
    for (int i = 0; i < res.size(); i++)
    {
        high = max(high, solhigh[res[i]]);
    }
    for (int i = 0; i < res.size(); i++)
    {
        if (high == solhigh[res[i]])
        {
            cout << soltime[res[i]] << " " << solhigh[res[i]];
        }
    }
}