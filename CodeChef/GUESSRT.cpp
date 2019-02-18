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
vi markglob;
vi markloc;
int n,m,k;
int N;
int prevn;
double premul=1;
double maxans=0;
double locans=0;

void fun(int M){
    if(M==(m+1)){
        //deb(markloc);
       //deb(locans);
     if(maxans<locans){
        maxans=locans;
        REP(i,0,m)markglob[i]=markloc[i];
    }
    return;
}
double loclocans=locans;
double locpremul=premul;
double locn=N;
locans+=premul/N;
premul=premul*(N-1)*1.0/N;
N+=k;
markloc[M-1]=1;
fun(M+1);
locans=loclocans;
premul=locpremul;
N=locn;
N=N%k;
markloc[M-1]=0;
fun(M+1);

}
int main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){

        maxans=0;
        locans=0;
        premul=1.0000000;
        //cin>>n>>k>>m;
        for(n=1;n<=20;n++){
            for( m=1;m<=20;m++){
                maxans=0;
                locans=0;
                premul=1.0000000;
                k=21;
                markloc.clear();
                markglob.clear();
                markloc.resize(m);
                markglob.resize(m);
                N=n;
                fun(1);
                deb(n);
                deb(m);
                deb(markglob);
                deb(maxans);

            }
        }
      /*  markloc.clear();
        markglob.clear();
        markloc.resize(m);
        markglob.resize(m);
        N=n;
        fun(1);
        deb(markglob);
        deb(maxans);*/

    }



    return 0;
}























  /*if(M==1 || markloc[M-2]==0){
        if(M==1)
        locans=locans+(1.0)/N;
        else if(markloc[M-2]==0){
            //locans=locans+(prevn-1)*1.0/(prevn*(N));
            deb("******************inside");
            deb(premul);
            deb(N);
            locans=locans+(premul)*(1.0)/N;
            deb(locans);
            deb("*******************outside");
        }
        markloc[M-1]=1;
    }
    else{
        if(markloc[M-2]==1)
            locans=locans+premul*1.0/N;
        markloc[M-1]=1;
        //N=N+k;
    }*/