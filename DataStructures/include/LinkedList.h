#ifndef LLIST_H
#define LLIST_H
#include<iostream> 

template<typename T>
struct node{
T data;
node<T>* link;
};

template<typename T>
class LList{
    node<T>* head;
    node<T>* end;
public:
    LList()
    {
	head = new node<T>;
	head->link = NULL;
	end = &(*head);

    };
    LList(const T& ob)
    {
	head = new node<T>;
	node<T>* next = new node<T>;
	head->link = next;
	head->data = ob;
	std::cout <<  head->data << std::endl;
	next->link = NULL;
	end = &(*next);
    };
    //LList(LList);
    LList operator=(const LList&);
    void add(const T& ob)
    {
      end->data=ob;
      node<T>* next = new node<T>;
      next->link=NULL;
      end->link = next;
      end = &(*next); 
    };
    void printList()
    {
	   int i =0;
	   node<T>* iter = head;
	   while(!(iter==NULL)) 
	   {
	       std::cout << "Element " << i << " is "  << iter->data << std::endl;
	       iter=iter->link;
	       i++;
	   }
    };
	   
    ~LList()
    {
	   node<T>* iter = head;
	   node<T>* tmp;
	   while(iter) 
	   {
	       tmp=iter->link;
	       delete iter;
	       iter = tmp;
	   }

    };
};
#endif
