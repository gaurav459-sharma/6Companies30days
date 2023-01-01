class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string>st;
        for(auto s:tokens){
            if(s=="+"||s=="-"||s=="*"||s=="/"){
                long long a=stoll(st.top());
                st.pop();
                long long b=stoll(st.top());
                st.pop();
                long long res;
                if(s=="+")res=b+a;
                else if(s=="-")res=b-a;
                else if(s=="*")res=b*a;
                else res=b/a;
                st.push(to_string(res));
            }
            else{
                st.push(s);
            }
        }
        return stoll(st.top());
    }
};