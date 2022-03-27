//Afham Bashir 
#include "DynamicArray.h"  //header file 
#include <iostream>
#include <string> 
using namespace std;


int main() {
  DynArray<int> array1;     //initilized array 1 and insanitautes as integer
  DynArray<string> array2;  //initilized array 2 and insanitautes as string
  DynArray<double> array3 = DynArray<double>(20); //using construcor with paramater

  array1.append(10);  // appends int 10 
  array1.append(20); 
  array1.append(30);
  array1.append(40); 
  array1.append(50);
  array1.append(60);
  array1.append(70);
  array1.append(80);
  array1.append(90);
  array1.append(100);
  array1.append(110);
  array1.append(120);
  array1.set(0, 40);  // sets array 1 position 0 to 40; 
  array1.insert(11, 5); // inserts 5 at position 11; 
  array1.insert(0, 7);   //inserts 7 at position 0; 
  array1.remove(0);      //removes the value at position 0 of array1. 
  array1.remove(11);    
  array1.resize(50);     // resizes the array to capacipty 50. 
  cout << "The size of the Array 2 is "<<array1.size() << "\n " << endl;  //output the current size of array1. 

  array2.append("dog");   //adds "dog" string to array2. 
  array2.append("cat");   // adds cat string
  array2.set(1, "bird");  // changes position 1 of array to "bird" string
  array2.insert(2, "cow");  //insers cow string as array 2 position 2
  array2.remove(2);         //removes string at position 2 
  array2.remove(1);         
  array2.resize(5);         //resize capacipty of array 2 to 5. 
  array2.append("snake");   //adds snake string to array 2.
  array2.append("bike");
  array2.append("yikes");
  array2.append("sike");  
  cout << "The size of the Array 2 is "<<array2.size() << "\n " << endl;  // outputs the curent size of array 2. 

  array3.append(15.1);   //adds 15.1 to array3.
  array3.append(14.6);   
  array3.append(69.1);
  array3.append(42.0); 
  array3.append(0.0001);  
  array3.append(34.5); 
  array3.append(7); 
  array3.set(4, 1.111);  //sets position 4 of the array3 to 1.111; 
  array3.set(1, 14.6);   //  sets position 1 of array3 to 14.6; 
  array3.insert(6,77.3);   //inserts 77.3 into position 6 in array3. 
  array3.remove(3);       //removes value at position 3 (69.1); 
  array3.remove(0);        
  array3.resize(6);       //resizes the capacipty of array 3 to 6.   
  cout << "The size of the Array 2 is "<<array3.size() << "\n " << endl; //outputs the current size of array 3. 

  for (int i = 0; i < array1.size(); i++) 
		cout << array1.get(i) << endl;        // prints array 1 using for loop
  cout << "\n" <<endl;
	for (int i = 0; i < array2.size(); i++)
		cout << array2.get(i) << endl;      //for loop to print array 2 by calling get function
                                        //get function returns value at array position. 
  cout << "\n" <<endl; 
  for (int i = 0; i < array1.size(); i++) 
		cout << array1.get(i) << endl; 
    
	return 0;
}