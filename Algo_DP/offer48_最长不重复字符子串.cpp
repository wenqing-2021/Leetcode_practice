#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0){
            return 0;
        }
        vector<char> s_vec;
        for (auto i : s){
            s_vec.emplace_back(i);
        }
        // find the shortest length with the end of s[i].
        vector<int> dp_vec(s_vec.size(), 0);
        // store the char and its order
        unordered_map<char, int> m;
        int result = 0;
        // initial
        m.insert(make_pair(s_vec[0], 0));
        dp_vec[0] = 1;
        result = 1;
        for (int i = 1; i < s_vec.size(); ++i){
            if (m.find(s_vec[i]) == m.end()){
                m.insert(make_pair(s_vec[i], i));
                dp_vec[i] = dp_vec[i-1] + 1;
            }
            else{
                auto it = m.find(s_vec[i]);
                // 判断是否在范围内【比如，abba】不加判断就无法通过
                if (i-1-it->second > dp_vec[i-1]){
                    dp_vec[i] = dp_vec[i-1] + 1;
                }
                else{
                    dp_vec[i] = (i - 1) - it->second + 1;
                }
                m[s_vec[i]] = i;
            }

            result = max(result, dp_vec[i]);
        }

        return result;
    }
};

int main(){

    Solution s1;
    int r = s1.lengthOfLongestSubstring("abcabcbb");
    cout << r << endl;

    return 0;
}