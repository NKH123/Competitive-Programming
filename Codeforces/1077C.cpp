#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    long long sum=0;
    cin>>n;
    vector<int> a;
    map<int,int> m;
    a.resize(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
        sum=sum+a[i];
        m[a[i]]++;

    }
    vector<int> J;
    long long SUM;
    for(int i=0;i<n;i++){
        m[a[i]]--;
        auto lar=m.end();
        lar--;
        if(lar->second==0){
            lar--;
        }
        SUM=sum-a[i]-(lar->first);
        if(SUM==(lar->first)){
            J.push_back(i);
        }
        m[a[i]]++;
    }
    cout<<J.size()<<"\n";
    for(int i=0;i<J.size();i++){
        cout<<J[i]+1<<" ";
    }
    cout<<"\n";
    return 0;
}