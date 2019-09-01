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

int n;
int r[1005][1005],g[1005][1005],Bb[1005][1005];
int a[1005][1005];
int b[1005][1005];
void flood(int I, int J){
    if(I<0 || I>=n || J<0 || J>=n){
        return;
    }
    if(b[I][J]==1){
        return;
    }
    else{
        b[I][J]=1;
        //up
        if(I!=0){
            if(a[I-1][J]==2){
                flood(I-1,J);
            }
        }
        //left
        if(J!=0){
            if(a[I][J-1]==2){
                flood(I,J-1);
            }
        }
        //right
        if(J!=(n-1)){
            if(a[I][J+1]==2){
                flood(I,J+1);
            }
        }
        //down
        if(I!=(n-1)){
            if(a[I+1][J]==2){
                flood(I+1,J);
            }
        }

        //up left
        if(I!=(0) && J!=0){
            if(a[I-1][J-1]==2){
                flood(I-1,J-1);
            }
        }

        //up right
        if(I!=(0) && J!=(n-1)){
            if(a[I-1][J+1]==2){
                flood(I-1,J+1);
            }
        }

        //down left
        if(I!=(n-1) && J!=(0)){
            if(a[I+1][J-1]==2){
                flood(I+1,J-1);
            }
        }
        //down right
        if(I!=(n-1) && J!=(n-1)){
            if(a[I+1][J+1]==2){
                flood(I+1,J+1);
            }
        }
    }
}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin>>n;
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>r[i][j];
            cin>>g[i][j];
            cin>>Bb[i][j];
            int R=r[i][j];
            int G=g[i][j];
            int B=Bb[i][j];
            if(R>(G+B)){
                a[i][j]=1;
            }
            if(G>(R+B)){
                a[i][j]=2;
            }
            if(B>(R+G)){
                a[i][j]=3;
            }
        }
    }
    int ans=0;
    deb("deb");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }

    deb("deb");
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(a[i][j]==2){
                if(b[i][j]==0){
                    ans++;
                    flood(i,j);
                }
                else{

                }
            }
        }
    }
    cout<<ans<<"\n";


    return 0;
}