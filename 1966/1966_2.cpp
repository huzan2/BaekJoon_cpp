#include <iostream>
#include <queue>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNum; // 테스트케이스의 수
    cin >> caseNum;
    for (int k = 0; k < caseNum; k++)
    {
        int n, target, count = 0;
        cin >> n >> target;
        queue<pair<int, int>> q; // 문서의 중요도와 인덱스를 같이 저장
        priority_queue<int> pq;  // 가장 높은 중요도를 뽑아내기 위한 max heap
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            q.push({num, i});
            pq.push(num);
        }
        while (!q.empty())
        {
            int pri = q.front().first, doc = q.front().second;
            // 큐의 첫 번째 문서에서 중요도와 인덱스 각각 가져오기
            q.pop();
            if (pri == pq.top())
            { // 우선순위 큐의 top == 남은 문서들 중 가장 높은 중요도
                count++;
                pq.pop();
                if (doc == target)
                {
                    cout << count << '\n';
                    break;
                }
            }
            else // 현재 선택된 문서보다 중요도가 높은 문서가 존재하면
            {
                q.push({pri, doc}); // 큐에 재삽입
            }
        }
    }
}