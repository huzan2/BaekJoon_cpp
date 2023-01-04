#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    queue<int> queue;
    vector<int> result;
    for (int i = 1; i <= n; i++) {
        queue.push(i);
    }
    int temp = 1;
    while (!queue.empty()) {
        if (temp != k) {
            queue.push(queue.front());
            queue.pop();
            temp++;
        } else if (temp == k) {
            result.push_back(queue.front());
            queue.pop();
            temp = 1;
        }
    }
    cout << "<";
    for (int i = 0; i < result.size() - 1; i++) {
        cout << result[i] << ", ";
    }
    cout << result[result.size() - 1] << ">";
}
