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

bool check(int A, int B, int C, int D){
    vi a;
    a.resize(4);
    a[0]=A;
    a[1]=B;
    a[2]=C;
    a[3]=D;
    sort(a.begin(),a.end());
    double mean=(a[0]+a[1]+a[2]+a[3])/4.0;
    double med=(a[1]+a[2])/2.0;
    double range=a[3]-a[0];
    
    if(range==(mean) && range==(med) && med==(mean)){
        return true;
    }
    else{
            // cout<<"NO\n";
        return false;
    }
}

int32_t main(){
    ios::sync_with_stdio(false);
    int n;
    cin>>n;
    if(n==0){
        cout<<"YES\n";
        cout<<"1\n1\n3\n3\n";
    }

    else if(n==1){
        int A;
        cin>>A;
        int d=3*A;
        if(d>(1e6)){
            cout<<"NO\n";
            return 0;
        }
        int b, c;
        b=2*A;
        c=2*A;
        if(b>(1e6)){
            cout<<"NO\n";
            return 0;
        }
        if(check(A,b,c,d)){
            cout<<"YES\n";
            cout<<b<<"\n"<<c<<"\n"<<d<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(n==2){
        int A, B;
        cin>>A>>B;
        if(A>B){
            swap(A,B);
        }
        int d=3*A;
        int c=4*A-B;
        if((d>0 && d<=1e6) && (c>0 && c<=1e6)){

        } 
        else{
            cout<<"NO\n";
            return 0;
        }
        if(check(A,B,c,d)){
            cout<<"YES\n";
            cout<<c<<"\n"<<d<<"\n";
        }
        else{
            cout<<"NO\n";
        }
    }
    else if(n==3){
        int A, B, C;
        cin>>A>>B>>C;
        int a=A;
        a=min(a,B);
        a=min(a,C);
        int d=3*a;
        // if(d>1e6){
        //     cout<<"NO\n";
        //     return 0;
        // }
        // if(check(A,B,C,d)){
        //     cout<<"YES\n";
        //     cout<<d<<"\n";
        // }
        // else{
        //     cout<<"NO\n";
        // }
        int f=0;
        for(int i=1;i<=1e6;i++){
            if(check(A,B,C,i)){
                f=1;
                cout<<"YES\n";
                cout<<i<<"\n";
                return 0;
            }
        }
        cout<<"NO\n";
        return 0;
    }
    else if(n==4){
        vi a;
        a.resize(4);
        REP(i,0,4){
            cin>>a[i];
        }
        sort(a.begin(),a.end());
        double mean=(a[0]+a[1]+a[2]+a[3])/4.0;
        double med=(a[1]+a[2])/2.0;
        double range=a[3]-a[0];
        if(range==(mean) && range==(med) && med==(mean)){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }



    return 0;
}