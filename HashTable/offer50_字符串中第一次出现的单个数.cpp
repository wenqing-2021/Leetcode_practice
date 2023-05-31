#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;


class Solution {
public:
    char firstUniqChar(string s) {
        if (s.size() == 0) return ' ';
        queue<char> q;
        unordered_map<char, int> mp;
        for (auto c : s){
            if (c == q.front()){
                q.pop();
                // check the next one
                char temp = q.front();
                while (!q.empty()){
                    if (mp.find(temp)->second == 1){
                        break;
                    }
                    q.pop();
                    temp = q.front();
                }
            }
            else{
                if (mp.find(c) == mp.end()){
                    q.push(c);
                    mp.insert(make_pair(c, 1));
                }
                else{
                    auto it = mp.find(c);
                    it->second += 1;
                    continue;
                }
            }
        }
        if (q.size() != 0) return q.front();

        return ' ';
    }
};


class Solution {
public:
    char firstUniqChar(string s) {
        vector<char> keys;
        unordered_map<char, bool> dic;
        for(char c : s) {
            if(dic.find(c) == dic.end())
                keys.push_back(c);
            dic[c] = dic.find(c) == dic.end();
        }
        for(char c : keys) {
            if(dic[c]) return c;
        }
        return ' ';
    }
};
