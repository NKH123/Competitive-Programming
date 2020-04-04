class Solution {
public:
    bool canConstruct(string s, int k) {
        int ans=0;
        vector<int>a(26,0);
        for(int i=0;i<s.size();i++){
            a[s[i]-'a']++;
        }
        if(s.size()==k){
            return true;
        }
        else if(s.size()<k){
            return false;
        }
            int f=0;
            for(int i=0;i<26;i++){
                if(a[i]%2==0){
                    
                }
                else{
                    f++;
                }
            }
            if(f==0){
                return true;
            }
            else{
                return k>=f;
            }
    }
};