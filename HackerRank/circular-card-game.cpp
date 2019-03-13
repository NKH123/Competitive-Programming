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
vi a;

void dfs(int i){
    if(a[i]==-1 || a[i]==0)return;
    if(a[i]==1){
        a[i]=-1;
        if(i!=n-1){
            if(a[i+1]!=-1)
                a[i+1]=1^a[i+1];
        }
        else{
            if(a[0]!=-1)
                a[0]=1^a[0];
        }
        if(i!=0){
            if(a[i-1]!=-1)
                a[i-1]=1^a[i-1];
        }
        else{
           /* if(n!=2)*/{
            if(a[n-1]!=-1)
                a[n-1]=1^a[n-1];
        }
    }
    if(i!=n-1){
            /*if(a[i+1]!=-1)
            a[i+1]=1^a[i+1];*/
        dfs(i+1);
    }
    else{
            /*if(a[0]!=-1)
         
            a[0]=1^a[0];*/
        dfs(0);
    }
    if(i!=0){
            /*if(a[i-1]!=-1)
            a[i-1]=1^a[i-1];*/
        dfs(i-1);
    }
    else{
            /*if(a[n-1]!=-1)
            a[n-1]=1^a[n-1];*/
        dfs(n-1);
    }


}
}
int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;

    while(t--){
        cin>>n;
        a.resize(n);
        REP(i,0,n)cin>>a[i];
          int f=1;
        if(n==2){
            if(a[0]==0 && a[1]==0){
                f=0;
            }
            if(a[0]==0 && a[1]==1){
                f=1;
            }
            if(a[0]==1 && a[1]==0){
                f=1;
            }
            if(a[0]==1 && a[1]==1){
                f=0;
            }
        }
        else{
            for(int i=0;i<n;i++){
                if(a[i]==1){
                    dfs(i);
                }
            }

            for(int i=0;i<n;i++){
                if(a[i]!=-1){
                 f=0;
                 break;
             }
         }
     }
     if(f){
        cout<<"Yes\n";
    }
    else{
        cout<<"No\n";
    }
}   



return 0;
}