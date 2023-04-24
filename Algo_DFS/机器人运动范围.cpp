#include <vector>
using namespace std;

class Solution {
public:
    int movingCount(int m, int n, int k) {
        max_i = m;
        max_j = n;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        dfs(0, 0, k, visited);
        return res_;
    }
private:
    int max_i, max_j, res_;
    void dfs(int i, int j, int k, vector<vector<bool>>& visited){
        // reach boundary
        if (i < 0 || j < 0 || i >= max_i || j >= max_j || visited[i][j] == true){
            return;
        }
        // check the current node is valid
        int i_1 = i % 10;
        int i_2 = i / 10;
        int j_1 = j % 10;
        int j_2 = j / 10;
        if ((i_1 + i_2 + j_1 + j_2) > k){
            return;
        }
        else{
            res_++;
            visited[i][j] = true;
            dfs(i-1, j, k, visited);
            dfs(i+1, j, k, visited);
            dfs(i, j-1, k, visited);
            dfs(i, j+1, k, visited);
        }
        return;
    }
};