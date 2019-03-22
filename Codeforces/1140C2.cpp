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

struct cmp {
    bool operator() (pi a, pi b) const {
        return a.S>b.S ;
    }
};
struct cmp1 {
    bool operator() (pi a, pi b) const {
        return a.F*a.S>b.F*b.S ;
    }
};
int32_t main(){
	ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    vi t(n),b(n);
    vector<pair<int, int > > pp;
    vi par(n);
    vi mini(n);
    REP(i,0,n){
        cin>>t[i]>>b[i];
        pp.PB({b[i],t[i]});
    }
    int maxi=-(1e18);
    int cumin=1e18;
    int chosen=-1;
    for(int i=0;i<n;i++){
        int ans=pp[i].F*pp[i].S;
        //maxi=max(ans,maxi);
        if(maxi<ans){
            maxi=ans;
            cumin=pp[i].F;
            chosen=i;
        }
    }
    set <pi, cmp>great;
    set <pi, cmp1>small;
    for(int i=0;i<n;i++){
        if(i!=chosen){
            if(pp[i].F>=cumin){
                great.insert(pp[i]);
            }
            else{
                small.insert(pp[i]);
            }
        }
    }
    int Maxi=maxi;
    // deb(pp);
    // deb(Maxi);
    // deb(pp[chosen]);
    vector<pi>Great(great.begin(),great.end());
    vector<pi>Small(small.begin(),small.end());
    // deb(Great);
    // deb(Small);
        // deb(small);
    // deb(great);
    for(int i=1;i<k;i++){
        // deb(i);
        int curans=maxi/cumin;
        int temp;
        int temp1;
         auto I=*great.begin();
          auto J=*small.begin();
        //choose from great
        if(!great.empty()){
             I=*great.begin();
             temp=(curans+I.S)*cumin;
        }
        else{
             temp=-(1e18);
        }
        //choose from small
        if(!small.empty()){
            J=*small.begin();
             temp1=(curans+J.S)*J.F;
        }
        else{
            temp1=-(1e18);
        }
        // deb(curans);
        // deb(J);
        // deb(I);
        // deb(temp);
        // deb(temp1);
        if(temp1>temp){
            cumin=J.F;
            maxi=temp1;
            small.erase(J);
            // deb("here");
            // for(auto g:small){
            //     deb(g);
            //     if(g.F>cumin){
            //         small.erase(g);
            //         great.insert(g);
            //     }
            // }
            for(auto it=small.begin();it!=small.end();it++){
                // deb(*it);
                if((*it).F>cumin){
                    pi A=*it;
                    it++;
                    small.erase(A);
                    great.insert(A);
                }
            }
        }
        else{
            if(temp1==temp && temp==-(1e18))break;
            maxi=temp;
            great.erase(I);
        }
        Maxi=max(maxi,Maxi);

    }
    cout<<Maxi<<"\n";







    return 0;
}