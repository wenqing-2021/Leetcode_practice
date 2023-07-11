
/*
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。
*/

#include <string>
#include <stack>
using namespace std;


class Solution {
public:
    int longestValidParentheses(string str) {
        int dp[30005],maxx=0;
        stack<int>s;
        int len=str.length();
        // 第一次循环找到一对有效括号，并且将他们置为空
        for(int i=0;i<len;i++){
            if(str[i]=='(') s.push(i);
            else if(!s.empty()){
                str[s.top()]=' ';
                s.pop();
                str[i]=' ';
            }
        }
        // 找到连续空的最长子串长度，并且返回
        for(int i=0;i<len;i++){
            if(str[i]==' '){ 
                dp[i+1]=dp[i]+1;
                maxx=max(maxx,dp[i+1]); 
            }
            else dp[i+1]=0;
        }
        // cout<<maxx;
        return maxx;
    }
};