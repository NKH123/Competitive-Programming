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

vi a;
int n, k;
int ans=1e18;
int lt=0;
vector<int>a_temp;
vector<int>bb;
int cost(int i, int j){
    map<int, int>m;
    m.clear();
    for(int I=i;I<=j;I++){
        m[a[I]]++;
    }
    int ans=j-i+1;
    int maxi=-1;
    int ele;
    for(auto g:m){
        // maxi=max(maxi,g.S);/
        if(maxi<g.S){
            ele=g.F;
            maxi=g.S;
        }
    }
    for(int J=i;J<=j;J++){
        a_temp[J]=ele;
    }
    ans-=maxi;
    return ans;
}

void fun(int x){
    // deb(x);
    if(x==(lt)){
        int ct=0;
        int temp=0;
        int start, end=0;
        a_temp=a;
        for(int i=0;i<lt;i++){
            if(ct==0){
                if(bb[i]==1){
                    ct=1;
                    start=i;
                }
            }
            else if(ct==1){
                if(bb[i]==0){
                    end=i-1;
                    ct=0;
                    temp+=cost(start,end);
                    
                }
            }
        }
        int diff=0;
        // deb(a_temp);
        for(int i=1;i<n;i++){
            if(a_temp[i]!=a_temp[i-1]){
                diff++;
            }
        }
        if(diff<=k){
            ans=min(ans,temp);
        }

    }   
    else{
        bb[x]=1;
        fun(x+1);
        bb[x]=0;
        fun(x+1);
    }
}
int32_t main(){
    ios::sync_with_stdio(false);

    int t;
    cin>>t;
    int T=t;
    while(t--){
        ans=1e18;
        cin>>n>>k;
        a.clear();
        a.resize(n);
        REP(i,0,n){
            cin>>a[i];
        }
        int no=n-1;
        lt=no;
        bb.resize(no);
        // deb(no);
        fun(0);
        cout<<"Case #"<<(T-t)<<": "<<ans<<"\n";
    }


    return 0;
}