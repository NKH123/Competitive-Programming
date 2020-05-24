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

int n, k;
vector<char>brac;
set<int>poss;
bool check(){
    int cur=0;
    for(int i=0;i<2*n;i++){
        if(brac[i]=='('){
            cur++;
        }
        else{
            cur--;
            if(cur<0){
                return false;
            }
        }
    }
    if(cur==0){
        return true;
    }
    else{
        return false;
    }
}
int get(){
    int ans=0;
    int cur=0;
    for(int i=0;i<2*n;i++){
        if(brac[i]=='('){
            ans+=cur;
            cur++;
        }
        else{
            cur--;
        }
    }
    return ans;
}
void fun(int I){
    // deb(I);
    if(I==(2*n)){
        if(check()){

            int K=get();
            poss.insert(K); 
            // if(K==5)
            deb(K);
                deb(brac);
            // }

        }
    }
    else{
        brac[I]='(';
        fun(I+1);
        brac[I]=')';
        fun(I+1);
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    brac.resize(2*n);
    fun(0);
    deb(poss);

    return 0;
}