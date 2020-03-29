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
    int k;
    cin>>k;
    vi ct;
    vector<pair<int, int> >moves;
    while(k--){
        int n;
        cin>>n;
        string s;
        string t;
        cin>>s>>t;
        ct.clear();
        ct.resize(26);
        for(int i=0;i<n;i++){
            ct[s[i]-'a']++;
            ct[t[i]-'a']++;
        }
        int f=0;
        for(int i=0;i<26;i++){
            if(ct[i]%2==1){
                f=1;
            }
        }
        if(f==1){
            cout<<"No\n";
        }
        else{
            moves.clear();
            for(int i=0;i<n;i++){
                if(s[i]!=t[i]){
                    int f=0;
                    for(int j=i+1;j<n;j++){
                        if(s[i]==s[j]){
                            moves.PB({j+1,i+1});
                            swap(s[j],t[i]);
                            f=1;
                            break;
                        }
                        
                    }
                    if(f==0){
                            for(int j=i+1;j<n;j++){
                                if(s[i]==t[j]){
                                    moves.PB({j+1,j+1});
                                    swap(s[j],t[j]);
                                    moves.PB({j+1,i+1});
                                    swap(s[j],t[i]);
                                    // f=1;
                                    break;
                                }
                            }
                        }
                }
            }
            cout<<"Yes\n";
            cout<<moves.size()<<"\n";
            for(int i=0;i<moves.size();i++){
                cout<<moves[i].F<<" "<<moves[i].S<<"\n";
            }
        }
    }

        return 0;
    }