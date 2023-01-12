#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    int arr[1001];
    cin >> n;
    arr[0] = -1;
    arr[1] = 1;
    arr[2] = 3;
    for (int i = 3; i <= n; i++) {
        arr[i] = (arr[i - 1] + arr[i - 2] + arr[i - 2]) % 10007;
    }
    cout << arr[n];
}
