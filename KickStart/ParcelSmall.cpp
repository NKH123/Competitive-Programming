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
int a[260][260];
int r,c;
int d[260][260];


int fun(){
    vector<pair<int, int> > q;
    q.clear();
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            if(a[i][j]==1){
                d[i][j]=0;
                q.push_back({i,j});
            }
        }
    }
    while(!q.empty()){
        auto G=q[q.size()-1];
        q.pop_back();
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(a[i][j]==0){
                    d[i][j]=min(d[i][j],abs(G.F-i)+abs(G.S-j));
                    
                }
            }
        }
    }
    int sum=-(1e18);
    for(int i=1;i<=r;i++){
        for(int j=1;j<=c;j++){
            sum=max(sum,d[i][j]);
        }
    }
    return sum;
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int TT=t;
    while(t--){

        cin>>r>>c;
        string s;
        memset(d,1e8,sizeof(d));
        for(int II=1;II<=r;II++){
            for(int JJ=1;JJ<=c;JJ++){
                d[II][JJ]=1e18;
            }
        }
        REP(i,0,r){
            cin>>s;
            REP(j,0,s.size()){
                a[i+1][j+1]=s[j]-'0';
            }
        }
        int ans=1e18;
        ans=min(fun(),ans);
        for(int i=1;i<=r;i++){
            for(int j=1;j<=c;j++){
                if(a[i][j]==0){
                    a[i][j]=1;
                    for(int II=1;II<=r;II++){
                        for(int JJ=1;JJ<=c;JJ++){
                            d[II][JJ]=1e18;
                        }
                    }
                    int ans1=fun();
                    ans=min(ans1,ans);
                    a[i][j]=0;
                }
            }
        }
        cout<<"Case #"<<TT-t<<": "<<ans<<"\n";


    }



    return 0;
}