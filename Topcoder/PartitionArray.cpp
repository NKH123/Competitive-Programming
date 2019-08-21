#include<bits/stdc++.h>
using namespace std;
class PartitionArray{
public:
     vector <int> positiveSum(vector <int> a){
        long long sum=0;
        for(int i=0;i<a.size();i++){
            sum+=a[i];
        }
        vector<int>c;
        if(sum>0){
            c.push_back(a.size());
        }
        else{
            c.push_back(-1);
        }
        return c;
     }
};


int32_t main(){
    ios::sync_with_stdio(false);




    return 0;
}