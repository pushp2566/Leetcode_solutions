class Solution {
public:
    int nextGreaterElement(int n) {
        string s=to_string(n);
        int m= s.size();
        int ind=-1;
        for(int i=m-2;i>=0;i--){
              if(s[i]<s[i+1]){
                ind=i;break;
              }
        }

        if(ind ==-1)return ind;

        int ind2;
        for(int i=m-1;i>ind;i--){
            if(s[i]>s[ind]){
                ind2=i;
                break;
            }
        }

        swap(s[ind],s[ind2]);

        for(int i=ind+1,j=m-1;i<m;i++,j--){
                  if(j<i)break;
                  swap(s[i],s[j]);
        }


  long long x = stoll(s);

        if (x > INT_MAX)
            return -1;

        return (int)x;


    }
};