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
#define remove erase
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
    int n;
    cin>>n;
    vi c(n);
    vi a(n);
    REP(i,0,n){
        char A;
        cin>>A;
        if(A=='1'){
            c[i]=1;
        }
        else{
            c[i]=0;
        }
    }
    REP(i,0,n){
        char A;
        cin>>A;
        if(A=='1'){
            a[i]=1;
        }
        else{
            a[i]=0;
        }
    }
    set<int>clown,acr,both, none;
    for(int i=0;i<n;i++){
        if(a[i]==0 && c[i]==0){
            none.insert(i+1);
        }
        else if(a[i]==0 && c[i]==1){
            clown.insert(i+1);
        }
        else if(a[i]==1 && c[i]==0){
            acr.insert(i+1);
        }
        else if(a[i]==1 && c[i]==1){
            both.insert(i+1);
        }
    }
    vector<int>ff,ss;
    int no=min(clown.size(),acr.size());
    deb(clown);
    deb(acr);
    deb(both);
    deb(none);
    for(int i=0;i<no;i++){
        ff.PB(*clown.begin());
        ss.PB(*acr.begin());
        clown.remove(clown.begin());
        acr.remove(acr.begin());
    }
    if(clown.size()>0){
        if(clown.size()>both.size()){
            cout<<-1<<"\n";
            return 0;
        }
        else{
            for(int i=0;i<clown.size();i++){
                ff.PB(*clown.begin());
                ss.PB(*both.begin());
                clown.remove(clown.begin());
                both.remove(both.begin());
            }
            if(both.size()%2==1){
                cout<<-1<<"\n";
                return 0;
            }
            else{
                for(int i=0;i<(both.size())/2;i++){
                    ff.PB(*both.begin());
                    both.remove(both.begin());
                    ss.PB(*both.begin());
                    both.remove(both.begin());
                }
                if(none.size()%2==1){
                    cout<<-1<<"\n";
                    return 0;
                }
                else{
                    ff.PB(*none.begin());
                    none.remove(none.begin());
                    ss.PB(*none.begin());
                    none.remove(none.begin());
                }
            }
        }
    }
    else{
        if(acr.size()>both.size()){
            cout<<-1<<"\n";
            return 0;
        }
        else{
            for(int i=0;i<acr.size();i++){
                ff.PB(*both.begin());
                ss.PB(*acr.begin());
                clown.remove(clown.begin());
                both.remove(both.begin());
            }
            if(both.size()%2==1){
                cout<<-1<<"\n";
                return 0;
            }
            else{
                for(int i=0;i<(both.size())/2;i++){
                    ff.PB(*both.begin());
                    both.remove(both.begin());
                    ss.PB(*both.begin());
                    both.remove(both.begin());
                    // clown.remove(clown.begin());

                }
                if(none.size()%2==1){
                    cout<<-1<<"\n";
                    return 0;
                }
                else{
                    ff.PB(*none.begin());
                    none.remove(none.begin());
                    ss.PB(*none.begin());
                    none.remove(none.begin());
                }
            }
        }
    }

    REP(i,0,ff.size()){
        cout<<ff[i]<<" ";
    }
    cout<<"\n";


    return 0;
}