#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,k;
int a[N];

void quick_sort(int a[],int l,int r)
{
    if(l>=r) return;
    int i=l-1,j=r+1,x=a[(l+r)>>1];
    while(i<j)
    {
        do i++;while(a[i]<x);
        do j--;while(a[j]>x);
        if(i<j) swap(a[i],a[j]);
    }
    quick_sort(a,l,j);
    quick_sort(a,j+1,r);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    quick_sort(a,1,n);
    cout<<a[k];
}