#include<bits/stdc++.h>
using namespace std;
int n;
int x,y;
vector<int> a(3);
int main(){
    cin>>n;
    while(n--){
        int sum=0;
       for(int i=0; i<3;i++){
            cin>>a[i];
            sum+=a[i];
        }
        cin>>x>>y;
        int f=0;
        for(int i=0; i<2;i++){
            for(int j=i+1;j<3;j++){
                int A=a[i], B=a[j];
                int C=sum-(A+B);
                int rep=0;
                while(rep<2){
                    int s1=x-A;
                    int s2=y-B;
                    if(((s1+s2)==C)&&((s1>=0)&&(s2>=0))){
                        f=1;
                    }
                    swap(A,B);
                    rep++;
                }
            }
        }
        if(f==1){
            cout<<"YES\n";
        }
        else{
            cout<<"NO\n";
        }

    }

}
