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
    int findKthLargest(vector<int>& nums, int k) {
        stack<int> s;
        for(int i = 0; i < nums.size(); i++)
        {
            if(s.empty())
            {
                s.push(nums[i]);
                continue;
            }
            if(!s.empty() && s.top() < nums[i])
            {
                if(s.size() == k)
                {
                    s.pop();
                    stack<int> tmp;
                    while(!s.empty() && s.top() < nums[i])
                    {
                        tmp.push(s.top());
                        s.pop();
                    }
                    s.push(nums[i]);
                    while(!tmp.empty())
                    {
                        s.push(tmp.top());
                        tmp.pop();
                    }
                }
                else if(s.size() < k) {
                    s.push(nums[i]);
                }
            }
            else{
                if(s.size() < k)
                    s.push(nums[i]);
            }

        }
        return s.top();
    }
};


class Solution {
public:
    int quicksort(vector<int> &nums, int left, int right, int k)
    {
        if(left == right)
        {
            return nums[k];
        }

        int partition = nums[left], i = left - 1, j = right + 1;
        while(i < j)
        {
            do i++; while(nums[i] < partition);
            do j--; while(nums[j] > partition);
            if(i < j)
                swap(nums[i], nums[j]);
        }
        if(k <= j) return quicksort(nums, left, j, k);
        else return quicksort(nums, j + 1, right, k);
    }
    int findKthLargest(vector<int>& nums, int k) {
        
    }
};


class Solution {
public:
    int quickSelect(vector<int>& nums, int left, int right, int k)
    {
        if(left == right)
            return nums[left];

        int pivot = nums[right];

        int saved_index = left;
        for(int j = left; j < right; j++)
        {
            if(nums[j] > pivot)
            {
                swap(nums[saved_index], nums[j]);
                saved_index++;
            }
        }
        swap(nums[saved_index], nums[right]);
        if(saved_index == k)
            return nums[saved_index];

        if(saved_index < k)
            return quickSelect(nums, saved_index+1, right, k);
        else{
            return quickSelect(nums, left, saved_index-1, k);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        return quickSelect(nums, 0, nums.size()-1, k - 1);
    }
};