#include <iomanip>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool isnum(char ch);

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    short num[26] = {
        -1,
    };

    int n, k = 0;
    double num1, num2;
    string str;
    char temp = ' ';
    cin >> n;
    cin >> str;
    for (int i = 0; i < n; i++) {
        cin >> num[i];
    }
    stack<double> stack;
    for (int i = 0; i < str.length(); i++) {
        if (isnum(str[i])) {
            char alphabet = str[i];
            int chtonum = alphabet - 65;
            stack.push(num[chtonum]);
        } else {
            num2 = stack.top();
            stack.pop();
            num1 = stack.top();
            stack.pop();
            switch (str[i]) {
            case '+':
                stack.push(num1 + num2);
                break;
            case '-':
                stack.push(num1 - num2);
                break;
            case '*':
                stack.push(num1 * num2);
                break;
            case '/':
                stack.push(num1 / num2);
                break;
            }
        }
    }
    cout << fixed << setprecision(2) << stack.top();
}

bool isnum(char ch) {
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
        return false;
    } else {
        return true;
    }
}
