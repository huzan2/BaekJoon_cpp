#include <algorithm>
#include <iostream>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, temp1, temp2;
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
        temp2 = p[i];
        for (int j = 1; j <= i - 1; j++) {
            temp1 = min(p[i - j] + p[j], arr[i - j] + arr[j]);
            if (temp1 < temp2) {
                temp2 = temp1;
            }
        }
        arr[i] = temp2;
    }
    cout << arr[n];
}
