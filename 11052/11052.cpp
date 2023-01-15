#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp, mxtemp = 0;
    cin >> n;
    int p[10001];
    int arr[10001];
    p[0] = -1;
    arr[0] = -1;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }
    arr[1] = p[1];
    for (int i = 2; i <= n; i++) {
        for (int j = 1; j <= i - 1; j++) {
            temp = max(arr[i - j] + arr[j], p[i]);
            if (temp > mxtemp) {
                mxtemp = temp;
            }
        }
        arr[i] = mxtemp;
    }
    cout << arr[n];
}
