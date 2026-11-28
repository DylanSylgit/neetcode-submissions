using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> parents(n,-1);
        int ret = n;


        for (int i = 0; i < edges.size(); i++) {
            int rootA = find(parents, edges[i][0]);
            int rootB = find(parents,edges[i][1]);

            if (rootA != rootB) {
                ret--;
                parents[rootB] = rootA;
            }
        }

        

        return ret;


    }

    int find(vector<int>& parents, int node) {
        if (parents[node] != -1) {
            return parents[node] = find(parents,parents[node]);
        }
        return node;
    }
};
