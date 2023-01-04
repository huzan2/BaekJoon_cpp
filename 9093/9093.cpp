#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main(void) {
    int t;
    string str;
    stack<char> stack;
    char temp;
    scanf("%d", &t);
    cin.ignore(256, '\n');
    while (t > 0) {
        getline(cin, str);
        for (int i = 0; i < str.length(); i++) {
            if (str[i] != ' ') {
                stack.push(str[i]);
            }
            if (str[i] == ' ') {
                while (!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                printf(" ");
            } else if (str[i] == '\n') {
                while (!stack.empty()) {
                    cout << stack.top();
                    stack.pop();
                }
                printf(" ");
            }
        }
        if (!stack.empty()) {
            while (!stack.empty()) {
                cout << stack.top();
                stack.pop();
            }
        }
        printf("\n");
        t--;
        str = "";
    }
}
