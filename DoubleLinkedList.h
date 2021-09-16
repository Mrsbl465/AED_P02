#ifndef __DOUBLELINKEDLIST_H__
#define __DOUBLELINKEDLIST_H__

#include "DoubleNode.h"
#include <iostream>

using namespace std;

template <class T>
class DoubleLinkedList{
    private:
        DoubleNode<T>* head; // Nodo a la cabeza
        // 9. Añadir un miembro dato/variable a la lista denominado pActual (puntero a nodo) 
        DoubleNode<T>* pActual; 
        int size; // Tamaño de la lista
        void init( ); // Inicializar
    public:
        // Constructor
        DoubleLinkedList( ) { init( ); }
        // Destructor
        ~DoubleLinkedList( );

        // Numero de elementos de la lista
        int getSize( ) const { return size; }
        // Revisa si la lista esta vacia 
        bool empty( ) const { return getSize( ) == 0; }
        // Limpia List
        void clear( );
        // Retorna nodo que apunta a la cabeza
        DoubleNode<T>* getHead(){ return head; }

        // Inserta nodo al final de la lista
        void push_back(T value);
        // Inserta valor en indice
        void insert(T value,int index);
        // Buscar por valor
        bool look_for(T value);
        // Buscar por valor
        void delete_by_value(T value);
        // Borrar al final
        void pop();
        //Eliminar por posicion
        void delete_by_position(int);
        //Imprimir    
        void print();

        void swap(int, int);
        bool ascendent(T,T);
        T at(int);
        int partition(bool, int,int);

        // 1. Implementar una función maximo de manera iterativa.
        T maximo_iterative();
        // 2. Implementar una función maximo de forma recursiva.
        T maximo_recursive();
        T maximo_recursive(T, DoubleNode<T>*);
        // 3. Implementar una función recursiva que imprima los datos de inicio a fin.
        void recursive_print_begin_end();
        void recursive_print_begin_end(DoubleNode<T>*);
        // 4. Implementar una función recursiva que imprima los datos de fin a inicio.
        void recursive_print_end_begin();    
        void recursive_print_end_begin(DoubleNode<T>*);
        // 5. Implementar una función iterativa que imprima los datos de fin a inicio.
        void iterative_print_end_begin();
        // 6. Implementar una función que cuente el número de elementos pares.
        int count_even_numbers();
        // 7. Implementar una función que ordene los datos de forma ascendente.
        void sort_ascendent();
        void sort_ascendent(int, int);
        // 8. Implementar una función que ordene los datos de forma descendente.
        void sort_descendent();
        void sort_descendent(int, int);
        // 10. void Begin() que coloca el puntero pActual a la cabeza de la lista.
        void Begin();
        // 11. void Last() que coloca el puntero pActual a al final de la lista.
        void Last();
        // 12. void Next() que mueve el puntero pActual al siguiente nodo.
        void Next();
        // 13. void Previus() que mueve el puntero pActual al nodo anterior.
        void Previous();
        // 14. T GetDato() que retorna el dato apuntado por pActual.
        T getDato();
        // 15. Usando las funciones, Begin y Next implemente una función para imprimir los datas de la lista.
        void print_data_15();
        // 16. Usando las funciones, Last y Previus implemente una función para imprimir los datas de la lista.
        void print_data_16();
        
 
};

// Inicializar
template <typename T>
void DoubleLinkedList<T>::init( ){
    size = 0; head = nullptr;
}

// Destructor
template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList( ){
    clear( );
    delete head;
}

// Limpia List
template <typename T>
void DoubleLinkedList<T>::clear( ) {
    while( !empty( ) )
        delete_by_position(0);
}

// Push_back
template <typename T>
void DoubleLinkedList<T>::push_back(T value){
    DoubleNode<T> *nuevo = new DoubleNode<T>(value);
    if(head==nullptr) head = nuevo;
    else{
        DoubleNode<T> *tmp=head;
        while(tmp->getNext()!=nullptr)
            tmp=tmp->getNext();
        tmp->setNext(nuevo);
        nuevo->setPrev(tmp);
    }
    size++;
}
  
// Insertar nodo por posicion
template <typename T>
void DoubleLinkedList<T>::insert(T value,int index){
    if(index<0){
        if(abs(index)>size){
            std::cout<<"Fuera de rango"<<std::endl;
        }else{
            insert(value,index+size);
        }
    }else{
        if(index>size){
            index=size;
        }
        if(index==0){
            if(size==0){
                DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
                head=newDoubleNode;
            }else{
                DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
                DoubleNode<T> *tmp=head;
                tmp=tmp->getNext();
                tmp->setPrev(newDoubleNode);
                newDoubleNode->setNext(head);
                head=newDoubleNode;
            }
            size++;
        }else if(index==size){
            push_back(value);
        }else{
            DoubleNode<T> *newDoubleNode=new DoubleNode<T>(value);
            DoubleNode<T> *tmp1=head;
            DoubleNode<T> *tmp2=head->getNext();
            for(int i=0;i<index-1;i++){
                tmp1=tmp1->getNext();
                tmp2=tmp2->getNext();
            }
            newDoubleNode->setNext(tmp1->getNext());
            newDoubleNode->setPrev(tmp1);
            tmp2->setPrev(newDoubleNode);
            tmp1->setNext(newDoubleNode);
            size++;
        }
    }
}

// Buscar nodo por valor
template <typename T>
bool DoubleLinkedList<T>::look_for(T value){
    DoubleNode<T> *tmp=head;
    while(tmp) {
        if(tmp->getValue()==value) return true; 
        tmp=tmp->getNext();     
    } 
    return false;
}

// Borrar por valor
template <typename T>
void DoubleLinkedList<T>::delete_by_value(T value){
    DoubleNode<T> *tmp1=head;
    DoubleNode<T> *tmp2=head->getNext();
    if(tmp1->getValue()==value){
        head=head->getNext();
        tmp2->setPrev(nullptr);
        size--;
    }
    else{
        while(tmp2!=nullptr){
            if(tmp2->getValue()==value){
                tmp1->setNext(tmp2->getNext());
                if(tmp2->getNext()!=nullptr){
                    tmp2=tmp2->getNext();
                    tmp2->setPrev(tmp1);
                }
                size--;
            }
            tmp1=tmp1->getNext();
            tmp2=tmp2->getNext();
        }
    }
}

// Borrar al final
template <typename T>
void DoubleLinkedList<T>::pop(){
    if(head==nullptr){
        std::cout<<" No se puede eliminar";
    }else{
        if(size==1){
            head=nullptr;
        }else{
            DoubleNode<T> *tmp1=head;
            DoubleNode<T> *tmp2=head->getNext();
            while(tmp2->getNext()!=nullptr){
                tmp1=tmp1->getNext();
                tmp2=tmp2->getNext();
            }
            tmp1->setNext(nullptr);
            delete tmp2;
        }
        size--;
        
    }
}

template <typename T>
void DoubleLinkedList<T>::delete_by_position(int index){
    if(index<0){
        if(abs(index)>size){
            std::cout<<"Fuera de rango"<<std::endl;
        }else{
            delete_by_position(index+size);
        }
    }
    else{
        if(index>=size){
            std::cout<<"Fuera de rango"<<std::endl;
        }else{
            if(index==0){
                head=head->getNext();
                size--;
            }else if(index==size-1){
                pop();
            }else{
                DoubleNode<T> *tmp1=head;
                DoubleNode<T> *tmp2=head->getNext();
                for(int i=0;i<index-1;i++){
                    tmp1=tmp1->getNext();
                    tmp2=tmp2->getNext();
                }
                tmp1->setNext(tmp2->getNext());
                tmp2=tmp2->getNext();
                tmp2->setPrev(tmp1);
                size--;
            }
        }
    }
}

// Imprime lista
template <typename T>
void DoubleLinkedList<T>::print(){
    DoubleNode<T> *tmp=head;
    for( ;tmp ; tmp = tmp->getNext()) std::cout<< " [ " << tmp->getValue()  << " ] " << "  ";
    std::cout<<std::endl;
}


// 1. Implementar una función máximo de manera iterativa.
template <typename T>
T DoubleLinkedList<T>::maximo_iterative(){
    T max=head->getValue();
    DoubleNode<T> *tmp = head->getNext();
    for( ;tmp ; tmp = tmp->getNext()){
        if(max<tmp->getValue()) max=tmp->getValue();
    }
    return max;
}

// 2. Implementar una función máximo de forma recursiva.
template <typename T>
T DoubleLinkedList<T>::maximo_recursive(){
    return maximo_recursive(head->getValue(),head);
}

template <typename T>
T DoubleLinkedList<T>::maximo_recursive(T max, DoubleNode<T> *tmp){
    if(!tmp) return max;
    if(tmp->getValue()>max) {max=tmp->getValue();}
    return maximo_recursive(max,tmp->getNext());    
}

// 3. Implementar una función recursiva que imprima los datos de inicio a fin.
template <typename T>
void DoubleLinkedList<T>::recursive_print_begin_end(){
    recursive_print_begin_end(head);
}

template <typename T>
void DoubleLinkedList<T>::recursive_print_begin_end(DoubleNode<T> *tmp){
    if(!tmp) std::cout<<std::endl;
    else{
        std::cout<< " [ " << tmp->getValue()  << " ] " << "  ";
        recursive_print_begin_end(tmp->getNext());
    }
}

// 4. Implementar una función recursiva que imprima los datos de fin a inicio.
template <typename T>
void DoubleLinkedList<T>::recursive_print_end_begin(){
    recursive_print_end_begin(head);
    std::cout<<std::endl;
}
    
template <typename T>
void DoubleLinkedList<T>::recursive_print_end_begin(DoubleNode<T> *tmp){
    if(!tmp) return;
    else{
        recursive_print_end_begin(tmp->getNext());
        std::cout<< " [ " << tmp->getValue()  << " ] " << "  ";
    }
}

// 5. Implementar una función iterativa que imprima los datos de fin a inicio.
template <typename T>
void DoubleLinkedList<T>::iterative_print_end_begin(){
    DoubleNode<T> *tmp=head;
    for(int i=0;i<size-1;i++)
        tmp=tmp->getNext();
    for( ;tmp ; tmp = tmp->getPrev())
        std::cout<< " [ " << tmp->getValue()  << " ] " << "  ";
    std::cout<<std::endl;
}

// 6. Implementar una función que cuente el número de elementos pares.  ́
template <typename T>
int DoubleLinkedList<T>::count_even_numbers(){
    DoubleNode<T> *tmp=head;
    int con=0;
    for( ;tmp ; tmp = tmp->getNext()){
        if((tmp->getValue())%2==0) con++;
    }
    return con;
}

// Funciones auxiliares
template <typename T>
T DoubleLinkedList<T>::at(int index){
    DoubleNode<T> *tmp=head;
    for(int i=0;i<index;i++){
        tmp=tmp->getNext();
    }
    return tmp->getValue();
}

template <typename T>
void DoubleLinkedList<T>::swap(int a, int b){
    DoubleNode<T> *tmp1=head;
    for(int i=0;i<a;i++){
        tmp1=tmp1->getNext();
    }
    DoubleNode<T> *tmp2=head;
    for(int i=0;i<b;i++){
        tmp2=tmp2->getNext();
    }
    T value=tmp2->getValue();
    tmp2->setValue(tmp1->getValue());
    tmp1->setValue(value);
}

template <typename T>
bool DoubleLinkedList<T>::ascendent(T value1,T value2){
    return (value1<value2);
}


template <typename T>
int DoubleLinkedList<T>::partition(bool asc, int low,int high){
    T pivot=at(high);
    int i=(low-1);
    for(int j=low;j<=high-1;j++){
        if(ascendent(at(j),pivot)==asc){
            i++;
            swap(i,j);
        }
    }
    swap(i+1,high);
    return i+1;        
}

// 7. Implementar una función que ordene los datos de forma ascendente.
template <typename T>
void DoubleLinkedList<T>::sort_ascendent(){
    sort_ascendent(0,size-1);
}

template <typename T>
void DoubleLinkedList<T>::sort_ascendent(int low, int high){
    if(low<high){
        int pivot=partition(true,low,high);
        sort_ascendent(low,pivot-1);
        sort_ascendent(pivot+1,high);
    }
}

// 8. Implementar una función que ordene los datos de forma descendente.
template <typename T>
void DoubleLinkedList<T>::sort_descendent(){
    sort_descendent(0,size-1);
}

template <typename T>
void DoubleLinkedList<T>::sort_descendent(int low, int high){
    if(low<high){
        int pivot=partition(false,low,high);
        sort_descendent(low,pivot-1);
        sort_descendent(pivot+1,high);
    }
}

// 10. void Begin() que coloca el puntero pActual a la cabeza de la lista.
template <typename T>
void DoubleLinkedList<T>::Begin(){
    pActual=head;
}


// 11. void Last() que coloca el puntero pActual a al final de la lista.
template <typename T>
void DoubleLinkedList<T>::Last(){
    while(pActual->getNext()!=nullptr){
        pActual=pActual->getNext();
    }
}

// 12. void Next() que mueve el puntero pActual al siguiente nodo.
template <typename T>
void DoubleLinkedList<T>::Next(){
    pActual=pActual->getNext();
}

// 13. void Previus() que mueve el puntero pActual al nodo anterior.
template <typename T>
void DoubleLinkedList<T>::Previous(){
    pActual=pActual->getPrev();
}

// 14. T GetDato() que retorna el dato apuntado por pActual.
template <typename T>
T DoubleLinkedList<T>::getDato(){
    return pActual->getValue();
}

// 15. Usando las funciones, Begin y Next implemente una función para imprimir los datas de la lista.
template <typename T>
void DoubleLinkedList<T>::print_data_15(){
    Begin();
    for(int i=0;i<size;i++){
        std::cout<< " [ " << getDato()  << " ] " << "  ";
        Next();
    }
    std::cout<<std::endl;
}

// 16. Usando las funciones, Last y Previus implemente una función para imprimir los datas de la lista.
template <typename T>
void DoubleLinkedList<T>::print_data_16(){
    Begin();
    Last();
    for(int i=0;i<size;i++){
        std::cout<< " [ " << getDato()  << " ] " << "  ";
        Previous();
    }
    std::cout<<std::endl;
}

#endif /* __DOUBLELINKEDLIST_H__ */

