#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b);

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    vector<string> wordlist;
    string instring;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> instring;
        wordlist.push_back(instring);
    }
    sort(wordlist.begin(), wordlist.end(), compare);

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
        {
            if (wordlist[i - 1] == wordlist[i])
            {
                continue;
            }
            else
            {
                cout << wordlist[i];
            }
        }
        else
        {
            cout << wordlist[i];
        }
        cout << '\n';
    }
}

bool compare(string a, string b)
{
    if (a.length() == b.length())
    {
        return a < b;
    }
    else
    {
        return (a.length() < b.length());
    }
}