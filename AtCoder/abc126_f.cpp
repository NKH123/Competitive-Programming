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


int32_t main(){
	ios::sync_with_stdio(false);

    int m, k;
    cin>>m>>k;
    int pp=1;
    REP(i,0,m){
        pp=pp*2;
    }
    vi b(2*pp);
    int ct=0;
    for(int i=0;i<b.size();i=i+2){
        b[i]=ct;
        b[i+1]=ct;
        ct++;
    }
    // ct--;
    deb(b);
    int ff=0;
    deb(ct);
    do{

            int f=1;
        for(int i=0;i<ct;i++){
            int st=-1,en=-1;
            for(int j=0;j<b.size();j++){
                 if(b[j]==i && st!=-1){
                    en=j;
                }
                if(b[j]==i && st==-1){
                    st=j;
                }
                
            }
            int Xor=0;
            for(int j=st;j<=en;j++){
                Xor=Xor^b[j];
            }
            if(Xor==k){

            }
            else{
                f=0;
                break;
            }
    }
    // deb("here");
    if(f){
        ff=1;
        deb("yes");
        deb(b);
    }
}while(next_permutation(b.begin(),b.end()));
    if(ff==0){
        deb("No");
    }

return 0;
}