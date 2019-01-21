#pragma once

struct List_Element
{
    int value; // warto�� elementu listy
    List_Element *next; // wska�nik na nast�pny element listy
    List_Element *previous; // wska�nik na poprzedni element listy

    List_Element(); // konstruktor pojedynczego elementu
    ~List_Element(); // destruktor pojedynczego elementu
};
