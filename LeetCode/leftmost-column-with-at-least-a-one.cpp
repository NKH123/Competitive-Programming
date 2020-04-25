/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int x, int y);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    bool check(int col, int n, int m, BinaryMatrix &binaryMatrix){
      for(int i=0;i<n;i++){
          int num=binaryMatrix.get(i,col);
          if(num==1){
              return true;
          }
      }  
      return false;
  }
  int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
    vector<int>nm=binaryMatrix.dimensions();
    int n=nm[0];
    int m=nm[1];
    int l=0, r=m-1;

    int ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid,n,m, binaryMatrix)){
            ans=mid;
            r=mid-1;
        }
        else{
            l=mid+1;
        }
    }
    return ans;

}
};
