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
    string s; int n, x ,k;
    cin>>n>>x>>k;
    cin>>s;

    k--;
        int no=n/x;
        if(n%x!=0){
            no++;
        }
        vector<set<int > > SS(no);
        int ct=0;
        for(int i=0;i<n;i+=x){
            for(int j=i;j<min(n,i+x);j++){
                SS[ct].insert(s[j]-'0');
            }
            ct++;
        }
        vector<int>mul(no);
        for(int i=0;i<no;i++){
            mul[i]=SS[i].size();
        }
        vector<int>suf(no);
        suf[no-1]=mul[no-1];
        for(int i=no-2;i>=0;i--){
            suf[i]=mul[i]*suf[i+1];
        }
        suf.push_back(1);
        vector<int>ans(no);
        int cur=0;
        vector<vector<int > >Ss(no);
        REP(i,0,no){
            for(auto g:SS[i]){
                Ss[i].PB(g);
            }
        }
        /*******************************/

        int prev=-1;
        deb(Ss);

        /**********************************/

        for(int k=0;k<suf[0];k++){
            deb(k);
           int temp=0;
           for(int i=0;i<no;i++){
            int j=0;
            int f=0;
            for( j=0;j<SS[i].size();j++){
                if(temp<k &&j!=0)
                    temp=temp+suf[i+1];
                if(temp<k){
                    cur=temp;
                }
                else{
                    if(temp>k){
                        temp-=suf[i+1];
                        j--;
                    }
                    f=1;
                    break;                
                }
            }
            if(f==0){
                j--;
            }
            ans[i]=Ss[i][j];
        }
        int cur=0;
        REP(i,0,no){
            cout<<ans[i];
            cur=cur*10+ans[i];
        }

        cout<<"\n";
        if(cur<=prev){
            cout<<"Bad\n";
            cout<<s<<"\n";
            cout<<x<<"\n";
            return 0;
        }
    }
        return 0;
}
    


