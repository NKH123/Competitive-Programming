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
    int t;
    cin>>t;
    int f;
    cin>>f;
    cout.flush();
    while(t--){
        int i=1;
        vector<int>ct(5);
        ct.clear();
        ct.resize(5);
        vector<vector<int> >pos;
        pos.clear();
        pos.resize(5);

        for(int i=1;i<=591;i=i+5){
            cout<<i<<"\n";
            char A;
            cin>>A;
            ct[A-'A']++;
            pos[A-'A'].push_back(i);
        }
        int First=-1;
        for(int i=0;i<5;i++){
            if(ct[i]==23){
                First=i;
                break;
            }
        }
        vector<int>ct1(5);
        ct1.clear();
        ct1.resize(5);
        vector<vector<int> >pos1;
        pos1.clear();
        pos1.resize(5);
        for(int i=0;i<pos[First].size();i++){
            cout<<pos[First][i]+1<<"\n";
            char A;
            cin>>A;
            ct1[A-'A']++;
            pos1[A-'A'].push_back(pos[First][i]+1);
        }
        int Second=-1;
        for(int i=0;i<5;i++){
            if(ct1[i]==5){
                Second=i;
                break;
            }
        }
        ct.clear();
        ct.resize(5);
        pos.clear();
        pos.resize(5);
        for(int i=0;i<pos1[Second].size();i++){
            cout<<pos1[Second][i]+1<<"\n";
            char A;
            cin>>A;
            ct[A-'A']++;
            pos[A-'A'].push_back(pos1[Second][i]+1);
        }
        int third=-1;
        for(int i=0;i<5;i++){
            if(ct[i]==1){
                third=i;
                break;
            }
        }
        ct1.clear();
        ct1.resize(5);
        pos1.clear();
        pos1.resize(5);
        for(int i=0;i<pos[third].size();i++){
            cout<<pos[third][i]+1<<"\n";
            char A;
            cin>>A;
            ct1[A-'A']++;
            pos1[A-'A'].push_back(pos[third][i]+1);
        }
        int fourth=-1;
        // deb(ct1);
        // for(int i=0;i<5;i++){
        //     if(ct1[i]==0){
        //         fourth=i;
        //     }
        // }
        int ctt=-1;
        for(int i=0;i<5;i++){
            if(ct1[i]==1){
                ctt=i;
                break;
            }
        }
        fourth=0+1+2+3+4-First-Second-third-ctt;
        int fifth=0+1+2+3+4-First-Second-third-fourth;
        string ans="ABCDE";
        ans[0]='A'+First;
        ans[1]='A'+Second;
        ans[2]='A'+third;
        ans[3]='A'+fourth;
        ans[4]='A'+fifth;
        cout<<ans<<"\n";
        char verdict;
        cin>>verdict;
        if(verdict=='N'){
            exit(0);
        }





    }



	return 0;
}