/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        queue<Node*> qu;
        int depth=0;
        if(root)qu.push(root);
        while(!qu.empty())
        {   int size = qu.size();
        depth++;
        for(int j=0;j<size;j++)
        {
            Node *tmp = qu.front();
            qu.pop();
            for(int i=0;i<tmp->children.size();i++)
            {
                if(tmp->children[i]) qu.push(tmp->children[i]);
            }
        }
        }
         return depth;
    }
};