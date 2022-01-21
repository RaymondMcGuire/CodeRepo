//
//  main.cpp
//  RomantoInteger
//
//  Created by 胡家豪 on 2021/06/01.
//

#include <iostream>
#include <string.h>
#include <unordered_map>
using namespace std;

/*
 Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

 Symbol       Value
 I             1
 V             5
 X             10
 L             50
 C             100
 D             500
 M             1000
 
 There are six instances where subtraction is used:

 I can be placed before V (5) and X (10) to make 4 and 9.
 X can be placed before L (50) and C (100) to make 40 and 90.
 C can be placed before D (500) and M (1000) to make 400 and 900.
 Given a roman numeral, convert it to an integer.
 
 https://leetcode.com/problems/roman-to-integer/
 */

int romanToInt(string s)
{
    unordered_map<char, int> roman;
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    
    int n = 0;
    n = (int)s.length();
    int ans = 0;
    for (int i = n - 1 ; i >= 0; i --)
    {
        if (i == n - 1)
        {
            ans = ans += roman[s[i]];
        }
        else if ((s[i + 1] == 'V' || s[i + 1] == 'X') && s[i] == 'I')
        {
            ans -= 1;
        }
        else if ((s[i + 1] == 'L' || s[i + 1] == 'C') && s[i] == 'X')
        {
            ans -= 10;
        }
        else if ((s[i + 1] == 'D' || s[i + 1] == 'M') && s[i] == 'C')
        {
            ans -= 100;
        }
        else
        {
            ans += roman[s[i]];
        }
    }
    return ans;
}

int main()
{
    string s;
    cout<<"insert a roman numerals"<<endl;
    cin>>s;
    int ans = romanToInt(s);
    cout<<ans<<endl;
    return 0;
}
