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
string lp,ls;
bool some(string s,string p){
   // cout<<s<<" "<<p<<"\n";
    //cout<<lp<<" "<<ls<<"\n";
    for(int i=0;i<s.size();i++){
        if(s[i]!=lp[i]){
         //   cout<<"Returning false first\n";
            return false;
        }
    }
    for(int i=0;i<p.size();i++){
        if(p[i]!=ls[i]){
         //   cout<<"Returning false second\n";
            return false;
        }
    }
    return true;

}


int main()
{   ios::sync_with_stdio(false);
    freopen("a.in", "r", stdin);
    //freopen("b.in", "r", stdin);
    //freopen("c.in", "r", stdin);
    //freopen("d.in", "r", stdin);
    int n;
    cin>>n;
    vector<pair<string,int >>a[101];
    vector<char>ANS;
    ANS.resize(2*n-2);
   
    string s;
    for(int i=0;i<(2*n-2);i++){
    	cin>>s;
    	int sz=s.size();
    	a[sz].PB({s,i});
    }
   
    lp=a[n-1][0].F;
    ls=a[n-1][1].F;
    reverse(ls.begin(),ls.end());
    //cout<<lp<<"\n";
   //cout<<ls<<"\n";
    ANS[a[n-1][0].S]='P';
    ANS[a[n-1][1].S]='S';
    for(int i=1;i<n-1;i++){
    	string A=a[i][0].F;
    	string B=a[i][1].F;
        reverse(B.begin(),B.end());
        if(some(A,B)){
            //trace(i);
            ANS[a[i][0].S]='P';
            ANS[a[i][1].S]='S';
        }
        else{
            reverse(B.begin(),B.end());
            reverse(A.begin(),A.end());
            if(some(B,A)){
                //trace(i);
                 ANS[a[i][0].S]='S';
            ANS[a[i][1].S]='P';
            }
        }
    	/*reverse(B.begin(),B.end());
    	trace(i);
    	cout<<A<<"\n";
    	cout<<B<<"\n";
    	int f=1;
    	int m=A.size();
    	trace(m);
    	for(int j=0;j<m;j++){
            cout<<"Comparing A\n";
    		trace(j);
    		if(A[j]!=lp[j]){
    			cout<<"I'm ehre\n";
    			f=0;
    			break;
    		}
    	}
    	if(f==0){
    		cout<<"SP A is not P so it must be S\n";
    		ANS[a[i][0].S]='S';
    		ANS[a[i][1].S]='P';
    	}
    	else{
    		//cout<<"PS\n";
            cout<<"A is P but B need to make sure\n";
    		int ff=1;
    		for(int j=0;j<B.size();j++){
                cout<<"Comparing B\n";
            trace(j);
    			if(B[j]!=ls[j]){
                    cout<<"I'm here\n";
    				ff=0;
    				break;
    			}
    		}
    		if(ff==1){
                cout<<"B can be S so let it be\n";
    			ANS[a[i][0].S]='P';
    		ANS[a[i][1].S]='S';
    		}
    		else{
                cout<<"B can't be S so make it P\n";
    			ANS[a[i][0].S]='S';
    		ANS[a[i][1].S]='P';
    		}
    		
    	}*/
    }

    for(auto d:ANS){
    	cout<<d;
    }
    cout<<"\n";
    return 0;
}