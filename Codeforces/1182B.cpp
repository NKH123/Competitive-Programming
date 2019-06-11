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
int h, w;
vector<vector<int> >a;
vector<vector<int> >vis;
int ff=1;
 int sd=-1;
 int las=-1;
 void vert(int I, int J){
    int f=1;
    for(int i=I;i<h;i++){
        if(a[i][J]==0){
            break;
        }
        else{
            las=i;
            vis[i][J]=1;
            if(J!=0 && J!=w-1){
                if(a[i][J-1]==1){
                    if(a[i][J+1]==1){
                        if(sd==-1)
                            sd=i;
                        else{
                            f=0;
                        }
                    }
                    else{
                        f=0;
                    }
                }
                else if(a[i][J+1]==1){
                    f=0;
                }
            }
        }
    }
    if(f==0){
        ff=0;
    }
    if(las==sd){
        ff=0;
    }
    if(sd==-1){
        ff=0;
    }
}
void horz(int I, int J){
    for(int j=J;j>=0;j--){
        if(a[I][j]==0){
            break;
        }
        else{
            vis[I][j]=1;
        }
    }
    for(int j=J+1;j<w;j++){
        if(a[I][j]==0){
            break;
        }
        else{
            vis[I][j]=1;
        }
    }
}
int32_t main(){
	ios::sync_with_stdio(false);

    cin>>h>>w;
    a.resize(h,vector<int>(w));
    vis.resize(h,vector<int>(w,0));
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            char A;
            cin>>A;
            if(A=='.'){
                a[i][j]=0;
            }
            else{
                a[i][j]=1;
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]==1){
                vert(i, j);
                if(ff==0){
                    cout<<"NO\n";
                    return 0;
                }
                horz(sd,j);
                i=h;
                j=w+1;
                break;
            }
        }
    }
    int f=0;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(a[i][j]==1){
                f=1;
            }
            if(a[i][j]==1 && vis[i][j]!=1){
                ff=0;
            }
        }
    }
    if(ff==0 || f==0){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    return 0;
}