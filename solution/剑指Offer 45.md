---
title: 剑指 Offer 45. 把数组排成最小的数
date: 2020-12-18 21:06:00
tags:
- Leetcode
categories:
- Leetcode
- 剑指 Offer 专题
notshow: true
---

## 剑指 Offer 45. 把数组排成最小的数

## 题目描述

<a class="btn" href="https://leetcode-cn.com/problems/ba-shu-zu-pai-cheng-zui-xiao-de-shu-lcof/" title="leetcode链接">剑指 Offer 45. 把数组排成最小的数</a>

**难度:**<font color=orange>中等</font>

**描述**

输入一个非负整数数组，把数组里所有数字拼接起来排成一个数，打印能拼接出的所有数字中最小的一个。

<!--more-->

**示例**

```cpp
输入: [10,2]
输出: "102"
    
输入: [3,30,34,5,9]
输出: "3033459"

限制:
0 < nums.length <= 100
输出结果可能非常大，所以你需要返回一个字符串而不是整数
拼接起来的数字可能会有前导 0，最后结果不需要去掉前导 0
```



### 解法

思路是, 因为每一个数字内的相对关系是不能改变的, 因此不能把数字拆分成各个数位做排序. 因此, 可以寻找数字排列先后的规律, 比如, `10` 和 `2` 两个数字可以组成 `102` 和 `210` , 但是 `102 < 210` 因此, `10` 在前. 这就是一种排序规则. 可以写一个 lambda 表达式指导 `sort()` 按照刚刚模拟的方式来排序所有数字. 最后拼接到目标串中.

```cpp
class Solution {
public:
    string minNumber(vector<int>& nums) {
        vector<string> strs;
        string res;
        for(auto n : nums)
            strs.push_back(to_string(n));
        sort(strs.begin(),strs.end(),[](const string & a, const string & b)->bool{
            return a+b < b+a; // 102 < 210
        });
        for(auto str : strs)
            res += str;
        return res;
    }
};
```
