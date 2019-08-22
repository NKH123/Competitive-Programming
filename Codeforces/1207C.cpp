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
    int t;
    cin>>t;
    set<int>ind;
    while(t--){
        int n, a, b;
        cin>>n>>a>>b;
        string s;
        cin>>s;
        int pipe=n*a;
        int pill=(n+1)*b;
        
        ind.clear();
        for(int i=0;i<s.size();i++){
            if(s[i]=='0'){

            }
            else{
                ind.insert(i);
                if(s[i-1]=='1'){
                    pill=pill+b;
                }
                else{
                    pill=pill+2*b;
                }
            }
        }
        int f=0;
        for(int i=1;i<s.size();i++){
            if(s[i]=='1'){
                if(f==1){

                }
                else{
                    pipe=pipe+a;
                    f=1;
                }
            }
            else{
                if(f==1){
                    auto Next=ind.lower_bound(i);
                    if(Next==ind.end()){
                        pipe=pipe+a;
                        f=0;
                    }
                    else{
                        int Nn=(*Next);
                        if((2*a)>((Nn-i-1)*b)){
                            if(Nn!=(i+1))
                            pill=pill+b;

                        }
                        else{
                            f=0;
                            pipe=pipe+a;
                        }
                    }
                }
            }
        }
        int ans=pill+pipe;
        cout<<ans<<"\n";


    }



    return 0;
}