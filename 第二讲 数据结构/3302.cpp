#include<bits/stdc++.h>
using namespace std;

string s;
stack<int> num;
stack<char> op;

void eval()
{
    int b=num.top();num.pop();
    int a=num.top();num.pop();
    if(op.top()=='+') num.push(a+b);
    if(op.top()=='-') num.push(a-b);
    if(op.top()=='*') num.push(a*b);
    if(op.top()=='/') num.push(a/b);
    op.pop();
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    unordered_map<char,int> pr{{'+',1},{'-',1},{'*',2},{'/',2}};
    cin>>s;
    for(int i=0;i<s.size();i++)
    {
        int x=0;
        if(isdigit(s[i]))
        {
            while(isdigit(s[i]))
            {
                x=x*10+s[i]-'0';
                i++;
            }
            i--;
            num.push(x);
        }
        else if(s[i]=='(') op.push('(');
        else if(s[i]==')')
        {
            while(op.top()!='(') eval();
            op.pop();
        }
        else
        {
            while(op.size()&&pr[op.top()]>=pr[s[i]]&&op.top()!='(')
            {
                eval();
            }
            op.push(s[i]);
        }
    }
    while(op.size()) eval();
    cout<<num.top();
    return 0;
}