#ifndef __DOUBLENODE_H__
#define __DOUBLENODE_H__

template <class T>
class DoubleNode{
    private:
        T value;
        DoubleNode<T>* next;
        DoubleNode<T>* prev;
    public:
        DoubleNode(T value=0,DoubleNode *next=nullptr, DoubleNode<T> *prev=nullptr) : value(value),next(next),prev(prev){}
        T getValue() const{ return value;}
        void setValue(T value){ this->value = value;}
        DoubleNode<T>* getNext() const{ return next; }
        void setNext(DoubleNode<T>* next){ this->next = next;}
        DoubleNode<T>* getPrev() const{ return prev; }
        void setPrev(DoubleNode<T>* prev){ this->prev = prev;}
};
#endif