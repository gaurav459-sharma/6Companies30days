class Solution {
public:
    void helper(vector<vector<int>>&res,vector<int>&ans,int num,int k,int n,int sum){
        //   cout<<num<<" "<<n<<" "<<k<<endl;
        if(k==0){
            if(sum==n)res.push_back(ans);
            return;
        }
      
        for(int i=num+1;i<=n-sum&&i<=9;i++){
            ans.push_back(i);
            helper(res,ans,i,k-1,n,sum+i);
             ans.pop_back();
        }
       
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>res;
        vector<int>tmp;
        helper(res,tmp,0,k,n,0);
        return res;
    }
};