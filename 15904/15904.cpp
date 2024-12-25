#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str, target = "UCPC";
    int index = 0;
    getline(cin, str);
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == target[index])
        {
            index++;
        }
        if (index == 4)
        {
            cout << "I love UCPC" << '\n';
            return 0;
        }
    }
    cout << "I hate UCPC" << '\n';
}