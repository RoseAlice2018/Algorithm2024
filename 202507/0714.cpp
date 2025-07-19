#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<unordered_map>
#include<unordered_set>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x):val(x), next(nullptr) {}
    ListNode(int x, ListNode *next):val(x), next(next){}
};

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode():val(0), left(nullptr), right(nullptr){}
    TreeNode(int x):val(x), left(nullptr), right(nullptr){}
    TreeNode(int x, TreeNode *left, TreeNode *right):val(x), left(left), right(right){}
};

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ret;
        for(int left = 0; left < nums.size(); left++)
        {
            if(left > 0)
            {
                while(nums[left] == nums[left - 1])
                    left++;
            }
            int target = -nums[left];
            vector<int> tmp; 
            for(int num : tmp){
                std::cout<<num<<endl;
            }
            for(int i = left + 1, j = nums.size() - 1; i < nums.size(); )
            {
                tmp.push_back(nums[left]);
                if(i >= j) break;
                if(nums[i] + nums[j] == target)
                {
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[j]);
                    ret.push_back(tmp);
                    i++;
                    j--;
                    tmp.clear();
                    continue;
                }
                else if(nums[i] + nums[j] > target)
                {
                    j--;
                }
                else{
                    i++;
                }
            }
        } 
        return ret;  
    }
};



class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int       
    }
};