#include <iostream>
#include <string>
#include <vector>

#define CAPACITY 1024

using namespace std;

int main(void) {

    vector<int> stack;
    int n;
    int num;
    string com = "";
    scanf("%d", &n);
    while (n != 0) {
        num = 0;
        cin >> com;
        if (com == "push") {
            cin >> num;
            stack.push_back(num);
            n--;
            continue;
        } else if (com == "pop") {
            if (stack.empty()) {
                printf("-1");
            } else {
                int pop = stack.back();
                printf("%d", pop);
                stack.pop_back();
            }
        } else if (com == "size") {
            int size = stack.size();
            printf("%d", size);
        } else if (com == "empty") {
            if (stack.empty()) {
                printf("1");
            } else {
                printf("0");
            }
        } else if (com == "top") {
            if (stack.empty()) {
                printf("-1");
            } else {
                int top = stack.back();
                printf("%d", top);
            }
        } else {
            return -1;
        }
        n--;
        printf("\n");
    }
}
