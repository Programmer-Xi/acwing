#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int m,ne[N],e[N],idx=0,head=-1;

void add_to_head()
{
    int x;
    cin>>x;
    e[idx]=x;
    ne[idx]=head;
    head=idx;
    idx++;
}

void remove()
{
    int k;
    cin>>k;
    if(!k) head=ne[head];
    ne[k-1]=ne[ne[k-1]];
}

void add()
{
    int k,x;
    cin>>k>>x;
    ne[idx]=ne[k-1];
    ne[k-1]=idx;
    e[idx]=x;
    idx++;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    memset(ne,-1,sizeof(ne));
    cin>>m;
    for(int i=1;i<=m;i++)
    {
        char op;
        cin>>op;
        if(op=='H')
        {
            add_to_head();
        }
        else if(op=='D')
        {
            remove();
        }
        else if(op=='I')
        {
            add();
        }
    }
    for(int i=head;i!=-1;i=ne[i])
    {
        cout<<e[i]<<" ";
    }
    return 0;
}