#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
vector<pii> alls,segs;
int n;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int l,r;
        cin>>l>>r;
        alls.push_back({l,r});
    }
    sort(alls.begin(),alls.end());
    int st=-2e9,ed=-2e9;
//    注释的代码是acwing官方代码
//    for(int i=0;i<n;i++)
//    {
//        if(ed<alls[i].first)
//        {
//            if(st!=-2e9)
//            {
//                segs.push_back({alls[i]});
//            }
//            st=alls[i].first;
//            ed=alls[i].second;
//        }
//        else ed = max(ed, alls[i].second);
//    }
//    if (st != -2e9) segs.push_back({st, ed});
    for(int i=0;i<n;i++)
    {
        if(ed<alls[i].first)
        {
            st=alls[i].first;
            ed=alls[i].second;
            segs.push_back(alls[i]);
        }
        else
        {
            ed = max(ed, alls[i].second);
            segs.back().second=ed;
        }
    }
    if (st == -2e9) cout<<0;
    else cout<<segs.size();
//    上述代码是我自己写的，是每次都对segs最后一项进行处理，而不是最后再把最后一项加上
    return 0;
}
