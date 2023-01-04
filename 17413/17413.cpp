#include <iostream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int i = 0;
    string str;
    getline(cin, str);
    stack<char> s;
    vector<char> v;

    while (i < str.size()) {
        if (str[i] == '<') {
            if (!s.empty()) {
                while (!s.empty()) {
                    v.push_back(s.top());
                    s.pop();
                }
            }
            while (str[i] != '>') {
                v.push_back(str[i]);
                i++;
            }
        } else if (str[i] == '>') {
            v.push_back(str[i]);
            i++;
        } else if (str[i] != ' ') {
            s.push(str[i]);
            i++;
        } else if (str[i] == ' ') {
            while (!s.empty()) {
                v.push_back(s.top());
                s.pop();
            }
            v.push_back(' ');
            i++;
        }
    }
    while (!s.empty()) {
        v.push_back(s.top());
        s.pop();
    }
    for (int k = 0; k < str.size(); k++) {
        cout << v[k];
    }
}
