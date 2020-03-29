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


int a[2][100005];
int n, q;
void print(){
    for(int i=0;i<2;i++){
        for(int j=0;j<=n;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<"\n";
    }
}

bool check(int c){
    if(a[0][c]==1 && a[1][c]==1){
        // return 0;
        return true;
    }
    if(a[0][c]==1 && a[1][c-1]==1){
        // return -1;
        return true;
    }
    if(a[0][c]==1 && a[1][c+1]==1){
        // return 0;
        return true;
    }
    if(a[1][c]==1 && a[0][c+1]==1){
        // return 0;
        return true;
    }
    if(a[1][c]==1 && a[0][c-1]==1){
        // return -1;
        return true;
    }
    if(a[1][c+1]==1 && a[0][c+1]==1){
        // return 1;
        return true;
    }
    if(a[1][c-1]==1 && a[0][c-1]==1){
        // return -1;
        return true;
    }
    return false;

    // return -2;


}
int32_t main(){
    ios::sync_with_stdio(false);
    
    cin >>n>>q;
    vi r(q), c(q);
    REP(i,0,q){
        cin>>r[i]>>c[i];
        r[i]--;
        c[i];
    }
    set<int>S;
    
    memset(a,0,sizeof(a));
    REP(i,0,q){
        a[r[i]][c[i]]=1^a[r[i]][c[i]];
        // cout<<"*************\n";
        // cout<<r[i]<<" "<<c[i]<<"\n";
        // print();
        // deb(S);
        // int qq=check(c[i]);
        // // deb(qq);
        // if(qq==-2){
        //     if(S.find(c[i])!=S.end()){
        //         S.erase(c[i]);
        //     }
        //     if(S.find(c[i]-1)!=S.end()){
        //         S.erase(c[i]-1);
        //     }
        //     if(S.find(c[i]+1)!=S.end()){
        //         S.erase(c[i]+1);
        //     }

        // }
        // else{
        //     if(qq==0){
        //         S.insert(c[i]);
        //     }
        //     else if(qq==-1){
        //         S.insert(c[i]-1);
        //     }
        //     else{
        //         S.insert(c[i]+1);
        //     }
        // }
        if(check(c[i])){
            S.insert(c[i]);
        }
        else{
            if(S.find(c[i])!=S.end()){
                S.erase(c[i]);
            }
        }
        if(check(c[i]-1)){
            S.insert(c[i]-1);
        }
        else{
            if(S.find(c[i]-1)!=S.end()){
                S.erase(c[i]-1);
            }
        }
        if(check(c[i]+1)){
            S.insert(c[i]+1);
        }
        else{
            if(S.find(c[i]+1)!=S.end()){
                S.erase(c[i]+1);
            }
        }
        // deb(S);
        if(S.size()==0){
            cout<<"Yes\n";
        }
        else{
            cout<<"No\n";
        }
    }
    


    return 0;
}