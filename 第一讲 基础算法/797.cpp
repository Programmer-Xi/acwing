#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m,a[N],d[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        d[i]=a[i]-a[i-1];
    }
    for(int i=1;i<=m;i++)
    {
        int  l,r,num;
        cin>>l>>r>>num;
        d[l]+=num;
        d[r+1]-=num;
    }
    for(int i=1;i<=n;i++)
    {
        a[i]=a[i-1]+d[i];
        cout<<a[i]<<" ";
    }
    return 0;
}