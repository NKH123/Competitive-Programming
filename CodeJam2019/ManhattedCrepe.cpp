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
	int T=t;
	while(t--){
		// deb("TEst case .............");
		int p,q;
		cin>>p>>q;
		vi xmin(p,0);
		vi xmax(p,q);
		vi ymin(p,0);
		vi ymax(p,q);
		// vi  y(2);
		// x[0]=0;
		// x[1]=q;
		// y[0]=0;
		// y[1]=q;
		REP(i,0,p){
			int A,B;
			char C;
			cin>>A>>B>>C;
			// deb(i);
			// deb(A);
			// deb(B);
			// deb(C);
			if(C=='N'){
				ymin[i]=max(ymin[i],B+1);
			}
			else if(C=='S'){
				ymax[i]=min(ymax[i],B-1);
			}
			else if(C=='E'){
				xmin[i]=max(xmin[i],A+1);
			}
			else if(C=='W'){
				xmax[i]=min(xmax[i],A-1);
			}
			

		}
		// deb(xmin);
		// deb(xmax);
		// deb(ymin);
		// deb(ymax);
		vi ct(p,0);
		for(int i=0;i<p;i++){
			for(int j=0;j<p;j++){
				if(i==j)continue;
				if(xmax[j]>=xmin[i] &&  ymax[j]>=ymin[i] && xmin[j]<=xmin[i] &&  ymin[j]<=ymin[i]){
					ct[i]++;
				}
			}
		}
		// deb(ct);
		int maxi=-1;
		REP(i,0,p){
			maxi=max(maxi,ct[i]);
		}
		// int ans1=0;
		// for(int i=1;i<p;i++){
		// 	if(ct[i]>ct[ans1]){
		// 		ans1=i;
		// 	}
		// 	else if(ct[i]==ct[ans1]){
		// 		if(xmin[i]<=xmin[ans1] ){
		// 			ans1=i;
		// 		}
		// 	}
		// }
		// int ans2=0;
		// for(int i=1;i<p;i++){
		// 	if(ct[i]>ct[ans2]){
		// 		ans2=i;
		// 	}
		// 	else if(ct[i]==ct[ans2]){
		// 		if(ymin[i]<=ymin[ans2] ){
		// 			ans2=i;
		// 		}
		// 	}
		// }
		int f=0;
		int X,Y;
		// for(int i=0;i<p;i++){
		// 	if(ct[i]==maxi){
		// 		if(f==0){
		// 			X=xmin[i];
		// 			Y=ymin[i];
		// 			f=1;
		// 		}
		// 		else{
		// 			// X=max(X,xmin[i]);
		// 			// Y=max(Y,ymin[i]);
		// 			if(X<xmin[i] || Y<ymin[i]){
		// 				X=xmin[i];
		// 				Y=ymin[i];
		// 			}
		// 		}
		// 	}
		// }
		// int ctt[11][11];
		vector<vector<int> >ctt(q+1);
		ctt.clear();
		ctt.resize(q+1);
		REP(i,0,q+1){
			ctt[i].resize(q+1);
		}
		// memset(ctt,0,sizeof(ctt));
		REP(i,0,q+1){
			REP(j,0,q+1){
				for(int k=0;k<p;k++){
					if(i>=xmin[k] && i<=xmax[k] && j<=ymax[k] && j>=ymin[k]){
						ctt[i][j]++;
					}
				}
			}
		}
		// deb(ctt);
		int maxct=0;
		for(int i=0;i<=q;i++){
			for(int j=0;j<=q;j++){
				if(ctt[i][j]>maxct){
					X=i;
					Y=j;
					maxct=ctt[i][j];
				}
				else if(ctt[i][j]==maxct){
					if(i<=X && j<=Y){
						X=i;
						Y=j;
					}
				}
			}
		}

		// cout<<"Case #"<<T-t<<": "<<xmin[ans1]<<" "<<ymin[ans2]<<"\n";
		cout<<"Case #"<<T-t<<": "<<X<<" "<<Y<<"\n";
	}



	return 0;
}