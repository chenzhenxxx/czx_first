class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int preDiff = 0;
        int curDiff = 0;
        int result = 1;
        for(int i=0;i<nums.size()-1;i++){
            curDiff = nums[i+1]-nums[i];
            if(preDiff<=0&&curDiff>0||preDiff>=0&&curDiff<0){
                result++;
                preDiff = curDiff;
            }
        }
        return result;
    }
};