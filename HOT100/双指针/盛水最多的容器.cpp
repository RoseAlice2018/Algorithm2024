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

class Solution {
public:
    int maxArea(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int ret = 0;
        while(left < right)
        {
            int height_ = min(height[left], height[right]);
            int width = right - left;
            if(height_ * width > ret)
                ret = height_ * width;
            
            if(height[left] <= height[right])
                left++;
            else 
                right--;
        }
        return ret;
    }
};