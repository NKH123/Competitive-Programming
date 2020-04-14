class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        deque<char>S;
        for(int i=0;i<s.size();i++){
            char A=s[i];
            S.push_back(s[i]);
        }
        for(int i=0;i<shift.size();i++){
            if(shift[i][0]==0){
                for(int j=0;j<shift[i][1];j++){
                    S.push_back(S.front());
                    S.pop_front();
                }
            }
            else{
                for(int j=0;j<shift[i][1];j++){
                    S.push_front(S.back());
                    S.pop_back();
                }
            }
        }
        string ans;
        for(auto g:S){
            ans=ans+g;
        }
        return ans;
    }
};