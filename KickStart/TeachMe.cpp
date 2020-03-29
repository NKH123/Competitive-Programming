#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
#define int ll
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int T=t;
    vector<set<int> >c;
    map<set<int>,int >M;
    while(t--){
        int n;
        cin>>n;
        int s;
        cin>>s;
        M.clear();
        c.clear();
        c.resize(n);
        for(int i=0;i<n;i++){
            int C;
            cin>>C;
            for(int j=0;j<C;j++){
                int A;
                cin>>A;
                c[i].insert(A);
            }
            M[c[i]]++;
        }
        int ans=n*(n-1);
        set<int>ss;
        vector<int>temp;
        // deb(M);
        for(int i=0;i<n;i++){
            int no=c[i].size();
            // ss.clear();
            temp.clear();
            for(auto g:c[i]){
                temp.push_back(g);
            }
            // deb("*******************");
            // deb(i);
            // deb(no);
            for(int j=0;j<(1LL<<no);j++){
                ss.clear();
                if(j==0)continue;
                if((j+1)==(1LL<<no)){
                    int Ct=M[c[i]];
                    // deb("*");
                    // deb(c[i]);
                    // deb(Ct);
                    // deb("*");
                    Ct--;
                    ans-=Ct;
                }
                else{
                    for(int J=0;J<no;J++){
                        if(((1LL<<J)&(j))!=0){
                            ss.insert(temp[J]);
                        }
                    }

                    int Ct=M[ss];
                    // deb("*");
                    // deb(ss);
                    // deb(Ct);
                    // deb("*");
                    ans-=Ct;
                }
            }
            // deb("**********************");
        }
        cout<<"Case #"<<(T-t)<<": "<<ans<<"\n";

    }



    return 0;
}