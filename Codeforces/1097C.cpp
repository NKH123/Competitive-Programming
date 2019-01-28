#include<bits/stdc++.h>
using namespace std;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i,a,b) for (int i = a; i <b; i++)
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int,int> pi;
#define trace(x) cout<<#x<<"="<<x<<"\n";
#define llp 1000000007
#define mod 1000000007


ll power(ll x, ll y) 
{
	ll temp;
	if( y == 0)
		return 1;
	temp = power(x, y/2);
	if (y%2 == 0)
		return (temp*temp)%mod;
	else
		return (((x*temp)%mod)*temp)%mod; 
}
   vi l[5000010];
    vi r[5000010];

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n;
    cin>>n;
    vector<bool>taken(n,false);
    vector<int>left;
    vector<int>right;
    left.resize(n);
    right.resize(n);
 
    REP(i,0,n){
    	string s;
    	cin>>s;
    	int sum=0;

    	for(auto g:s){
    		if(g=='('){
    			sum++;
    		}
    		else{
    			sum--;
    		}
    		if(sum<0){
    			left[i]=-1;
    		}
    	}
    	if(left[i]!=-1){
    		left[i]=sum;
    		l[sum].PB(i);
    	}
    	sum=0;
    	
    	for(int j=s.size()-1;j>=0;j--){
    		//trace(j);
    		if(s[j]==')'){
    			sum++;
    		}
    		else{
    			sum--;
    		}
    		if(sum<0){
    			right[i]=-1;
    		}
    		//trace(sum);

    	}
    	if(right[i]!=-1){
    		/*cout<<"I'm here ";
    		trace(sum);*/

    		right[i]=sum;
    		r[sum].PB(i);
    	}
    }
    ll ans=0;
    for(int i=0;i<n;i++){
    	if(left[i]>=0){
    		if(r[left[i]].size()!=0){
    		//	cout<<"left ";
    		//	trace(i);
    		ans++;
    			int A=r[left[i]][r[left[i]].size()-1];
    			if(A==i){
    				ans--;
    				goto L;
    			}
    			right[A]=-1;
    			left[A]=-1;
    			
    		//	trace(A);
    			r[left[i]].pop_back();
    			
    			//remove(l[left[i]].begin(),l[left[i]].end(),i);
    			vector<int>::iterator position = find(l[left[i]].begin(), l[left[i]].end(), i);
if (position != l[left[i]].end()) // == myVector.end() means the element was not found
    l[left[i]].erase(position);
left[i]=-1;
    			right[i]=-1;
    			//trace(A);
    		}
    	}
    	L:
    	 if(right[i]>=0){
    		if(l[right[i]].size()!=0){
    		//	cout<<"right ";
    		//	trace(i);
    			
    			ans++;
    			int A=l[right[i]][l[right[i]].size()-1];
    		//	trace(A);
    				if(A==i){
    				ans--;
    				continue;
    			}
    			right[A]=-1;
    			left[A]=-1;
    			
    			//trace(A);
    			//cout<<"before popping\n";
    			//for(auto g:l[left[i]])
    			l[right[i]].pop_back();
    			remove(r[right[i]].begin(),r[right[i]].end(),i);
    			vector<int>::iterator position = find(r[right[i]].begin(),r[right[i]].end(), i);
if (position != r[right[i]].end()) // == myVector.end() means the element was not found
    r[right[i]].erase(position);
		left[i]=-1;
    			right[i]=-1;
    			//trace(A);
    		}

    	}

    }
    cout<<ans<<"\n";
    return 0;
}