#include<bits/stdc++.h>
using namespace std;
class Restrictions{
public:
    vector <int> exist(int n, int m, vector <int> type, vector <int> l, vector <int> r, vector <int> val){
        vector<int>a(n,1);
        vector<int>mini(n,1);
        vector<int>maxi(n,1000000);
        vector<int>inv;
        inv.push_back(-1);
        for(int i=0;i<m;i++){
            if(type[i]==1){
                for(int j=l[i];j<=r[i];j++){
                    {
                        mini[j]=max(mini[j],val[i]);
                    }
                }
            }
            else{
                for(int j=l[i];j<=r[i];j++){
                    {
                        maxi[j]=min(maxi[j],val[i]);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            if(maxi[i]<mini[i]){
                return inv;
            }
            a[i]=mini[i];
        }
        return a;
    }

};


int32_t main(){
    ios::sync_with_stdio(false);




    return 0;
}