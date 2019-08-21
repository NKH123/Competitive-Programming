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



int32_t main(){
    ios::sync_with_stdio(false);
    string s;
    string t;
    cin>>s>>t;
    vector<int>fwd(s.size()+1);
    vector<int>bwd(s.size()+1);
    int n=s.size();
    int j=0;
    for(int i=1;i<=s.size();i++){
        if(j<t.size() && s[i-1]==t[j]){
            j++;
        }
        fwd[i]=j;
    }
    j=0;
    for(int i=s.size();i>=1;i--){
        if(j<t.size() && t[t.size()-j-1]==s[i-1]){
            j++;
        }
        bwd[i]=j;
    }
    int ans=0;
    int r=n;
    // deb(fwd);
    // deb(bwd);
    for(int i=0;i<=n;i++){
        // deb(i);
        if(i==0){
            while(bwd[r]<t.size()){
                r--;
            }
            // deb(r);
            ans=max(ans,r-1);
        }
        else{
            int R=r;

            while(r<=n && (fwd[i]+bwd[r])>=t.size()){
                R=r;
                if(r==n){
                    break;
                }
                r++;
                
            }
            // deb(R);
            ans=max(ans,R-1-i);

        }
        // deb(ans);
    }
    int l=1;
    for(int i=(n+1);i>=0;i--){
        // deb(i);
        if(i==(n+1)){
            while(fwd[l]<t.size()){
                l++;
            }
            // deb(l);
            ans=max(ans,n-l);
            // deb(ans);
        }
        else{
            int L=l;
            while(l>=0 && (fwd[l]+bwd[i])>=t.size()){
                L=l;
                if(l==0){
                    break;
                }
                l--;
            }
            // deb(L);
            // deb(bwd[i]);
            // deb(fwd[L]);
            ans=max(ans,i-L-1);
            // deb(ans);
        }
    }
    cout<<ans<<"\n";
    return 0;
}