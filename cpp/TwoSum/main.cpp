//
//  main.cpp
//  TwoSum
//
//  Created by 胡家豪 on 2021/06/01.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 Given an array of integers nums and an integer target,
 return indices of the two numbers such that they add up to target.
 You may assume that each input would have exactly one solution,
 and you may not use the same element twice.
 
 https://leetcode.com/problems/two-sum/
 */

vector<int> twoSum(vector<int>&nums,int target)
{
    vector<int> res;
    for (int i = 0; i < nums.size(); i ++)
    {
        for (int j = i + 1; j < nums.size(); j ++)
        {
            if (nums[i] + nums[j] == target)
            {
                res.push_back(i);
                res.push_back(j);
                goto outloop;
            }
        }
    }
    outloop:
    return res;
}
int main()
{
    vector<int>a(4);
    int value = 0;
    cout<<"insert value"<<endl;
    for (int i = 0; i < a.size(); i ++)
    {
        cin>>value;
        a[i] = value;
    }
    int target;
    cout<<"insert target"<<endl;
    cin>>target;
    vector<int> res = twoSum(a, target);
    cout<<"["<<res[0]<<","<<res[1]<<"]"<<endl;
    
    return 0;

}
