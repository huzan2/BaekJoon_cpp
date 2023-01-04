#include <iostream>
#include <string>
using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;
    int i = 0;
    int result = 0;
    int stick = 0;
    while (i < str.length()) {
        if (str[i] == '(') {
            if (str[i + 1] != ')') {
                stick++;
                i++;
            } else {
                result += stick;
                i += 2;
            }
        } else if (str[i] == ')') {
            stick--;
            i++;
            result++;
        }
    }
    cout << result;
}
