//
//  main.cpp
//  LongestCommonPrefix
//
//  Created by 胡家豪 on 2021/06/04.
//

/*
 Write a function to find the longest common prefix string amongst an array of strings.

 If there is no common prefix, return an empty string "".
 
 https://leetcode.com/problems/longest-common-prefix/
 */
#include <iostream>
#include <vector>

using namespace std;

string longestCommonPrefix(vector<string>& strs)
{
    if(strs.size() == 0)
    {
        return "";
    }
    string ans = strs[0];
    
    for(int i = 0;i < strs.size() - 1;i ++)
    {
        string s1 = ans;
        string s2 = strs[i + 1];
        ans = "";
        int j = 0;
        while(j < s1.length() && j < s2.length())
        {
            if(s1[j] == s2[j])
            {
                ans.push_back(s1[j]);
            }
            else
            {
                break;
            }
            j ++;
        }
    }
    return ans;
}
int main()
{
    vector<string> str(3);
    string str1;
//    cout<<"insert a string"<<endl;
//    for (int i = 0; i < str.size(); i ++)
//    {
//        cin>>str1;
//        str[i] = str1;
//    }
    str[0] = "flower";
    str[1] = "flight";
    str[2] = "flies";

    cout<<longestCommonPrefix(str)<<endl;
    
    return 0;
}
