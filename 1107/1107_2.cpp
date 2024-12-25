#include <iostream>
#include <string>
#include <cstdlib>
#include <cstring>

using namespace std;

bool check(string str);
bool btn[10];
int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    memset(btn, true, sizeof(btn));

    if (m == 10)
    {
        cout << abs(100 - n);
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int temp;
        cin >> temp;
        btn[temp] = false;
    }
    if (check(to_string(n)))
    {
        int rst = to_string(n).length();
        cout << min(abs(100 - n), rst) << '\n';
        return 0;
    }
    int rst1 = 1000001, rst2 = 1000001, cnt = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        cnt++;
        if (check(to_string(i)))
        {
            rst1 = to_string(i).length() + cnt;
            break;
        }
    }
    cnt = 0;
    for (int i = n + 1; i < 1000001; i++)
    {
        cnt++;
        if (check(to_string(i)))
        {
            rst2 = to_string(i).length() + cnt;
            break;
        }
    }
    int result = min(rst1, rst2);
    cout << min(result, abs(100 - n)) << '\n';
    return 0;
}

bool check(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (!btn[str[i] - '0'])
        {
            return false;
        }
    }
    return true;
}