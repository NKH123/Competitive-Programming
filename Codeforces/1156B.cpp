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
string S;
vector<char>s;
bool bad(int i){
    if(i==0){
        if(s.size()!=1){
            if(s[i+1]==(s[i]-1) || s[i+1]==(s[i]+1)){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return false;
        }
    }
    else if(i==s.size()-1){

        if(s[i-1]==(s[i]-1) || s[i-1]==(s[i]+1)){
            return true;
        }
        else{
            return false;
        }


    }
    else{
        if(s[i-1]==(s[i]-1) || s[i-1]==(s[i]+1) || s[i+1]==(s[i]-1) || s[i+1]==(s[i]+1)){
            return true;
        }
        else{
            return false;
        }
    }

}
bool check(int J, int I){
    if(s[J]==s[I] || (abs(I-J)<=1))return false;
    else{
        int i=I;
        if(I==0){
            {
                if(!(s[i+1]==(s[J]-1) || s[i+1]==(s[J]+1)) ){
                    swap(s[i],s[J]);
                    
                    return true;
                }
                else{
                    return false;
                }
            }
            
        }
        else if(i==s.size()-1){

            if(!(s[i-1]==(s[J]-1) || s[i-1]==(s[J]+1))){
                return true;
            }
            else{
                return false;
            }


        }
        else{
            if(!(s[i-1]==(s[J]-1) || s[i-1]==(s[J]+1) || s[i+1]==(s[J]-1) || s[i+1]==(s[J]+1))){
                return true;
            }
            else{
                return false;
            }
        }


    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--){

        cin>>S;
        s.resize(S.size());
        REP(i,0,S.size()){
            s[i]=S[i];
        }
        int ff=0;
        for(int i=0;i<s.size();i++){
            // deb("new................................");
            // deb(s);
            if(bad(i)){
                // deb("Yes bad....");
                // deb(i);
                int f=0;
                int fff=0;
                for(int j=0;j<s.size();j++){
                    // deb(j);
                    if(j==i)continue;
                    else if(check(j,i) ){
                        // deb("Yes check");
                        swap(s[j],s[i]);
                        // deb("after swap");
                        // deb(s);
                        if(j<i && bad(j))
                        /*if(bad(i) || bad(j))*/{
                            // deb("bad!!");
                            // deb("undo swap");
                            swap(s[j],s[i]);
                            // deb(s);
                            f=1;
                        }
                        else{
                            f=0;
                        }
                        if(f==0){
                            j=s.size()+1;
                            fff=1;
                        }
                    }
                }
                if(fff==0){
                    // deb("here");
                    ff=1;
                    cout<<"No answer\n";
                    break;
                }
            }
        }
        if(!(ff)){
            REP(i,0,s.size()){
                cout<<s[i];
            }
            cout<<"\n";
        }
    }



    return 0;
}