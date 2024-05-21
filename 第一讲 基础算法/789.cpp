#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,q,a[N];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=q;i++)
    {
        int k;
        cin>>k;
        int l=1,r=n;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]<k)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        if(a[l]!=k) cout<<"-1 -1"<<endl;
        else
        {
            cout << l-1 << ' ';
            int l = 1, r = n;
            while (l < r)
            {
                int mid =l+(r-l+1)/2;
                if (a[mid] <= k) l = mid;
                else r = mid - 1;
            }

            cout << l-1 << endl;
        }
    }
    return 0;
}