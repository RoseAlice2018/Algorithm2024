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
    int distinctIntegers(int n) {
        unordered_set<int> desk;
        desk.insert(n);
        int _last_size = desk.size();
        while(1)
        {
            for(int i = 1; i <= n; i++)
            {
                for(auto iter : desk)
                {
                    if(iter % i == 1)
                    {
                        if(desk.count(i))
                            continue;
                        else 
                            desk.insert(i);
                    }
                }
            }

            if(_last_size == desk.size())
                break;
            _last_size = desk.size();
        }
        return desk.size();
    }
};

class Solution {
public:
    int distinctIntegers(int n) {
        return n == 1? 1 : n-1;      
    }
};