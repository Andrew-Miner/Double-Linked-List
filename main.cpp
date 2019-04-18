#include <iostream>
#include "list.h"

/*-------------------------------------
 * Program Name: Merge & Insertion Sort
 * Author: Andrew Miner
 * Purpose: Create An Insertion Sort
 *          Function and A Merge Sort
 *          Function
 * Notes:
 */

using namespace std;

void testList();
void testSorts();

int main(int argc, char *argv[])
{
    //testList();
    testSorts();
    cout<<"======================================"<<endl;
    return 0;
}

void testSorts()
{
    int array[10] = {10, 4, 6, 8, 2, 9, 5, 7, 3, 1};
    List<int> myList(array, 10);
    List<int> myListCopy(myList);

    cout << endl << endl << endl;
    cout << "List: " << myList << endl << endl;

    myList.InsertionSort();
    cout << "Insertion Sort: " << myList << endl << endl;

    myListCopy.MergeSort();
    cout << "Merge Sort: " << myListCopy << endl << endl;

}

void testList()
{

    //Testing Constructor That Takes An Array Pointer and Size
    //========================================================
    int array[5] = {0,1,2,3,4};
    List<int> myArrayList(array, 5);
    cout<<"Creating New List With Array Pointer (myArrayList): "<<myArrayList<<endl<<endl;

    //Testing Copy Constructor
    //========================
    List<int> myArrayListCopy(myArrayList);
    cout<<"Copy Constructor: "<<myArrayListCopy<<endl<<endl;

    //Testing Equals Operator and DeleteFront()
    //=========================================
    myArrayListCopy = myArrayList;
    cout<<"Equals Operator: ";
    while (myArrayListCopy.Begin() != myArrayListCopy.End())
    {
        cout<<myArrayListCopy;
        cout<<endl<<"Deleted Front: ";
        myArrayListCopy.DeleteFront();
    }
    cout<<endl<<"Deleteing Front When Empty (0 == NULL): "<<myArrayListCopy.DeleteFront()<<endl<<endl;

    List<int> edgeCases;

    //Testing InsertAfter() with Begin() Iterator on an Empty List
    //============================================================
    edgeCases.InsertAfter(edgeCases.Begin(), 1);
    cout<<"Empty InsertAfter@Begin() (edgeCases): "<<edgeCases<<endl<<endl;

    //Testing Clear
    //=============
    edgeCases.Clear();
    cout<<"List Length: "<<edgeCases.Length()<<endl<<endl;

    //Testing InsertBefore() with Begin() Iterator on an Empty List
    //============================================================
    edgeCases.InsertBefore(edgeCases.Begin(), 1);
    cout<<"Empty InsertBefore@Begin(): "<<edgeCases<<endl<<endl;
    edgeCases.Clear();

    //Testing InsertAfter() with End() Iterator on an Empty List
    //============================================================
    edgeCases.InsertAfter(edgeCases.End(), 1);
    cout<<"Empty InsertAfter@End(): "<<edgeCases<<endl<<endl;
    edgeCases.Clear();

    //Testing InsertBefore() with End() Iterator on an Empty List
    //============================================================
    edgeCases.InsertBefore(edgeCases.End(), 1);
    cout<<"Empty InsertBefore@End(): "<<edgeCases<<endl<<endl;

    //Testing InsertAfter() with End() Iterator on an Non-Empty List
    //==============================================================
    edgeCases.InsertAfter(edgeCases.End(), 3);
    cout<<"Keep in mind list.End() == nullptr"<<endl;
    cout<<"InsertAfter@End(): "<<edgeCases<<endl<<endl;

    //Testing InsertBefore() with End() Iterator on an Non-Empty List
    //==============================================================
    edgeCases.InsertBefore(edgeCases.End(), 2);
    cout<<"InsertBefore@End(): "<<edgeCases<<endl<<endl;

    //Testing operator+=() with myArrayList && edgeCases
    //==================================================
    myArrayList += edgeCases;
    cout<<"myArrayList += edgeCases: "<<myArrayList<<endl<<endl;

    //Testing InsertionSort()
    //=======================
    edgeCases = myArrayList;
    edgeCases.InsertionSort();
    cout<<"edgeCases Insertion Sort: "<<edgeCases<<endl<<endl;

    //Testing MergeSort()
    //===================
    cout << myArrayList << endl;
    myArrayList.MergeSort();
    cout<<"myArrayList Merge Sort: "<<myArrayList<<endl<<endl;
}
