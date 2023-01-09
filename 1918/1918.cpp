#include <iostream>
#include <stack>
#include <string>

using namespace std;

int getpriority(char op);
bool isnum(char ch);
bool isp(char ch);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    stack<char> stack;
    string result;

    cin >> str;
    for (int i = 0; str[i] != '\0'; i++) {
        if (isnum(str[i])) {
            cout << str[i];
        } else {
            if (!isp(str[i])) {
                if (stack.empty()) {
                    stack.push(str[i]);
                } else {
                    while (!stack.empty() &&
                           getpriority(stack.top()) >= getpriority(str[i])) {
                        cout << stack.top();
                        stack.pop();
                    }
                    stack.push(str[i]);
                }
            } else {
                if (str[i] == '(') {
                    stack.push(str[i]);
                } else if (str[i] == ')') {
                    while (stack.top() != '(') {
                        cout << stack.top();
                        stack.pop();
                    }
                    stack.pop();
                }
            }
        }
    }
    while (!stack.empty()) {
        if (isp(stack.top())) {
            stack.pop();
            continue;
        }
        cout << stack.top();
        stack.pop();
    }
}

bool isnum(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '(' ||
        ch == ')') {
        return false;
    } else {
        return true;
    }
}

bool isp(char ch) {
    if (ch == '(' || ch == ')') {
        return true;
    } else {
        return false;
    }
}

int getpriority(char op) {
    switch (op) {
    case '(':
    case ')':
        return 0;
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    }
    return -1;
}
