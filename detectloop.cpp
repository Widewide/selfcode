#include <bits/stdc++.h>
using namespace std;
struct node{
    int data;
    node* next;
    bool visited;
    node (int x){
        data=x;
        next=NULL;
        visited=false;
    }
};
node* insertend(node* head,int x){
    node* temp=new node(x);
    if(head==NULL)
    return temp;
    node* curr=head;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
    return head;
}
void printll(node* head){
    node* curr=head;
    if(head==NULL)
    return;
    while(curr!=NULL){
        cout<<curr->data<<endl;
        curr=curr->next;
    }
    return;
}
node *insertbegin(node *head,int x){
    node *temp=new node(x);
    temp->next=head;
    return temp;
}
void detect(node *head){
    int k=1;
    node* curri=head;
    while(curri!=NULL && k==1){
        if(curri->visited==false)
        curri->visited=true;
        else
        k=0;
        curri=curri->next;
    }
    if(k==1)
    cout<<"no";
    else
    cout<<"yes";
}
void detecttemp(node* head){
    int k=1;
    node* temp;
    node* curr=head;
    node* next=curr->next;
    while(curr!=NULL && k==1){
        next=curr->next;
        if(curr->next==temp)
        k=0;
        curr->next=temp;
        curr=next;
    }
    if(k==0){
        cout<<"yes";
    }
    else
    cout<<"no";
}
bool floydmethod(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            return true; 
        }
    }
    return false;
}
int lengthofloop(node* head){
    node* fast=head;
    node* slow=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break; 
        }
    }
    if(fast!=slow)
    return -1;
    node* temp=slow;
    int count=1;
    while(slow->next!=temp){
    count++;
    slow=slow->next;
    cout<<'*';
    }
    return count;
}  
void deleteloop(node *head){
    node* curri=head;
    node* start;
    node* end;
    while(curri!=NULL){
        end=curri;
        if(curri->visited==false)
        curri->visited=true;
        else{
        start=curri;
        break;
    }
        curri=curri->next;
    }
    node* k=head;
    while(k->next!=start){
        k=k->next;
    }
    k->next=NULL;
    end->next=NULL;
    node* temp=start;
    node* next;
    while(start!=NULL){
        next=start->next;
        temp=start;
        start=next;
        delete temp;
    }
}
void floydremovehead(node* head){
    node* slow=head;
    node* fast=head;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            break;
        }
    }
    if(slow!=fast){
        return;
    }
    slow=head;
    while(slow->next!=fast->next){
        slow=slow->next;
        fast=fast->next;
    }
    slow->next=NULL;
}
void removetemp(node* temp){
    node* next=temp->next;
    node* nextnext=temp->next->next;
    temp->data=next->data;
    temp->next=nextnext;
    delete next;
    return;
}
int main(){
    node* head=new node(10);
    node *temp1=new node(15);
    node *temp2=new node(12);
    node *temp3=new node(20);  
    head->next=temp1;
    temp1->next=temp2;
    temp2->next=temp3;
    temp3->next=NULL;
/*     detect(head); 
    detecttemp(head); */
/*     if(floydmethod(head)){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    } */
    // deleteloop(head);
/*     cout<<lengthofloop(head)<<endl;
    floydremovehead(head);
    printll(head); */
    removetemp(temp2);
    printll(head);
}