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

void print(deque<pair<int, int> > Q){
    while(Q.size()!=0){
        cout<<"{ "<<Q.front().first<<", "<<Q.front().second<<"}, ";
        Q.pop_front();
    }
    cout<<"\n";
}


int32_t main(){
    ios::sync_with_stdio(false);
    int h, w;
    cin>>h>>w;
    int ch, cw;
    cin>>ch>>cw;
    int dh, dw;
    cin>>dh>>dw;
    vector<vector<char> >a(h, vector<char>(w));
    // int dis[h][w];
    // bool vis[h][w];
    vector<vector<int> > dis(h, vector<int>(w));
    vector<vector<bool> > vis(h, vector<bool>(w));
    REP(i,0,h){
        REP(j,0,w){
            cin>>a[i][j];
            dis[i][j]=1e18;
            vis[i][j]=false;
        }
    }
    dis[ch-1][cw-1]=0;
    vis[ch-1][cw-1]=true;
    deque<pair<int, int> >Q;
    Q.push_back({ch-1, cw-1});
    vi dx_1 = {0,1,0,-1};
    vi dy_1 = {-1,0,1,0};
    while(Q.size()!=0){
        auto cur = Q.front();
        deb(cur);
        Q.pop_front();
        deb("before");
        print(Q);
        for(int i=0; i<4; i++){
            int X = cur.first + dx_1[i];
            int Y = cur.second + dy_1[i];
            if (X>=0 && X < h && Y>=0 && Y<w ){
                if(!vis[X][Y] && a[X][Y] == '.') {
                    dis[X][Y] = min(dis[X][Y], dis[cur.first][cur.second]);
                    Q.push_front({X, Y});
                    vis[X][Y] = true;
                }
            }
            
        }
        // for(int i = -2; i<=2; i++) {
        //         for(int j = -2; j<=2; j++) {
        //             int X = cur.first + i;
        //             int Y = cur.second + j;
        //             if (X>=0 && X < h && Y>=0 && Y<w ){
        //                 if(!vis[X][Y] && a[X][Y] == '.') {
        //                     dis[X][Y] = min(dis[X][Y], dis[cur.first][cur.second] + 1);
        //                     Q.push_back({X, Y});
        //                     vis[X][Y] = true;
        //                 }
        //             }
        //         }
        // }
        deb("after");
        print(Q);
        deb("******************************");
    }
    


    deb(vis);
    deb(dis);

    if (dis[dh-1][dw-1] == 1e18){
        cout<<-1<<"\n";
    }
    else
    cout<<dis[dh-1][dw-1]<<"\n";


    return 0;
}

kevingeorgejoe@gmail.com,
ryan.rozario1999@gmail.com,
tejasc256@gmail.com,
awadjikar@gmail.com,
nakulsuresh98@gmail.com,
gaurivgn@gmail.com,
roshgeorge66@gmail.com,
aasthac67@gmail.com,
sulludps@gmail.com,
rohanrajbabli@gmail.com,
cmshoukath2@gmail.com,
mishalahmed98@gmail.com,
ankit.karody@gmail.com,
sudhakar1990@gmail.com,
manashsharma20@gmail.com,
shashank9867@gmail.com,
nishanth80442@gmail.com,
hmnth.pahu@gmail.com,
harshprakashgupta@gmail.com,
nimish.gite@jsw.in,
lkcbharath@gmail.com,
adityapai14@gmail.com,
ayush.gupta.go@gmail.com,
dhanueshrc28@gmail.com,
akashkayath28@gmail.com,
nikitachauhan622@gmail.com,
gnarayang@gmail.com,
pavan333rakesh@gmail.com,
a.ayushkumar1997@gmail.com,
saisiddarthyv8@gmail.com,
varunpattar@gmail.com,
vithikshah@gmail.com,
aashaym1@gmail.com,
srivi567@gmail.com,
prajwalpspbelagavi@gmail.com,
rkauraiya1167@gmail.com,
ankitraut12379@gmail.com,
jelwin13afc@gmail.com,
abheekbabel@gmail.com,
yashwanthmiryala172@gmail.com,
crjkrhlms@gmail.com,
madhuparnabhowmik04@gmail.com,
siddharth12375@gmail.com,
dhruvagja8808@gmail.com,
sharmilabiswas531999@gmail.com,
akashrao811998@gmail.com,
kainspraveen@icloud.com,
nikithakamurthy@gmail.com,
firenani5@gmail.com,
vandana.swj@gmail.com,
mailme.vikasb@rediffmail.com,
saharshsonu40@gmail.com,
vara1999akash@gmail.com,
tanyarai282@gmail.com,
p.prabhath52000@gmail.com,
amodhshenoy@gmail.com,
ganagawadi@gmail.com,
deepakkavoor99@gmail.com,
siddhartha.15.manju@gmail.com,
sanathramesh55@gmail.com,
thejaswini360@gmail.com,
NJnisarg@gmail.com,
chandannaik999@gmail.com,
yuvrajdalia98@gmail.com,
msshashi21@gmail.com,
harsh.maru759@gmail.com,
neeraj.deshpande3@gmail.com,
govardhangdg@gmail.com,
neeramitra.reddy@gmail.com,
sdewangan021@gmail.com,
ckiran41999@gmail.com,
srikrishnapoo@yahoo.in,
pankajkumarnj1@gmail.com,
hrishikeshrathod350@gmail.com,
ankursingh6186@gmail.com,
venkubh@gmail.com,
yashmagarwal786@gmail.com,
nchethan14@gmail.com,
adarshdbg428@gmail.com,
anujraj1601@gmail.com,
ssverma360@gmail.com,
anild3027@gmail.com,
adityakaria01@gmail.com,
mohan.jadiya@gmail.com,
hemanthsai392@gmail.com,
avdheshyadavdow@gmail.com,
vmehra25@yahoo.com,
hemanth.heroic@gmail.com,
pankajpoddar73@gmail.com,
niwedita.dakshana2017@gmail.com,
gvaibhav1734@gmail.com,
adsatish47@gmail.com,
rjgenius123@gmail.com,
Aviswas7544007@gmail.com,
anagaveni1978@gmail.com,
shaheenanas687@gmail.com,
abhishekranjan698@gmail.com,
parthdodiya999@gmail.com,
arqum212@gmail.com,
vs1998489@gmail.com,
navadiyadhruvik2@gmail.com,
kumararun15898@gmail.com,
ashish.bhatia2909@gmail.com,
99nimit99@gmail.com,
shivamkumar777794@gmail.com,
alisaganjam01@gmail.com,
saur.agarwala@gmail.com,
rahul.kr0324@gmail.com,
vasram74@gmail.com,
vikasjnayak30@gmail.com,
shubhamgkp004@gmail.com,
rakshiths690@gmail.com,
ashokkhatri14@gmail.com,
jayashivaraj7@yahoo.com,
py.abhinav2@gmail.com,
rohitkumar.dakshana17@gmail.com,
ranjanakrishnamurthy118@gmail.com,
raghavraghuwanshi0101@gmail.com,
nav.20110083504@gmail.com