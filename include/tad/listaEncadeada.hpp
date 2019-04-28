#ifndef LINKEDLIST_HPP_INCLUDED
#define LINKEDLIST_HPP_INCLUDED

#include <iostream>
#include "node.hpp"

using namespace std;

template <typename T>
struct ListaEncadeada
{
    int Contador;

    Node<T> *Cabeca;
    Node<T> *Cauda;

    ListaEncadeada();

    Node<T> * Get(int index);

    void InserirCabeca(T valor);
    void InserirCauda(T valor);
    void Inserir(int index, T valor);

    int Pesquisar(T valor);

    void RemoverCabeca();
    void RemoveCauda();
    void Remover(int index);

    int GetContador();

    void ImprimirLista();

};

template <typename T>
ListaEncadeada<T>:: ListaEncadeada() : Contador(0), Cabeca(nullptr), Cauda(nullptr) {}

template <typename T>
Node<T> * ListaEncadeada<T>::Get(int index)
{

    if (index < 0 || index > Contador)
    {
        return nullptr;
    }

    Node<T> *node = Cabeca;

    for (int i = 0; i < index; ++i)
    {
        node = node->Proximo;
    }

    return node;

}

template <typename T>
void ListaEncadeada<T>::InserirCabeca(T valor)
{

    Node<T> *node = new Node<T>(valor);

    node->Proximo = Cabeca;

    Cabeca = node;

        if (Contador == 0)
    {
        Cauda = Cabeca;
    }

    Contador++;

}

template <typename T>
void ListaEncadeada<T>::InserirCauda(T valor)
{

    if (Contador == 0)
    {
        InserirCabeca(valor);
        return;
    }

    Node<T> *node = new Node<T>(valor);

    Cauda-> Proximo = node;

    Cauda = node;

    Contador++;

}

template <typename T>
void ListaEncadeada<T>::Inserir(int index, T valor)
{

    if (index < 0 || index > Contador)
    {
        return;
    }

    if (index == 0)
    {
        InserirCabeca(valor);
        return;
    }

    else if (index == Contador)
    {
        InserirCauda(valor);
        return;
    }

    Node<T> * nodeAnterior = Cabeca;

    for (int i = 0; i < index - 1; ++i)
    {
        nodeAnterior = nodeAnterior->Proximo;
    }

    Node<T> *proximoNode = nodeAnterior->Proximo;

    Node<T> *node = new Node<T>(valor);

    node->Proximo = proximoNode;
    nodeAnterior->Proximo = node;

    Contador++;

}

template <typename T>
int ListaEncadeada<T>::Pesquisar(T val)
{
    return 0;
}

template <typename T>
int ListaEncadeada<T>::GetContador()
{
    return Contador;
}

template <typename T>
void ListaEncadeada<T>::ImprimirLista()
{
}

#endif // LINKEDLIST_HPP_INCLUDED
