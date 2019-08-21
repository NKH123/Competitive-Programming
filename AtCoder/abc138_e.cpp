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
string s;
string t;
bool check(){
    vi A(26);
    for(int i=0;i<s.size();i++){
        A[s[i]-'a']++;
    }
    vi B(26);
    for(int i=0;i<t.size();i++){
        B[t[i]-'a']++;
    }
    // deb(A);
    // deb(B);
    for(int i=0;i<26;i++){
        if(A[i]==0 && B[i]!=0){
            return false;
        }
    }
    return true;
}
int getTimes(){
    vi A(26);
    for(int i=0;i<s.size();i++){
        A[s[i]-'a']++;
    }
    vi B(26);
    for(int i=0;i<t.size();i++){
        B[t[i]-'a']++;
    }
    int times=1;
    for(int i=0;i<26;i++){
        if(B[i]==0)continue;
        int temp=A[i]/B[i];
        if((A[i]%B[i])!=0){
            temp++;
        }
        times=max(times,temp);
    }
    return times;

}
int32_t main(){
    ios::sync_with_stdio(false);
    cin>>s>>t;
    if(!check()){
        cout<<-1<<"\n";
        return 0;
    }    
    // int times=getTimes();
    string S=s;
    // for(int i=1;i<times;i++){
        // s+=S;
    // }
    int J=0;
    // deb(s);
    int ans=0;
    int n=s.size();
    // for(int i=0;;i++){
    //     if(s[(i%n)]==t[J]){
    //         J++;
    //     }

    //     if(J==(t.size())){
    //         ans=i+1;
    //         break;
    //     }
    //     // if(i==(s.size()-1)){
    //     //     s+=S;
    //     // }

    // }
    map<char,set<int> >M;
    for(int i=0;i<s.size();i++){
        M[s[i]].insert(i);
    }
    // int J=0;
    int i=0;
    // int ans=0;
    while(J!=(t.size())){
        auto temp=M[t[J]].lower_bound(i);
        if(temp==M[t[J]].end()){
            ans+=(n-1-i+1);
            i=0;
            continue;
        }
        else{
            ans+=((*temp)-i+1);
            i=((*temp)+1)%n;
        }
        J++;
        //update ans
        //update temp

    }
    cout<<ans<<"\n";


    return 0;
}