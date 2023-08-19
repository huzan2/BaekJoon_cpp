#include <iostream>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int e, s, m;
    cin >> e >> s >> m;
    // maxyear = 7980;
    if (e == s && s == m)
    {
        cout << e;
        return 0;
    }
    int a = 1, b = 1, c = 1, cnt = 1;
    for (int i = 1; i <= 7980; i++)
    {
        if (a == e && b == s && c == m)
        {
            cout << cnt;
            return 0;
        }
        else
        {
            cnt++;
            if (a == 15)
            {
                a = 1;
            }
            else
            {
                a++;
            }
            if (b == 28)
            {
                b = 1;
            }
            else
            {
                b++;
            }
            if (c == 19)
            {
                c = 1;
            }
            else
            {
                c++;
            }
        }
    }
}