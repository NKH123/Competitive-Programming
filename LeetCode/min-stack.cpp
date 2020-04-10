class MinStack {
public:
    /** initialize your data structure here. */
    vector<int>S;
    vector<int>M;
    MinStack() {
            S.clear();
            M.clear();
    }
    
    void push(int x) {
        S.push_back(x);
        if(M.size()==0){
            M.push_back(x);
        }
        else{
            if(M[M.size()-1]>=x){
                M.push_back(x);
            }
        }
    }
    
    void pop() {
        int ele=S[S.size()-1];
        S.pop_back();
        if(M.size()!=0){
            if(M[M.size()-1]==ele){
                M.pop_back();
            }
        }
    }
    
    int top() {
        return S[S.size()-1];
    }
    
    int getMin() {
        return M[M.size()-1];
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */