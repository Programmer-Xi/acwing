#include<bits/stdc++.h>
using namespace std;

string a;
int b;
vector<int> A,C;

void mul(vector<int> &A,int b)
{
    for(int i=0,t=0;i<A.size()||t;i++)
    {
        if(i<A.size())
            t+=A[i]*b;
        C.push_back(t%10);
        t/=10;
    }
    while(C.size()>1&&C.back()==0)
    {
        C.pop_back();
    }
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>b;
    for(int i=a.size()-1;i>=0;i--)
    {
        A.push_back(a[i]-'0');
    }
    mul(A,b);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    return 0;
}