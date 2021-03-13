/*
 * @Author: myjdml
 * @Date: 2021-03-12 19:19:35
 * @LastEditors: myjdml
 * @LastEditTime: 2021-03-14 03:07:00
 * @FilePath: /LCcn-practice/stack/最小栈.cpp
 * @Description: nothing is everything
 */
#include <iostream>
#include <stack>
using namespace std;

class MinStack {
public:
  /** initialize your data structure here. */
  MinStack() {
  }
  
  void push(int x) {
    if (data.size() == 0) {
      // 第一个元素栈为空，无需比较，直接压栈
      data.push(x);
      min.push(x);
    } else {
      // 每个元素与最小栈栈顶比较，不大于则压入最小栈
      data.push(x);
      if (min.top() >= x) {
        min.push(x);
      }
    }
  }
  
  void pop() {
    if (data.top() == min.top())
    {
      min.pop();
    }
    data.pop();
  }
  
  int top() {
    return data.top();
  }
  
  int getMin() {
    return min.top();
  }
private:
  stack<int> data;
  stack<int> min;
};

int main ()
{
  MinStack minStack;
  minStack.push(0);
  minStack.push(1);
  minStack.push(0);
  cout << minStack.getMin() << endl; 
  minStack.pop();
  minStack.top();      
  cout << minStack.getMin() << endl;   
  return 0;
}
