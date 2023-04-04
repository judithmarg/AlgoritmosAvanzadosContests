#include<bits/stdc++.h>
using namespace std;
// extraido de GeeksForGeeks

struct SegmentTreeNode {
    int start, end, sum;
    SegmentTreeNode *left;
    SegmentTreeNode *right;

    SegmentTreeNode(int start, int end){
        this->start = start;
        this->end = end;
        this->sum = 0;
        this->left = nullptr;
        this->right = nullptr;
    }

    void update(int index, int value){ 
        if(start == end){
            sum = value;
            return;
        }
        int mid = (start+end) /2;
        if(index <= mid ){
            if(left == nullptr){
                left = new SegmentTreeNode(start,mid);
            }
            left->update(index,value);
        }else{
            if(right == nullptr){
                right = new SegmentTreeNode(mid+1,end);
            }
            right->update(index,value);
        }
        sum = (left != nullptr? left->sum : 0) + (right != nullptr? right->sum:0);
    }

    int query(int qs,int qe){
        if(qs <= start && qe >= end){
            return sum;
        }else if(qs > end|| qe < start){
            return 0;
        }else{
            int leftsum = (left!=nullptr? left->query(qs,qe):0);
            int rightsum = (right!=nullptr? right->query(qs,qe):0);
            return leftsum+rightsum;
        }
    }

};

class SegmentTree{
    private:
        SegmentTreeNode *root;
    public:
        SegmentTree(int n){
            root = new SegmentTreeNode(0,n-1);
        }

        void update(int index, int value){
            root-> update(index, value);
        }

        int query(int start, int end){
            return root->query(start,end);
        }
};

int main(){
    vector<int> arr = {1,3,5,7,8,11};
    SegmentTree st(arr.size());
    st.update(1,2);
    cout << st.query(1,4) <<endl;
    return 0;
}