#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    cin>>n>>k;
    int a[10007];
    for(int i=0;i<k;i++){
        cin>>a[i];
    }
    double lo=0,hi=1e12;
    double mid;
    long long inv;
    double rem;
    for(int i=0;i<400;i++){
        mid=(hi+lo)/2;
        inv=n;
        rem=0;
        for(int j=0;j<k;j++){
            if(a[j]>=mid){
                inv--;
            }
            else{
                rem=rem+a[j];
            }

        }
        if(rem<=0){
            lo=mid;
        }
        else{
            rem=rem/inv;
            hi=mid+rem;
        }

    }
 
        printf("%6f",mid);
    return 0;
}