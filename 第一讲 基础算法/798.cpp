#include<bits/stdc++.h>
using namespace std;

const int N=1010;
typedef long long ll;
int g[N][N],q,n,m;
ll d[N][N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>q;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            cin>>g[i][j];
            //g[i][j]=g[i][j-1]+g[i-1][j]+d[i][j]-g[i-1][j-1]
            d[i][j]=g[i][j]+g[i-1][j-1]-g[i-1][j]-g[i][j-1];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x1,y1,x2,y2,c;
        cin>>x1>>y1>>x2>>y2>>c;
        d[x1][y1]+=c;
        d[x2+1][y1]-=c;
        d[x1][y2+1]-=c;
        d[x2+1][y2+1]+=c;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            g[i][j]=g[i][j-1]+g[i-1][j]+d[i][j]-g[i-1][j-1];
            cout<<g[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}