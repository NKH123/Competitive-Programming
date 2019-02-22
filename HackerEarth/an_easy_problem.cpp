#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define print(x) cout<<#x<<" is "; for(int i=0;i<x.size();i++){cout<<x[i]<<" ";}cout<<"\n"
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


int main(){
	ios::sync_with_stdio(false);
    int hr,min;
    cin>>hr;

    char c;

    cin>>c;
    cin>>min;
    int x;
    cin>>x;
    ll add=24*60;
    int i=0;
    int f=0;
    int ct=0;
    //trace(min);
    //trace(hr);
    //trace(x);hr+min
    if((hr+min)%x==0){
        f=1;
    }
    else{
        while(ct<=add){
            min=min+1;
            if(min==60){
                hr++;
                if(hr==24){
                    hr=0;
                }
                min=0;
            }
            //min=min%60;   
            int sum=hr/10 +(hr)%10+min/10 +min%10;
            i++;
            if(sum%x==0){
                f=1;
                break;
            }

            ct++;
        }
    }
    if(f==1){
        cout<<i<<"\n";
    }
    else{
        cout<<-1<<"\n";
    }



    return 0;
}