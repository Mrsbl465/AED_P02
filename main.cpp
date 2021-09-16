#include <iostream>

#include <cstdlib>
#include <ctime>

#include "DoubleLinkedList.h"

using namespace std;

int main(){
    DoubleLinkedList<int> list;

    /*
    srand((unsigned) time(0));
    for (int i= 0; i<10;i++){
        int randomNumber = rand();
        list.push_back(randomNumber);
    }*/


    
    list.push_back(5);
    list.push_back(2);
    list.push_back(8);
    list.push_back(-12);

    list.print();

    cout << " EJ.1 EL VALOR MAXIMO (ITERATIVO): " << list.maximo_iterative() << endl;
    cout << " EJ.2 EL VALOR MAXIMO (RECURSIVO): " << list.maximo_recursive() << endl;

    cout << " EJ.3 PRINT (RECURSIVO)" << endl;
    list.recursive_print_begin_end();

    cout << " EJ.4 PRINT INVERSO (RECURSIVO)" << endl;
    list.recursive_print_end_begin();

    cout << " EJ.5 PRINT INVERSO (ITERATIVO)" << endl;
    list.iterative_print_end_begin();

    cout << " EJ.6 CANTIDAD DE PARES: " << list.count_even_numbers() << endl;

    cout << " EJ.7 ORDENAR ASCENDENTEMENTE" << endl;
    list.sort_ascendent();
    list.print();

    cout << " EJ.8 ORDENAR DESCENDENTEMENTE" << endl;
    list.sort_descendent();
    list.print();

    cout << " EJ.15 (EJ. 9, EJ.10, EJ. 12 Y EJ. 14) " << endl;
    list.print_data_15();

    cout << " EJ.16 (EJ. 9, EJ.11, EJ. 13 Y EJ. 14) " << endl;
    list.print_data_16();

    /*
    list.push_back(1);
    list.push_back(2);
    list.print();
    list.insert(3,2);
    list.insert(4,-4);
    list.insert(5,0);
    list.print();
    list.delete_by_value(4);
    list.print();
    cout<<"Pase 1"<<endl;
    list.delete_by_value(5);
    list.print();
    cout<<"Pase 2"<<endl;
    list.delete_by_position(-4);
    list.print();
    cout<<"Pase 3"<<endl;
    list.delete_by_position(15);
    list.print();
    cout<<"Pase 4"<<endl;
    */
   /*
   list.push_back(5);
   list.push_back(4);
   list.push_back(7);
   list.push_back(8);
   list.push_back(2);*/
   //cout<<list.maximo_recursive(list.getSize(),list.getHead())<<endl;//funca
   //cout<<list.maximo_iterative()<<endl;//funca
   //list.print();
   //list.recursive_print_begin_end(list.getHead());//funca
   //list.recursive_print_end_begin(list.getHead());//deberia funcar si le pasas la direccion del ultimo nodo
   //list.iterative_print_end_begin();//funca
   //cout<<list.count_even_numbers();//funca
   // list.print();
   // list.sort_descendent();
   // cout<<"Pase e sort"<<endl;
   // list.print();
   
}