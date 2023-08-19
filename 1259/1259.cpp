#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    bool con = true;
    int num;
    string str = "";
    while (con)
    {
        bool ispal = true;
        cin >> num;
        if (num == 0)
        {
            con = false;
            return 0;
        }
        if (num < 10)
        {
            cout << "yes" << '\n';
            continue;
        }
        str = to_string(num);
        int right = str.length() - 1, half = 0;
        if (str.length() % 2 == 0)
        {
            half = str.length() / 2 - 1;
        }
        else
        {
            half = (str.length() - 1) / 2 - 1;
        }
        for (int i = 0; i <= half; i++)
        {
            if (str[i] != str[right])
            {
                ispal = false;
            }
            right--;
        }
        if (ispal)
        {
            cout << "yes";
        }
        else
        {
            cout << "no";
        }
        cout << '\n';
    }
}