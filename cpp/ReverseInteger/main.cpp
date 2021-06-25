//
//  main.cpp
//  ReverseInteger
//
//  Created by 胡家豪 on 2021/06/03.
//

#include <iostream>
using namespace std;

/*
 Given a signed 32-bit integer x, return x with its digits reversed.
 If reversing x causes the value to go outside the signed 32-bit integer
 range [-2^31, 2^31 - 1], then return 0.
 https://leetcode.com/problems/reverse-integer/
 */

int reverse(int x)
{
    int res = 0;
    if (x == 0)
    {
        return 0;
    }
    while (x)
    {
        if (res > INT_MAX / 10 || res < INT_MIN /10)
        {
            return 0;
        }
        res = res * 10 + (x % 10);
        x /= 10;
    }
    return res;
}

int main()
{
    cout<<"insert a number"<<endl;
    int x;
    cin>>x;
    cout<<reverse(x)<<endl;
}
