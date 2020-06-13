class Node
{
    int elem;
    Node* next;
public:
    Node(int, Node*);
    int  getElem();
    void setElem(int);
    Node*getNext();
    void setNext(Node*);
};

class LinkedList
{
    int size;
    Node* head;
public:
    LinkedList();
    ~LinkedList();
    void insert(int);
    void remove(int);
    void print();
};
