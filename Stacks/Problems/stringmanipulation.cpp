class Solution{
    public:
    int removeConsecutiveSame(vector <string > v) 
    {
        stack<string> s;
        
        for(int i = 0;i<v.size(); i++)
        {
            if(s.empty())
            {
                s.push(v[i]);
            }
            else if(s.top() == v[i])
            {
                s.pop();
            }
            else s.push(v[i]);
        }
        return s.size();
        // Your code goes here
    } 
};