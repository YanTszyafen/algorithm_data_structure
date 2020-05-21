#include <iostream>
#include <fstream>

using namespace std;

struct BST{
    int key;
    int left;
    int right;
};

bool check(BST *tree, int const &j, int const &k, int const &c){
    switch(k){
        case 0:
            if(tree[j].key > c) return false;
            break;
        case 1:
            if(tree[j].key < c) return false;
            break;
        default:break;
    }
    if(tree[j].left != 0 && !check(tree, tree[j].left, k, c)) return false;
    if(tree[j].right !=0 && !check(tree, tree[j].right, k, c)) return false;
    return true;
}


bool isBST(BST *tree, int const &j){
    if(tree[j].left == 0 & tree[j].right == 0) return true;
    if(tree[j].left != 0 && tree[j].key < tree[tree[j].left].key) return false;
    if(tree[j].right != 0 && tree[j].key > tree[tree[j].right].key) return false;
    if(tree[j].left != 0 && !check(tree, tree[j].left, 0, tree[j].key)) return false;
    if(tree[j].right!= 0 && !check(tree, tree[j].right, 1, tree[j].key)) return false;
    if(tree[j].left != 0 && !isBST(tree, tree[j].left)) return false;
    if(tree[j].right != 0 && !isBST(tree, tree[j].right)) return false;
    return true;
}

int main() {
    ifstream if_in;
    if_in.open("input.txt");
    int n;
    if_in >> n;
    ofstream outfile;
    outfile.open("output.txt");
    if(n==0){
        outfile << "YES";
        outfile.close();
        return 0;
    }
    BST *tree;
    tree = new BST[n+1];
    for(int i=1; i<=n; i++){
        if_in >> tree[i].key >> tree[i].left >> tree[i].right;
    }
    if_in.close();
    if(isBST(tree, 1)) outfile << "YES";
    else outfile << "NO";
    outfile.close();
    return 0;
}