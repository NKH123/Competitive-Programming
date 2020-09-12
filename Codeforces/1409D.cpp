#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (long long i = a; i <b; i++)
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

unsigned long long sum(unsigned long long n) {
    unsigned long long ans = 0;
    while(n>0) {
        ans += (n%10);
        n/=10;
    }
    return ans;
}
unsigned long long get_len(unsigned long long n) {
    unsigned long long len =0;
    while(n>0) {
        len++;
        n=n/10;
    }
    return len;
}
unsigned long long get_ith(unsigned long long n, unsigned long long i) {
    unsigned long long len = get_len(n);
    unsigned long long rel = len - i - 1;
    unsigned long long ret = 1;
    for(unsigned long long i=0; i<rel; i++) {
        ret= ret*10;
    } 
    n = n/ret;
    ret = n%10;
    return ret;

}
int32_t main(){
    ios::sync_with_stdio(false);
    unsigned long long t;
    cin>>t;
    while(t--) {
        unsigned long long n, s;
        cin>>n>>s;
        unsigned long long ans  = 0;
        while(sum(n) > s) {
            // // deb("here");
            // deb("*********************");
            // deb(n);
            vector<int>a;
            a.clear();
            unsigned long long N = n;
            while(N > 0) {
                a.push_back(N%10);
                N/=10;
            }
            // deb(a);
            unsigned long long size = a.size();
            unsigned long long cur = 0;
            a.push_back(0);
            for(int i= size - 1; i>=0; i--) {
                cur += a[i];
                if (cur > s) {
                    unsigned long long car  = 1;
                    for(int j = i + 1; j<=size; j++) {
                        if(car==1) {
                            a[j]+=1;
                            if(a[j]==(10)) {
                                a[j]=0;
                                car =1;
                            } else {
                                car = 0;
                            }
                        }
                    }
                    for(int j=0; j<=i; j++) {
                        a[j] = 0;
                    }
                    break;
                }
            }
            N = 0;
            // deb(a);
            for(int i=((int)a.size()) - 1; i>=0; i--) {
                N = N*10 + a[i];
            }
            ans += (N-n);
            // deb(N);
            n=N;
            // deb(n);
        }
        cout<<ans<<"\n";
    }

    return 0;
}