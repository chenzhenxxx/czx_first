class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
       unordered_map<char,int> umap;
       for(auto &i :magazine){
           umap[i]++;
       }
       for(auto &j:ransomNote){
           if(umap.find(j)==umap.end()||umap[j]==0) return false;
           else umap[j]--;

       }
       return true;
    }
};