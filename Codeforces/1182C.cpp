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
int n;
vector<string>a;
map<int,pair<int, int> >M; //index maps to no. of vowels and last vowel
bool isVowel(char A){
    if(A=='a' || A=='e' || A=='i' || A=='o' || A=='u' ){
        return true;
    }
    else{
        return false;
    }
}
int getInd(char A){
    if(A=='a'){
        return 1;
    }
    if(A=='e'){
        return 2;
    }
    if(A=='i'){
        return 3;
    }
    if(A=='o'){
        return 4;
    }
    if(A=='u'){
        return 5;
    }
}
map<pair<int, int>,set<int> >ss;
vector<int>same_last;
map<int, vector<int> >same_no;

int32_t main(){
	ios::sync_with_stdio(false);
    cin>>n;
    a.resize(n);
    REP(i,0,n){
        cin>>a[i];
        int ct=0;
        char las;
        for(int j=0;j<a[i].size();j++){
            if(isVowel(a[i][j])){
                las=a[i][j];
                ct++;
            }
        }
        int no =getInd(las);
        M[i]={ct,no};
        ss[{ct,no}].insert(i);

    }
    for(auto g:ss){
        if(g.S.size()==0){
            continue;
        }
        else{
            if(g.S.size()%2==0){
                for(auto G:g.S){
                    same_last.PB(G);
                }
            }
            else{
                int ct=0;
                for(auto G:g.S){
                    ct++;
                    if(ct!=g.S.size())
                        same_last.PB(G);
                    else{
                        same_no[g.F.F].PB(G);
                    }
                }
            }
        }
    }
    vector<int>Same_No;
    for(auto g:same_no){
        if(g.S.size()==0)continue;
        if(g.S.size()%2==0){
            for(auto G:g.S){
                Same_No.PB(G);
            }
        }
        else{
            int ct=0;
            for(auto G:g.S){
                ct++;
                if(ct!=g.S.size()){
                    Same_No.PB(G);
                }

            }
        }
    }
    int sin, doub;
    sin=Same_No.size()/2;
    doub=same_last.size()/2;
    vector<int>ans1;
    vector<int>ans2;
    vector<int>ans3;
    vector<int>ans4;
    int ctt=0;
    if(doub<sin){
        int N=same_last.size();
        for(int i=0;i<(N-1);i=i+2){
            ctt++;
            ans1.PB(Same_No[i]);
            ans3.PB(Same_No[i+1]);
            ans2.PB(same_last[i]);
            ans4.PB(same_last[i+1]);
        }
    }
    else{
        int i=0;
        int I=0;
        int N=Same_No.size();
        for(int i=0;i<(N-1);i=i+2){
            ctt++;
            ans1.PB(Same_No[i]);
            ans3.PB(Same_No[i+1]);
            ans2.PB(same_last[i]);
            ans4.PB(same_last[i+1]);
            I=i+2;
        }
        i=I;
        N=same_last.size();
        for(;i<(N-3);i=i+4){
            ctt=ctt+1;
            ans1.PB(same_last[i]);
            ans3.PB(same_last[i+1]);
            ans2.PB(same_last[i+2]);
            ans4.PB(same_last[i+3]);
        }
    }
    cout<<ans1.size()<<"\n";
    for(int i=0;i<ans1.size();i++){
        cout<<a[ans1[i]]<<" "<<a[ans2[i]]<<"\n";
        cout<<a[ans3[i]]<<" "<<a[ans4[i]]<<"\n";
    }
    return 0;
}