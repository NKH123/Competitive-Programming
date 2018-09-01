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
    int t;
    cin>>t;
    while(t--){
        int d,n;
        cin>>d>>n;
        string s;
        cin>>s;
        //string S;
        string S;
        int a[26];
        memset(a,0,sizeof(a));
        for(int i=0; i<d;i++){
            //a[i]=1;
            S=S+char('a'+i);
        }
        for(auto g:s){
            a[g-'a']=1;

        }
       /* for(auto g:a){
            cout<<g<<" ";
        }
        cout<<"\n";*/
        /*for(auto g:S){
            if(a[g-'a']){
                g='-';
            }
        }*/
        for(int i=0; i<S.size();i++){
            if(a[S[i]-'a']){
                S[i]='-';
            }
        }
        string ans;
        //cout<<"S is:"<<S<<"\n";
        for(int i=0; i<S.size();i++){
            if(S[i]!='-'){
                ans+=S[i];
            }
        }
        for(int i=0; i<n;i++){
            cout<<ans;
        }
        cout<<"\n";


    }
    return 0;
}
