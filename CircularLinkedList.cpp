#include<iostream>
using namespace std;

struct Node {
  int data;
  Node* next;
  Node(int val):data(val),next(nullptr){}
};

class CircularLinkedList{
private:
  Node* tail;//β�ڵ�,tail-next ָ��ͷ�ڵ�
public:
  CircularLinkedList():tail(nullptr){}

  //β������
  void insertBack(int val){
    Node* newNode = new Node(val);
    if(!tail){
      tail=newNode;
      tail->next=tail;
    }
    else{
      newNode->next=tail->next;
      tail->next=newNode;
      tail=newNode;
    }
  }
    //ͷ������
    void insertFront(int val){
      Node* newNode = new Node(val);
      if(!tail){
        tail=newNode;
        tail->next=tail;
      }
      else{
        newNode->next = tail->next;
        tail->next = newNode;
      }
    }
    //ɾ��ָ��ֵ
    void deleteValue(int val){
      if(!tail)return;
      Node* cur=tail->next;
      Node* prev=tail;
      do{
        if(cur->data==val){
          if(cur==tail&&cur->next==tail){
            delete cur;
            tail=nullptr;
            return;
          }
          prev->next=cur->next;
          if(cur==tail)tail=prev;
          delete cur;
          return;
        }
        prev=cur;
        cur=cur->next;
      }while(cur!=tail->next);
    }
    //���ҽڵ�
    Node* find(int val){
      if(!tail)return nullptr;
      Node* cur=tail->next;
      do{
        if(cur->data == val) return cur;
        cur=cur->next;
      }while(cur!=tail->next);
      return nullptr;
    }
    //��ӡ����
    void print(){
      if(!tail){
        cout<<"List is empty"<<endl;
        return;
      }
      Node* cur = tail->next;
      do{
        cout<<cur->data<<" ";
        cur=cur->next;
      }while(cur!=tail->next);
      cout<<endl;
    }

  //��תѭ������
  void reverse(){
    if(!tail || tail->next == tail) return;

  }
  
  ~CircularLinkedList(){
    if(!tail)return;
    Node* cur=tail->next;
    Node* nextNode;
    do{
      nextNode = cur->next;
      delete cur;
      cur=nextNode;
    }while(cur!=tail->next);
    tail=nullptr;
  }
};


int main(){
  CircularLinkedList clist;
  clist.insertBack(1);
  clist.insertBack(2);
  clist.insertFront(0);
  clist.print();// ���:0 1 2

  clist.deleteValue(1);
  clist.print(); // ���:0 2

  if(clist.find(2))cout<<"Found 2"<<endl;
  else cout<<"Not Found 2 "<<endl;

  return 0;
}
