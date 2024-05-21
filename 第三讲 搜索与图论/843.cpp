#include <bits/stdc++.h>
using namespace std;

const int N = 15;
int n;
bool g[N][N], row[N], col[N];
int dx[] = {1, 1, 1, 0, 0, -1, -1, -1};
int dy[] = {-1, 0, 1, 1, -1, 1, -1, 1};

void dfs(int cnt, int x)
{
    if (cnt == n)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (g[i][j]) cout << "Q";
                else cout << ".";
            }
            cout << endl;
        }
        cout << endl;
        return;
    }
    for (int i = x; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (row[i] || col[j]) continue;
            int flag = 1;
            for (int k = 0; k < 8; k++)
            {
                for (int a = i, b = j; a >= 1 && a <= n && b >= 1 && b <= n; a += dx[k], b += dy[k])
                {
                    if (g[a][b])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (!flag) break;
            }
            if (flag)
            {
                g[i][j] = true;
                row[i] = true;
                col[j] = true;
                dfs(cnt + 1, i + 1);
                g[i][j] = false;
                row[i] = false;
                col[j] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    dfs(0, 1);
    return 0;
}
