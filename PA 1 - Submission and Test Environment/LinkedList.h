#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Node.h"

template<class T>
class LinkedList {
public: // DO NOT CHANGE THIS PART.
    LinkedList();
    LinkedList(const LinkedList<T> &obj);

    ~LinkedList();

    int getSize() const;
    bool isEmpty() const;
    bool contains(Node<T> *node) const;

    Node<T> *getDummyHead() const;
    Node<T> *getDummyTail() const;
    Node<T> *getActualHead() const;
    Node<T> *getActualTail() const;
    Node<T> *getNode(const T &data) const;
    Node<T> *getNodeAtIndex(int index) const;

    void insertAtTheBeginning(const T &data);
    void insertAtTheEnd(const T &data);
    void insertBeforeGivenNode(const T &data, Node<T> *node);

    void deleteNode(Node<T> *node);
    void deleteNode(const T &data);
    void deleteAllNodes();

    void swapNodes(Node<T> *node1, Node<T> *node2);

    void traverse() const;

    LinkedList<T> &operator=(const LinkedList<T> &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.

private: // DO NOT CHANGE THIS PART.
    Node<T> *dummyHead;
    Node<T> *dummyTail;
};

template<class T>
LinkedList<T>::LinkedList() {
    /* TODO */
    dummyHead = new Node<T>();
    dummyTail = new Node<T>();
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    
}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T> &obj) {
    /* TODO */
    dummyHead = new Node<T>();
    dummyTail = new Node<T>();
    dummyHead->next = dummyTail;
    dummyTail->prev = dummyHead;
    Node<T> *current = obj.dummyHead->next;
    while (current!=obj.dummyTail){
            insertAtTheEnd(current->data);
            current = current->next;
        }
}

template<class T>
LinkedList<T>::~LinkedList() {
    /* TODO */
    deleteAllNodes();
    delete dummyHead;
    delete dummyTail;
}

template<class T>
int LinkedList<T>::getSize() const {
    /* TODO */
    int a=0;
    
    if (this->isEmpty()) {
            
            return 0;
        }
    else{
        Node<T> *node = this->getActualHead();

        while (node && node->next) {
            a++;
            node = node->next;
        }
    return a;
    }
    
}

template<class T>
bool LinkedList<T>::isEmpty() const {
    /* TODO */
    return dummyHead->next == dummyTail;

}

template<class T>
bool LinkedList<T>::contains(Node<T> *node) const {
    /* TODO */
    Node<T> *current = dummyHead->next;
    if(node==dummyTail || node==dummyHead) return 0;
    while(current!=dummyTail){
         
         if(node->data==current->data){
             return 1;
         }
         current = current->next;
         
     }
     return 0;
}

template<class T>
Node<T> *LinkedList<T>::getDummyHead() const {
    /* TODO */
    return dummyHead;
}

template<class T>
Node<T> *LinkedList<T>::getDummyTail() const {
    /* TODO */
    return dummyTail;
}

template<class T>
Node<T> *LinkedList<T>::getActualHead() const {
    /* TODO */
    if( isEmpty()){
        return NULL;
    }
    else{
        return dummyHead->next;
    }
}

template<class T>
Node<T> *LinkedList<T>::getActualTail() const {
    /* TODO */
    if( isEmpty()){
        return NULL;
    }
    else{
        return dummyTail->prev;
    }
}

template<class T>
Node<T> *LinkedList<T>::getNode(const T &data) const {
    /* TODO */
    Node<T> *current = dummyHead->next;
    while(current!=dummyTail){
         
         if(data==current->data){
             return current;
         }
         current = current->next;
         
     }
     return NULL;
}

template<class T>
Node<T> *LinkedList<T>::getNodeAtIndex(int index) const {
    /* TODO */
    int i=0;
    Node<T> *current = dummyHead->next;
    int a=getSize();
    if(index>(a-1)) return NULL;
    while(current!=dummyTail){
         
         if(i==index){
             return current;
         }
         current = current->next;
         i++;
     }
      return NULL;
}

template<class T>
void LinkedList<T>::insertAtTheBeginning(const T &data) {
    /* TODO */
    if (isEmpty()){
        Node<T> *newNode = new Node<T>(data,dummyHead,dummyTail);
        dummyHead->next = newNode;
        dummyTail->prev = newNode;
        }
    else{
        Node<T> *first = dummyHead->next;
        Node<T> *newNode= new Node<T>(data,dummyHead,first);
        dummyHead->next = newNode;
        first->prev = newNode;
    }
}

template<class T>
void LinkedList<T>::insertAtTheEnd(const T &data) {
    /* TODO */
    if (isEmpty()){
        Node<T> *newNode = new Node<T>(data,dummyHead,dummyTail);
        dummyHead->next = newNode;
        dummyTail->prev = newNode;
        }
    else{
        Node<T> *last = dummyTail->prev;
        Node<T> *newNode= new Node<T>(data,last,dummyTail);
        last->next = newNode;
        dummyTail->prev = newNode;
    }
}

template<class T>
void LinkedList<T>::insertBeforeGivenNode(const T &data, Node<T> *node) {
    /* TODO */
        if(!contains(node)) return;
        
        Node<T> *prevnode = node->prev;
        Node<T> *newNode= new Node<T>(data,prevnode,node);
        prevnode->next = newNode;
        node->prev = newNode;
}

template<class T>
void LinkedList<T>::deleteNode(Node<T> *node) {
    /* TODO */
    if(!contains(node)) return;
    if(node==dummyTail || node==dummyHead) return;
    node->next->prev = node->prev;
    node->prev->next = node->next;
    delete node;
          
}

template<class T>
void LinkedList<T>::deleteNode(const T &data) {
    /* TODO */
    
     Node<T>*find =  getNode(data);
     if(find==NULL) return;
     deleteNode(find);
           
     
}

template<class T>
void LinkedList<T>::deleteAllNodes() {
    /* TODO */
     while (dummyTail->prev!=dummyHead){
            Node<T> *remove = dummyTail->prev;
            remove->next->prev = remove->prev;
            remove->prev->next=dummyTail;
            delete remove;
        }
}

template<class T>
void LinkedList<T>::swapNodes(Node<T> *node1, Node<T> *node2) {
    /* TODO */
   if(node1==node2) return;
   if(node1==NULL || node2==NULL) return;
   if(node1==dummyTail || node1==dummyHead) return;
   if(node2==dummyTail || node2==dummyHead) return;
   if(contains(node1)&&contains(node2)){
        Node<T>*next1 = node1->next;
        Node<T>*prev1 = node1->prev;
        Node<T>*next2 = node2->next;
        Node<T>*prev2 = node2->prev;

        if(node1->next == node2){
            node1->next = next2;
            node1->prev = node2;
            node2->next = node1;
            node2->prev = prev1;
            prev1->next = node2;
            next2->prev = node1;
        }
    
        else if(node1->prev == node2){
            node1->prev = prev2;
            node1->next = node2;
            node2->prev = node1;
            node2->next = next1;
            next1->prev = node2;
            prev2->next = node1;
        }
          
        else{
            node1->next = next2;
            node1->prev = prev2;
            node2->next = next1;
            node2->prev = prev1;
            next1->prev = node2;
            prev1->next = node2;
            next2->prev = node1;
            prev2->next = node1;
        }
   }

   
}

template<class T>
void LinkedList<T>::traverse() const {
    /* ALREADY IMPLEMENTED. DO NOT CHANGE. */

    if (this->isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T> *node = this->getActualHead();

    while (node && node->next) {
        std::cout << *node << std::endl;
        node = node->next;
    }
}

template<class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &rhs) {
    /* TODO */
    if (&rhs != this){
    deleteAllNodes();
    Node<T> *current = rhs.dummyHead->next;
    while (current!=rhs.dummyTail){
            
            insertAtTheEnd(current->data);
            current = current->next;
        }
    }
    return *this;
}

#endif //LINKEDLIST_H
