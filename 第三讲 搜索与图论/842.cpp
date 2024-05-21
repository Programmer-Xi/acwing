#include<bits/stdc++.h>
using namespace std;

const int N=10;
bool use[N];
int d[N],n;

void dfs(int num,int cnt)
{
    if(cnt==n)
    {
        for(int i=1;i<=n;i++)
        {
            cout<<d[i]<<" ";
        }
        cout<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
    {
        if(use[i]) continue;
        use[i]=true;
        d[cnt+1]=i;
        dfs(i,cnt+1);
        use[i]=false;
    }
}

int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        use[i]=true;
        d[1]=i;
        dfs(i,1);
        use[i]=false;
    }
    return 0;
}