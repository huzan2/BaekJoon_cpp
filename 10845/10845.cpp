#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    string cmd;
    int num;
    queue<int> queue;
    while (n--) {
        cin >> cmd;
        if (cmd == "push") {
            cin >> num;
            queue.push(num);
        } else if (cmd == "pop") {
            if (queue.empty()) {
                cout << "-1\n";
            } else {
                cout << queue.front() << '\n';
                queue.pop();
            }
        } else if (cmd == "size") {
            cout << queue.size() << '\n';
        } else if (cmd == "empty") {
            if (queue.empty()) {
                cout << "1\n";
            } else {
                cout << "0\n";
            }
        } else if (cmd == "front") {
            if (queue.empty()) {
                cout << "-1\n";
            } else {
                cout << queue.front() << '\n';
            }
        } else if (cmd == "back") {
            if (queue.empty()) {
                cout << "-1\n";
            } else {
                cout << queue.back() << '\n';
            }
        }
    }
}
