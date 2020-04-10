class Solution {
public:
    bool backspaceCompare(string S, string T) {
        vector<char>a;
        vector<char>b;
        for(int i=0;i<S.size();i++){
            if(S[i]=='#'){
                if(a.size()!=0){
                    a.pop_back();
                }
            }
            else{
                a.push_back(S[i]);
            }
        }
        for(int i=0;i<T.size();i++){
            if(T[i]=='#'){
                if(b.size()!=0){
                    b.pop_back();
                }
            }
            else{
                b.push_back(T[i]);
            }
        }
        if(a.size()!=b.size()){
            return false;
        }
        for(int i=0;i<a.size();i++){
            if(a[i]!=b[i]){
                return false;
            }
        }
        return true;
    }
};