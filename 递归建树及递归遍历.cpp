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

// 先序遍历打印二叉树
void FiPrintfTree(BinTree T)

{
    if (T != NULL) {
        cout << T->data;          // 输出当前节点的数据
        FiPrintfTree(T->lchild);  // 先序遍历左子树
        FiPrintfTree(T->rchild);  // 先序遍历右子树
    }
    else
        return;
}
// 中序遍历打印二叉树
void SePrintfTree(BinTree T){
   if (T != NULL) {
        SePrintfTree(T->lchild);  // 先序遍历左子树
        cout << T->data;          // 输出当前节点的数据
        SePrintfTree(T->rchild);  // 先序遍历右子树
    }
    else
        return;
}
// 后序遍历打印二叉树
void ThPrintfTree(BinTree T){
    if (T != NULL) {    
        ThPrintfTree(T->lchild);  // 先序遍历左子树
        ThPrintfTree(T->rchild);  // 先序遍历右子树
        cout << T->data;          // 输出当前节点的数据
    
    }
    else
        return;
}
void FloorPrint_QUEUE(BinTree T) //层序遍历_队列实现
{
    queue <BinTree> q;
    if (T != NULL)
    {
        q.push(T);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->data ; 

        if (q.front()->lchild != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->lchild);   
        }

        if (q.front()->rchild != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rchild);
        }
        q.pop();  //已经遍历过的节点出队列
    }
}
int main() {
    BinTree root = NULL;
    CreateBinaryTree(root);  // 创建二叉树
    FiPrintfTree(root); 
    cout << '\n'; 
    SePrintfTree(root);
     cout << '\n';
    ThPrintfTree(root);
     cout << '\n';
    FloorPrint_QUEUE(root);
    system("pause");
    return 0;
}
