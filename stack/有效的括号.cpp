/*
 * @Author: myjdml
 * @Date: 2021-03-11 22:24:01
 * @LastEditors: myjdml
 * @LastEditTime: 2021-03-12 01:55:50
 * @FilePath: /stack/stack.cpp
 * @Description: nothing is everything
 */
#include <iostream>
#include <string>
#include <stack>
using namespace std;

class Solution {
public:
  bool isValid(string s) {
    stack<string> Stack;
    for (int i = 0; i < s.length(); i++)
    {
      string targetChar = s.substr(i, 1);
      judge(Stack, targetChar);
    }
    if (Stack.size() == 0) {
      return true;
    } else {
      return false;
    }
  }
  void judge(stack<string> &St, string target) {
    // 判空
    bool judgeEmpty = St.size() == 0 && (target == ")" || target == "]" || target == "}");
    
    if (judgeEmpty) {
      St.push(target);
    } else {
      bool judge = (target == ")" && St.top() == "(") || (target == "]" && St.top() == "[") || (target == "}" && St.top() == "{");
      if (judge) {
        St.pop();
      } else {
        St.push(target);
      }
    }
  }
};

int main()
{
  Solution s;
  cout << s.isValid("}") << endl;
  return 0;
}
