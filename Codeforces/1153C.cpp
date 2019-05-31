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
int n;
// void no(){
//     cout<<":(\n";
//     return 0;
// }
vi a;
bool check(){
    vi pref(n,0);
    pref[0]=a[0];
    REP(i,1,n){
        pref[i]=pref[i-1]+a[i];
    }
    if(pref[n-1]!=0){
        return false;
    }
    for(int i=0;i<n-1;i++){
        if(pref[i]<=0){
            return false;
        }
    }
    return true;
}
void solve(int ct){
    if(ct==n){
        if(check()){
            // deb(a);
            REP(i,0,n){
                if(a[i]==1){
                    cout<<"(";
                }
                else{
                    cout<<")";
                }
            }
            cout<<"\n";
        }
    }
    else{
        a[ct]=1;
        solve(ct+1);
        a[ct]=-1;
        solve(ct+1);
    }
}
int32_t main(){
	ios::sync_with_stdio(false);
    string s;
    cin>>n;
    cin>>s;
    n=s.size();
    if(s.size()%2==1){
        cout<<":(\n";
        return 0;
    }
    else{
        int ct=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')ct++;
        }
        if(ct>(n/2)){
            cout<<":(\n";
            return 0;
        }
        else{
            for(int i=0;i<n;i++){
                if(s[i]=='?'){
                    if(ct<(n/2)){
                        s[i]='(';
                        ct++;
                    }
                }
            }
            a.resize(n);
            for(int i=0;i<n;i++){
                if(s[i]=='('){
                    a[i]=1;
                }
                else{
                    s[i]=')';
                    a[i]=-1;
                }
            }
            if(check()){
                cout<<s<<"\n";
            }
            else{
                cout<<":(\n";
                return 0;
            }
        }
    }



    return 0;
}