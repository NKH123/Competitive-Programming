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
int gcd(int a, int b, int &x, int &y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    int x1, y1;
    int d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

bool find_any_solution(int a, int b, int c, int &x0, int &y0, int &g) {
    g = gcd(abs(a), abs(b), x0, y0);
    if (c % g) {
        return false;
    }

    x0 *= c / g;
    y0 *= c / g;
    if (a < 0) x0 = -x0;
    if (b < 0) y0 = -y0;
    return true;
}


int32_t main(){
    ios::sync_with_stdio(false);
    int n, p, w, d;
    cin>>n>>p>>w>>d;
    int g=__gcd(w, d);
    if(p%g!=0){
        cout<<"-1\n";
        return 0;
    }
    int x0, y0;
    if(find_any_solution(w,d,p, x0, y0,g)){
        // deb(x0);
        // deb(y0);
        int k=0;
        //choose k and minimize
        int div=(d-w)/g;
        int l=0, r=1e18;
        // deb(div);
        while(l<=r){
            int mid=(l+r)/2;
            int newX=x0+mid*((d)/g);
            int newY=y0-mid*((w)/g);
            if((x0+y0+mid*(div))>=0 && (newX>=0 && newY>=0)){
                k=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        // deb(k);
        int X=x0+k*((d)/g);
        int Y=y0-k*((w)/g);
        int D=n-X-Y;
        if(D<0 || Y<0 || X<0 || (X+Y+D)!=n){
            cout<<-1<<"\n";
        }
        else{
            cout<<X<<" "<<Y<<" "<<D<<"\n";
        }
    }       
    else{
        cout<<"-1\n";
    }


    return 0;
}