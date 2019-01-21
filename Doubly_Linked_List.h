#pragma once
#include "List_Element.h"

class Doubly_Linked_List
{
    List_Element *head; // wskaźnik na początek listy dwukierunkowej
    List_Element *tail; // wskaźnik na koniec listy dwukierunkowej
    int counter; // zmienna przechowująca liczbę elementów listy
    int auxiliary; // pomocnicza zmienna, do której przypisuję wartości liczbowe z pliku
    friend void manage_list(int n, int x); //deklaracja przyjaźni metody zarządzajacej listą z klasą w celu uzyskania dostępu do prywatnych atrybutów

public:

    Doubly_Linked_List(); // konstruktor klasy Doubly_Linked_List
    ~Doubly_Linked_List(); // destruktor klasy Doubly_Linked_List
    void push_front(int x); // metoda dodająca element na początku listy
    void push_back(int x); // metoda dodająca element na końcu listy
    void pop_front(); // metoda usuwająca element na początku listy
    void pop_back(); //metoda usuwająca element na końcu listy
    void whereToPushAfter(int which, int x, List_Element *el); // metoda dodająca element za wskazaną liczbą, jeśli nie istnieje to na poczatek listy
    void popFirstMet(int which, List_Element *el); // metoda usuwająca pierwszą napotkaną wartość podaną przez użytkownika, jeśli nie istnieje to nic nie robi
    void throwOut(List_Element *el); // metoda odpowiadająca za usunięcie pojedynczego elementu
    void display(); // metoda odpowiedzialna za wyświetlenie całej listy
    bool search(int which); // metoda sprawdzająca czy dana liczba znajduje się na liście
};
