//
//  main.cpp
//  Palindrome
//
//  Created by 胡家豪 on 2021/06/01.
//

#include <iostream>
using namespace std;
/*
 Given an integer x, return true if x is palindrome integer.
 An integer is a palindrome when it reads the same backward as forward.
 For example, 121 is palindrome while 123 is not.
 
 https://leetcode.com/problems/palindrome-number/
 */

bool isPalindrome(int x)
{
    bool isPal = false;
    if (x < 0)
    {
        return isPal;
    }
    else
    {
        int a = x;
        int res = 0;
        while (a != 0)
        {
            int digit = a % 10;
            res = res * 10 + digit;
            a /= 10;
        }
        if (res == x)
        {
            isPal = true;
        }
    }
    return isPal;
}

int main()
{
    int num = 0;
    cout<<"insert a number"<<endl;
    cin>>num;
    if (isPalindrome(num))
    {
        cout<<"true"<<endl;
    }
    else
    {
        cout<<"false"<<endl;
    }

    cout<<"exit"<<endl;

    return 0;
}
