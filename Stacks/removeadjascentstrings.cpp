class Solution {
public:
    string removeDuplicates(string A) {
        stack<char> s;
        for(int i = 0;i<A.size();i++)
        {
            if(s.empty() ||  A[i] != s.top())
            {
                s.push(A[i]);
            }
            else
            {
                s.pop();
            }
        
        }
    string ans="";
    while(!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
    }
};