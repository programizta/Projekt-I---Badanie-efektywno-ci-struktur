#pragma once

struct List_Element
{
    int value; // wartoœæ elementu listy
    List_Element *next; // wskaŸnik na nastêpny element listy
    List_Element *previous; // wskaŸnik na poprzedni element listy

    List_Element(); // konstruktor pojedynczego elementu
    ~List_Element(); // destruktor pojedynczego elementu
};
