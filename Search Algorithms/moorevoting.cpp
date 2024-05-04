// to find majority element
//leedcode 169
class Solution {
public:
    int majorityElement(vector<int>& A) {
        int cand=A[0];
        int count=1;

        int n = A.size();
        for(int i =1; i<n;i++)
        {
            if(A[i]==cand)
            {
                count++;
            }
            else
            {
                count--;
            
            if(count==0)
            {
                cand = A[i];
                count =1;  
            }
        }
    }
    return cand;
    }
};