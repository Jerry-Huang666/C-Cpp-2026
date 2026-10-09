#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int value;
    struct Node *next;
}Node;

Node *createlist(int data) {
    Node *head=(Node*)malloc(sizeof(Node));
    head->value=data;
    head->next=NULL;
    return head;
}
void push(Node *head,int data) {
    Node *next=head->next;
    head->next=(Node*)malloc(sizeof(Node));
    head->next->value=data;
    head->next->next=next;
}
void pop_value(Node *head,int data) { //按值删除
    Node *pre=NULL;
    bool count=false;       //用一个变量来储存看是否找到了删除的位点
    if (head->value==data) {
        head=head->next;
    }
    else {
        for (Node *h=head;h!=NULL;h=h->next) {
            if (h->value==data) {
                pre->next=h->next;
                free(h);  //一定别忘记返还内存！！！
                count=true;
                break;
         }
            else pre=h;
    }
        if (count==false)printf("未找到对应数据");
    }
}
Node *reverse(Node *head) {          //对链表进行逆序操作
    Node *next=NULL;
    Node *pre=NULL;
    for (Node *h=head;h!=NULL;h=next) {
        next=h->next;
        h->next=pre;
        pre=h;
    }
    return pre;
}
int check(Node *head,int data,int n) {      //查找值为data的节点并将节点序号输出
    int count=1,num=0;                //num变量用于储存查找到的次数
    bool ch=false;                    //确认是否找到了对应值
    for (Node *h=head;h!=NULL;h=h->next) {
        if (h->value==data) {
            num++;
            if (num==n) {            //输入n,确认需要输出第几个data
                ch=true;
                break;
            }
        }
        count++;
    }
    if (ch) {
        return count;
    }
    else return -1;
}
int main(){
    Node *head=createlist(1);
    push(head,2);
    push(head,3);
    push(head,5);
    for (Node *h=head;h!=NULL;h=h->next) {
        printf("%d\n",h->value);
    }
    head=reverse(head);
    printf("%d\n",check(head,5,1));
    printf("%d\n",check(head,5,2));
    return 0;
}
