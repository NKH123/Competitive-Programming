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
ostream &operator << ( ostream & os, const multiset< T > &v ) {
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

class PosNegDice{
    public:
    vector<int> evaluateRoll(int t, vector<int>pos, vector<int>neg){
        vector<int>ans;
        ans.push_back(0);
        multiset<int>Pos, Neg;
        Pos.clear();
        Neg.clear();
        ans.push_back(0);
        int a[501];
        memset(a,0,sizeof(a));
        for(int i=0;i<pos.size();i++){
            a[pos[i]]++;
            Pos.insert(pos[i]);
        }
        int b[501];
        memset(b,0,sizeof(b));
        for(int i=0;i<neg.size();i++){
            b[neg[i]]++;
            Neg.insert(neg[i]);
        }
        int c[501];
        deb(Pos);
        deb(Neg);
        memset(c,0,sizeof(c));
        for(int i=0;i<501;i++){
            c[i]=min(a[i],b[i]);
            if(c[i]>0){
                for(int j=0;j<c[i];j++){
                    Pos.erase(Pos.find(i));
                    Neg.erase(Neg.find(i));
                }
            }
        }
        int f=0;
        deb(Pos);
        deb(Neg);
        for(auto g:Pos){
            if(g<=t){
                f=1;
            }
        }
        ans[0]=f;
        ans[1]=Neg.size();
        return ans;
        
        
            
    }
};


int32_t main(){
    ios::sync_with_stdio(false);
    PosNegDice P;
    vi a={1,6,2};
    vi b={6};
    deb(a);
    deb(b);
    deb(P.evaluateRoll(1,a,b));

    return 0;
}