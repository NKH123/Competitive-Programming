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
    vi a;
    while(t--){
        int n;
        cin>>n;
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        int m=1;
        vi b;
        b.clear();
        b.resize(n,-1);
        b[0]=0;
        for(int i=1;i<n;i++){
            // if(b[i]==0){
            //     b[i]=m++;
            // }
            // else{
            //     continue;
            // }

            // for(int j=i+1;j<n;j++){
            //         deb(m);
            //     if(__gcd(a[i],a[j])==1){
            //         // a[j]=__gcd(a[i],a[j]);
            //         // b[j]=b[i];
            //         // deb(a[i]);
            //         // deb(a[j]);
            //         if(b[i]==b[j])
            //         b[j]=m++;
            //         // m=max(m,b[j]+1);
            //     }
            // }
            int f=0;
            for(int j=0;j<m;j++){
                int ff=1;
                for(int k=0;k<i;k++){
                    if(b[k]==j)
                    if(__gcd(a[i],a[k])==1){
                        ff=0;
                        break;
                    }
                }
                if(ff==1){
                    f=1;
                    b[i]=j;
                    break;
                }
            }
            if(f==0){
                b[i]=m++;
            }
        }

        cout<<m<<"\n";
        for(int i=0;i<n;i++){
            cout<<b[i]+1<<" ";
        }
        cout<<"\n";
    }

    return 0;
}