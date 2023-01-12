#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, j, max = 0, imax;
    cin >> n;
    vector<double> vec(n);
    for (int i = 0; i < n; i++) {
        cin >> j;
        vec[i] = j;
        if (max < j) {
            max = j;
            imax = i;
        }
    }
    double sum = 0;
    for (int i = 0; i < n; i++) {
        vec[i] = vec[i] / max * 100;
        sum += vec[i];
    }
    cout.precision(10);
    cout << fixed;
    cout << sum / n;
}
