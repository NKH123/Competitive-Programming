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
#define llp 1000000007
#define mod 1000000007

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
int n;
vi N;
int ct=0;
int eval(){
    // deb(N);
    int ans=0;
    for(int i=0;i<N.size();i++){
        ans=ans*10+N[i];
    }
    return ans;
}
bool check(){
    int f=0;
    for(int i=0;i<N.size();i++){
        if(N[i]==3){
            f=1;
        }
    }
    if(!f)return false;
    f=0;
    for(int i=0;i<N.size();i++){
        if(N[i]==5){
            f=1;
        }
    }
    if(!f)return false;
    f=0;
    for(int i=0;i<N.size();i++){
        if(N[i]==7){
            f=1;
        }
    }
    if(!f)return false;
    return true;
}
void fun(){
    if(eval()>n){
        return;
    }
    else{
        N.PB(3);
        if(eval()<=n && check())ct++;
        fun();
        N.pop_back();
        N.PB(5);
       if(eval()<=n && check())ct++;
        fun();
        N.pop_back();
        N.PB(7);
       if(eval()<=n && check())ct++;
        fun();
        N.pop_back();
    }

}
int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    fun();
    cout<<ct<<"\n";

	return 0;
}