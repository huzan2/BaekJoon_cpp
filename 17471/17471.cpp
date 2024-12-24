#include <iostream>
#include <vector>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, temp1, temp2;
    int people[11] = {
        0,
    };
    vector<int> rel[11];
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> people[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> temp1;
        for (int j = 0; j < temp1; j++)
        {
            cin >> temp2;
            rel[i].push_back(temp2);
        }
    }
}