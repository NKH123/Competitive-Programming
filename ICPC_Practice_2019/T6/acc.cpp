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
bool check(){
    int f=1;
    for(int i=0;i<n;i++){
        int I=i+1;
        if(abs(a[i]-I)<k){
            f=0;
        }
    }
    if(f==0){
        return false;
    }
    else{
        return true;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    
    while(t--){
        cin>>n>>k;
        a.clear();
        a.resize(n+1);
        if(k==0){
            for(int i=1;i<=n;i++){
                cout<<i<<" ";
            }
            cout<<"\n";
            continue;
        }
        else if((2*k)>n){
            cout<<-1<<"\n";
        }
        else{
            int range=2*k;
            for(int i=1;i<=n;i+=range){
                int low=i;
                int high=i+range-1;
                if(high>n){
                    continue;
                }
                int start=low+k;
                for(int j=low;j<(low+k);j++){
                    a[j]=start;
                    start++;
                }
                start=low;
                for(int j=(low+k);j<=high;j++){
                    a[j]=start;
                    start++;
                }
            }
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                    a[i]=i;
                }
            }
            // deb(a);
            int rem=n%(2*k);
            if(rem>0){
                vi b=a;
                vi last;
                int to=n-k;
                for(int i=n;;i--){
                    if(abs(i-a[i])>=k){
                        break;
                    }
                    last.PB(a[i]);
                    a[i-k]=a[i];
                }
                int from=n-k+1;
                
                for(int i=1;i<=n;i++){
                    if(a[i]!=b[i]){
                        a[from]=b[i];
                        from++;
                    }
                    if(from>n){
                        break;
                    }
                }


            }
            for(int i=1;i<=n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";

        }
    }





return 0;
}