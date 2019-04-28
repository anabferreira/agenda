#ifndef NODE_HPP_INCLUDED
#define NODE_HPP_INCLUDED

#include <iostream>

using namespace std;

template <typename T>
struct Node
{

    T Valor;
    Node<T> *Proximo;

    Node(T valor);

};

template <typename T>
Node<T>::Node(T valor) : Valor(valor), Proximo(nullptr) {}

#endif // NODE_HPP_INCLUDED
