#include<iostream>

using namespace std;

template<typename E>
struct node
{
 E data;
 node<E>* next;
};
template<typename E>
struct node2
{
    E data;
    node2<E>* next;
    node2<E>* pre;
};
template<typename E>
node<E>* getNode(E key)
{
    node<E>* temp=new node<E>;
    temp->data=key;
    temp->next=NULL;
    return temp;
}
template<typename E>
node2<E>* getNode2(E key)
{
    node2<E>* temp=new node2<E>;
    temp->data=key;
    temp->next=NULL;
    temp->pre=NULL;
    return temp;
}
template <typename E>
class linked_list
{
  node<E>* head;
  node<E>* last_node;
  int size;
  public:
      linked_list()
      {
          head=NULL;
          last_node=NULL;
          size=0;
      }
      void append(E key)
      {
          if(head==NULL)
          { size++;
            head=getNode(key);
            last_node=head;
          }else{
          node<E>* temp=last_node;
          last_node->next=getNode(key);
          size++;
          last_node=temp->next;
          }
      }
      E getValue(node<E>* temp)
      {
          return temp->data;
      }
      node<E>* getFirstele()
      {
          return head;
      }
      void setFirstele(node<E>* temp)
      {
          head=temp;
      }
      node<E>* lastnode()
      {
          return last_node;
      }

    void print()
    {
        node<E>* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int total_ele()
    {return size;}
};
template <typename E>
void reverse_list(linked_list<E> &a)
{
    node<E>* temp=a.getFirstele();
    node<E>* pre=NULL;
    node<E>* next=NULL;
    while(temp!=NULL)
    {
        next=temp->next;
        temp->next=pre;
        pre=temp;
        temp=next;
    }
    a.setFirstele(pre);
}
template <typename E>

   void reverse_recursion(linked_list<E> &a,node<E>* temp)
   {

       if(temp->next==NULL)
       {
           a.setFirstele(temp);
           return;
       }
        reverse_recursion(a,temp->next);
        temp->next->next=temp;
        temp->next=NULL;
   }
   template<typename E>
   void swap_node(linked_list<E> &a,E x,E y)
   {
       node<E>* temp1=a.getFirstele();
       node<E>* temp2=NULL;
       node<E>* temp3=a.getFirstele();
       node<E>* temp4=NULL;
       node<E>* t;

       while(temp1->data!=x && temp1!=NULL)
       {
           temp2=temp1;
           temp1=temp1->next;
       }
       while(temp3->data!=y && temp3!=NULL)
       {
           temp4=temp3;
           temp3=temp3->next;
       }
       if(temp1==NULL || temp3==NULL)
        cout<<"Swap Operation is not possible\n";

       if(temp2==NULL)  //if x is head
        a.setFirstele(temp3);
        else
        temp2->next=temp3;

        if(temp4==NULL) //if y is head
        a.setFirstele(temp1);
        else
        temp4->next=temp1;

        t=temp3->next;
        temp3->next=temp1->next;
        temp1->next=t;

   }
   template <typename E>
   E Get_midnode(linked_list<E>& a)
   {
       node<E>* temp1=a.getFirstele();
       node<E>* temp2=a.getFirstele();
       while(temp1!=NULL && temp1->next!=NULL)
       {
           temp1=temp1->next->next;
           temp2=temp2->next;
       }
       return temp2->data;
   }
   template <typename E>
    void Find_loop(linked_list<E>& a)
   {
       node<E>* temp1=a.getFirstele();
       node<E>* temp2=a.getFirstele();
       while(1)
       {
           temp1=temp1->next->next;
           temp2=temp2->next;
           if(temp1!=NULL && temp1->next!=NULL && temp2!=NULL){
           if(temp1==temp2)
           {
               cout<<"Loop is found\n";
               break;
           }
           }
           else {cout<<"There is no loop in list\n";break;}
       }
   }

template <typename E>
class doubly_linkedList
{
    node2<E>* head;
  node2<E>* lastNode;
  int size;
  public:
      doubly_linkedList()
      {
          head=NULL;
          lastNode=NULL;
          size=0;
      }

      void append(E key)
      {
          if(head==NULL)
          { size++;
            head=getNode2(key);
            lastNode=head;
          }else{
          node2<E>* temp=lastNode;
          lastNode->next=getNode2(key);
          size++;
          lastNode=temp->next;
          lastNode->pre=temp;
          }
      }
       E getValue(node2<E>* temp)
      {
          return temp->data;
      }
      node2<E>* getFirstele()
      {
          return head;
      }
      void setFirstele(node2<E>* temp)
      {
          head=temp;
      }

      void insert_node2(E data)
      {
          E key;node2<E>* temp=getNode2(data);node2<E>* curr=head;
          cout<<"Enter the key value after do you want to add node\n";
          cin>>key;
          while(curr->data!=key && curr!=NULL)
            curr=curr->next;
            if(curr==NULL)
                {cout<<"key data is not found\n"; return;}
                size++;
            temp->next=curr->next;
            if(curr->next!=NULL)
            curr->next->pre=temp;
            temp->pre=curr;
            if(curr->next==NULL)
            {curr->next=temp;
            lastNode=temp;}
            else curr->next=temp;
      }
      E remove_node2(E key)
      {
          node2<E>* curr=head;

          while(curr->data!=key && curr->next!=NULL){
                cout<<"d:  "<<curr->data;
            curr=curr->next;}
          if(curr==NULL)
            {cout<<"key node is not found in list\n"; return -1;}
           if(curr==head)
               head=curr->next;
               if(curr->next!=NULL)
             {cout<<"d1: "<<curr->next->pre->data;
                 curr->next->pre=curr->pre;}

           if(curr->pre!=NULL)
            {
            cout<<"d2: "<<curr->pre->next->data;
            curr->pre->next=curr->next;}


             E temp=curr->data;
             size--;
          // delete curr;
           return temp;
      }
      void print_2()
    {
        node2<E>* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }
    }
    int total_ele()
    {return size;}

};



int main()
{
    linked_list<int> a;
    int b[]={2,3,4,7},n=4,i=0;
    a.append(1);
    a.append(2);
    a.append(3);
     a.append(4);
     a.lastnode()->next=a.getFirstele()->next;
    a.append(2);
    a.append(6);
  a.print();
    //cout<<"\n size: "<<a.total_ele()<<a.getValue(a.getFirstele());
    //reverse_list(a);
   // reverse_recursion(a,a.getFirstele());
    //for(i=0;i<n/2;i++)
   //swap_node(a,b[i],b[n-i-1]);
   //cout<<"MidNode: "<<Get_midnode(a);
   // cout<<"\n";
    Find_loop(a);
    // a.print();

  /*   doubly_linkedList<int> A;
     A.append(8);
     A.append(2);
     A.append(3);
     A.append(1);
     A.append(8);
     A.print_2();
     //A.insert_node2(22);
     //A.print_2();
    // A.insert_node2(0);
     //print_2();
    int t= A.remove_node2(8);
     t=A.remove_node2(8);
      t=A.remove_node2(2);
      cout<<endl;
     A.print_2();
     cout<<"\nSize: \n"<<A.getValue(A.getFirstele()); */
}
