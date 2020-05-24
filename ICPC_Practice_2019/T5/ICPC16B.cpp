#include <bits/stdc++.h>
using namespace std;
#define int long long 
#define fast ios_base::sync_with_stdio(NULL)
 
 
const int mod = 1e9+7;
 
 
signed main() {
    fast;
    int t;
    cin>>t;
    map<int,int> m;
    vector<int>a;
    while(t--){
        int n;
        cin>>n;
        a.clear();
        a.resize(n);
        m.clear();    
        for(int i=0;i<n;i++){
            cin>>a[i];
            m[a[i]]++;
        }
        if(n==1){
            cout<<"yes"<<endl;
            continue;
        }
        int cnt=0;
        for(auto i:m){
            if(abs(i.first)>1)cnt++;
        }
        if(cnt>1){
            cout<<"no"<<endl;
        }
        else{
            int ones=m[1];
            int neg=m[-1];
            
            vector<int>arr;
            arr.clear();
            for(auto g:m){
                if(g.second>=1){
                    arr.push_back(g.first);
                    if(g.second>1){
                        arr.push_back(g.first);
                    }
                }
            }
            //-1 case
            m.clear();
            for(int i=0;i<arr.size();i++){
                m[arr[i]]++;
            }
            int f=1;
            for(int i=0;i<arr.size();i++){
                for(int j=0;j<arr.size();j++){
                    if(i!=j){
                        int prod=arr[i]*arr[j];
                        if(m[prod]==0){
                            f=0;
                        }
                    }
                }
            }
            if(f==1){
                cout<<"yes\n";
            }
            else{
                cout<<"no\n";
            }
            
        }
        
    }
    
    
    return 0;
}
 
 

