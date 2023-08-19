#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string temp = "";
    cin >> n;
    int tnum = 1665, cnt = 1;
    if (n == 1)
    {
        cout << 666;
        return 0;
    }
    while (1)
    {
        tnum++;
        temp = to_string(tnum);
        for (int i = 2; i < temp.length(); i++)
        {
            if (temp.at(i) == '6' && temp.at(i - 1) == '6' && temp.at(i - 2) == '6')
            {
                cnt++;
                if (n == cnt)
                {
                    cout << tnum;
                    return 0;
                }
                break;
            }
        }
    }
}