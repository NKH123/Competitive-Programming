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
    int n, ma, mb;
    cin>>n>>ma>> mb;
    vi a(n),b(n),c(n);
    REP(i,0,n){
        cin>>a[i]>>b[i]>>c[i];
    }
    // deb(a);
    // deb(b);
    // deb(c);
    map<pair<int, int> , int>M;
    map<pair<int, int> , int>M1;
    for(int i=0;i<n;i++){
        M1.clear();
        if(M.count({a[i],b[i]})==0)
        M1[{a[i],b[i]}]=c[i];
        else{
           M1[{a[i],b[i]}]=min(c[i],M[{a[i],b[i]}]);
        }
        for(auto g:M){
            int A=g.F.F;
            int B=g.F.S;
            int C=g.S;
            if(M.count({A+a[i],B+b[i]})==0){
                M1[{A+a[i],B+b[i]}]=C+c[i];
            }
            else{
                int cost=M[{A+a[i],B+b[i]}];
                if(cost>C+c[i]){
                    M1[{A+a[i],B+b[i]}]=C+c[i];
                }
            }
        }
        // deb(i);
        // deb(M1);

        for(auto g:M1){
            M[{g.F.F,g.F.S}]=g.S;
        }
        // deb(M);
    }
    int f=0;
    int ans=1e18;
    for(auto g:M){
        int A=g.F.F;
        int B=g.F.S;
        int C=g.S;
        int temp=__gcd(A,B);
        A=A/temp;
        B=B/temp;
        if(ma==A && mb==B){
            f=1;
            ans=min(ans,C);
        }
    }
    // for(auto g: M){
    //     int temp=__gcd(g.F.F,g.F.S);
    //     if((g.F.F/temp)==ma && (g.F.S/temp)==mb){
    //         deb(g);
    //     }
    // }
    if(f==0){
        cout<<-1<<"\n";
    }
    else{
        cout<<ans<<"\n";
    }


    return 0;
}