#include<bits/stdc++.h>
using namespace std;

int lowbit(int x)
{
    return x&(-x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int num,ans=0;
        cin>>num;
        while(num)
        {
            num-=lowbit(num);
            ans++;
        }
        cout<<ans<<" ";
    }
}