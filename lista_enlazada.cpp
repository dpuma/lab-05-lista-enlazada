#include "header.h"
#include <iostream>
using namespace std;

Node::Node(int elem, Node* next = nullptr) {
    this->elem = elem; this->next = next;
}
int Node::getElem() {
    return elem;
}
Node* Node::getNext() {
    return next;
}
void Node::setElem(int elem) {
    this->elem = elem;
}
void Node::setNext(Node* next) {
    this->next = next;
}

LinkedList::LinkedList() {
    size = 0;
    head = nullptr;
}
LinkedList::~LinkedList() {
    if (head != nullptr)
    {
        Node* tmp = head;
        while(tmp->getNext() != nullptr)
        {
            tmp = tmp->getNext();
            delete head;
            head = tmp;
        }
        delete head;
    }
}
void LinkedList::insert(int nuevoValor) {
    Node* test = head;
    Node* nuevoNodo = new Node(nuevoValor);

    if (test == nullptr)   // insertarndo en array vacio
        head = nuevoNodo;
    else if (nuevoValor < test->getElem()) { // existe array pero debe insertar en pos 0
        nuevoNodo->setNext(head);
        head = nuevoNodo;
    }
    else {    // existe array y no sabe donde insertar
        while (test->getNext() != nullptr && test->getNext()->getElem() < nuevoValor)
            test = test->getNext();
        if (test->getNext() != nullptr)
            nuevoNodo->setNext(test->getNext());
        test->setNext(nuevoNodo);
    }
    size++;
}
void LinkedList::remove(int elem) {
    Node* test = head;
    if (test == nullptr)  // comprueba que no esta vacio
        cout << "esta vacio" << endl;
    else if (test->getElem() == elem) {  // testea primer elemento
        head = test->getNext();
        delete test;
        size--;
    }
    else {
        Node* tmp;
        while(test->getNext() != nullptr) {   // se desplaza buscando elem, si llega a null quiere decir q no se encontró
            tmp = test;
            test = test->getNext();
            if (test->getElem() == elem) {
                tmp->setNext(test->getNext());
                delete test;
                size--;
                return;
            }
        }
        cout << "no se encontro" << endl;
    }
}
void LinkedList::print() {
    Node* test = head;
    if (test == nullptr) { return; }
    do {
        cout << test->getElem() << " ";
        test = test->getNext();
    } while (test != nullptr);
    cout << endl;
}

int main()
{
    LinkedList lista;
    lista.insert(12);
    lista.insert(1);
    lista.insert(100);
    lista.insert(-1);
    lista.insert(0);
    lista.print();      // -1 0 1 12 100
    lista.remove(-1);
    lista.print();      // 0 1 12 100
    lista.remove(13);   // no se encontro
    lista.print();      // 0 1 12 100
    lista.remove(100);
    lista.remove(1);
    lista.remove(0);
    lista.print();      // 12
    lista.remove(12);
    lista.print();      //
    lista.remove(1);    // esta vacio
    lista.print();      //

    return 0;
}
