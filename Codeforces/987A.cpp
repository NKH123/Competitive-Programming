#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
#define llp 1000000007

int main()
{   ios::sync_with_stdio(false);
int n;
cin>>n;
string s;
map<int, string> m;
set<int> st;
m[0]="Power";
m[1]="Time";m[2]="Space";m[3]="Soul";m[4]="Reality";m[5]="Mind";
REP(i,0,n)
{
    cin>>s;
    switch(s[0])
    {
       case 'p' :
                st.insert(0);
                break;
       case 'g' :st.insert(1); break;
        case 'b' :st.insert(2); break;
        case 'o' : st.insert(3);break;
        case 'r' :st.insert(4); break;
        case 'y' :st.insert(5); break;
    }
}
int M=6-n;
set<int>:: iterator it;
cout<<M<<"\n";
REP(i,0,6)
{if((it=st.find(i))==st.end())
{
    cout<<m[i]<<"\n";
}

}

    return 0;
}
