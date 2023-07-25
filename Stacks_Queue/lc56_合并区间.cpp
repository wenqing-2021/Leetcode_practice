/*
以数组 intervals 表示若干个区间的集合，其中单个区间为 intervals[i] = [starti, endi] 。请你合并所有重叠的区间，并返回 一个不重叠的区间数组，该数组需恰好覆盖输入中的所有区间 。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/merge-intervals
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        quicksort(intervals, 0, n-1);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size();) {
            // 找到当前slow指针的最大值
            int t = intervals[i][1];
            // j是fast指针
            int j = i + 1;
            // 向前找到间断点
            while (j < intervals.size() && intervals[j][0] <= t) {
                t = max(t, intervals[j][1]);
                j++;
            }
            ans.push_back({ intervals[i][0], t });
            // 更新slow指针
            i = j;
        }
        return ans;
    }

    void quicksort(vector<vector<int>>& vec, int l, int r){
        if (l > r) return;
        int i = l, j = r;
        while(i < j){
            while (i < j && vec[j][0] >= vec[l][0]) j--;
            while (i < j && vec[i][0] <= vec[l][0]) i++;
            swap(vec[i], vec[j]);
        }
        swap(vec[i], vec[l]);
        quicksort(vec, l, i-1);
        quicksort(vec, i+1, r);
    }
};