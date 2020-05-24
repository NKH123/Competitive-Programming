#include <iostream>
using namespace std;

int main() {
    int t;cin >> t;
    while(t--)
    {
        int n,m,d,p;cin >> n >> m >> d >> p;
        if(m<d*n || m>p*n) cout << -1 << endl;
        else
        {
            int k=0;
            int count=0;
            while(k<n)
            {
                bool flag=0;
            for(int j=0;j<n;j++)
            {
                cout << j+1 << " " << (j+k)%n+1 << endl;
                count++;
                if(count==m) {flag=1;break;}
            }
            if(flag) break;
            k++;
            }
        }
    }
	return 0;
}
