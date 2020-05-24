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
    int n, k;
    cin>>n>>k;
    int maxi=(n-1)*(n)/2;
    if(k>maxi){
        cout<<"Impossible\n";
        return 0;
    }
    // int nearest=0;
    // for(int i=1;;i++){
    //     int trian=i*(i+1)/2;
    //     if(trian>k){
    //         break;
    //     }
    //     else{
    //         nearest=i+1;
    //     }
    // }
    // int rem=n-nearest;
    // int remk=k-(nearest-1)*(nearest)/2;
    // int single=min(rem,remk);
    // int outside=rem-single;
    vector<char>brac;
    // //deb(1);
    // for(int i=0;i<nearest;i++){
    //     brac.PB('(');
    // }
    // for(int i=0;i<nearest;i++){
    //     brac.PB(')');
    // }
    // //deb(brac);
    // int f=0;
    // if(brac.size()!=0){
    //     f=1;
    //     brac.pop_back();
    // }
    // //deb(2);
    // //deb(single);
    // //deb(brac);
    // for(int i=0;i<single;i++){
    //     brac.PB('(');
    //     brac.PB(')');

    // }
    // if(f==1)
    // brac.PB(')');
    // //deb(4);
    // for(int i=0;i<outside;i++){
    //     brac.PB('(');
    //     brac.PB(')');
    // }
    // //deb(3);
    // for(int i=0;i<brac.size();i++){
    //     cout<<brac[i];
    // }
    // cout<<"\n";
    int rem=k;
    int remb=n;
    int level=0;
    int cur=0;
    int cursum=0;
    int op=0;
    while(cursum<k){
        if(cursum+cur<=k){
            brac.PB('(');
            cursum+=cur;
            cur++;
            
            remb--;
            op++;
        }
        else{
            brac.PB(')');
            cur--;
            op--;
        }
        

    }
    for(int i=0;i<op;i++){
        brac.PB(')');
    }
    if(remb>0){
        for(int i=0;i<remb;i++){
            brac.PB('(');
            brac.PB(')');
        }
    }
    for(int i=0;i<brac.size();i++){
        cout<<brac[i];
    }
    cout<<"\n";


    return 0;
}