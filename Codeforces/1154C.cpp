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
    int a,b,c;
    cin>>a>>b>>c;
    int ans=0;
    vi F{3,2,2,2,1,1,1};
    vi R{2,2,1,1,1,1,0};
    vi C{2,2,2,1,1,0,0};
    int FF=3,RR=2,CC=2;
    
    vi Ff{1,0,0,1,0,0,1};
    vi Rr{0,1,0,0,0,1,0};
    vi Cc{0,0,1,0,1,0,0};
    for(int i=0;i<7;i++){
        if(a>=F[i] && b>=R[i] && c>=C[i]){
            // deb("**************************");
            // deb(i);
            int ra, rb, rc;
            ra=a-F[i];
            rb=b-R[i];
            rc=c-C[i];
            // deb(ra);
            // deb(rb);
            // deb(rc);
            int temp=(7-i);
            // deb(i);
            int weeks=min(ra/FF,min(rb/RR,rc/CC));
            temp+=7*weeks;
            ra-=weeks*(F[0]);
            rb-=weeks*(R[0]);
            rc-=weeks*(C[0]);
            // deb(weeks);
            // deb(ra);
            // deb(rb);
            // deb(rc);
            // deb(temp);
            /*if(weeks!=0)*/{
            for(int j=0;j<7;j++){
                // if(ra>=F[j] && rb>=R[j] && rc>=C[j]){

                // }
                if(ra>=Ff[j]){
                    ra-=Ff[j];
                }
                else{
                    break;
                }
                if(rb>=Rr[j]){
                    rb-=Rr[j];
                }
                else{
                    break;
                }
                if(rc>=Cc[j]){
                    rc-=Cc[j];
                }
                else{
                    break;
                }
                temp++;

            }
        }
            // deb(temp);
            ans=max(ans, temp);
        }
        else{
            int ra=a, rb=b, rc=c;
            int temp=0;
            for(int j=i;j<7;j++){
                // if(ra>=F[j] && rb>=R[j] && rc>=C[j]){

                // }
                if(ra>=Ff[j]){
                    ra-=Ff[j];
                }
                else{
                    break;
                }
                if(rb>=Rr[j]){
                    rb-=Rr[j];
                }
                else{
                    break;
                }
                if(rc>=Cc[j]){
                    rc-=Cc[j];
                }
                else{
                    break;
                }
                temp++;

            }
            ans=max(temp,ans);
        }
    }
    cout<<ans<<"\n";



	return 0;
}   