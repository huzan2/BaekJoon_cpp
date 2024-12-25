#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> p;
    priority_queue<int, vector<int>, greater<int>> pq;
    // 작은 값부터 튀어나오도록 최소힙 (min heap) 이용
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        pq.push(temp);
    }
    int rst = 0, wait = 0;
    while (!pq.empty())
    {
        int time = pq.top() + wait; // 소요시간+대기시간
        wait += pq.top();           // 앞사람 때문에 기다린 시간 업데이트
        pq.pop();
        rst += time; // 총 소요시간의 합 업데이트
    }
    cout << rst << '\n';
}