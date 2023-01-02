// Approach
// prevprevprev is used to the store answer of previos rotation (initially k=0)
// store prefix sum in psum=0psum=0psum=0
// Now

// for every rotation the last index element comes at index0(0∗nums[0]=0) 0 (0*nums[0]=0)0(0∗nums[0]=0)
// ->means we have to substract this from prevprevprev
// i.eprev−(n−1)∗nums[i] prev-(n-1)*nums[i]prev−(n−1)∗nums[i]
// for every rotation every elements shifts to right means we have to add the prefixsum except the element which comes to index 0
// i.e prev+(n−1)∗nums[i]+psum−nums[i]prev+(n-1)*nums[i]+psum-nums[i]prev+(n−1)∗nums[i]+psum−nums[i]
// Complexity
// Time complexity:
// 0(N)

// Space complexity:
// 0(1)

// Code
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int prev=0,psum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            prev+=(i*nums[i]);
            psum+=nums[i];
        }
        int res=prev;
        for(int i=n-1;i>0;i--){
            prev=prev-(n-1)*nums[i]+psum-nums[i];
            res=max(res,prev);
        }
        return res;

    }
};