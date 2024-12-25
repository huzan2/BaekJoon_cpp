#include <iostream>
#include <vector>

using namespace std;

class doc
{
public:
    int num, pri;
};

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int caseNum; // 테스트케이스의 수
    cin >> caseNum;
    for (int k = 0; k < caseNum; k++)
    {
        int n, target, count = 0;
        vector<doc> q;
        cin >> n >> target;

        for (int m = 0; m < n; m++)
        {
            doc newDoc;
            newDoc.num = m;
            cin >> newDoc.pri;
            q.push_back(newDoc);
        }

        while (count <= n)
        {
            doc head = q.front(); // 벡터의 첫 문서
            bool flag = false;
            for (int i = 1; i < q.size(); i++)
            {
                // 두 번째 문서부터 마지막 문서까지 우선순위 비교
                if (q[i].pri > head.pri)
                {
                    flag = true;
                    break;
                    // 우선순위가 더 높은 문서가 발견되면 반복문 탈출
                }
            }
            q.erase(q.begin()); // 벡터의 첫 문서 삭제
            if (flag)           // 우선수위가 더 높은 문서가 발견되었다면
            {
                q.push_back(head); // 해당 문서를 벡터의 마지막에 push
            }
            else // 우선순위가 더 높은 문서가 없었다면
            {
                count++;                // 출력한 문서의 수 증가
                if (head.num == target) // 문제에서 요구한 문서인지 확인
                {
                    cout << count << '\n';
                    break;
                }
            }
        }
    }
}