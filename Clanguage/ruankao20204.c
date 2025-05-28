#include<stdio.h>

typedef struct Node *NodePtr;

struct Node
{
    int key;
    NodePtr next;
    /* data */
};

// 根据数组a的前n个元素创建单循环链表
NodePtr craterList(int a[],int n){

    NodePtr tail=NULL,p;
    if(n<1) return NULL;
    p=(NodePtr)malloc(sizeof(struct Node));//创建第一个节点
    if(!p) return tail;
    p->key=a[0];
    p->next=p;
    tail=p;

    for(int i=1;i<n;i++){ //创建剩余的n-1个节点
    p=(NodePtr)malloc(sizeof(struct Node));
    if(!p)break;
    p->key=a[i];
    p->next=tail->next;
    tail->next=p;
    tail=p;
    }
    return tail;

}

void display(NodePtr tail){
// 从表头元素开始，依次输出单循环链表中节点数据域的值
    if(!tail) return;
    NodePtr p=tail->next;
    do{
        printf("%d ",p->key);
        p=p->next;
    }while(p!=tail->next);
}

int main(){
    int a[]={30,34,24,28};
    NodePtr tail;
    tail=craterList(a,4);
    display(tail);
    return 0;
}
