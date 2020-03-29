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

void series(int n, int d) 
{ 

    // if S.D. is 0 then print all 
    // elements as 0. 
    vector<double>a(n+1);
    if (d == 0) { 

        // print n 0's 
        for (int i = 1; i <= n; i++) 
            // cout << "0 "; 
            a[i]=0;
        // cout << endl; 
        // return; 
    } 

    // if S.D. is even 
    else if (n % 2 == 0) { 

        // print -SD, +SD, -SD, +SD 
        for (int i = 1; i <= n; i++) { 
            // cout << pow(-1, i) * d << " "; 
            a[i]=pow(-1, i) * d;
        } 
        // cout << endl; 
    } 
    else // if odd 
    { 
        // convert n to a float integer 
        double m = n; 
        double r = (m / (m - 1)); 
        double g = (double)(d * (double)sqrtf(r)); 

        // print one element to be 0 
        // cout << "0 "; 
        a[1]=0;

        // print (n-1) elements as xi derived 
        // from the formula 
        for (int i = 2; i <= n; i++) { 
            // cout << pow(-1, i) * g << " "; 
            a[i]= pow(-1, i) * g;
        } 
        // cout << endl; 
    } 
    int f=1;
    for(int i=1;i<=n;i++){
        if(a[i]>(1e8) || a[i]<(-(1e8))){
            f=0;
        }
    }
    if(f==0){
        printf("-1\n");
    }
    else{
        for(int i=1;i<=n;i++){
            printf("%0.9lf ",a[i] );
        }
        printf("\n");
    }
} 


int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        int n, d;
        cin>>n>>d;
        if(n==1 && d!=0){
            printf("-1\n");
        }
        else
        series(n, d); 
    }


    return 0;
}