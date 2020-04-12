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
    int n;
    string s;
    cin>>n;
    cin>>s;
    set<int>LR;
    set<int>LB;
    set<int>LG;
    set<int>RR;
    set<int>RB;
    set<int>RG;
    for(int i=1;i<n;i++){
        if(s[i]=='R'){
            RR.insert(i);
        }
        if(s[i]=='G'){
            RG.insert(i);
        }
        if(s[i]=='B'){
            RB.insert(i);
        }
    }
    int ans=0;
    if(s[0]=='R'){
            LR.insert(0);
        }
        if(s[0]=='G'){
            LG.insert(0);
        }
        if(s[0]=='B'){
            LB.insert(0);
        }
    for(int i=1;i<n-1;i++){

        if(s[i]=='R'){
            RR.erase(i);
            //GB
            ans+=(LG.size()*RB.size());
            for(auto g:LG){
                if(RB.find(i+i-g)!=RB.end()){
                    ans--;
                }
            }
            //BG
            ans+=(LB.size()*RG.size());
            for(auto g:LB){
                if(RG.find(i+i-g)!=RG.end()){
                    ans--;
                }
            }
            LR.insert(i);
        }
         if(s[i]=='G'){
            RG.erase(i);
            //RB
            ans+=(LR.size()*RB.size());
            for(auto g:LR){
                if(RB.find(i+i-g)!=RB.end()){
                    ans--;
                }
            }
            //BR
            ans+=(LB.size()*RR.size());
            for(auto g:LB){
                if(RR.find(i+i-g)!=RR.end()){
                    ans--;
                }
            }
            LG.insert(i);
            
        }
         if(s[i]=='B'){
            RB.erase(i);
            //RG
            ans+=(LR.size()*RG.size());
            for(auto g:LR){
                if(RG.find(i+i-g)!=RG.end()){
                    ans--;
                }
            }
            //GR
            ans+=(LG.size()*RR.size());
            for(auto g:LG){
                if(RR.find(i+i-g)!=RR.end()){
                    ans--;
                }
            }
            LB.insert(i);
            
        }
    }
    cout<<ans<<"\n";

    return 0;
}