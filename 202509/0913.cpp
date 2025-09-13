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


// 
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int m = version1.size();
        int n = version2.size();

        int i = 0, j = 0;
        while(i < m || j < n)
        {
            long val1 = 0;
            for(; i < m; i++)
            {
                if(version1[i] == '.')
                {
                    i++;
                    break;
                }
                val1 = val1 * 10 + version1[i] - '0';
            }
            long val2 = 0;
            for(;j < n; j++)
            {
                if(version2[j] == '.')
                {
                    j++;
                    break;
                }
                val2 = val2 * 10 + version2[j] - '0';
            }
            cout<<val1<<" "<<val2<<endl;
            if(val1 > val2) return 1;
            else if (val1 < val2) return -1;
        }
        return 0;
    }
};

























