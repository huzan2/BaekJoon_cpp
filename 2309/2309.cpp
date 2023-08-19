#include <iostream>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[9] = {
        0,
    };
    int result[7] = {
        0,
    };
    int sum = 0;
    for (int i = 0; i < 9; i++)
    {
        cin >> arr[i];
        sum += arr[i];
    }
    for (int i = 0; i < 8; i++)
    {
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - (arr[i] + arr[j]) == 100)
            {
                int l = 0;
                for (int k = 0; k < 9; k++)
                {
                    if (k == i || k == j)
                    {
                        continue;
                    }
                    else
                    {
                        result[l] = arr[k];
                        l++;
                    }
                }
            }
        }
    }
    sort(result, result + 7);
    for (int i = 0; i < 7; i++)
    {
        cout << result[i] << '\n';
    }
}