#include <iostream>
#include <stack>
#include <queue>
// Using linked lists
template <typename T>
class Node
{
public:
  Node (T value) // default constructor of the node
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

// BST
template <typename T>
class BSTNode
{
public:
  BSTNode (T value) // constructor with parameters
  : data_ (value), left_(NULL), right_(NULL) // initializing Node objects
  {}
    /// setting up and retrieving data_
    void setData(T Data_value) { data_ = Data_value; }
    T getData() const { return data_; } // getter method for data_

    /// setting up and retrieving left_ and right_ pointers
    BSTNode<T>* getLeft() const { return left_; }
    void setLeft(BSTNode<T>* Lnode) { left_ = Lnode; }

    BSTNode<T>* getRight() const { return right_; }
    void setRight(BSTNode<T>* Rnode) { right_ = Rnode; }

  BSTNode () // default constructor without parameters
  : left_(NULL), right_(NULL) // initializing Node objects
  {}

// variable definition
private:
  T data_;
  BSTNode<T> * left_;
  BSTNode<T> * right_;
};

template <typename T>
class ListBST
{
public:
  ListBST () // default constructor without parameters
  {}
    /// setting up root pointer
    BSTNode<T>* getRoot() const { return root_; }
    void setRoot(BSTNode<T>* root) { root_ = root; }

    /// create a new BST element
    BSTNode<T>* createBST(T data)
    {
      BSTNode<T>* newBST = new BSTNode<T>(data);
      return newBST; // return newly created node
    }

    /// Inserting a BSTNode into a BST Tree
    BSTNode<T>* insertBST (T data, BSTNode<T>* var = root_)
    {
      // testing if the BST is empty
      if (root_ == NULL)
        setRoot(createBST(data)); // set root to newly created element

      if (var == NULL) /// create a new BST and attach it to correct leaf
        var = createBST(data);
      // if the BST is not empty
      else
      { /// if data is less than or equal to root_'s data
        if (data <= var->getData())
          var->setLeft(insertBST(data, var->getLeft()));

        else /// if data is greater than to root_'s data
          var->setRight(insertBST(data, var->getRight()));
      }
    return var;
    }

    /// search function
    T search(T value, BSTNode<T>* root = root_)
    {
      if (root == NULL)
          return 0;
      else
      {
        if (value == root->getData())
          return root->getData();

        else if (value < root->getData())
          return search(value, root->getLeft());

        else if (value > root->getData())
          return search(value, root->getRight());
      }
      return 0;
    }

    /// find min value in a BST
    T findMin(BSTNode<T>* root = root_) /// pass root_ pointer to the method
    {
      if (root == NULL) // exit when BST is empty
        return 0;

      else
      { /// get left most value of BST
        if (root->getLeft() != NULL) // Loop until last element of the BST
          return findMin(root->getLeft());

        else // return last left most BST element
          return root->getData();
      }
      return 0;
    }

    /// find max value in a BST
    T findMax(BSTNode<T>* root = root_) /// pass root_ pointer to the method
    {
      if (root == NULL) // exit when BST is empty
        return 0;

      else
      { /// get right most value of BST
        if (root->getRight() != NULL) // Loop until last element of the BST
          return findMax(root->getRight());

        else // return last right most BST element
          return root->getData();
      }
      return 0;
    }

    // getting height of a Tree
    int findHeight(BSTNode<T>* root = root_)
    {
      int Lheight = 0, Rheight = 0;
      if (root == NULL)
        return -1;

      else
      {
        Lheight += findHeight(root->getLeft());
        Rheight += findHeight(root->getRight());
      }

      if (Lheight > Rheight)
        return Lheight + 1;

      else
        return Rheight + 1;
    }

    ///// The three depth first tree traversals "pre, in, and post order"
    // Preorder BST traversal <root, left, right>
    void Preorder (BSTNode<T>* root = root_)
    {
      if (root == NULL)
        return;

      else
      {
        std::cout << root->getData() << ' ';
        Preorder(root->getLeft());
        Preorder(root->getRight());
      }
    }

    // Inorder BST traversal <root, left, right>
    void Inorder (BSTNode<T>* root = root_)
    {
      if (root == NULL)
        return;

      else
      {
        Inorder(root->getLeft());
        std::cout << root->getData() << ' ';
        Inorder(root->getRight());
      }
    }

    // Postorder BST traversal <root, left, right>
    void Postorder (BSTNode<T>* root = root_)
    {
      if (root == NULL)
        return;

      else
      {
        Postorder(root->getLeft());
        Postorder(root->getRight());
        std::cout << root->getData() << ' ';
      }
    }

    // breath first tree traversal (Level order traversal)
    // Level order traversal
    void level_order (BSTNode<T>* root = root_)
    {
      if (root == NULL) // if BST pointer is empty then exit
        return;

      else
      {
        std::queue<BSTNode<T>*> BSTQ;
        BSTQ.push(root);
        while (!BSTQ.empty())
        {
          // std::cout << BSTQ.front()->getData() << ' '; // could b here too
          if(BSTQ.front()->getLeft() != NULL)
            BSTQ.push(BSTQ.front()->getLeft());

          if(BSTQ.front()->getRight() != NULL)
            BSTQ.push(BSTQ.front()->getRight());

          std::cout << BSTQ.front()->getData() << ' ';
          BSTQ.pop();
        }
      }
    }

    // Verify that a Tree is a BST
    bool isBST (BSTNode<T>* root = root_, T min = INT_MIN, T max = INT_MAX)
    {
      return false;
    }

private:
  static BSTNode<T>* root_;
};
template <typename T>
BSTNode<T>* ListBST<T>:: root_ = NULL;

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
          std::cout << "List has only one element!\n";
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
        if (ptr->getNext() == NULL)
        {
          phead_ = ptr; // set lastNode as head of the list
          return; // exit recursion
        }
        revPrint(ptr->getNext());
        Node<T>* q = ptr->getNext(); // save the address of the lastNode
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

//////////////////////////////////////////////////////////////////////////////
/////////////// Using stacks for Pre and Post fix evaluation /////////////////
//////////////////////////////////////////////////////////////////////////////
// void evaluatePost(std::string strExpression, std::char [] operators)
// {
//   for (int i = 0; i < strExpression.length(); ++i)
//   {
//
//   }
// }

// void postFixNotation(std::string expression)
// {
//   std::string operatorsList = "-+*/";
//   std::stack<int> postFix;
//   std::stack<char> operators;
//   for (int i = 0; i < expression.length(); ++i)
//   {
//     for (int j = 0; j < operatorsList.length(); ++j)
//     {
//       if (expression[i] != operatorsList[j]) // if element is not an operator
//         postFix.push(expression[i]);
//
//       else
//       {
//         operators.push(expression[i]);
//         // if (!operators.empty()) // if the stack is not empty
//         // {
//         //   if ((operators.pop() == '-' || operators.pop() == '+') &&
//         //       (operators[i] == '*' || operators[i] == '/'))
//         //   {
//         //
//         //   }
//         // }
//       }
//     }
//   }
//   for (int i = 0; i < operators.size(); ++i)
//     std::cout << operators[i];
//
//   for (int i = 0; i < postFix.size(); ++i)
//     std::cout << postFix[i];
//}
int main(int argc, char const *argv[]) {
  /* code */

  /// BST usages
  ListBST<int> myBST;
  myBST.insertBST(15);   //               15
  myBST.insertBST(10);   //           10      20
  myBST.insertBST(20);   //         8   12  18   25
  myBST.insertBST(18);   //       5            22   35
  myBST.insertBST(25);   //                  21  23
  myBST.insertBST(8);    //
  myBST.insertBST(5);
  myBST.insertBST(22);
  myBST.insertBST(21);
  myBST.insertBST(23);
  myBST.insertBST(12);
  myBST.insertBST(35);
  std::cout<< "Search: " << myBST.search(12) << '\n';
  std::cout << "Min: " << myBST.findMin() << '\n';
  std::cout << "Max: " << myBST.findMax() << '\n';
  std::cout << "Height: " << myBST.findHeight() << '\n';
  std::cout << "Pre-Order: "; myBST.Preorder(); std::cout << '\n';
  std::cout << "In-Order: "; myBST.Inorder(); std::cout << '\n';
  std::cout << "Post-Order: "; myBST.Postorder(); std::cout << '\n';
  std::cout << "Level-Order: "; myBST.level_order(); std::cout << '\n';
  std::cout << "Is BST: "; if (myBST.isBST()) std::cout << "Yes!\n"; 
                            else std::cout << "Nope! \n";
  // std::string strExpression;
  // //char strExpression [20];
  // std::cout << "========== Prefix Notation ==========\n";
  // std::cout << "Enter your expression here: ";
  //
  // std::cin>> strExpression; // getting elements of the expression
  // std::cout << strExpression;
  // for (int i = 0; i < strExpression.length(); ++i)
  // {
  //   std::cout << strExpression[i] << ' ';
  // }
  // std::cout << std::endl;
  // std::cout << "*********** Use of Link Lists ************\n";
  // Node <int> first(5);
  // Node <int> second(7);
  // //std::cout << first;
  // LinkedList <int> third;
  // third.AddList(8);
  // third.AddList(38);
  // third.AddList(12);
  // third.AddList(73);
  // third.AddList(98);
  // third.AddList(54);
  // third.AddList(17);
  // std::cout << third;
  // third.sortLink();
  // std::cout << "\n============ Sorted list =============\n" << third;
  // std::cout << "\nList printed in reverse order: ";
  // third.revPrint();
  // third.RevList();
  // std::cout << "\nList reversed using recursion: " << third;
  //
  // // LinkedList <char> fourth;
  // // Node <char> fifth('A');
  // // Node <char> six('B');
  // // Node <char> sev('H');
  // // Node <char> eight('J');
  //
  // LinkedList <float> fourth;
  // Node <float> fifth(7.85);
  // Node <float> six(45.12);
  // Node <float> sev(3.25);
  // Node <float> eight(4.1);
  // Node <float> f(38.25);
  // Node <float> g(84.1);
  //
  // fourth.inserHead(fifth);
  // fourth.inserHead(six);
  // fourth.inserTail(eight);
  // fourth.inserTail(sev);
  // fourth.inserTail(f);
  // fourth.inserTail(g);
  // std::cout << "\nInserting a Node: " << fourth;
  //
  // fourth.RevList();
  // std::cout << "\nList reversed using recursion: " << fourth;

  return 0;
}
