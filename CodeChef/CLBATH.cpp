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

 long long gcd( long long a, long long b) // Euclidean algorithm
    {
        return b==0 ? a : gcd(b,a%b);
    }
int main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    while(n--){
        ll v1,t1,v2,t2,v3,t3;
        cin>>v1>>t1>>v2>>t2>>v3>>t3;
        ll a=(t1-t3);
        ll b=(t2-t3);
        if((a>0 && b>0 )||(a<0 && b<0) ){
     
            cout<<"NO\n";
            continue;
        }
        a=abs(a);
        b=abs(b);
        ll x,y;
       
     
        if( (a==0 || b==0) && !(a==0 && b==0)){
        
            if(a==0){
                x=v3;
            
                if(x>(v1)){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
            else
            if(b==0){

                y=v3;
         
                if(y>(v2)){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }
            }
        }
        else if(a==0 && b==0){
       
            if(v3>(v1+v2)){
                cout<<"NO\n";
            }
            else cout<<"YES\n";
        }
        else{
            ll LCM=(a*b)/gcd(a,b);
          
            x=LCM/a;
            y=LCM/b;
        
            int k=ceil((v3*1.0)/(x+y));
        
            x=k*x;
            y=k*y;
         
            if(x>v1 || y>v2){
                cout<<"NO\n";
            }
            else{
                cout<<"YES\n";
            }
        }
        
    }



    return 0;
}