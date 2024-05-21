#include<bits/stdc++.h>
using namespace std;

const int N=3e5+10;
typedef pair<int,int> pii;
int n,m;
vector<int> alls;
vector<pii> add,ins;
long long a[N],s[N];

int find(int x)
{
    int l=0,r=alls.size()-1;
    while(l<r)
    {
        int mid=l+(r-l)/2;
        if(alls[mid]<x) l=mid+1;
        else r=mid;
    }
    return l+1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int x,c;
        cin>>x>>c;
        add.push_back({x,c});
        alls.push_back(x);
    }
    for(int i=1;i<=m;i++)
    {
        int l,r;
        cin>>l>>r;
        ins.push_back({l,r});
        alls.push_back(l);
        alls.push_back(r);
    }
    sort(alls.begin(),alls.end());
    alls.erase(unique(alls.begin(),alls.end()),alls.end());
    for(auto item:add)
    {
        int x=find(item.first);
        a[x]+=item.second;
    }
    for(int i=1;i<=alls.size();i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(auto item:ins)
    {
        cout<<s[find(item.second)]-s[find(item.first)-1]<<endl;
    }
    return 0;
}