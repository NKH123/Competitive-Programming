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


int32_t main(){
	ios::sync_with_stdio(false);
    // int h1, m1;
    // cin>>h1>>m1;
    string s1;
    cin>>s1;
    int h1=(s1[0]-'0')*10+(s1[1]-'0');
    int m1=(s1[3]-'0')*10+(s1[4]-'0');
    string s2;
    cin>>s2;
    int h2=(s2[0]-'0')*10+(s2[1]-'0');
    int m2=(s2[3]-'0')*10+(s2[4]-'0');
    if(h1==h2){
        int mini=(m1+m2)/2;
        if(h1<10){
            cout<<0<<h1<<":";
        }
        else{
            cout<<h1<<":";
        }
        if(mini<10){
            cout<<0<<mini;
        }
        else{
            cout<<mini;
        }
        cout<<"\n";
    }
    else{
        int mins=60-m1;
        int H1=h1+1;
        while(H1<h2){
            mins+=60;
            H1++;
        }
        mins+=m2;
        // deb(mins);
        for(int i=0;i<(mins)/2;i++){
            m1=m1+1;
            if(m1==60){
                m1=0;
                h1++;
            }
        }
        if(h1<10){
            cout<<0<<h1<<":";
        }
        else{
            cout<<h1<<":";
        }
        if(m1<10){
            cout<<0<<m1;
        }
        else{
            cout<<m1;
        }
        cout<<"\n";

    }



	return 0;
}