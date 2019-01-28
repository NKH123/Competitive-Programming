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
int lor(char a){
    if(a=='d' || a=='f'){
        return 0;
    }
    else{
        return 1;
    }
}
int solve(string s){
    int ans=0;
    for(int i=0;i<s.size();i++){
        if(i==0){
            ans=ans+2;
        }
        else{
            if(lor(s[i-1])==lor(s[i])){
                ans=ans+4;
            }
            else{
                ans=ans+2;
            }
        }
    }
    return ans;
}

int main()
{   ios::sync_with_stdio(false);
//freopen("a.in", "r", stdin);
//freopen("b.in", "r", stdin);
//freopen("c.in", "r", stdin);
//freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
         set<string> ss;
            ss.clear();
            int ans=0;
        while(n--){
           
            string s;
            cin>>s;
            int temp=solve(s);
            //cout<<"temp="<<temp<<"\n";
            if(ss.find(s)!=ss.end()){
                temp=temp/2;
            }
            ss.insert(s);
            ans=ans+temp;


        }
        cout<<ans<<"\n";
    }

    return 0;
}