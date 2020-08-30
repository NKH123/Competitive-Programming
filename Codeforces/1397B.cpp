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


int power(int a, int b) {
    if(b==0) {
        return 1;
    } else {
        int ans = power(a, b/2);
        ans = ans * ans;
        if(b%2==1) {
            ans = a*ans;
        }
        return ans;
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int ans = 0;
    vi a;
    a.resize(n);
    for(int i=0; i<n;i++) {
        cin>>a[i];
    }
    sort(a.begin(),a.end());
    for(int i=0; i<n;i++) {
        ans +=abs(1-a[i]);
    }
    if(n >= 65 ) {
        cout<<ans<<"\n";  
    } else {
        for(int c = 2; c <=100000; c++) {
            int temp_ans  = 0;
            int log = 0;
            int num = LLONG_MAX;
            while(num > 0) {
                num = num / c;
                log++;
            }
            log--;
            if (n > log) {
                continue;
            }
            for(int i=0; i<n;i++) {
                temp_ans +=abs(power(c,i)-a[i]);
            }
            // deb(c);
            // deb(temp_ans);
            ans= min(ans, temp_ans);
            // deb(ans);
        }
        cout<<ans<<"\n";
    }

    return 0;
}