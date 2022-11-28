#include<stdio.h>
#include<stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
}*newnode,*list1,*list2,*temp1,*temp2,*temp;
struct ListNode* head=NULL;
struct ListNode* tail=NULL;

struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
     struct ListNode* list3;
    struct ListNode* head;
    if(list1== NULL && list2!=NULL)
        return list2;
    else if(list1 != NULL && list2 == NULL )
        return list1;
    else if(list1 == NULL && list2 == NULL)
        return NULL;
    if(list1->val < list2->val){
        list3= list1;
        list1 = list1->next;
        list3->next = NULL;
    }
    else{
        list3 = list2;
        list2 = list2->next;
        list3->next = NULL;
    }
    head = list3;
    while(list1 || list2){
        if(list1 == NULL && list2 != NULL){
            list3->next = list2;
            list2 = list2->next;
            list3= list3->next;
            list3->next = NULL;
            continue;
        }
        else if(list2 == NULL && list1 != NULL){
            list3->next = list1;
            list1 = list1->next;
            list3 = list3->next;
            list3->next = NULL;
            continue;
        }
        if(list1->val < list2->val){
            list3->next = list1;
            list1 = list1->next;
            list3 = list3->next;
            list3->next = NULL;
        }
        else{
            list3->next = list2;
            list2 = list2->next;
            list3 = list3->next;
            list3->next = NULL;
        }
    }
   
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if(listsSize==0)  return NULL;
    for(int i=1;i<listsSize;i++){
        lists[0]=mergeTwoLists(lists[0],lists[i]);
    }
    return lists[0];
}
struct ListNode *create(struct ListNode *head)
{
    char ch;
    int value;
    printf("1-Continue or 0-Exit");
    fflush(stdin);
    scanf("%c",&ch);
    while(ch=='c')
    {
        newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
        printf("Enter value\n");
        scanf("%d",&value);
        newnode->val=value;
        newnode->next=NULL;
        if(head==NULL)
        {
            head=newnode;
            tail=newnode;
        }
        else
        {
            tail->next=newnode;
            tail=newnode;
        }
        printf("1-Continue or 0-Exit");
        fflush(stdin);
        scanf("%c",&ch);
    }
    return head;
}
void display(struct ListNode* head)
{
    temp=head;
    while(temp!=NULL)
    {
        printf("%d->",temp->val);
        temp=temp->next;
    }
}
int main()
{
    int n;
    printf("Enter number of lists: ");
    scanf("%d",&n);
    struct ListNode* l[3]={NULL};
    for(int i=0;i<n;i++)
    {
        struct ListNode* h1=NULL;
        printf("\n Enter %d list \n",i+1);
        l[i]=create(h1);
        printf("Initial List: \n");
        display(l[i]);
    }
    struct ListNode* p = mergeKLists(l,n);
    printf("After Sorting: ");
    display(p);
    return 0;
}