#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, l, h;
    cin >> n >> l >> h;
    priority_queue<int> score;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        score.push(temp);
    }
    for (int i = 0; i < h; i++)
    {
        score.pop();
    }
    double cnt = 1;
    double avg = (double)score.top();
    score.pop();
    cout.precision(15);
    while (score.size() > l)
    {
        int temp = (double)score.top();
        cnt++;
        double oldWeight = (cnt - 1) / cnt;
        double newWeight = 1 / cnt;
        avg = (avg * oldWeight) + (newWeight * temp);
        score.pop();
    }
    cout << avg << '\n';
}