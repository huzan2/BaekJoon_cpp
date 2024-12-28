#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, k;
    cin >> n >> k;
    // 2개의 역량 증가량을 더해서 큰 순서로 정렬
    priority_queue<int> sum12;
    priority_queue<int> sum23;
    priority_queue<int> sum13;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        sum12.push(a + b);
        sum23.push(b + c);
        sum13.push(a + c);
    }
    int rst1 = 0, rst2 = 0, rst3 = 0;
    // 정렬된 max heap에서 k개를 선택
    for (int i = 0; i < k; i++)
    {
        rst1 += sum12.top();
        rst2 += sum23.top();
        rst3 += sum13.top();
        sum12.pop();
        sum23.pop();
        sum13.pop();
    }
    // 가장 큰 값 출력
    cout << max({rst1, rst2, rst3}) << '\n';
}