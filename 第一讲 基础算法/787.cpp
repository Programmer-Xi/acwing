#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,a[N],tmp[N];

void merge_sort(int l,int r)
{
    if(l>=r)
        return;
    int mid=l+(r-l)/2;
    merge_sort(l,mid), merge_sort(mid+1,r);
    int k=0,i=l,j=mid+1;
    while(i<=mid&&j<=r)
    {
        if(a[i]<=a[j])
            tmp[k++]=a[i++];
        else
            tmp[k++]=a[j++];
    }
    while(i<=mid)
        tmp[k++]=a[i++];
    while(j<=r)
        tmp[k++]=a[j++];
    for(i=l,j=0;i<=r;i++,j++)
        a[i]=tmp[j];
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
    for(int i=1;i<=n;i++)
    {
        cout<<a[i]<<" "<<endl;
    }
    return 0;
}