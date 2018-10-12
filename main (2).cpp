/*6. One problem with dynamic arrays is that once the array is created using the new operator, the size cannot be changed. For example, you might want to add or delete entries from the array as you can with a vector. This project asks you to create functions that use dynamic arrays to emulate the behavior of a vector.
First, write a program that creates a dynamic array of five strings. Store five names of your choice into the dynamic array. Next, complete the following two functions:
string* addEntry( string *dynamicArray, int &size, string newEntry); This function should create a new dynamic array one element larger than dynamicArray, copy all elements from dynamicArray into the new array, add the new entry onto the end of the new array, increment size, delete dynamicArray, and return the new dynamic array.
string* deleteEntry(string *dynamicArray, int &size, string                     entryToDelete);
This function should search dynamicArray for entryToDelete. If not found, the request should be ignored and the unmodified dynamicArray
*/
#include<iostream>
#include<string>
using namespace std;
string* addEntry(string *dynamicArray, int &size, string newEntry);
string *deleteEntry(string *dynamicArray, int &size, string entryToDelete);
int main()
{
    string v ,g;
  int x=5;
    string *arr;
    arr = new string[x];
    arr[0] = "mohamed";
   arr[1] = "ahmed";
   arr[2] = "ibrahim";
    arr[3] = "ismail";
   arr[4] = "adel";
   cout << "plesse enter the new name : \a\n";
   cin>> v;
   cout<<endl;
    cout<<"before adding the new name :"<<endl;
    for(int i=0; i < x; i++){
        cout << i+1 << ": " << arr[i] << endl;
    }
    cout<<endl;
    cout<<"after adding the new name :"<<endl;
   arr=addEntry(arr, x,v);
    for(int i=0; i < x; i++){
        cout << i+1 << ": " <<arr[i] << endl;
    }
    cout << "\n";
    cout << "plesse enter the new name : \a\n";
   cin>> g;
     arr=deleteEntry(arr, x,g);
    for(int i=0; i < x; i++)
        cout << i+1 << ": " << arr[i] << endl;
    return 0;
}
string *addEntry(string *dynamicArray, int& size, string newEntry)
{
   // create a new dynamic array 1 element larger than dynamicArray
   string *new_arr;
   new_arr = new string[size + 1];

   // copy all elements from dynamicArray into new array
   for(int i = 0; i < size; i++)
   {
       new_arr[i] = dynamicArray[i];
   }

   // add the new entry onto the end of the new array
   new_arr[size] = newEntry;

   // increment size
   size++;

   // delete dynamicArray
   delete [] dynamicArray;

   // and return the new array
   return new_arr;
}

string* deleteEntry(string* dynamicArray, int& size, string entryToDelete)
{
    int stop;
    // create a new dynamic array 1 element smaller than dynamicArray
    string* newArray = new string[size - 1];
    for (int i = 0; i < size -1; i++)
    {
        if (dynamicArray[i] != entryToDelete)
            newArray[i] = dynamicArray[i];
        else
        {
            stop=i;
            break;
        }
    }

    for (int i = stop; i < size - 1; i++)
        newArray[i] = dynamicArray[i + 1];

    size--;
    // delete dynamicArray
    delete [] dynamicArray;
    return newArray;
}
