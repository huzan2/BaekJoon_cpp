#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    char err[10]; // 고장난 버튼의 숫자를 담을 배열 선언
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> err[i];
        // 고장난 버튼의 숫자를 배열에 저장
    }
    if (n == 100)
    {
        cout << 0;
        return 0;
        // 현재 채널이 100이므로 n==100인 경우 0 출력
    }
    if (m == 10)
    {
        cout << abs(100 - n);
        return 0;
        // 모든 숫자버튼이 고장난 경우 100-n의 절댓값 출력(+-버튼으로 이동)
    }
    bool ch[1000001];
    for (int i = 0; i <= 1000000; i++)
    {
        ch[i] = true;
        string chnum = to_string(i);
        for (int j = 0; j < chnum.length(); j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (chnum[j] - '0' == err[k] - '0')
                {
                    ch[i] = false;
                    break;
                }
            }
        }
    }
    string strn = to_string(n);
    if (ch[n])
    {
        int result = min((int)strn.length(), abs(100 - n));
        cout << result;
        return 0;
    }
    else
    {
        int up = 0, down = 0, chtemp = n;
        while (!ch[chtemp])
        {
            chtemp++;
            up++;
            if (chtemp > 1000000)
            {
                up = 500000;
                break;
            }
        }
        string upnum = to_string(chtemp);
        chtemp = n;
        while (!ch[chtemp])
        {
            chtemp--;
            down++;
            if (chtemp < 0)
            {
                down = 500000;
                break;
            }
        }
        string downnum = to_string(chtemp);
        int res = min(up + upnum.length(), down + downnum.length());
        int result = min(res, abs(100 - n));
        cout << result;
        return 0;
    }
}