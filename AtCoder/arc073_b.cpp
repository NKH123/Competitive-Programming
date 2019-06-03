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

// int dp[]
bool comp(int a, int b){
    return a>b;
}
int32_t main(){
	ios::sync_with_stdio(false);
    int n,W;
    cin>>n;
    cin>>W;
    vi w(n),v(n);
    int mini=1e18;
    REP(i,0,n){
        cin>>w[i]>>v[i];
        if(mini>w[i]){
            mini=w[i];
        }
    }
    vector<int>a,b,c,d;

    REP(i,0,n){
        if(w[i]==mini){
            a.PB(v[i]);
        }
        if(w[i]==mini+1){
            b.PB(v[i]);
        }
        if(w[i]==mini+2){
            c.PB(v[i]);
        }
        if(w[i]==mini+3){
            d.PB(v[i]);
        }
    }
    sort(a.begin(),a.end(),comp);
    sort(b.begin(),b.end(),comp);
    sort(c.begin(),c.end(),comp);
    sort(d.begin(),d.end(),comp);
    for(int i=1;i<a.size();i++){
        a[i]+=a[i-1];
    }
    for(int i=1;i<b.size();i++){
        b[i]+=b[i-1];
    }
    for(int i=1;i<c.size();i++){
        c[i]+=c[i-1];
    }
    for(int i=1;i<d.size();i++){
        d[i]+=d[i-1];
    }
    int ans=-1;
    for(int i=0;i<=a.size();i++){
        for(int j=0;j<=b.size();j++){
            for(int k=0;k<=c.size();k++){
                for(int l=0;l<=d.size();l++){
                    if(mini*i+(mini+1)*j+(mini+2)*k+(mini+3)*l<=W){
                        int temp=0;
                        if(i!=0){
                            temp+=a[i-1];
                        }
                        if(j!=0){
                            temp+=b[j-1];
                        }
                        if(k!=0){
                            temp+=c[k-1];
                        }
                        if(l!=0){
                            temp+=d[l-1];
                        }

                        ans=max(temp, ans); 
                    }
                }
            }
        }
    }

    cout<<ans<<"\n";



	return 0;
}