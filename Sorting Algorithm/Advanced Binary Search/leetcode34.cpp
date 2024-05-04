#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    int getIndex(vector<int> &nums, int target, bool first)
    {
        int s = 0;
        int e = nums.size() - 1;
        int ans = -1;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;

            if (nums[mid] == target)
            {
                ans = mid;
                if (first)
                {
                    e = mid - 1;
                }
                else
                    s = mid + 1;
            }

            else if (nums[mid] > target)
            {
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int> &nums, int target)
    {
        vector<int> v(2,-1);
        int first =getIndex(nums, target, true);
        
        if(first ==-1)
        {
            return v;
        }
        int last = getIndex(nums, target, false);
        v[0] = first;
        v[1] = last;
        return v;
       
    }
};

int main()
{
    Solution obj;
    vector<int> nums = {1,2,3,4,5,6,7};
    int first =  obj.getIndex(nums, 5, true);
    int last =  obj.getIndex(nums, 5, false);
    vector<int> finalans = obj.searchRange(nums, 5);
    for(int i = 0;i<2;i++)
    {
        cout<<finalans[i]<<endl;
    }

}
