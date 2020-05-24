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
        int x;
        cin>>x;
        if(x==0){
            cout<<1<<" "<<1<<"\n";
            continue;
        }
        int f=0;
        for(int i=1;(i*i)<(x);i++){
            if((x%i)==0){
                int I=i;
                int J=x/i;
                if(J<I){
                    swap(I,J);
                }
                int sum=I+J;
                if((sum%2)==1){
                    continue;
                }
                // deb(I);
                // deb(J);
                int diff=J-I;
                int n=sum/2;
                int b=diff/2;
                // deb(n);
                // deb(b);
                // if((b%2==0)){
                //     continue;
                // }
                int mt=n/b;
                int m=((n/b)+1)/2;
                // deb(m);
                for(int jj=m-5;jj<(m+5);jj++){
                    // deb(jj);
                    if((2*jj-1)==0)continue;
                    int cal=2*jj-1;
                    int Cal=n/(cal);
                    if((n%cal)!=0){
                        Cal++;
                    }

                    if((Cal)==b){
                        cout<<n<<" "<<jj<<"\n";
                        f=1;
                        break;
                    }
                }
                // cout<<n<<" "<<m<<"\n";
                // f=1;
                // break;

            }
        }
        if(f==1){
            // continue;
        }
        else{
            cout<<-1<<"\n";
        }
    }



    return 0;
}