#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;
    string temp[1000];
    for (int i = 0; i < str.length(); i++) {
        temp[i] = str.substr(i);
    }
    sort(temp, temp + str.length());
    for (int i = 0; i < str.length(); i++) {
        cout << temp[i] << '\n';
    }
}
