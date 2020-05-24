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


char a[15][15];

bool check(){
    //horizontal
    int cur=0;
    for(int i=0;i<10;i++){
        cur=0;
        for(int j=0;j<10;j++){
            if(a[i][j]=='X'){
                cur++;
            }
            else{
                cur=0;
            }
            deb(cur);
            if(cur==5){
                return true;
            }
        }
    }

    //vertical
    cur=0;
    for(int j=0;j<10;j++){
        cur=0;
        for(int i=0;i<10;i++){
            if(a[i][j]=='X'){
                cur++;
            }
            else{
                cur=0;
            }
            if(cur==5){
                return true;
            }
        }
    }

    //lr diagonal
    map<int, int>ct;
    // cur=0;
    for(int i=0;i<10;i++){
        // cur=0;
        for(int j=0;j<10;j++){
            if(a[i][j]=='X'){
                ct[i-j]++;
            }
            else{
                ct[i-j]=0;
            }
            if(ct[i-j]==5){
                return true;
            }
        }
    }

    ct.clear();
    //rl diagonal
    for(int i=0;i<10;i++){
        // cur=0;
        for(int j=0;j<10;j++){
            if(a[i][j]=='X'){
                ct[i+j]++;
            }
            else{
                ct[i+j]=0;
            }
            if(ct[i+j]==5){
                return true;
            }
        }
    }


    return false;
}


int32_t main(){
    ios::sync_with_stdio(false);

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++ ){
            cin>>a[i][j];
        }
    }
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++ ){
            // cin>>a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
    int f=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(a[i][j]=='.'){
                // deb(i);
                // deb(j);
                a[i][j]='X';
                if(check()){
                    // deb("yes");
                    f=1;
                    i=100;
                    j=100;
                    break;
                }
                else{

                }

                a[i][j]='.';
            }
        }
    }
    // a[0][2]='X';
    // check();
    if(f==1){
        cout<<"YES\n";
    }
    else{
        cout<<"NO\n";
    }


    return 0;
}