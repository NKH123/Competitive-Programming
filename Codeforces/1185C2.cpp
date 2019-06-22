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
int n, M;
vi t;
vector<vector<int> >adj(101);
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n>>M;
    t.resize(n);
    REP(i,0,n)cin>>t[i];
    vi pref(n);
    pref[0]=t[0];
    REP(i,1,n){
        pref[i]=pref[i-1]+t[i];
    }
    for(int i=0;i<n;i++){
        if(i==0){
            cout<<0<<" ";
            adj[t[0]].PB(i);
        }
        else{
            int req=0;
            int ct=0;
            if((pref[i-1]+t[i])>M){
                req=(pref[i-1]+t[i])-M;
                for(int j=100;j>=0;j--){
                    if(adj[j].size()!=0){
                        int mini=req/j;
                        if(req%j!=0){
                            mini++;
                        }
                        int inc=min((int)adj[j].size(),mini);
                        req=req-inc*j;
                        ct+=inc;
                        if(req<=0){
                            j=-100;
                        }
                        if(j==-100){
                            break;
                        }
                    }
                }
            }
            cout<<ct<<" ";
            adj[t[i]].PB(i);
        }
    }
    cout<<"\n";


    return 0;
}