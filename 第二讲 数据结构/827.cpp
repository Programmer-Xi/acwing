#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int l[N],r[N],e[N],idx,m;

//节点 k 右侧插入
void insert(int k,int x)
{
    e[idx]=x;
    l[idx]=k;
    r[idx]=r[k];
    l[r[k]]=idx;
    r[k]=idx;
    idx++;
}

void remove(int k)
{
    l[r[k]]=l[k];
    r[l[k]]=r[k];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    r[0]=1,l[1]=0,idx=2;
    cin>>m;
    int x,k;
    for(int i=1;i<=m;i++)
    {
        string op;
        cin>>op;
        if(op=="L")
        {
            cin>>x;
            insert(0,x);
        }
        if(op=="R")
        {
            cin>>x;
            insert(l[1],x);
        }
        if(op=="D")
        {
            cin>>k;
            remove(k+1);
        }
        if(op=="IL")
        {
            cin>>k>>x;
            insert(l[k+1],x);
        }
        if(op=="IR")
        {
            cin>>k>>x;
            insert(k+1,x);
        }
    }
    for(int i=r[0];i!=1;i=r[i])
    {
        cout<<e[i]<<" ";
    }
    return 0;
}