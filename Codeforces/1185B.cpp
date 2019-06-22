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

int n;
string s, t;

int Count(int J, char a){
    int ct=0;
    for(int i=J;i<t.size();i++){
        if(t[i]==a)ct++;
        else break;
    }
    return ct;
}


int32_t main(){
    ios::sync_with_stdio(false);
    cin>>n;
    while(n--){

        cin>>s>>t;
        if(t.size()<s.size()){
            cout<<"NO\n";
            continue;
        }
        int I=0;
        int minlen=0;
        int maxlen=0;
        int J=0;
        int f=0;
        for(int i=0;i<26;i++){
            char a='a'+i;
            if(s[s.size()-1]!=a){
                s+=a;
                break;
            }
        }
        for(int i=0;i<s.size();i++){
            if(J==t.size()){
                cout<<"NO\n";
                f=1;
                break;
            }
            if(i==0){
                continue;
            }
            else{
                if(s[i]!=s[i-1]){
                    minlen=(i-1)-I+1;
                    int ct=Count(J,s[i-1]);
                    J+=(ct);
                    if(ct<minlen){
                        cout<<"NO\n";
                        f=1;
                        break;
                    }
                    I=i;
                }
            }
        }
        if(f==1){
            continue;
        }
        if(J!=t.size()){
            int f=0;
            for(int i=J;i<t.size();i++){
                if(t[i]!=t[i-1]){
                    f=1;
                    cout<<"NO\n";
                    break;
                }
            }
            if(f==1)continue;
        }
        cout<<"YES\n";
    }



    return 0;
}