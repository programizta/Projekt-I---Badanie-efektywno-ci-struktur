#include <iostream>
#include <fstream>
#include "Doubly_Linked_List.h"

using namespace std;

Doubly_Linked_List::Doubly_Linked_List()
{
    head = tail = NULL; // początkowy element listy nie wskazuje nigdzie w pamięci
    ifstream send;
    send.open("data.txt", ios::out);
    send >> counter; // muszę ten chwyt uprościć, bo chcę odczytywać od drugiego elementu wartości w pliku
    counter = 0;

    while(send >> auxiliary)
    {
        push_back(auxiliary);
    }
    send.close();
}

Doubly_Linked_List::~Doubly_Linked_List() // postanowiłem, że destruktor będzie usuwał elementy od początku listy
{
    while(counter)
    {
        if(counter)
        {
            List_Element *el = head; // przypisanie głowy do nowego elementu listy
            if(el->previous) el->previous->next = el->next;
            else head = el->next;

            if(el->next) el->next->previous = el->previous;
            else tail = el->previous;
            delete el;
            counter--; // derkementacja elementow listy, bo sukcesywnie destruktor usuwa elementy
        }
    }
}

void Doubly_Linked_List::push_front(int x)
{
    counter++; // inkrementacja liczby elementów listy
    List_Element *el = new List_Element;
    el->value = x; // wprowadzamy wartość naszego nowego elementu
    el->previous = NULL; // ustawiamy wskaźnik na poprzedni element jako NULL, bo poprzedni nie istnieje
    el->next = head; // następnym elementem listy staje sie poprzedni element
    head = el; // głowę ustawiamy jako nowy wprowadzony element listy

    if(el->next) el->next->previous = el;
    else tail = el;
}

void Doubly_Linked_List::push_back(int x)
{
    counter++; // inkrementacja liczby elementów listy
    List_Element *el = new List_Element;

    el->value = x;
    el->next = NULL;
    el->previous = tail;
    tail = el;

    if(el->previous) el->previous->next = el;
    else head = el;
}

void Doubly_Linked_List::pop_front()
{
    if(counter) throwOut(head);
    else cout << "Lista jest juz pusta!\n";
}

void Doubly_Linked_List::pop_back()
{
    if(counter) throwOut(tail);
    else cout << "Lista jest juz pusta!\n";
}

void Doubly_Linked_List::throwOut(List_Element *el)
{
    counter--;
    if(el->previous) el->previous->next = el->next;
    else head = el->next;
    if(el->next) el->next->previous = el->previous;
    else tail = el->previous;
    delete el;
}

void Doubly_Linked_List::whereToPushAfter(int which, int x, List_Element *el)
{
    counter++; // inkrementacja liczby elementów listy
    List_Element *new_el = new List_Element;
    while(el)
    {
        if(el->value == which) break;
        else el = el->next;
    }
    new_el->value = x;
    if(el->next)
    {
        counter--;
        new_el->next = el->next;
        new_el->previous = el;
        el->next->previous = new_el;
        el->next = new_el;
    }
    else
    {
        push_back(x);
    }
}

void Doubly_Linked_List::popFirstMet(int which, List_Element *el)
{
    while(el)
    {
        if(el->value == which) break;
        else el = el->next;
    }
    throwOut(el);
}

void Doubly_Linked_List::display()
{
    List_Element *el = head;

    if(counter)
    {
        cout << "Oto zawartosc listy:\n";
        while(el)
        {
            cout << el->value << " ";
            el = el->next;
        }
    }
    else cout << "Lista jest pusta!\n";
}

bool Doubly_Linked_List::search(int which)
{
    List_Element *el = head;
    if(counter)
    {
        while(el)
        {
            if(el->value == which) return true;
            else el = el->next;
        }
        return false;
    }
    return false;
}
