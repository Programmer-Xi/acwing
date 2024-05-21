#include<bits/stdc++.h>
using namespace std;

string a,b;
vector<int> A,B,C;

bool cmp(vector<int> &A,vector<int> &B)
{
    if(A.size()!=B.size())
        return A.size()>B.size();
    for(int i=A.size()-1;i>=0;i--)
    {
        while(A[i]!=B[i])
            return A[i]>B[i];
    }
    return true;
}

void sub(vector<int> &A,vector<int> &B)
{
    for(int i=0,t=0;i<=A.size()-1;i++)
    {
        t=A[i]-t;
        if(i<B.size())
        {
            t-=B[i];
        }
        C.push_back((t + 10) % 10);
        if(t<0) t=1;
        else t=0;
    }
    while (C.size() > 1 && C.back() == 0) C.pop_back();
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
    for(int i=b.size()-1;i>=0;i--)
    {
        B.push_back(b[i]-'0');
    }
    if(!cmp(A,B))
    {
        cout<<"-";
        sub(B,A);
    }
    else sub(A,B);
    for(int i=C.size()-1;i>=0;i--)
    {
        cout<<C[i];
    }
    return 0;
}