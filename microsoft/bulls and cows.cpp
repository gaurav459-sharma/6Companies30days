class Solution {
public:
    string getHint(string secret, string guess) {
        unordered_map<char,int>mp;
        for(auto it:secret)mp[it]++;
        unordered_set<char>st;
        int b=0,c=0;
        for(int i=0;i<secret.length();i++){
            if(secret[i]==guess[i]){
                b++;
                mp[secret[i]]--;
                if(mp[secret[i]]==0)mp.erase(secret[i]);
                st.insert(secret[i]);
            }
           
           
        }
        for(int i=0;i<secret.length();i++){
              if(secret[i]!=guess[i]){
                 if(mp.find(guess[i])!=mp.end()){
                     c++;
                      mp[guess[i]]--;
                if(mp[guess[i]]==0)mp.erase(guess[i]);
                 }
              }
        }

        string res=to_string(b);
        res+='A';
        res+=to_string(c);
        res+='B';
        return res;

    }
};