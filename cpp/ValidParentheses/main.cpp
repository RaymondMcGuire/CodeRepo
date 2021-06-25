//
//  main.cpp
//  ValidParentheses
//
//  Created by 胡家豪 on 2021/06/04.
//

/*
 Given a string s containing just the characters '(', ')', '{', '}', '[' and ']',
 determine if the input string is valid.

 An input string is valid if:

 Open brackets must be closed by the same type of brackets.
 Open brackets must be closed in the correct order.
 
 https://leetcode.com/problems/valid-parentheses/
 */
#include <iostream>
#include <stack>

using namespace std;

bool isValid(string s)//字符查找消除
{
    bool isValid = false;
    for (int i = 0; i < (int)s.length(); i ++)
    {
        if ((s[i] == '(' && s[i + 1] == ')')
            || (s[i] == '[' && s[i + 1] == ']')
            || (s[i] == '{' && s[i + 1] == '}'))
        {
            s = s.erase(i,2);
            i = -1;
        }
    }
    if (s.length() == 0)
    {
        isValid = true;
    }
    return isValid;
}

bool isValidStack(string s)//栈
{
    bool isValid = false;
    stack<char>stack1;
    stack1.push(s[0]);
    for (int i = 1; i < (int)s.length(); i++)
    {
        if ((s[i] == ')') || (s[i] == ']') ||(s[i] == '}'))
        {
            if (stack1.empty())
            {
                return false;
            }
            if ((stack1.top() == '(' && s[i] == ')')
                || (stack1.top() == '[' && s[i] == ']')
                || (stack1.top() == '{' && s[i] == '}'))
            {
                stack1.pop();
            }
            else
            {
                stack1.push(s[i]);
            }
        }
        else
        {
            stack1.push(s[i]);
        }
    }
    if (stack1.empty())
    {
        isValid = true;
    }
    return isValid;
}

int main()
{
    string str = "";
    cout<<"insert a string"<<endl;
    cin>>str;
    cout<<isValidStack(str)<<endl;
    
}
