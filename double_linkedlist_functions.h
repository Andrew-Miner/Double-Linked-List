#ifndef DOUBLE_LINKEDLIST_FUNCTIONS_H
#define DOUBLE_LINKEDLIST_FUNCTIONS_H
#include <assert.h>
#include <iostream>

template <typename ITEM_TYPE>
struct node
{
    ITEM_TYPE item;
    node* nextPtr;
    node* prevPtr;

    node():item(NULL), nextPtr(NULL), prevPtr(NULL){}

    node(ITEM_TYPE t):item(t), nextPtr(NULL), prevPtr(NULL){}

    node(ITEM_TYPE t, node<ITEM_TYPE>* nextPtr):item(t), nextPtr(nextPtr), prevPtr(NULL){}

    node(ITEM_TYPE t, node<ITEM_TYPE>* nextPtr, node<ITEM_TYPE>* prevPtr):item(t), nextPtr(nextPtr), prevPtr(prevPtr){}
};

/*
 * Precondition:
 *  insertMe must be initialized
 * Postcondition:
 *  Creates new node with insertMe and inserts the node
 *  at the front if linked list headPtr
 *  Returns pointer pointing to new node
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& insertMe);

/*
 * Precondition:
 *  insertMe and afterMe must not be initialized
 * Postcondition:
 *  Creates new node with insertMe and inserts the node
 *  at after the pointer afterMe
 *  Returns pointer pointing to new node
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>* afterMe, const ITEM_TYPE& insertMe);

/*
 * Precondition:
 *  item, beforeMe, and headPtr must be initialized
 * Postcondition:
 *  Creates new node with item and inserts the node
 *  at before the pointer beforeMe
 *  Returns pointer pointing to new node
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* beforeMe, const ITEM_TYPE& item);

/*
 * Precondition:
 *  deleteMe and headPtr should be initialized
 *  linked list headPtr must contain deleteMe
 * Postcondition:
 *  Removes and deletes node deleteMe from
 *  linked list headPtr
 *  Returns item of deleted node
 */
template <typename ITEM_TYPE>
ITEM_TYPE _delete(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* &deleteMe);

/*
 * Precondition:
 *  headPtr and removeMe must be intialized
 *  linked list headPtr must contain removeMe
 * Postcondition:
 *  Removes removeMe from linked list headPtr
 *  Returns node removed
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _remove(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* removeMe);

/*
 * Precondition:
 *  headPtr and item must be intialized
 * Postcondition:
 *  Returns node containing item, or null if
 *  no node is found
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item);

/*
 * Precondition:
 *  none
 * Postcondition:
 *  Prints linked list printMe to ostream out
 *  returns ostream out
 */
template <typename ITEM_TYPE>
std::ostream& _print_list(std::ostream& out, node<ITEM_TYPE>* printMe);

/*
 * Precondition:
 *  headPtr must be intialized
 * Postcondition:
 *  Deletes linked list headPtr
 */
template <typename ITEM_TYPE>
void _delete_list(node<ITEM_TYPE>* &headPtr);

/*
 * Precondition:
 * Postcondition:
 *  Returns pointer to newly created
 *  linked list copy of headPtr
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy(node<ITEM_TYPE>* headPtr);

/*
 * Precondition:
 *  headPtr and index must be intialized
 *  index must be greater than -1
 * Postcondition:
 *  Returns reference to item contained in node
 *  located at index in linked list headPtr or
 *  returns null if index is greater than linked
 *  list size
 */
template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* headPtr, int index);

/*
 * Precondition:
 *  headPtr and item must be intialized
 * Postcondition:
 *  Returns index of node in linked list headPtr
 *  that contains item or returns -1 if no such
 *  node it found
 */
template <typename ITEM_TYPE>
int _index(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item);

/*
 * Precondition:
 *  headPtr and item must be intialized
 * Postcondition:
 *  returns sorted node before index item should be placed at
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item);

/*
 * Precondition:
 *  headPtr and item must be intialized
 * Postcondition:
 *  Inserts item into sorted position in linked list
 *  headPtr
 *  Returns node in which item was placed
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item);

/*
 * Precondition:
 *  headPtr and item must be intialized
 * Postcondition:
 *  Inserts item into sorted position in linked list
 *  headPtr if item is unique
 *  Returns node in which item was placed or returns
 *  null if item isn't unique
 */
template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_unique_sorted(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item);

template <typename ITEM_TYPE>
int _linked_list_size(node<ITEM_TYPE>* headPtr);

template <typename ITEM_TYPE>
void _reverse_linked_list(node<ITEM_TYPE>* &headPtr);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* headPtr);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insertion_sort(node<ITEM_TYPE>* &headPtr);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _merge_sort(node<ITEM_TYPE>* &headPtr);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _push_back(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item);

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _push_back(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* appendMe);
//=====================================================================================

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_head(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& insertMe)
{
    headPtr = new node<ITEM_TYPE>(insertMe, headPtr);
    if(headPtr->nextPtr)
        headPtr->nextPtr->prevPtr = headPtr;
    return headPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_after(node<ITEM_TYPE>* afterMe, const ITEM_TYPE& insertMe)
{
    assert(afterMe);
    afterMe->nextPtr = new node<ITEM_TYPE>(insertMe, afterMe->nextPtr);
    afterMe->nextPtr->prevPtr = afterMe;
    return afterMe->nextPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_before(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* beforeMe, const ITEM_TYPE& item)
{
    assert(beforeMe && headPtr);

    if(!beforeMe->prevPtr)
        return _insert_head(headPtr, item);
    else
        return _insert_after(beforeMe->prevPtr, item);
}

template <typename ITEM_TYPE>
ITEM_TYPE _delete(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* &deleteMe)
{
    assert (headPtr && deleteMe);

    ITEM_TYPE returnMe = deleteMe->item;

    if(deleteMe->prevPtr)
    {
        delete _remove(headPtr, deleteMe);
        deleteMe = NULL;
    }
    else
        delete _remove(headPtr, deleteMe);

    return returnMe;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _remove(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* removeMe)
{
    assert (headPtr && removeMe);

    if(removeMe->prevPtr)
    {
        removeMe->prevPtr->nextPtr = removeMe->nextPtr;
        if(removeMe->nextPtr)
            removeMe->nextPtr->prevPtr = removeMe->prevPtr;
    }
    else
    {
        headPtr = removeMe->nextPtr;
        if(headPtr)
            headPtr->prevPtr = NULL;
    }

    removeMe->nextPtr = NULL;
    removeMe->prevPtr = NULL;
    return removeMe;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _search(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item)
{
    node<ITEM_TYPE>* w = headPtr;
    while(w)
    {
        if(w->item == item)
            return w;
        w = w->nextPtr;
    }
    return NULL;
}

template <typename ITEM_TYPE>
std::ostream& _print_list(std::ostream& out, node<ITEM_TYPE>* printMe)
{
    assert (printMe);
    node<ITEM_TYPE>* w = printMe;
    while(w)
    {
        if(!w->prevPtr)
            out<<"|||";
        out<<"<-"<<w->item<<"->";
        if(!w->nextPtr)
            out<<"|||";

        w = w->nextPtr;
    }
    return out;
}

template <typename ITEM_TYPE>
void _delete_list(node<ITEM_TYPE>* &headPtr)
{
    while(headPtr)
        _delete(headPtr, headPtr);
    headPtr = NULL;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _copy(node<ITEM_TYPE>* headPtr)
{
    assert(headPtr);
    node<ITEM_TYPE> *temp,
                    *walker = headPtr->nextPtr,
                    *newHead = new node<ITEM_TYPE>(headPtr->item),
                    *prevTemp = newHead;

    while(walker)
    {
        if(prevTemp)
        {
            temp = new node<ITEM_TYPE>(walker->item, NULL, prevTemp);
            prevTemp->nextPtr = temp;
        }

        prevTemp = temp;
        walker = walker->nextPtr;
    }

    return newHead;
}

template <typename ITEM_TYPE>
ITEM_TYPE& _at(node<ITEM_TYPE>* headPtr, int index)
{
    assert (headPtr && index > -1 && index < LinkedListSize(headPtr));
    for(int i = 0;i<index;i++)
    {
        headPtr = headPtr->nextPtr;
    }
    return headPtr->item;
}

template <typename ITEM_TYPE>
int _index(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item)
{
    int i = 0;
    while(headPtr && headPtr->item != item)
    {
        i++;
        headPtr = headPtr->nextPtr;
    }

    if(headPtr->item != item)
        return -1;
    return i;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _where_this_goes(node<ITEM_TYPE>* headPtr, const ITEM_TYPE& item)
{
    if(!headPtr || headPtr->item > item)
        return NULL;
    while(headPtr->nextPtr && headPtr->nextPtr->item <= item)
        headPtr = headPtr->nextPtr;
    return headPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insert_sorted(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item)
{
    node<ITEM_TYPE>* beforeInsert = _where_this_goes(headPtr, item);
    if(beforeInsert)
        return _insert_after(beforeInsert, item);
    else
        return _insert_head(headPtr, item);

}

template <typename ITEM_TYPE, class POLICY>
node<ITEM_TYPE>* _insert_unique_sorted(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item, POLICY p)
{
    node<ITEM_TYPE>* beforeInsert = WhereThisGoes(headPtr, item);
    if(beforeInsert)
    {
        if(beforeInsert->item == item)
        {
            beforeInsert->item = p(beforeInsert->item, item);
            return beforeInsert;
        }
        return InsertAfter(beforeInsert, item);
    }
    else
        return InsertHead(headPtr, item);
}

template <typename ITEM_TYPE>
int _linked_list_size(node<ITEM_TYPE>* headPtr)
{
    int i = 0;
    while(headPtr)
    {
        i++;
        headPtr = headPtr->nextPtr;
    }
    return i;
}

template <typename ITEM_TYPE>
void _reverse_linked_list(node<ITEM_TYPE>* &headPtr)
{
    node<ITEM_TYPE>* temp;
    while(headPtr)
    {
        temp = headPtr->prevPtr;
        headPtr->prevPtr = headPtr->nextPtr;
        headPtr->nextPtr = headPtr->prevPtr;

        if(headPtr->prevPtr)
            headPtr = headPtr->prevPtr;
        else
            break;
    }
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _last_node(node<ITEM_TYPE>* headPtr)
{
    assert(headPtr);
    node<ITEM_TYPE>* walker = headPtr;
    walker = walker->nextPtr;
    while(walker != NULL)
    {
        walker = walker->nextPtr;
        headPtr = headPtr->nextPtr;
    }
    return headPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _insertion_sort(node<ITEM_TYPE>* &headPtr)
{
    if(!headPtr)
        return headPtr;

    node<ITEM_TYPE>* temp = NULL;

    while(headPtr)
       _insert_sorted(temp, _delete(headPtr, headPtr));

    headPtr = temp;

    return headPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _merge_sort(node<ITEM_TYPE>* &headPtr)
{
    assert(headPtr);

    if(!headPtr->nextPtr)
        return headPtr;

    node<ITEM_TYPE> *list_1 = headPtr,
                    *list_2 = _split_list(headPtr),
                    *result = nullptr;

    list_1 = _merge_sort(headPtr);
    list_2 = _merge_sort(list_2);

    while(list_1 && list_2)
    {
        if(list_1->item <= list_2->item)
            _push_back(result, _remove(list_1, list_1));
        else
            _push_back(result, _remove(list_2, list_2));
    }

    while(list_1)
        _push_back(result, _remove(list_1, list_1));
    while(list_2)
        _push_back(result, _remove(list_2, list_2));

    return result;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _split_list(node<ITEM_TYPE>* headPtr)
{
    int length = _linked_list_size(headPtr);
    node<ITEM_TYPE>* walker = headPtr;

    for(int i = 1; i < length/2; i++)
        walker = walker->nextPtr;

    headPtr = walker->nextPtr;
    walker->nextPtr = nullptr;
    headPtr->prevPtr = nullptr;
    return headPtr;
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _push_back(node<ITEM_TYPE>* &headPtr, const ITEM_TYPE& item)
{
    node<ITEM_TYPE>* newNode = new node<ITEM_TYPE>(item);
    return _push_back(headPtr, newNode);
}

template <typename ITEM_TYPE>
node<ITEM_TYPE>* _push_back(node<ITEM_TYPE>* &headPtr, node<ITEM_TYPE>* appendMe)
{
    appendMe->nextPtr = nullptr;
    appendMe->prevPtr = nullptr;

    if(headPtr)
    {
        node<ITEM_TYPE>* last_node = _last_node(headPtr);
        last_node->nextPtr = appendMe;
        appendMe->prevPtr = last_node;
    }
    else
        headPtr = appendMe;

}

#endif // DOUBLE_LINKEDLIST_FUNCTIONS_H
