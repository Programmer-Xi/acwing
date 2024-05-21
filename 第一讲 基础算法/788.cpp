#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,a[N],tmp[N];
long long ans;

void merge_sort(int l,int r)
{
    if(l>=r) return;
    int mid=l+(r-l)/2;
    merge_sort(l,mid);
    merge_sort(mid+1,r);
    int i=l,j=mid+1,k=0;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
        {
            tmp[k++]=a[i++];
        }
        else
        {
            tmp[k++]=a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid) tmp[k++]=a[i++];
    while(j<=r) tmp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
    {
        a[i]=tmp[j];
    }
    return;
}

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
    merge_sort(1,n);
    cout<<ans;
    return 0;
}