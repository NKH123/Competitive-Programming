#include<bits/stdc++.h>
using namespace std;
int t;
string a;
string b;
int main() {
    cin >> t;
    while (t--) {
        cin >> a >> b;
        /*int sel[3];
        memset(sel, 0, sizeof(sel));
        int f0 = 0;
        for (int i = 0; i < 3; i++) {
            if (a[i] == 'b' || b[i] == 'b') {
                sel[i] = 1;
                f0 = 1;
                break;
            }
        }
        if (f0 == 0) {
            cout << "no\n";
            continue;
        }
        f0 = 0;
        for (int i = 0; i < 3; i++) {
            if (!sel[i]) {
                if (a[i] == 'b' || b[i] == 'b') {
                    sel[i] = 1;
                    f0 = 1;
                    break;
                }
            }
        }
        if (f0 == 0) {
            cout << "no\n";
            continue;
        }
        f0 = 0;
        for (int i = 0; i < 3; i++) {
            if (!sel[i]) {
                if (a[i] == 'o' || b[i] == 'o') {
                    sel[i] = 1;
                    f0 = 1;
                    break;
                }
            }
        }
        if (f0 == 0) {
            cout << "no\n";
            continue;
        } else {
            cout << "yes\n";
        }*/
        int f=0;
        for(int i=0; i<8;i++){
            string c;
            c.clear();
            for(int j=0;j<3;j++){
                if(i&(1<<j)){
                    c.push_back(a[j]);
                }
                else{
                    c.push_back(b[j]);
                }
            }
            if(c=="bob"||c=="bbo"||c=="obb"){
                f=1;
            }
        }
        if(f==0){
            cout<<"no\n";
        }
        else{
            cout<<"yes\n";
        }
 
 
 
 
    }
    return 0;
}