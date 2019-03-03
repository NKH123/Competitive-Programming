#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
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
vi a;
ll ccount=0;
vi b(4);
  int n;
bool check1(){
    vector<vector<int>>aa;
    aa.resize(8);
    REP(i,0,8){
        aa[i].resize(4);
    }
     aa[0]={0,2,1,3};
     aa[1]={2,0,3,1};
     aa[2]={2,1,3,0};
     aa[3]={1,2,0,3};
     aa[4]={1,3,0,2};
     aa[5]={3,1,2,0};
     aa[6]={3,0,2,1};
    aa[7]={0,3,1,2};
    for(int i=0;i<8;i++){
        int f=0;
        for(int j=0;j<4;j++){
            if(aa[i][j]!=b[j]){
                f=1;
            }
        }
        if(!f){
            return true;
        }
    }
    return false;
}
bool check(){
    for(int i=2;i<n;i++){
        if(a[i]==a[i-2]){
            return false;
        }
    }

    for(int i=3;i<n;i++){
        for(int j=0;j<4;j++){
            b[j]=a[i-3+j];
        }
        if(check1()){
            return false;
        }
    }
    return true;
}
void solve(int x){
    if(x==n){
        if(check()){
            deb(a);
            ccount++;
        }
        return;
    }
  
    for(int i=0;i<4;i++){
        a[x]=i;
        if(x>=2){
            if(a[x]==a[x-2]){
                continue;
            }
        }
        solve(x+1);
    }
}
int main(){
	ios::sync_with_stdio(false);

    int t;
    cin>>t;
    while(t--){
        ccount=0;
      
        cin>>n;
         a.resize(n);
        solve(0);
       
        deb(a);
        deb(ccount);
    }


	return 0;
}