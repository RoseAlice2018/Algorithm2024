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
    string getHint(string secret, string guess) {
        int bulls = 0, cows = 0;
        unordered_map<char, int> key_map;
        unordered_map<char, int> guess_map;

        //比较两者每一位的数据
        for(int i = 0; i < min(secret.size(), guess.size()); i++)
        {
            if(secret[i] == guess[i])
            {
                bulls ++;
            }
            else 
            {
                if(key_map.count(secret[i]))
                    key_map[secret[i]]++;
                else 
                    key_map[secret[i]] = 1;

                if(guess_map.count(guess[i]))
                    guess_map[guess[i]]++;
                else
                    guess_map[guess[i]] = 1; 
            }   
        }

        // 比较map
        for(auto  key : guess_map)
        {
            if(key_map.count(key.first))
            {
                cows++;
                key_map[key.first]--;
            }
        }
        return to_string(bulls) + 'A' + to_string(cows) + 'B';
    }
};