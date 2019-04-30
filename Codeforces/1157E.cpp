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

map<int, int> mm;
int32_t main(){
	ios::sync_with_stdio(false);
    int n;
    cin>>n;
    vi a(n);
    vi b(n);

    REP(i,0,n)cin>>a[i];
    REP(i,0,n){
        cin>>b[i];
        mm[b[i]]++;
    }
    vi c(n);
    REP(i, 0 , n){
        int red=n-a[i];
        if(mm.find(red)!=mm.end()){
            auto g=mm.find(red);
            c[i]=0;
            (*g).S--;
            if((*g).S==0){
                mm.erase(g);
            }
        }
        else{
            int L=-1,R=-1;
            mm[red]=0;
            auto g=mm.find(red);
            if(g!=mm.begin()){
                g--;
                // c[i]=(a[i]+g.F)%n;
                L=(*g).F;
                // g.S--;
                // if(g.S==0){
                //     mm.erase(g);
                // }
            }
            else{
                auto g=mm.end();
                g--;
                L=(*g).F;
            }
            g=mm.find(red);
            g++;
            if(g!=mm.end()){
                // c[i]=(a[i]+g.F)%n;
                R=(*g).F;
                // g.S--;
                // if(g.S==0){
                //     mm.erase(g);
                // }
            }
            else{
                g=mm.begin();
                R=(*g).F;
            }
            if(L!=-1 && R!=-1){
                int LL=(a[i]+L)%n;
                int RR=(a[i]+R)%n;
                if(LL<=RR){
                    c[i]=LL;
                    g=mm.find(red);
                    g--;
                    (*g).S--;
                    if((*g).S==0){
                        mm.erase(g);
                    }
                }
                else{
                    c[i]=RR;
                    g=mm.find(red);
                    g++;
                    (*g).S--;
                    if((*g).S==0){
                        mm.erase(g);
                    }
                }
            }
            else if(L!=-1){
                int LL=(a[i]+L)%n;
                c[i]=LL;
                g=mm.find(red);
                g--;
                (*g).S--;
                if((*g).S==0){
                    mm.erase(g);
                }
            }
            else{
                int RR=(a[i]+R)%n;
                c[i]=RR;
                g=mm.find(red);
                g++;
                (*g).S--;
                if((*g).S==0){
                    mm.erase(g);
                }
            }
            g=mm.find(red);
            mm.erase(g);

        }
    }


    REP(i,0,n){
        cout<<c[i]<<" ";
    }
    cout<<"\n";

    return 0;
}