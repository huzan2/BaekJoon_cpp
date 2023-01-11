#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, temp2, temp3;
    cin >> n;

    vector<int> vec(n + 1);
    vec[0] = 0;
    vec[1] = 0;
    vec[2] = 1;
    vec[3] = 1;

    for (int i = 4; i <= n; i++) {
        int temp2 = 0, temp3 = 0;
        vec[i] = vec[i - 1] + 1;
        if (i % 3 == 0) {
            vec[i] = min(vec[i], vec[i / 3] + 1);
        }
        if (i % 2 == 0) {
            vec[i] = min(vec[i], vec[i / 2] + 1);
        }
    }
    cout << vec[n];
}
