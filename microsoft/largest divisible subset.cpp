class Solution {
public:
// unordered_map<int,vector<int>>memo;
//    vector<int> helper(vector<int>&nums,int index){
//     //  if(index==nums.size())return;
//       if(memo.find(index)!=memo.end()){
//          return memo[index];
//       }
   
//     for(int i=index+1;i<nums.size();i++){
//       if(nums[i]%nums[index])continue;
//       auto it= helper(nums,i);
//       if(it.size()>memo[index].size())memo[index]=it;
//    }
//    memo[index].push_back(nums[index]);
//    return memo[index];
    
      
//    }
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        // vector<int>res;
        // sort(nums.begin(),nums.end());
        // for(int i=0;i<nums.size();i++){
        //     auto it= helper(nums,i);
        //     if(it.size()>res.size())res=it;
            
        // }
        // return res;
       
        sort(nums.begin(),nums.end());
       
        int f=0;
        if(nums[0]!=1){
           nums.insert(nums.begin(),1);
           f=1;
        }
        int n=nums.size();
       int dp[n][2];

       for(int i=n-1;i>=0;i--){
           dp[i][0]=0; //as we have always one element in subset
           dp[i][1]=i;  //index where we got largest subset length
           for(int j=i+1;j<n;j++){
               if(nums[j]%nums[i]==0&&dp[j][0]>dp[i][0]){
                    dp[i][0]=dp[j][0];
                    dp[i][1]=j; //insert that index we find maximum subset length
               }
           }
           dp[i][0]++;
       }

       vector<int>ans;
       ans.push_back(nums[0]);
       int i=0;
       while(dp[i][1]!=i){
           i=dp[i][1];
           ans.push_back(nums[i]);
       }
       if(f){
           ans.erase(ans.begin());
       }
       return ans;

    }
};