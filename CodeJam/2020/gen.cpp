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
int x=0, y=0;
int limit;

set<pair<int,int> >P;
void fun(int I){
    // deb("******");
    // deb(x);
    // deb(y);
    // deb("******");
    P.insert({x,y});

    // if(P.size()>limit){
    //     // return;
    //     deb(P);
    //     exit(0);
    // }
    if(I==limit){
        return;
    }
    // x+=(1<<i);
    // fun(i+1);
    // x-=(1<<i);
    // x-=(1<<i);
    // fun(i+1);
    int X=x,  Y=y;
    // for(int i=-1;i<=1;i++){
    //     for(int j=-1;j<=1;j++){
    //         if((i==0 && j==0 )||(i==1 && j==1) ){
    //             continue;
    //         }
    //         else{
    //             x=X;
    //             y=Y;
    //             if(i==1)
    //             x+=i*(1LL<<I);
    //             else
    //             x-=(1LL<<I);

    //             if(j==1){
    //                 y+=i*(1LL<<I);
    //             }
    //             else{

    //                 y-=(1LL<<I);
    //             }

                // cout<<"from "<<X<<" "<<Y<<"\n";
                // cout<<"to "<<x<<" "<<y<<"\n";
    //             fun(I+1);
    //             x=X;
    //             y=Y;
    //             // x=X;
    //             // y=Y;
    //             // cout<<"from "<<X<<" "<<Y<<"\n";
    //             // cout<<"to "<<x<<" "<<y<<"\n";
    //             // y+=i*(1LL<<I);
    //             // fun(I+1);
    //             // x=X;
    //             // y=Y;
    //         }
    //     }
    // }
    //x jumps right
    deb(I);
    x=x+(1LL<<I);
    deb("right");
    cout<<"from "<<X<<" "<<Y<<"\n";
    cout<<"to "<<x<<" "<<y<<"\n";
    fun(I+1);
    deb(I);
    //x jumps left
    x=X;
    deb("left");
    x-=(1LL<<I);

                cout<<"from "<<X<<" "<<Y<<"\n";
                cout<<"to "<<x<<" "<<y<<"\n";
    fun(I+1);
    deb(I);
    x=X;
    deb("up");
    y+=(1LL<<I);

                cout<<"from "<<X<<" "<<Y<<"\n";
                cout<<"to "<<x<<" "<<y<<"\n";
    fun(I+1);
    deb(I);

    y=Y;
    deb("down");
    y-=(1LL<<I);

                cout<<"from "<<X<<" "<<Y<<"\n";
                cout<<"to "<<x<<" "<<y<<"\n";
    fun(I+1);
    // deb(I);
    x=X;
    y=Y;


    //y up


    //y down




}

int32_t main(){
    ios::sync_with_stdio(false);
    cin>>limit;
    fun(0);
    // deb(P);

    deb("YOLO");
    for(auto g:P){
        int X=abs(g.F);
        int Y=abs(g.S);
        if(__builtin_popcount((X|Y)+1)!=(1)){
            cout<<X<<" "<<Y<<"\n";
        }
    }


    return 0;
}