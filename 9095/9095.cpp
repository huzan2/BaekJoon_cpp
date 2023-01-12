#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int t, n;
    cin >> t;
    int arr[11];
    while (t--) {
        cin >> n;
        arr[1] = 1;
        arr[2] = 2;
        arr[3] = 4;
        for (int i = 4; i <= n; i++) {
            arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 3]);
        }
        cout << arr[n] << '\n';
    }
}
