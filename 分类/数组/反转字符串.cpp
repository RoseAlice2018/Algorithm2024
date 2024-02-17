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
    void reverseString(vector<char>& s) {
        int n = s.size();
        for(int left = 0 , right = n-1; left < right ; ++left, --right)
        {
            swap(s[left], s[right]);
        }
    }
};