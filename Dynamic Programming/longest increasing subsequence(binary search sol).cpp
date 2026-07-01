// binary search solution
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> vec;
        for(int i=0;i<nums.size();i++){
            if(vec.empty()) vec.push_back(nums[i]);
            else{
                if(vec.back()>nums[i]){
                    int l=0;
                    int r=vec.size()-1;
                    int idx=r;
                    while(l<=r){
                        int mid=(l+r)/2;
                        if(vec[mid]>=nums[i]){
                            idx=mid;
                            r=mid-1;
                        }else{
                            l=mid+1;
                        }
                    }vec[idx]=nums[i];
                }else if(nums[i]>vec.back()){
                    vec.push_back(nums[i]);
                }
            }
        }return vec.size();
    }
};