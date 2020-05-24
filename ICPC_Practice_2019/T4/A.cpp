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
    int n,A, b;
    cin>>n>>A>>b;
    vi a(n);
    REP(i,0,n){
        a[i]=1;
    }

    if(b==0 && A!=0){
        int rem=A;
        int maxi=1;
        for(int i=2;i<n;i++){
            a[i]=maxi+1;
            maxi++;
            rem--;
            if(rem==0){
                break;
            }
        }
        if(rem>0){
            cout<<-1<<"\n";
        }
        else{
            for(int i=0;i<n;i++){
                cout<<a[i]<<" ";
            }
            cout<<"\n";
        }
        return 0;
    }
    int sum=1;
    int rem=b;
    int j=0;
    int maxi=1;
    if(rem!=0)
    for(int i=1;i<n;i++){
        a[i]=sum+1;
        maxi=max(maxi,a[i]);
        sum+=(sum+1);
        rem--;
        j=i;
        if(rem==0){
            break;
        }
    }
    // deb(a);
    rem=A;
    // deb(rem);
    // deb(maxi);
    // deb(j);
    if(rem!=0)
    for(int i=j+1;i<n;i++){
        a[i]=maxi+1;
        maxi++;
        rem--;
        if(rem==0){
            break;
        }
    }
    int f=1;
    for(int i=0;i<n;i++){
        if(a[i]>(50000)){
            f=0;
        }
    }
    if(f==0){
        cout<<-1<<"\n";
    }
    else{
        for(int i=0;i<n;i++){
            cout<<a[i]<<" ";
        }
        cout<<"\n";
    }




    return 0;
}