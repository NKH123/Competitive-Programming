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

int n,m;
vector<vector<int> >a;
set<int>s;

void valinsert(int i,int j){
	if(i>=0 && (j>=0 && j<=(m-1))){
		s.insert(a[i][j]);
	}
}
int getno(int i,int j){
	s.clear();
	valinsert(i-2,j);
	valinsert(i-1,j+1);
	valinsert(i-1,j-1);
	valinsert(i,j-2);
	if(s.size()==0){
		return 1;
	}
	else{
		int ret=1;
		while(s.find(ret)!=s.end()){
			ret++;
			
		}
		return ret;
	}


}
void valinsert1(int i,int j){
	if(i>=0 && (j>=0 && j<=(m))){
		s.insert(a[i][j]);
	}
}
int getno1(int i,int j){
	s.clear();
	valinsert1(i-2,j);
	valinsert1(i-1,j+1);
	valinsert1(i-1,j-1);
	valinsert1(i,j-2);
	if(s.size()==0){
		return 1;
	}
	else{
		int ret=1;
		while(s.find(ret)!=s.end()){
			ret++;
			
		}
		return ret;
	}


}

int main()
{   ios::sync_with_stdio(false);
    //freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int t;
    cin>>t;
    while(t--){
    	cin>>n>>m;
    	a.resize(n);
    	for(int i=0;i<n;i++){
    		a[i].resize(m);
    	}
    	int maxi=-1;
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
    			int A=getno(i,j);
    			a[i][j]=A;
    			maxi=max(maxi,A);
    		}
    	}
    	if(maxi==5){
    		maxi=-1;
    		a.resize(n+1);
    		for(int i=0;i<n+1;i++){
    		a[i].resize(m+1);
    		}
    		for(int i=0;i<n+1;i++){
    		for(int j=0;j<m+1;j++){
    			int A=getno1(i,j);
    			//int A;
    			a[i][j]=A;

    			maxi=max(maxi,A);
    		}
    	}
    }
    if(n==2 && maxi==4){
        maxi=3;
        int k=0;
        for(int i=0;i<m;i++){
             if(i%2==0){
                k++;
                if(k==4){
                    k=1;
                }
            }
            a[0][i]=k;

        }
           k=2;
        for(int i=0;i<m;i++){
             if(i%2==1){
                k++;
                if(k==4){
                    k=1;
                }
            }
            a[1][i]=k;

        }
    }
    else if(m==2 && maxi==4){
         maxi=3;
        int k=0;
        for(int i=0;i<n;i++){
             if(i%2==0){
                k++;
                if(k==4){
                    k=1;
                }
            }
            a[i][0]=k;

        }
          k=2;
        for(int i=0;i<n;i++){
             if(i%2==1){
                k++;
                if(k==4){
                    k=1;
                }
            }
            a[i][1]=k;

        }

    }
    	cout<</*"Im here maxi=      "<<*/maxi<<"\n";
    	for(int i=0;i<n;i++){
    		for(int j=0;j<m;j++){
	    			cout<<a[i][j]<<" ";
    		} 
    		cout<<"\n";
    	}
    }
    
    return 0;
}