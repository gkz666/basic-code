#include <iostream>
#include <queue>
using namespace std;

// 定义节点结构
typedef struct node
{
    char data;     // 数据
    node* lchild;  // 左孩子指针
    node* rchild;  // 右孩子指针
} * BinTree;       // 二叉树指针类型别名

// 创建二叉树
void CreateBinaryTree(BinTree& T)
{
    char ch;
    cin >> ch;
    if (ch == '#')  // 如果输入是'#'，表示空节点
        {T = NULL;
        }
    else {
        T = new node;    // 创建新节点
        T->data = ch;    // 设置节点数据
        T->lchild = NULL;  // 初始化左孩子为NULL
        T->rchild = NULL;  // 初始化右孩子为NULL
        CreateBinaryTree(T->lchild);  // 递归创建左子树
        CreateBinaryTree(T->rchild);  // 递归创建右子树
    }
}
    int height(BinTree root) {
        if (root == NULL) {
            return 0;
        }
        int leftHeight = height(root->lchild);
        int rightHeight = height(root->rchild);
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1) {
            return -1;
        } else {
            return max(leftHeight, rightHeight) + 1;
        }
    }

    bool isBalanced(BinTree T) {
        return height(T) >= 0;
    }


int main() {
    BinTree root = NULL;
    CreateBinaryTree(root);  // 创建二叉树
    height(root);
    cout<<isBalanced(root);

    system("pause");
    return 0;
}
