//定义两个数组维护i的左边的最小值和右边的最大值
class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
       int n=nums.size();
       vector<int> minn(n);
       vector<int> maxx(n);
       minn[0]=nums[0];
       for(int i=1;i<n;i++)
       {
          minn[i]=min(minn[i-1],nums[i]);
       }
       maxx[n-1]=nums[n-1];
       for(int i=n-2;i>=0;i--)
       {
           maxx[i]=max(maxx[i+1],nums[i]);
       }
       for(int i=1;i<n-1;i++)
       {
           if(minn[i]<nums[i]&&nums[i]<maxx[i])
           {
               return true;
           }
       }
       return false;
    }
};



//超级牛逼的一个思路
//设置small 和mid,每次进行更新，贪心，自己可以推导一下，如果遍历过程中遇到小于 first\textit{first}first 的元素，
// 则会用该元素更新 first\textit{first}first，虽然更新后的 first\textit{first}first 出现在 second\textit{second}second 的后面，
//是在 second\textit{second}second 的前面一定存在一个元素 first’\textit{first'}first’ 小于 second\textit{second}second，因此
//当遇到 num>second\textit{num} > \textit{second}num>second 时，(first’,second,num)(\textit{first'}, \textit{second}, \textit{num})
//(first’,second,num) 即为递增的三元子序列。

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
    int len=nums.size();
    if(len<3) return false;
    int small=INT_MAX,mid=INT_MAX;
    for(auto &i:nums)
    {
        if(i<=small)small=i;
        else if(i<=mid)mid=i;
        else return true;
    }
    return false; 
    }
};