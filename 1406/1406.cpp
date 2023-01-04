#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int num;
    cin >> str;
    stack<char> left;
    stack<char> right;
    for (int i = 0; i < str.length(); i++) {
        left.push(str[i]);
    }
    cin >> num;
    char cmd;
    char temp;
    while (num--) {
        cin >> cmd;
        switch (cmd) {
        case 'L':
            if (left.empty()) {
                continue;
            }
            right.push(left.top());
            left.pop();
            break;
        case 'D':
            if (right.empty()) {
                continue;
            }
            left.push(right.top());
            right.pop();
            break;
        case 'B':
            if (left.empty()) {
                continue;
            }
            left.pop();
            break;
        case 'P':
            cin >> temp;
            left.push(temp);
            break;
        }
    }
    while (!left.empty()) {
        right.push(left.top());
        left.pop();
    }
    while (!right.empty()) {
        cout << right.top();
        right.pop();
    }
}
