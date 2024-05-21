#include<bits/stdc++.h>
using namespace std;

const int N=1010;
typedef long long ll;
int g[N][N],n,m,q;
ll sum[N][N];

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
            sum[i][j]=sum[i][j-1]+sum[i-1][j]+g[i][j]-sum[i-1][j-1];
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x1,x2,y1,y2;
        cin>>x1>>y1>>x2>>y2;
        cout<<sum[x2][y2]-sum[x1-1][y2]-sum[x2][y1-1]+sum[x1-1][y1-1]<<endl;
    }
    return 0;
}