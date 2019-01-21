#include <cstdlib>
#include "List_Element.h"

List_Element::List_Element()
{
    next = previous = NULL; // na początku element listy nie wskazuje nigdzie
}

List_Element::~List_Element()
{
    next = previous = NULL; // od teraz wskaźniki nie wskazują nigdzie w pamięci
}
