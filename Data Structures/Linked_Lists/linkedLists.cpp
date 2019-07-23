#include <iostream>

// Using linked lists
template <typename T>
class Node
{
public:
  Node (T value) // copy constructor of the node
  : data_ (value), nextNode_(NULL) // initializing Node objects
  {}
    void setData(T Data_value) { data_ = Data_value; }
    T getData() const { return data_; } // getter method for data_

    Node<T>* getNext() const { return nextNode_; }
    void setNext(Node<T>* node) { nextNode_ = node; }

// variable definition
private:
  T data_;
  Node<T> * nextNode_;
};

template <typename T>
std::ostream & operator<< (std::ostream & ostream, const Node<T>& node)
{
  ostream << "\n<Node address: " << &node << " data: " << node.getData() << ">\n";
  return ostream;
}

template <typename T>
class LinkedList
{
public:
  LinkedList () // default constructor
  : phead_ (NULL), tail_(NULL) // default pointers to NULL
  {}
    void AddList(T key)
    {
      Node<T> *listPtr = new Node<T>(key);
      if (phead_ == NULL && tail_ == NULL) // if the list is empty
      {
        phead_ = tail_ = listPtr;
        phead_->setData(key);
      }
      else // do this when the list is not empty
      {
        Node<T>* ptr = phead_;
        while (ptr->getNext() != NULL)
        {
          ptr = ptr->getNext();
        }
        if (ptr->getNext() == NULL)
        {
          ptr->setNext(listPtr);
        }
      }
    }

    //===== Return the biggest Node ====//
    Node<T>* getBiggest(Node<T>* stopNode)
    {
      Node<T> *ptr = phead_, *swapPtr = NULL;
      T largest = phead_->getData(); // largest is head node
      while(ptr->getNext() != stopNode)
      {
        if (ptr->getData() > largest)
        {
          largest = ptr->getData();
          swapPtr = ptr;
        }

        ptr = ptr->getNext(); // getting the last node of the list
      }
      // doing a test for the node right before the last one
      if (ptr->getData() > largest)
      {
        largest = ptr->getData();
        swapPtr = ptr;
      }
      // performing swaps
      if (largest > stopNode->getData())
      { // if the last node is not the largest
        T tempVar = stopNode->getData();
        stopNode->setData(largest);
        swapPtr->setData(tempVar);
      }

      return ptr; // this pointer contains the node right before lastNode
    }

    void sortLink()
    {
      Node<T> *ptr = phead_, *lastNode = NULL;
      bool sorted = false;
      while(ptr->getNext() != NULL)
        ptr = ptr->getNext(); // getting the last node of the list

        //std::cout << "last: " << ptr->getData() << '\n';
      lastNode = ptr;
      while (!sorted)
      {
        if (lastNode != phead_)
        {
          Node<T>* trs = NULL;
          trs = getBiggest(lastNode);
          lastNode = trs;
        }

        else
          sorted = true;
      }
    }

    // Inserting a node at the biginning of the list
    void inserHead(Node<T> &node) // method gets the address of a node
    {
      if (phead_ == NULL) // Tests if the list is empty
        phead_ = &node;

      else // if list is not empty
      {
        Node<T> *ptr = phead_; // copy head pointer
        phead_ = &node; // let head pointer point to the new node
        node.setNext(ptr); // make the new node point to previous head node
      }
    }

    // Inserting a node at the biginning of the list
    void inserTail(Node<T> &node) // method gets the address of a node
    {
      if (phead_ == NULL) // Tests if the list is empty
        phead_ = &node;

      else // if list is not empty
      {
        Node<T> *ptr = phead_; // copy head pointer
        while (ptr->getNext() != NULL)
          ptr = ptr->getNext(); // get last node in the list

        ptr->setNext(&node); // let head pointer point to the new node
      }
    }

    // return last node from a starting and ending point
    Node<T>* LNode(Node<T>*start, Node<T>* stop) const
    {
      Node<T> *ptr = start; // copy head pointer
      while (ptr->getNext() != stop)
        ptr = ptr->getNext(); // get last node in the list

      return ptr;
    }

    void reverser(Node<T>* head, Node<T>* tail)
    {
      // Do the swap
      T temp = tail->getData();
      tail->setData(head->getData());
      head->setData(temp);

      head = head->getNext();
      tail = LNode(head, tail);

      if (head != tail)
        reverser(head, tail);
    }
    void reverseList()
    {
      Node<T> *ptr = phead_, *last = NULL;
      while (ptr->getNext() != last)
        ptr = ptr->getNext();

      last = ptr;
      ptr = phead_;
      reverser(ptr, last);
    }

    void reversedList()
    {
      Node<T> *ptr = NULL, *temp = NULL, *start = phead_;
      if (phead_ != NULL) // if the list is not empty
      {
        if (phead_->getNext() != NULL)// if the list contains at least two nodes
        {
          ptr = phead_->getNext(); // ptr takes the next node's address
          do
          {
            if (ptr->getNext() != NULL) // is there a third node
              temp = ptr->getNext(); // temp takes third node's address

            if (start == phead_)
            {
              phead_->setNext(NULL);
              ptr->setNext(phead_);
            }
            else
              ptr->setNext(phead_);

            phead_ = ptr;
            ptr = temp;
            temp = temp->getNext();

            if (temp->getNext() == NULL)
            {
              ptr->setNext(phead_);
              temp->setNext(ptr);
              phead_ = temp;
              break;
            }
          }while (temp->getNext() != NULL);
        }
        else
          std::cout << "impossible";
      }
    }

    //print the list in reverse order
    void revPrint(Node<T>* ptr = reversePrint)
    {
      // if list is not empty and it's the first run
      if (ptr == NULL && phead_ != NULL && set == false)
      {
        ptr = phead_;
        set = true;
        revPrint(ptr);
      }

      // if the pointer hasn't reached the end of the list
      else if (ptr != NULL)
      {
        revPrint(ptr->getNext());
        std::cout << ptr->getData() << ' ';
      }
      // when the pointer reaches the end of the list then exit recursion
      else if (ptr == NULL && set == true) return; // this line is optional
    }

    // reversing a list using recursion
    void RevList (Node<T>* ptr = reversePrint)
    {
      // if list is not empty and it's the first run
      if (ptr == NULL && phead_ != NULL && set == false)
      { // starting point
        ptr = phead_;
        set = true;
        revPrint(ptr);
      }

      // if the pointer hasn't reached the end of the list
      else if (ptr != NULL)
      {
        if (ptr->->getNext() == NULL)
        {
          phead_ = ptr; // set lastNode as head of the list
          return; // exit recursion
        }
        revPrint(ptr->getNext());
        Node<T>* p = ptr->getNext(); // save the address of the lastNode
        q->setNext(ptr); // make lastNode point to the one right before
        ptr->setNext(NULL); // set the current node pointer to NULL
        //std::cout << ptr->getData() << ' ';
      }
      // when the pointer reaches the end of the list then exit recursion
      else if (ptr == NULL && set == true) return; // this line is optional
    }

    Node<T>* getHead() const { return phead_; } // return head_
    Node<T>* getTail() const { return tail_; } // return tail_

private:
  Node<T> * phead_;
  Node<T> * tail_;
  bool set = false;
  static Node<T>* reversePrint;
};
template <typename T>
Node<T>* LinkedList<T>::reversePrint = NULL;


template <typename T>
std::ostream & operator<< (std::ostream & ostream, const LinkedList<T>& list)
{
  Node<T>* ptr = list.getHead();
  std::cout << '\n';
  while (ptr != NULL)
  {
    ostream << "<Node address: " << ptr << " data: " << ptr->getData() << ">\n";
    ptr = ptr->getNext();
  }

  return ostream;
}

int main(int argc, char const *argv[]) {
  /* code */
  std::cout << "*********** Use of Link Lists ************\n";
  Node <int> first(5);
  Node <int> second(7);
  //std::cout << first;
  LinkedList <int> third;
  third.AddList(8);
  third.AddList(38);
  third.AddList(12);
  third.AddList(73);
  third.AddList(98);
  third.AddList(54);
  third.AddList(17);
  std::cout << third;
  third.sortLink();
  std::cout << "\n============ Sorted list =============\n" << third;
  std::cout << "\nList printed in reverse order: ";
  third.revPrint();

  // LinkedList <char> fourth;
  // Node <char> fifth('A');
  // Node <char> six('B');
  // Node <char> sev('H');
  // Node <char> eight('J');

  LinkedList <float> fourth;
  Node <float> fifth(7.85);
  Node <float> six(45.12);
  Node <float> sev(3.25);
  Node <float> eight(4.1);
  Node <float> f(38.25);
  Node <float> g(84.1);

  fourth.inserHead(fifth);
  fourth.inserHead(six);
  fourth.inserTail(eight);
  fourth.inserTail(sev);
  fourth.inserTail(f);
  fourth.inserTail(g);
  std::cout << "\nInserting a Node: " << third;

  third.reversedList();
  std::cout << "\nReversed List: " << third;

  LinkedList <int> test;
  test.AddList(8);
  test.AddList(38);
  //test.AddList(12);
  std::cout << test;
  test.reversedList();
  std::cout << "\nReversed List: " << test;
  // fourth.reverseList();
  // std::cout << "Here: ";
  // std::cout << fourth;
  //
  // fourth.sortLink();
  // std::cout << "\n============ Sorted list =============\n";
  // std::cout << fourth;

  return 0;
}
