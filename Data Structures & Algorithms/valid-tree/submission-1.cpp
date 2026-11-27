using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if (edges.size() > n-1) return false;
        vector<vector<int>> nodes(n);

        for (int i = 0; i < edges.size(); i++) {
            nodes[edges[i][0]].push_back(edges[i][1]);
            nodes[edges[i][1]].push_back(edges[i][0]);
        }

        unordered_set<int> visit;
        
        if (dfs(nodes,-1,visit,0) == false) return false;

        return visit.size() == n;


    }

    bool dfs(vector<vector<int>>& nodes, int parent, unordered_set<int>& visit, int node) {

        if (visit.count(node)) return false;

        visit.insert(node);
        for (int n : nodes[node]) {
            if (n == parent) continue;

            if (!dfs(nodes,node,visit,n)) return false;

        }
        return true;

    }
};
