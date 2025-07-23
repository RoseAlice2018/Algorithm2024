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
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int first = m - 1;
        int second = n - 1;
        int space = m + n - 1;
        
        while(first >=0 && second >= 0)
        {
            if(nums1[first] > nums2[second])
            {
                nums1[space] = nums1[first];
                space--;
                first--;
            }
            else{
                nums1[space] = nums2[second];
                space--;
                second--;
            }
        }

        while(second >= 0)
        {
            nums1[space] = nums2[second];
            space--;
            second--;
        }
    }
};