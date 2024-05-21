#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int N=110;
int g[N][N],d[N][N],n,m;
queue<pii> q;
int dx[]={1,-1,0,0};
int dy[]={0,0,1,-1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    memset(d,-1,sizeof(d));
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
        }
    }
    q.push({1,1});
    d[1][1]=0;
    while(!q.empty())
    {
        pii t=q.front();
        q.pop();
        for(int i=0;i<=3;i++)
        {
            int a=t.first+dx[i],b=t.second+dy[i];
            if(a<=0||a>n||b<=0||b>m) continue;
            if(d[a][b]!=-1) continue;
            if(g[a][b]!=0) continue;
            d[a][b]=d[t.first][t.second]+1;
            q.push({a,b});
        }
    }
    cout<<d[n][m];
    return 0;
}