#include<bits/stdc++.h>
using namespace std;

const int N=1e5+10;
int n,m,x,a[N],b[N],ans;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m>>x;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=m;i++)
    {
        cin>>b[i];
    }
    int start;
    for(int i=1;i<=n;i++)
    {
        if(a[i]>=x-b[m])
        {
            start=i;
            break;
        }
    }
    int i=start,j=1;
    while(i<=n&&j<=m)
    {
        if(x-a[i]==b[j])
        {
            cout << i - 1 << " " << j - 1;
            break;
        }
        else if(x-a[i]>b[j])
        {
            j++;
        }
        else if(x-a[i]<b[j])
        {
            i++;
            while (a[i] + b[j] >= x)
            {
                j--;
            }
        }
    }
    return 0;
}