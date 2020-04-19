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
#define mod 1000000000
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

string s;
bool isnum(char s){
    if(s>='0' && s<='9'){
        return true;
    }else{
        return false;
    }
}
int id=0;
pair<int, pair<int, int> > process(int I){
    id++;
    //deb("***");
    //deb("In process");
    //deb(id);
    int mul=s[I]-'0';
    // int I=i+1;
    I++;
    vector<int>st;
    st.clear();
    st.PB(mul);
    int X=0, Y=0;
    while(st.size()!=0){
        //deb(st);
        if(s[I]=='('){
            st.PB(s[I]);
        }
        else if(s[I]=='N'){
            // X--;
            Y--;
        }
        else if(s[I]=='S'){
            // X++;
            Y++;
        }
        else if(s[I]=='E'){
            // Y--;
            X++;
        }
        else if(s[I]=='W'){
            // Y++;
            X--;
        }
        else if(isnum(s[I])){
            pair<int, pair<int, int> > xy;
            
            xy=process(I);
            //deb(xy);
            I=xy.first;
            X+=(xy.S.F);
            Y+=(xy.S.S);
        }
        else if(s[I]==')'){
            st.pop_back();
            int mul=st[st.size()-1];
            X=mul*X;
            Y=mul*Y;
            st.pop_back();
        }
        I++;
    }

    //deb(id);
    //deb("Out process");
    //deb("****");
    id--;

    return {I-1,{X,Y}};

}
int32_t main(){
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        cout<<"Case #"<<i<<": ";
        cin>>s;
        int x=0, y=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='N'){
                y--;
                if(y<0){
                    // y=(1e9+y)%(mod);
                    y=y%mod;
                    y=(y+mod)%mod;
                }
                if(y>=(1e9)){
                    // y=(y-1e9)%mod;
                    y=y%mod;
                }
            }
            else if(s[i]=='S'){
                y++;
                if(y<0){
                    // y=(1e9+y)%(mod);
                    y=y%mod;
                    y=(y+mod)%mod;
                }
                if(y>=(1e9)){
                    // y=(y-1e9)%mod;
                    y=y%mod;
                }
            }
            else if(s[i]=='E'){
                x++;
                if(x<0){
                    // x=1e9+x;
                    x=x%mod;
                    x=(x+mod)%mod;
                }
                if(x>=(1e9)){
                    // x-=1e9;
                    x=x%mod;
                }
            }
            else if(s[i]=='W'){
                x--;
                if(x<0){
                    x=x%mod;
                    x=(x+mod)%mod;
                }
                if(x>=(1e9)){
                    x=x%mod;                }
            }
            else if(isnum(s[i])){
                pair<int, pair<int, int> >xy;
                xy=process( i);
                //deb(xy);
                x+=xy.S.F;
                y+=xy.S.S;
                if(x<0){
                    x=x%mod;
                    x=(x+mod)%mod;
                }
                if(x>=(1e9)){
                    x=x%mod;
                }
                if(y<0){
                    y=y%mod;
                    y=(y+mod)%mod;
                }
                if(y>=(1e9)){
                    y=y%mod;
                }
                i=xy.F;
            }
            //deb(i);
            //deb(x);
            //deb(y);
        }
        int X=x+1;
        int Y=y+1;

        cout<<X<<" "<<Y<<"\n";
    }
    // 10(10(10(10(10(10(10(10(10(10(S)))))))
    // 10(10(10(10(10(10(10(10(10(10(S))))))))))
    // 9(9(9(9(9(9(9(9(9(9(S))))))))))
    return 0;
}