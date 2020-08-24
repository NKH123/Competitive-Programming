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

bool can1 (int x){
    if(x>=8){
        return true; 
    }
    else{
        return false;
    }
}
bool can2(int x, int y){
    if(x>=8){
        return true;
    }
    else if(x>=6 && y>=2){
        return true;
    }
    else if(x>=4 && y>=4){
        return true;
    }
    return false;
}
bool can3(int x, int y, int z){
    if(x>=8){
        return true;
    }
    else if(x>=6 && y>=2){
        return true;
    }
    else if(x>=4 && y>=4){
        return true;
    }
    else if(x>=4 && y>=2 && z>=2){
        return true;
    }
    return false;
}

set<pair<int, int> >S;
map<int, int>M;
bool check(){
    if(S.size() == 0){
        return false;
    }
    else if(S.size()==1){
        auto top1 = *(S.begin());

        bool result=can1(-(top1.F));
        return result;
    }
    else if(S.size() == 2){
        auto top1 = *(S.begin());
        S.erase(S.begin());
        auto top2 = *(S.begin());
        bool result=can2(-(top1.F), -(top2.F));
        S.insert(top1);
        return result;

    }
    else{
        auto top1 = *(S.begin());
        S.erase(S.begin());
        auto top2 = *(S.begin());
        S.erase(S.begin());
        auto top3 = *(S.begin());
        bool result=can3(-(top1.F), -(top2.F), -(top3.F));
        S.insert(top1);
        S.insert(top2);
        return result;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a;
    a.resize(n);
    M.clear();
    S.clear();
    REP(i,0,n){
        cin>>a[i];
        M[a[i]]++;
    }
    for(auto g:M){
        S.insert({-g.S, g.F});
    }
    int q;
    cin>>q;
    while(q--){
        char A;
        int x;
        cin>>A>>x;
        int f=0;
        if(A=='+'){
            if(M[x]!=0){
                S.erase(S.find({-M[x],x}));
            }
            M[x]++;
            S.insert({-M[x],x});
            
        }
        else{
            S.erase(S.find({-M[x],x}));
            M[x]--;
            if(M[x]!=0){
                 S.insert({-M[x],x});
            }
        }
        if(check()){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }

    return 0;
}