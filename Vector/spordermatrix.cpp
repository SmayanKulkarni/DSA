//leetcode 54

#include <iostream>
#include <vector>
using namespace std;
class Solution
{
    public:
        vector<int> spiralorder(vector<vector<int>>& matrix)
        {   
            vector<int> ans;
            int m = matrix.size();
            int n = matrix[0].size();
            if(n==0) return ans;
            int sr=0, er=m-1,sc=0,ec=n-1;
            int count=0;
            while(sr<=er && sc<=ec)
            {
                for(int i=sc;i<=ec;i++)
                {
                    ans.push_back(matrix[sr][i]);
                    count++;
                }
                sr++;
                if(count==m*n) return ans;

                for(int i=sr;i<=er;i++)
                {
                    ans.push_back(matrix[i][ec]);
                    count++;
                }
                ec--;
                if(count==m*n) return ans;
                for(int i=ec;i>=sc;i--)
                {
                    ans.push_back(matrix[er][i]);
                    count++;
                }
                er--;
                if(count==m*n) return ans;

                for(int i= er;i>=sr;i--)
                {
                    ans.push_back(matrix[i][sc]);
                    count++;
                }
                sc++;
                if(count==m*n) return ans;
            }
            return ans;

        }
    

};

int main()
{
    Solution obj;
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{3,4,6},{3,5,7}};
    vector<int> ans = obj.spiralorder(matrix);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}