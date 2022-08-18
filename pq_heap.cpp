//Priority queue heap
#include <iostream>
#include <utility>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(){}
    Node(int data){
        this->data = data;
    }
};

class Pq{
    public:
    Node *start;

    void enqueue(int data){
        Node *tmp = new Node(data);
        if(start == NULL){
            start = tmp;
            tmp->next = NULL;
            return;
        }
        Node *p = new Node;
        p = start;
        if(p->data > tmp->data){
            tmp->next = p;
            start = tmp;
            return;
        }
        while(p->next != NULL && p->data <= tmp->data){
            p = p->next;
        }
        tmp->next = p->next;
        p->next = tmp;
        if(p->data > tmp->data)
            swap(p->data, tmp->data);
    }

    void dequeue(){
        if(start == NULL)
            return;
        Node *p = new Node;
        p = start;
        start = p->next;
        p->next = NULL;
    }

    void display(){
        Node *p = new Node;
        p = start;
        while(p != NULL){
            cout << "-> " << p->data;
            p = p->next;
        }
        cout << "\n";
    }
};

int main(){
    Pq *pq = new Pq;
    pq->start = NULL;
    pq->enqueue(80);
    pq->display();
    pq->enqueue(30);
    pq->display();
    pq->enqueue(50);
    pq->display();
    pq->enqueue(10);
    pq->display();
    pq->enqueue(40);
    pq->display();
    pq->dequeue();
    pq->dequeue();
    pq->display();
    pq->enqueue(20);
    pq->display();
    return 0;
}