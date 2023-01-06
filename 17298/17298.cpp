#include <iostream>
#include <stack>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n = 0, temp = 0;
    vector<int> v;
    cin >> n;
    vector<int> ans(n);
    stack<int> s;
    int pos = n - 2;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    s.push(v[n - 1]);
    ans[n - 1] = -1;
    while (pos >= 0) {
        if (s.empty()) {
            ans[pos] = -1;
            s.push(v[pos]);
        }
        if (v[pos] < s.top()) {
            ans[pos] = s.top();
            s.push(v[pos]);
        } else {
            while (!s.empty()) {
                s.pop();
                if (s.empty()) {
                    ans[pos] = -1;
                    s.push(v[pos]);
                    break;
                }
                if (v[pos] < s.top()) {
                    ans[pos] = s.top();
                    s.push(v[pos]);
                    break;
                }
            }
            if (s.empty()) {
                ans[pos] = -1;
                s.push(v[pos]);
            }
        }
        pos--;
    }
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
}
