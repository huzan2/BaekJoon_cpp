#include <iostream>
#include <string>

using namespace std;

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[26] = {
        0,
    };

    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] < 91) {
            arr[str[i] - 65] += 1;
        } else if (str[i] > 96) {
            arr[str[i] - 97] += 1;
        }
    }
    int max = 0, pre_max = -1, imax;
    for (int i = 0; i < 26; i++) {
        if (arr[i] >= max) {
            pre_max = max;
            max = arr[i];
            imax = i;
        }
    }
    if (max == pre_max) {
        cout << '?';
    } else {
        cout << char(imax + 65);
    }
}
