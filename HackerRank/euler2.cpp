#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
        vector<int> A;
        for(int i=100;i<=999;i++){
                for(int j=i;j<=999;j++){
                        int a=i*j;
                        int a1=a/1000;
                        int a2=a%1000;
                        int a3=0;
                        while(a2>0){
                            a3=a3*10+a2%10;
                            a2=a2/10;
                        }
                        if(a1==a3){
                                A.push_back(a);    
                        }
                }
        }
       
       sort( A.begin(), A.end() );
A.erase( unique( A.begin(), A.end() ), A.end() );
         /*for(auto d: A){
            cout<<d<<" ";
        }
        cout<<"\n";*/
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        cin >> n;
            /*auto a=lower_bound(A.begin(),A.end(),n)-A.begin();
            cout<<A[a]<<"\n";*/
        int lo=0,hi=A.size()-1;
        int ans;
        int mid;
        /*while(lo<=  hi){
            mid=(lo+hi)/2;
            if(A[mid]>=n){
                ans=A[mid];
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }*/
        auto a=lower_bound(A.begin(),A.end());
        a--;
        cout<<*a<<"\n";
    }
    return 0;
}