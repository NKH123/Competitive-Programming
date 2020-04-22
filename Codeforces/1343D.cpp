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

bool comp(pair<int, int>A,pair<int, int>B){
    return (A.F+A.S)<(B.F+B.S);
}

int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    vi a;
    vi par;
    map<int,int>S;
    vector<pair<int, int> >A;
    while(t--){
        int n, k;
        cin>>n>>k;
        a.clear();
        par.clear();
        par.resize(2*k+1);
        S.clear();
        REP(i,0,n){
            int A;
            cin>>A;
            a.PB(A);
        }

        int tot=n/2;
        A.clear();
        for(int i=0;i<(n/2);i++){
            S[a[i]+a[n-1-i]]++;
            A.PB({min(a[i],a[n-1-i]),max(a[i],a[n-1-i])});
        }
        sort(A.begin(),A.end(),comp);
        //deb(par);
        //deb(S);
        vi ans;
        ans.clear();
        ans.resize(A.size());
        int sg=0;
        int I=2*k+1;
        for(int i=A.size()-1;i>=0;i--){
            //deb(A);
            //deb(i);
            if(i==(A.size()-1) || (A[i+1].F+A[i+1].S)!=(A[i].F+A[i].S)){

                // int Sum=A[i].F+A[i].S;
                int ini=2*k;
                if(i!=A.size()-1){
                    ini=(A[i+1].F+A[i+1].S-1);
                }
                ans[i]=1e18;
                //deb(ini);
                for(int Sum=ini;Sum>=(A[i].F+A[i].S);Sum--){
                    //deb(Sum);

                    if(I!=Sum){
                        int J=I;
                        for( int j=J-1;j>=Sum;j--){
                            sg+=par[j];
                            I=j;
                        }
                    }
                    int Ans=A.size()-1-i;
                    if(Sum!=(A[i].F+A[i].S)){
                        Ans=Ans+1;
                        if((Sum-k)>A[i].S){
                            Ans++;
                        }
                    }
                    Ans+=(sg);
                    //deb(Ans);
                    ans[i]=min(ans[i],Ans);
                }
            }
            else{
                ans[i]=ans[i+1];
            }
            //deb(ans[i]);
            par[max(A[i].F,A[i].S)]++;
            //deb(par);
            //deb("*******************");
        }
        sg=0;
        I=0;
        par.clear();
        par.resize(2*k+1);
        //deb(A);
        //deb(ans);
        vi add;
        add.clear();
        add.resize(A.size());
        for(int i=0;i<ans.size();i++){
            //deb("small");

            //deb(i);
            //deb(A);
            if(i==0 || (A[i-1].F+A[i-1].S)!=(A[i].F+A[i].S)){
                add[i]=1e18;
                int ini=0;
                int Sum=0;
                if(i!=0){
                    ini=(A[i-1].F+A[i-1].S+1);
                }
                for(int Sum=ini;Sum<=(A[i].F+A[i].S);Sum++){
                    //deb(Sum);
                    int Ans=i;
                    int big=Sum-k;
                    if(big<0){

                    }
                    else{
                        if((I<(big-1) )){
                            int J=I;
                            for(int j=J;j<big;j++){
                                sg+=par[j];
                                I=j;
                            }
                        }
                    }
                    Ans+=sg;
                    //deb("Ans before fuck");
                    //deb(Ans);
                    if(Sum!=(A[i].F+A[i].S)){
                        Ans++;
                        if(A[i].S>=Sum ){
                            Ans++;
                        }
                    }
                //deb(Ans);
                    add[i]=min(add[i],Ans);
                }

            }
            else{
                add[i]=add[i-1];
            }
            par[max(A[i].F,A[i].S)]++;
            //deb(add[i]);
            //deb(par);
            //deb("**************************");
        }
        //deb(ans);
        //deb(add);
        int Ans=1e18;
        for(int i=0;i<ans.size();i++){
            Ans=min(Ans,ans[i]+add[i]);
        }
        cout<<Ans<<"\n";

        // cout<<ans<<"\n";
        


    }

    return 0;
}