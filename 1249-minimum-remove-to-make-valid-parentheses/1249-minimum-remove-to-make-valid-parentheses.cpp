class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int n=s.size();
        stack<int>st;
        unordered_set<int>indexes;
        for(int i=0;i<n;i++){
            if(st.empty()){
                if(s[i]==')')indexes.insert(i);
                else  if(s[i]=='(')st.push(i);
            }
            else{
               if(s[i]==')')st.pop();
               else  if(s[i]=='(')st.push(i);

            }
        }
        while(!st.empty()){
            int i=st.top();
            indexes.insert(i);
            st.pop();
        }

                string ans;
                for(int i=0;i<n;i++){
                    if(indexes.find(i)==indexes.end(i)){
                        ans.push_back(s[i]);
                    }
                }

                return ans;
    }
};