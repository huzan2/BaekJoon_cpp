#include <iostream>
#include <vector>

// 시간초과

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<int> v;
    vector<int> result;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
        temp = -1;
        int j = i + 1;
        bool b = true;
        while (b) {
            if (j == n) {
                b = false;
            }
            if (v[j] > v[i]) {
                b = false;
                temp = v[j];
            }
            j++;
        }
        // result.push_back(temp);
        cout << temp << " ";
    }
    /*
        int k = 0;
        while (k < n) {
            cout << result[k];
            if (k != n - 1) {
                cout << " ";
            }
            k++;
        }
        */
}
