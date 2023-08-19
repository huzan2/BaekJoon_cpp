#include <iostream>
#include <string>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string str = "";
    cin >> str;
    cin >> n;
    cout << str[n - 1];
}