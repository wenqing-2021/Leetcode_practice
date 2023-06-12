
#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    int res = 0;
    int translateNum(int num) {
        vector<bool> used;
        vector<int> num_vector;
        int count = 0;
        string num_str = to_string(num);
        for (auto s : num_str){
            num_vector.emplace_back(s-'0');
            used.emplace_back(false);
        }
        backtrack(num_vector, count, used);
        return res;
    }
    void backtrack(vector<int>& num, int& count, vector<bool>& used){
        if (count == num.size()){
            res++;
            return;
        }
        for (int i = 0; i < num.size(); ++i){
            if (!used[i]){
                count++;
                used[i] = true;
                backtrack(num, count, used);
                used[i] = false;
                count--;
                if (i < num.size() - 1){
                    if ((num[i] * 10 + num[i+1]) <= 25){
                        used[i] = true;
                        used[i+1] = true;
                        count += 2;
                        backtrack(num, count, used);
                        used[i] = false;
                        used[i+1] = false;
                        count -= 2;
                    }
                }
            }
        }
    }
};

class Solution2 {
public:
    int translateNum(int num) {
        string src = to_string(num);
        int len =src.size();

        vector<int> dp(len+1,0);
        dp[0] =1;
        dp[1] =1;

        for(int i = 2; i<=len;++i){
            string tmp = src.substr(i-2,2);
            dp[i] = (tmp<="25" && tmp>="10" >0) ? dp[i-1]+dp[i-2]:dp[i-1]; 
        
        }
        return dp[len];
    }
};

int main(){
    Solution s1;
    Solution2 s2;
    // int result = s1.translateNum(123);
    int result = s2.translateNum(123);
    cout << result << endl;
    return 0;
}