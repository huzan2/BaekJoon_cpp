#include <iostream>
#include <stack>

using namespace std;

int main(void) {
    bool right = false;
    char str[50];
    int t;
    stack<char> stack;
    scanf("%d", &t);
    while (t--) {
        if (!stack.empty()) {
            while (!stack.empty()) {
                stack.pop();
            }
        }
        scanf("%s", str);
        int i = 0;
        while (str[i] != '\0') {
            if (str[i] == '(') {
                stack.push(str[i]);
            } else if (str[i] == ')') {
                if (stack.empty()) {
                    stack.push('!');
                    break;
                }
                stack.pop();
            }
            i++;
        }
        if (stack.empty()) {
            printf("YES\n");
        } else {
            printf("NO\n");
        }
    }
}
