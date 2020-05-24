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
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define sz(x) (int)(x.size())
#define mod 1000000007
#define endl "\n"
template < typename F, typename S >
ostream& operator << ( ostream& os, const pair< F, S > & p ) {
    return os << "(" << p.first << ", " << p.second << ")";
}

template < typename T >
ostream &operator << ( ostream & os, const vector< T > &v ) {
    os << "{";
    typename vector< T > :: const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "}";
}

template < typename T >
ostream &operator << ( ostream & os, const set< T > &v ) {
    os << "[";
    typename set< T > :: const_iterator it;
    for ( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << *it;
    }
    return os << "]";
}

template < typename F, typename S >
ostream &operator << ( ostream & os, const map< F, S > &v ) {
    os << "[";
    typename map< F , S >::const_iterator it;
    for( it = v.begin(); it != v.end(); it++ ) {
        if( it != v.begin() ) os << ", ";
        os << it -> first << " = " << it -> second ;
    }
    return os << "]";
}

#define deb(x) cerr << #x << " = " << x << endl;



int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vector<int>nos;
    map<int, int>M;
    while(t--){
       int n,m;
       cin>>n>>m;
       M.clear();
       int ans=(1LL<<m)-1;
       ans=(ans/2);
       nos.clear();
       for(int i=0;i<n;i++){
        string s;
        cin>>s;
        int N=0;
        for(int j=s.size()-1;j>=0;j--){
            int pos=s.size()-j-1;
            if(s[j]=='1'){
                N=N+(1LL<<pos);
            }
        }
        nos.push_back(N);
       }
       sort(nos.begin(),nos.end());
       int tot=(1LL<<n);
       // deb(nos);
       for(int i=0;i<nos.size();i++){

            if((tot%2)==0){
                if(nos[i]<ans){
                    ans++;
                }
                else if(nos[i]==ans){
                    ans++;
                }
                else{

                }
            }
            else{
                if(nos[i]<ans){

                }
                else if(nos[i]==ans){
                    while(M[ans-1]==1){
                        ans--;
                    }
                    ans--;
                }
                else{
                    while(M[ans-1]==1){
                        ans--;
                    }
                    ans--;
                }
            }
            M[nos[i]]=1;
            tot--;
       }
       vector<int>Ans;
       Ans.clear();
       while(ans>0){
            Ans.PB(ans%2);
            ans/=2;
       }
       // cout<<ans<<"\n";
       while(Ans.size()<m){
         Ans.push_back(0);
       }
       reverse(Ans.begin(),Ans.end());
       for(int i=0;i<Ans.size();i++){
        cout<<Ans[i];
       }
       

       cout<<"\n";

    }

    return 0;
}