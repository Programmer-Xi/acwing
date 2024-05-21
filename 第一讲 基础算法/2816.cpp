#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m;
queue<int> qa,qb;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)
    {
        int num;
        cin>>num;
        qa.push(num);
    }
    for(int i=1;i<=m;i++)
    {
        int num;
        cin>>num;
        qb.push(num);
    }
    while(!qa.empty()&&!qb.empty())
    {
        if(qa.front()==qb.front())
        {
            qa.pop();
            qb.pop();
        }
        else
        {
            qb.pop();
        }
    }
    if(!qa.empty())
    {
        cout<<"No";
    }
    else
        cout<<"Yes";
    return 0;
}