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
    vi P, N;
    vi a;
    while(t--) {
        int n;
        cin>>n;
        P.clear();
        a.clear();
        N.clear();
        for(int i=0; i<n; i++) {
            int X;
            cin>>X;
            a.PB(X);
            if(X>=0) {
                P.PB(X);
            } else {
                N.PB(X);
            }
        }
        if (n==5) {
            int ans = 1;
            for(int i=0; i<n; i++) {
                ans=ans*a[i];
            }
            cout<<ans<<"\n";
            continue;
        }
        sort(a.begin(), a.end());
        if (N.size()!=0) {
            sort(N.begin(), N.end());
        }
        if (P.size()!=0) {
            sort(P.begin(), P.end());
        }
        // deb(1);
        int sz=P.size();
        int ans = 0;
        int ans5 = 1;
        if (P.size()>=5) {

            for(int i=sz-1;i>=(sz-5) ;i--) {
                ans5 = ans5*P[i];
            }
            ans = ans5;
        }
        // deb(2);
        if (P.size()>=3) {
            int ans3 = 1;
            // // deb(P.size());
            int sz=P.size();
            for(int i=sz-1;i>=(sz-3) ;i--) {
                // // deb(i);
                ans3 = ans3*P[i];
            }
            // deb("yo");
            if (N.size()>=2) {
                int n2=1;
                for(int i=0; i<2; i++) {
                    n2=n2*N[i];
                }
                ans = max(ans, (ans3*n2));
            }
        }
        // deb(3);
        if (P.size()>=1) {
            int ans1=P[sz-1];

            if (N.size()>=4) {
                int n4=1;
                for(int i=0; i<4; i++) {
                    n4=n4*N[i];
                }
                ans = max(ans, (ans1*n4));
            }
        }
        // deb(4);
        if (P.size()==0) {
            int ans0=1;
            int szz=N.size();
            for(int i=szz-1; i>=(szz-5); i--) {
                ans0=ans0*N[i];
            }
            ans=ans0;
        }
        // deb(5);
        cout<<ans<<"\n";

        
    }

    return 0;
}