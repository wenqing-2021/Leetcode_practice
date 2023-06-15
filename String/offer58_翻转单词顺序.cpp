#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        vector<string> str_vec;
        string temp_s;
        string res;
        for (auto &c : s){
            if (c != ' '){
                temp_s += c;
            }
            else if (c == ' ' && !temp_s.empty()){
                str_vec.push_back(temp_s);
                temp_s.clear();
            }
        }
        if (!temp_s.empty()){
            str_vec.push_back(temp_s);
        }
        reverse(str_vec.begin(), str_vec.end());
        for (auto &word : str_vec){
            res += word + ' ';
        }
        
        return res.substr(0, res.length()-1);
    }
};