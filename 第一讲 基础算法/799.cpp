#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,a[N],ans,b[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1,j=1;i<=n;i++)
    {
        b[a[i]]++;
        while(j<i&&b[a[i]]>1) b[a[j++]]--;
        ans=max(ans,i-j+1);
    }
    cout<<ans;
    return 0;
}