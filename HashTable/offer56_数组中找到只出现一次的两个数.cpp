
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<int> singleNumbers(vector<int>& nums) {
        unordered_map<int, bool> mp;
        vector<int> res;
        for (auto num_i : nums){
            // first show
            if (mp.find(num_i) == mp.end()){
                mp.insert(make_pair(num_i, true));
            }
            else{
                auto it = mp.find(num_i);
                it->second = false;
            }
        }

        for (auto it = mp.begin(); it != mp.end(); ++it){
            if (it->second){
                res.push_back(it->first);
            }
        }

        return res;
    }
};


int main(){

    vector<int> test_vec = {1,3,3,4,5,1,2,5};

    Solution s1;

    vector<int> res = s1.singleNumbers(test_vec);

    for (auto& num : res){
        cout << num << endl;
    }

    return 0;

}