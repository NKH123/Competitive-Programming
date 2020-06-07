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
#define endl "\n"
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
    int T;
    cin>>T;
    while(T--){
        int c, h, t;
        cin>>h>>c>>t;
        int ct=1;
        int temp=0;
        double avg=(c+h)/2.0;
        if(t<=avg){
            cout<<2<<"\n";
        }
        else{
            int l=1, r=1e18;
            int ans=0;
            double yoabs=1e18;
            while(l<=r){
                int mid=(l+r)/2;
                int no=(2*mid)-1;
                int cno=no/2;
                int hno=cno+1;
                double temp=1.0*((cno*c)+(hno*h))/(cno+hno);
                if(temp>=(t)){
                    l=mid+1;
                    ans=mid;
                    yoabs=min(yoabs,abs(temp-t));
                }
                else{
                    r=mid-1;
                }
            }
            //check just smaller
            int Ans=ans;
            Ans++;
            int no=(2*Ans)-1;
            int cno=no/2;
            int hno=cno+1;
            double temp=1.0*((cno*c)+(hno*h))/(cno+hno);
            double zabs=abs(temp-t);
            if(zabs<yoabs){
                int AAns=(2*Ans)-1;
                cout<<AAns<<"\n";
            }
            else{
                int AAns=(2*ans)-1;
                cout<<AAns<<"\n";
            }
        }
    }

    return 0;
}