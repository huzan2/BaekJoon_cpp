#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> v;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < k; j++)
        {
            int temp;
            cin >> temp;
            v.push_back({i + 1, temp}); // 사람의 번호, 카드의 값 순서로 저장
        }
    }
    int idx = 0, value = 0;
    while (v.size() > 1)
    {
        value = v[idx].second;    // 카드의 값 저장
        v.erase(v.begin() + idx); // 선택된 카드 삭제
        idx = (idx + (value - 1)) % v.size();
        // 인덱스가 범위를 초과하거나 음수가 되는 것을 방지하기 위해 모듈로 연산 이용
    }
    cout << v[0].first << ' ' << v[0].second << '\n';
}