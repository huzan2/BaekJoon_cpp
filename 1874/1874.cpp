#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    int n;
    scanf("%d", &n);
    stack<int> stack;
    vector<char> chvec;
    int start = 1;
    int num;
    bool possible = true;
    while (n--) {
        scanf("%d", &num);
        while (start <= num) {
            stack.push(start);
            start++;
            chvec.push_back('+');
        }
        if (start >= num) {
            if (stack.top() > num) {
                possible = false;
            } else if (stack.top() == num) {
                stack.pop();
                chvec.push_back('-');
            }
        }
    }
    if (possible) {
        for (int i = 0; i < chvec.size() - 1; i++) {
            printf("%c\n", chvec[i]);
        }
        printf("%c", chvec[chvec.size() - 1]);
    } else {
        printf("NO");
    }
}
