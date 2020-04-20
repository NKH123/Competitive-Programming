    class Solution {
    public:
        int search(vector<int>& a, int target) {
            int l=0, r=a.size()-1;
            int n=a.size();
            int ans=-1;
            //find pivot

            int I=0;
            int ele=-(1000000000);
            int piv;
            while(l<=r){
                int mid=(l+r)/2;
                piv=mid;
                if(a[l]<a[r]){
                    if(a[mid]>ele){
                        r=mid-1;
                    }
                    else{
                        l=mid+1;
                    }
                }
                else if(a[l]>a[r]){
                    // l=mid+1;
                    if(a[mid]>=a[r]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
                else{
                    if(a[mid]>a[r]){
                        l=mid+1;
                    }
                    else{
                        r=mid-1;
                    }
                }
            }
            cout<<piv<<"\n";
            l=0, r=n-1;

            while(l<=r){
                int mid=(l+r)/2;
                if(a[mid]==target){
                    return mid;
                }
                else if(a[mid]>target){
                    if(a[l]>=a[r]){
                        if(a[l]>target){
                            if(piv>mid)
                            l=mid+1;
                            else{
                                r=mid-1;
                            }
                        }
                        else{
                            r=mid-1;
                        }
                    }
                    else{
                        r=mid-1;
                    }
                }
                else if(a[mid]<target){
                   if(a[l]>=a[r]){
                        if(a[r]>=target){
                            l=mid+1;
                            // if
                            // r=mid-1;
                        }
                        else{
                            // l=mid+1;
                            // r=mid-1;
                            if(mid<piv){
                                l=mid+1;
                            }
                            else{
                                r=mid-1;
                            }
                            // r=mid-1;
                        }
                    }
                    else{
                        // r=mid-1;
                        l=mid+1;
                    }
                }
            }
            return ans;
        }
    };