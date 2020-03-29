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
    while(t--){
        int a, b, c;
        cin>>a>>b>>c;
        int tot=a+2*b+3*c;
        if(tot%2==1){
            cout<<"NO\n";
        }
        else{
            if((a%2==0) && (b%2==0) &&(c%2==0)){
                cout<<"YES\n";
            }
            else if((a%2==1) && (b%2==1) &&(c%2==1)){
                cout<<"YES\n";
            }
            else{
                int f=1;
                //Divide 3
                // if(c%2==0){
                //     c=0;
                // }
                // else{
                //     c=1;
                //     //2 and 1
                    
                //     //1 1 1
                //     if(a>=3){
                //         a-=3;
                //     }
                //     else if(a>0 && b>0){
                //         a--;
                //         b--;
                //     }
                //     else{
                //         f=0;
                //     }
                // }
                // //Divide 2
                // if(b%2==0){

                // }
                // else{
                //     //1 1
                //     if(a>=2){
                //         a-=2;
                //     }
                //     else{
                //         f=0;
                //     }
                // }

                // //Divide 1
                // if(a%2==0){

                // }
                // else{
                //     f=0;
                // }
                int req=tot/2;
                // int rem=req-3*c;
                int quo=req/3;
                

                if(f==0){
                    cout<<"NO\n";
                }
                else{
                    cout<<"YES\n";
                }


            }
        }
    }



    return 0;
}