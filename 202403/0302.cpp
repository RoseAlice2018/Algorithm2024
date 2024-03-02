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
    unordered_map<int, vector<int>> edges_map;
    unordered_set<int> visted;
    unordered_set<int> restricted_set;
    void dfs(int node)
    {
        visted.insert(node);
        auto edges = edges_map[node];
        for(int i = 0; i < edges.size(); i++)
        {
            auto target = edges[i];
            if(visted.count(target) || restricted_set.count(target))
                continue;;
            dfs(target);
        }
        return;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        for(int i = 0; i < edges.size(); i++)
        {
            auto edge = edges[i];
            if(edges_map.count(edge[0]))
                edges_map[edge[0]].push_back(edge[1]);
            else 
                edges_map[edge[0]] = vector<int>{edge[1]};
            
            if(edges_map.count(edge[1]))
                edges_map[edge[1]].push_back(edge[0]);
            else 
                edges_map[edge[1]] = vector<int>{edge[0]};
        }

        for(int i = 0; i < restricted.size(); i++)
            restricted_set.insert(restricted[i]);
        
        dfs(0);
        return visted.size();
    }
};