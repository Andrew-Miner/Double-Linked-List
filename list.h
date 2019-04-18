#ifndef LIST_H
#define LIST_H
#include "double_linkedlist_functions.h"
#include <iostream>

template <typename ITEM_TYPE>
class List
{
public:
    class Iterator
    {
    public:
        friend class List;
        Iterator(){p = NULL;}
        Iterator(node<ITEM_TYPE>* pointer){p=pointer;}

        Iterator operator++(int);
        Iterator& operator++();
        Iterator& operator+=(int move);
        Iterator operator+(const int& move);
        Iterator operator-(const int& move);
        Iterator operator[](int move){return this+move;}
        ITEM_TYPE& operator*();
        bool operator!=(const List<ITEM_TYPE>::Iterator& itr);
        bool operator==(const List<ITEM_TYPE>::Iterator& lhs) {return p == lhs.p;}
        const node<ITEM_TYPE>* getNodePointer() const {return p;}

    private:
        node<ITEM_TYPE>* p;

    };

    List();
    List(ITEM_TYPE* newList, int listSize);
    List(const List<ITEM_TYPE>& other);
    List(const node<ITEM_TYPE>* &headPtr);
    ~List();
    List<ITEM_TYPE>::Iterator InsertHead(const ITEM_TYPE& item);
    List<ITEM_TYPE>::Iterator InsertBefore(List<ITEM_TYPE>::Iterator leftOf, const ITEM_TYPE& item);
    List<ITEM_TYPE>::Iterator InsertAfter(List<ITEM_TYPE>::Iterator rightOf, const ITEM_TYPE& item);
    ITEM_TYPE Delete(List<ITEM_TYPE>::Iterator deleteMe);
    ITEM_TYPE DeleteFront();
    void Clear();
    List<ITEM_TYPE> Copy(const List<ITEM_TYPE>& copyMe);
    List<ITEM_TYPE>::Iterator Remove(List<ITEM_TYPE>::Iterator removeMe);
    int Index(const ITEM_TYPE& item);
    ITEM_TYPE& At(const int& index);
    List<ITEM_TYPE>::Iterator SortedInsert(const ITEM_TYPE& item);
    List<ITEM_TYPE>::Iterator UniqueSortedInsert(const ITEM_TYPE& item);
    List<ITEM_TYPE>::Iterator Search(const ITEM_TYPE& item);
    List<ITEM_TYPE>& operator=(const List<ITEM_TYPE>& other);
    int Length();
    List<ITEM_TYPE>::Iterator Begin();
    List<ITEM_TYPE>::Iterator End();
    List<ITEM_TYPE>& operator+=(const List<ITEM_TYPE>& rhs);
    void InsertionSort();
    void MergeSort();
    friend std::ostream& operator<<(std::ostream& out, const List<ITEM_TYPE>& list) {return _print_list(out, list.listPtr);}

private:
    node<ITEM_TYPE>* listPtr;
    int size;
};

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Iterator::operator++(int)
{
    List<ITEM_TYPE>::Iterator temp(p);
    operator++();
    return temp;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator& List<ITEM_TYPE>::Iterator::operator++()
{
    if(p)
        p=p->nextPtr;
    return *this;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator& List<ITEM_TYPE>::Iterator::operator+=(int move)
{
    p = *this+move;
    return *this;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Iterator::operator+(const int& move)
{
    Iterator temp(p);
    for(int i=0;i<move;i++)
    {
        if(temp.p->nextPtr)
            temp.p=temp.p->nextPtr;
        else
            return NULL;
    }
    return temp;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Iterator::operator-(const int& move)
{
    Iterator temp(p);
    for(int i=0;i<move;i++)
    {
        if(temp.p->prevPtr)
            temp.p=temp.p->prevPtr;
        else
            return NULL;
    }
    return temp;
}

template <typename ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::Iterator::operator*()
{
    return p->item;
}

template <typename ITEM_TYPE>
bool List<ITEM_TYPE>::Iterator::operator!=(const List<ITEM_TYPE>::Iterator& itr)
{
    return p != itr.p;
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>::List()
{
    listPtr = NULL;
    size = 0;
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>::List(ITEM_TYPE* newList, int listSize)
{
    listPtr = NULL;
    for(int i = listSize-1;i>-1;i--)
        InsertHead(*(newList+i));
    size = listSize;
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>::List(const List<ITEM_TYPE>& other)
{
    listPtr = _copy(other.listPtr);
    size = other.size;
}
template <typename ITEM_TYPE>
List<ITEM_TYPE>::List(const node<ITEM_TYPE>* &headPtr)
{
    listPtr = _copy(headPtr);
    size = 0;

    node<ITEM_TYPE>* walker = headPtr;
    while(walker)
    {
        walker = walker->nextPtr;
        size++;
    }
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>::~List()
{
    if(listPtr)
        _delete_list(listPtr);
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator=(const List<ITEM_TYPE>& other)
{
    if(listPtr)
        _delete_list(listPtr);
    listPtr = _copy(other.listPtr);
    size = other.size;
    return *this;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertHead(const ITEM_TYPE& item)
{
    size++;
    return List<ITEM_TYPE>::Iterator(_insert_head(listPtr, item));
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertBefore(List<ITEM_TYPE>::Iterator leftOf, const ITEM_TYPE& item)
{
    size++;
    if(leftOf.p && listPtr)
        return List<ITEM_TYPE>::Iterator(_insert_before(listPtr, leftOf.p, item));
    if(!listPtr && !leftOf.p)
        return List<ITEM_TYPE>::Iterator(_insert_head(listPtr, item));
    else if(listPtr)
        return List<ITEM_TYPE>::Iterator(_insert_before(listPtr, _last_node(listPtr), item));
    else
        return NULL;

}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::InsertAfter(List<ITEM_TYPE>::Iterator rightOf, const ITEM_TYPE& item)
{
    size++;
    if(rightOf.p)
        return List<ITEM_TYPE>::Iterator(_insert_after(rightOf.p, item));
    else if(!listPtr && !rightOf.p)
        return List<ITEM_TYPE>::Iterator(_insert_head(listPtr, item));
    else if(listPtr)
        return List<ITEM_TYPE>::Iterator(_insert_after(_last_node(listPtr), item));
    else
        return NULL;
}

template <typename ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::Delete(List<ITEM_TYPE>::Iterator deleteMe)
{
    size--;
    return _delete(listPtr, deleteMe.p);
}

template <typename ITEM_TYPE>
ITEM_TYPE List<ITEM_TYPE>::DeleteFront()
{
    if(listPtr)
    {
        size--;
        return _delete(listPtr, listPtr);
    }
    else
        return NULL;
}

template <typename ITEM_TYPE>
void List<ITEM_TYPE>::Clear()
{
    if(listPtr)
        _delete_list(listPtr);
}

template <typename ITEM_TYPE>
List<ITEM_TYPE> List<ITEM_TYPE>::Copy(const List<ITEM_TYPE>& copyMe)
{
    return copyMe;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Remove(List<ITEM_TYPE>::Iterator removeMe)
{
    size--;
    return _remove(listPtr, removeMe.p);
}

template <typename ITEM_TYPE>
int List<ITEM_TYPE>::Index(const ITEM_TYPE& item)
{
    return _index(listPtr, item);
}

template <typename ITEM_TYPE>
ITEM_TYPE& List<ITEM_TYPE>::At(const int& index)
{
    //if(index<0 || index>=size)
        //return NULL; Can't return null should throw instead, but I'm lazy
        //and I don't think this function is required
    return at(listPtr, index);
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::SortedInsert(const ITEM_TYPE& item)
{
    size++;
    return List<ITEM_TYPE>::Iterator(InsertSorted(listPtr, item));
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::UniqueSortedInsert(const ITEM_TYPE& item)
{

    node<ITEM_TYPE>* r = _insert_unique_sorted(listPtr, item);
    if(r)
        size++;
    return List<ITEM_TYPE>::Iterator(r);
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Search(const ITEM_TYPE& item)
{
    return List<ITEM_TYPE>::Iterator(_search(listPtr, item));
}

template <typename ITEM_TYPE>
int List<ITEM_TYPE>::Length()
{
    return size;
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::Begin()
{
    return List<ITEM_TYPE>::Iterator(listPtr);
}

template <typename ITEM_TYPE>
typename List<ITEM_TYPE>::Iterator List<ITEM_TYPE>::End()
{
    return List<ITEM_TYPE>::Iterator();
}

template <typename ITEM_TYPE>
List<ITEM_TYPE>& List<ITEM_TYPE>::operator+=(const List<ITEM_TYPE>& rhs)
{
    node<ITEM_TYPE>* tempLast = _last_node(listPtr);
    tempLast->nextPtr = _copy(rhs.listPtr);
    tempLast->nextPtr->prevPtr = tempLast;
    return *this;
}

template <typename ITEM_TYPE>
void List<ITEM_TYPE>::InsertionSort()
{
    if(listPtr)
        _insertion_sort(listPtr);
}

template <typename ITEM_TYPE>
void List<ITEM_TYPE>::MergeSort()
{
    if(listPtr && size > 1)
        listPtr = _merge_sort(listPtr);
}

#endif // LIST_H
