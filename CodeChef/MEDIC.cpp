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
int ans;
bool leap(int n){
    if(n%4==0){
        if(n%100==0){
            if(n%400==0){
                return true;
            }
            else{
                return false;
            }
        }
        else{
            return true;
        }
    }
    else{
        return false;
    }
}

void incans(int day, int last){
    ans++;
    while((day+2)<=last){
        day+=2;
        ans++;
    }
}

int32_t main(){
	ios::sync_with_stdio(false);
    int t;
    cin>>t;
    int aa[12];
    aa[0]=31;
    aa[1]=28;
    aa[2]=31;
    aa[3]=30;
    aa[4]=31;
    aa[5]=30;
    aa[6]=31;
    aa[7]=31;
    aa[8]=30;
    aa[9]=31;
    aa[10]=30;
    aa[11]=31;

    while(t--){
        string s;
        cin>>s;
        int year=0;
        int mo=0;
        int day=0;
        ans=0;
        // deb(s);
        for(int i=0;i<4;i++){
            // deb(i);
            // deb(s[i]);
            // deb(char(s[i]));
            year=year*10+(char(s[i])-'0');
            // deb(year);
        }
        for(int i=5;i<=6;i++){
            mo=mo*10+char(s[i])-'0';
        }
        for(int i=8;i<=9;i++){
            day=day*10+char(s[i])-'0';
        }
        int oday=day;
        // deb(year);
        // deb(mo);
        // deb(day);

        if(leap(year)){

            aa[1]++;


            while(aa[mo-1]%2!=1){
                // ans+=(aa[mo-1]-day+1)/2;
                // if(aa[mo-1]%2==day%2){
                //     ans++;
                // }
                incans(day,aa[mo-1]);
                mo++;
                if(oday%2==1)
                day=1;
                else day=2;
            }
            // ans+=(aa[mo-1]-day+1)/2;
            // if(aa[mo-1]%2==day%2){
            //     ans++;
            // }
            incans(day,aa[mo-1]);
            



            aa[1]--;
        }
        else{
            // deb("here");
            while(aa[mo-1]%2!=1){
                // deb("here1");
                // ans+=(aa[mo-1]-day+1)/2;
            // if(aa[mo-1]%2==day%2){
            //     ans++;
            // }
                incans(day,aa[mo-1]);
                // deb(ans);
                // deb(mo);
                // deb(day);
                mo++;
                if(oday%2==1)
                day=1;
                else day=2;
            }
            // deb(ans);
            // ans+=(aa[mo-1]-day+1)/2;
            // if(aa[mo-1]%2==day%2){
            //     ans++;
            // }
            incans(day,aa[mo-1]);
            // deb(ans);
            // deb(mo);
        }
        cout<<ans<<"\n";
    }



    return 0;
}