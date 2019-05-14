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
    int n;
    cin>>n;
    string s;
    cin>>s;
    vi a(n,0);
    int I=1;
    int cc=0;
    for(int i=0;i<n;i++){
        I=max(I,i+1);
        if(I>=n){
            break;
        }
        if(cc%2==0){
            while(s[i]==s[I]){
                a[I]=1;
                I++;
                if(I>=n){
                    break;
                }
            }
            i=I;

        }
        if(I>=n){
            break;
        }
        else{
            cc++;
        }

    }
    int ct=0;
    for(int i=0;i<n;i++){
        if(!a[i])ct++;
    }
    if(ct%2==1){
        ct--;
    }
    cout<<n-ct<<"\n";
    int C=0;
    // deb(a);
    for(int i=0;i<n;i++){
        if(C>=ct){
            cout<<"\n";
            return 0;
        }
        else{
            if(!a[i]){
                cout<<s[i];
                C++;
            }
        }
    }
    cout<<"\n";


    return 0;
}