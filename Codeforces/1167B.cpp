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
    vi a;
    a.PB(4);
    a.PB(8);
    a.PB(15);
    a.PB(16);
    a.PB(23);
    a.PB(42);
    int sum=4+8+15+16+23+42;
    vi b(6);
    cout.flush();
    cout<<"? 1 2\n";
    int A;
    cin>>A;
    int aa,bb;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(a[i]*a[j]==A){
                aa=a[i];
                bb=a[j];
                break;
            }
        }
    }
    b[0]=aa;
    b[1]=bb;
    cout<<"? 3 4\n";
    
    cin>>A;
    
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(a[i]*a[j]==A){
                aa=a[i];
                bb=a[j];
                break;
            }
        }
    }
    b[2]=aa;
    b[3]=bb;
    cout<<"? 4 5\n";
    
    cin>>A;
    
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(a[i]*a[j]==A){
                aa=a[i];
                bb=a[j];
                break;
            }
        }
    }
    b[4]=aa;
    b[5]=bb;
    if(b[2]==b[4]){
        swap(b[2],b[3]);
        swap(b[4],b[5]);
    }
    else if(b[2]==b[5]){
        swap(b[2],b[3]);

    }
    else if(b[3]==b[4]){
        swap(b[4],b[5]);
    }
    else if(b[3]==b[5]){

    }
    cout<<"? 2 3\n";
    cin>>A;
    for(int i=0;i<6;i++){
        for(int j=i+1;j<6;j++){
            if(a[i]*a[j]==A){
                aa=a[i];
                bb=a[j];
                break;
            }
        }
    }
    if(b[0]==aa){
        swap(b[0],b[1]);
    }
    else if(b[1]==aa){

    }
    else if(b[0]==bb){
        swap(b[0],b[1]);
    }
    else if(b[1]==aa){

    }
    b[5]=sum;
    for(int i=0;i<5;i++){
        b[5]-=b[i];
    }
    cout<<"!"<<" "<<b[0]<<" "<<b[1]<<" "<<b[2]<<" "<<b[3]<<" "<<b[4]<<" "<<b[5]<<"\n";




	return 0;
}