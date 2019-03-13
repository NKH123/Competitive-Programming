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
vi a,b,c;
vi aa(10),bb(10),cc(10);// aa[10],bb[10],cc[10];
int maxsz;
vi AA,BB,CC;
int f=0;

void fun(int pos,int car){
    deb("***********");
    deb(pos);
    deb(car);
    if(pos>=maxsz){
        if(car==0){
            f=1;
        }
    }
    else{
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                int sum=i+j+car;
                int car=sum/10;
                sum=sum%10;
                if(sum==CC[maxsz-1-pos] && aa[i] && bb[j]){
                    aa[i]--;
                    bb[i]--;
                    AA[pos]=aa[i];
                    BB[pos]=bb[i];
                    deb(i);
                    deb(j);
                    deb(car);
                    fun(pos+1,car);
                    aa[i]++;
                    bb[i]++;
                }
            }
        }
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){
        f=0;
        int A,B,C;
        int n;
        cin>>n;
        cin>>A>>B>>C;
        aa.clear();
        aa.resize(10);
        bb.clear();
        bb.resize(10);
        cc.clear();
        cc.resize(10);

        a.clear();
        b.clear();
        c.clear();  
        while(A>0){
            a.PB(A%10);
            aa[A%10]++;
            A=A/10;
        }
        while(B>0){
            b.PB(B%10);
            bb[B%10]++;
            B=B/10;

        }
        while(C>0){
            c.PB(C%10);
            cc[C%10]++;
            C=C/10;
        }
      
        maxsz=max({a.size(),b.size(),c.size()});
         deb(maxsz);
        while(a.size()<maxsz){
            a.PB(0);
            aa[0]++;
        }
        while(b.size()<maxsz){
            b.PB(0);
            bb[0]++;
        }
        while(c.size()<maxsz){
            c.PB(0);
            cc[0]++;
        }
        reverse(a.begin(),a.end());
        reverse(b.begin(),b.end());
        reverse(c.begin(),c.end());
        deb(a);
        deb(b);
        deb(c);
        CC.resize(c.size());
        REP(i,0,c.size())CC[i]=c[i];
        deb(CC);
        AA.resize(maxsz);
        BB.resize(maxsz);
        deb(aa);
        deb(bb);
        deb(cc);
        fun(0,0);
        /*cout<<"NO\n";
        label1: ;*/
        if(f==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }
    }



	return 0;
}