#include "three_sum.h"
#include <algorithm>

/*
计算 sum = nums[i]+nums[left]+nums[right]
sum==0 → 找到三元组 → 存入 result → 左右指针去重并移动
sum<0 → 左指针右移 → 取更大的数
sum>0 → 右指针左移 → 取更小的数
循环直到 left >= right
*/

std::vector<std::vector<int>> ThreeSum::findTriplets(std::vector<int>& nums) {
    // result:用来存储所有符合条件的三元组
    std::vector<std::vector<int>> result;
    //计算数组的大小
    int n = nums.size();
    //数组长度小于3就会return不再继续
    if (n < 3) return result;

    //对数组nums进行排序
    std::sort(nums.begin(), nums.end()); // 先排序，方便去重

    //这里n-2是为了确保有足够剩下的两个数组成三元组，避免数组越界
    for (int i = 0; i < n - 2; i++) {
        /*
        i > 0：保证只有 i ≥ 1 才会执行 nums[i-1]
        当 i=0 时：
        i > 0 为假
        整个条件短路 → nums[i-1] 根本不会被访问
        所以安全，没有越界!
        i=0不会访问nums[-1],从i=0开始是安全的，后续i>0才会检查重复
        */
        if (i > 0 && nums[i] == nums[i - 1]) continue; // 跳过重复的第一个数
        
        /*
          nums=【-4，-1，-1，0，1，2】
          nums【i】= -4；i也就是下标为0；left=i+1->nums[left]=-1,right=n-1=5->nums[right]=2    
        */
        int left = i + 1;
        int right = n - 1;

        // 当 左指针 left 小于右指针 right 时，继续找三元组; 如果 left >= right → 数组没位置可以组成三元组了 → 停
        while (left < right) {
            //计算当前三元组的和，三个数分别为：第一个数i，左指针left，右指针right
            int sum = nums[i] + nums[left] + nums[right];
            
            //如果三个数加起来等于0表示找到了有效三元组，并把它们存起来
            if (sum == 0) {
                //放置结果到vector里
                result.push_back({nums[i], nums[left], nums[right]});

                // 去重，就是为了判断left和left+1是否一样，一样的话移到下一个不同的数字
                while (left < right && nums[left] == nums[left + 1]) left++;
                while (left < right && nums[right] == nums[right - 1]) right--;

                left++;
                right--;
            } else if (sum < 0) {
                left++; //如果三个数加起来小于0->总和太小，因为数组是排序的->左指针往右走可以取到更大的数；
            } else { // sum > 0
                right--; //如果三个数加起来大于0->总和太大，因为数组是排序的->左指针往左走>    可以取到更小的数；
            }
        }
    }

    return result;
}

