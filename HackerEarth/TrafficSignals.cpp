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
				int n,m;
				cin>>n>>m;
				vector<string> ss;
				vector<string> sss;
				ss.resize(m);
				sss.resize(m);
				vector<pair<int,int > >ct;
				vector<int>ans;
				ct.resize(n);
				for(int i=0;i<n;i++){
					ct[i].second=i;
				}
				for(int i=0;i<m;i++){
					cin>>ss[i];
					sss[i]=ss[i];
					//ct[i].second=i;
					for(int j=0;j<n;j++){
						if(ss[i][j]=='1'){
							ct[j].first++;
						}
					}
				}
				sort(ct.begin(),ct.end());
				// deb(ct);
				set<pair<int, int > >pq(ct.begin(),ct.end());
				// deb("set begin");
				// for(auto g:ct){
				// 	deb(g);
				// }
				// deb("set end");
				while(pq.size()!=0){
					auto g=*pq.begin();
					ans.push_back(g.second+1);
					int iind=g.F;
					pq.erase(g);
					for(auto G: pq){
						// deb(G);
						int ind=G.second;
						// for(int i=0;i<n;i++){
						// 	// if(ss[G.second][i]=='1' && ss[iind][i]=='0'){
						// 	// 	 ss[G.second][i]='0';
						// 	// 	 G.first--;
						// 	// }

						// }
						for(int i=0;i<m;i++){
							if(ss[i][G.second]=='1' && ss[i][iind]=='0'){
								ss[i][G.second]=0;
								G.first--;
							}

						}
					}
				}
				int sum=0;
				for(int i=0;i<m;i++){
					int pay=0;
					for(int j=0;j<n;j++){
						// deb(i);
						// deb(j);
						// deb(sss[i]);
						if(sss[i][ans[j]-1]=='1'){
							pay++;
						}
						else{
							pay++;
							break;
						}
					}
					// deb(i);
					// deb(pay);
					sum+=pay;
				}
				cout<<sum<<"\n";
				for(int i=0;i<ans.size();i++){
					cout<<ans[i]<<" ";
				}
				cout<<"\n";




				return 0;
			}