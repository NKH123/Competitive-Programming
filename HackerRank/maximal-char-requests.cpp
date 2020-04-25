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
int n;
string s;
int q;
int x, y;
vector<vector<int> >ct;
void pre(){
    ct.clear();
    ct.resize(s.size(),vector<int>(26,0));
    for(int i=0;i<n;i++){
        if(i==0){
            ct[i][s[i]-'a']++;
        }
        else{
            for(int j=0;j<26;j++){
                ct[i][j]=ct[i-1][j];
            }
            ct[i][s[i]-'a']++;
        }
    }


}
int get(int x, int y){
    vector<int>ans(26,0);
    int Ans=0;
    // y--;
    // x--;

    for(int i=0;i<26;i++){
        ans[i]=ct[y][i];
        if(x!=0){
            ans[i]-=ct[x-1][i];
        }
    }
    //deb(ans);
    for(int i=25;i>=0;i--){
        if(ans[i]>0){
            return ans[i];
        }
    }
    return 0;
}

int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    cin>>s;
    cin>>q;
    for(int i=0;i<s.size();i++){
        if(s[i]>='A' && s[i]<='Z'){
            s[i]=tolower(s[i]);
        }
    }
    pre();
    //deb(ct);
    while(q--){
        int x, y;
        cin>>x>>y;
        int ans=get(x, y);
        cout<<ans<<"\n";
    }

    return 0;
}