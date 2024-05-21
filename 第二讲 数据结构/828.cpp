#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int m,st[N],top=0;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        string op;
        cin>>op;
        if(op=="push")
        {
            int x;
            cin>>x;
            st[top++]=x;
        }
        if(op=="pop")
        {
            top--;
        }
        if(op=="empty")
        {
            if(top) cout<<"NO"<<endl;
            else cout<<"YES"<<endl;
        }
        if(op=="query")
        {
            cout<<st[top-1]<<endl;
        }
    }
    return 0;
}