#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k, l;
    int arr[101][101];
    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> y >> x;
        arr[x][y] = 2;
    }
    cin >> l;
    int t[101];
    char c[101];
    for (int i = 0; i < l; i++)
    {
        cin >> t[i] >> c[i];
    }
    int time = 0;
    arr[1][1] = 1;
    vector<pair<int, int>> snake;
    snake.push_back(make_pair(1, 1));
    bool con = true;
    while (con)
    {
    }
}