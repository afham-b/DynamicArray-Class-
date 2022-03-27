#pragma once

template <typename T>  // template class
class DynArray {      
  private: 
     T *p_values;     //the array could be an int, double, string, so we use T 
    int capacity;     //how much the array can hold max.
    int cur_size;     //how many values the array currently has
    void expand (int new_capacity);   //private member function, increseases capacity of array. 
  public:
    DynArray();      //default constructor 
    DynArray(int size); //constructor with intger parameter for size of the array 
    ~DynArray() {delete[] p_values; }  //deconstructor, clears pointers. 
    int size() const { return cur_size;} //function return size of the array.
    void append (T value);               //assigns value to array, could be of differnt data types, hence the use of T. 
    void set (int pos, T value) {p_values[pos] = value;} //changes a position of the array to the new value, which could be of multiple different data types. 
    T get(int pos) const {return p_values[pos];}  // returns value at array position 
    void insert( int pos, T value); // puts in value into array at specified position
    void remove( int pos);          //removes value of array at specific position
    void resize (int size);         // resizes that capacity of the array. 
};

template<typename T>         //template allows that array to be constructed in differn datatypes.
DynArray<T>:: DynArray () {
  p_values = new T[10];       // default constructor starts with array of capacity 10. 
  capacity = 10; 
  cur_size = 0; 
}

template<typename T>
DynArray<T>:: DynArray (int size){    
  p_values = new T[size]; //constructor with intger parameter that specificically gives capacity. 
  capacity = size; 
  cur_size = 0; 
}

template<typename T>           //uses template because value to be appended can be multiple datatypes
void DynArray<T>::append(T value) { 
  if (cur_size == capacity)       // if the capacity runs out. 
     expand (capacity+10);        // increase the capacity of array via expand function 
  p_values[cur_size] = value;     //assign value to specif array position. 
  cur_size++;                     //increament the current size. 
}

template<typename T>   //uses template because array can be in multiple datatypes
void DynArray<T>::expand(int new_capacity) { //expand function increases the array capacity. 
    if (new_capacity <= capacity)   // if desired capacity is NOT larger than current size. 
        return;                     // ther is no need to expand array. 
    T *p = p_values;                //template pointer to hold array. 
    capacity = new_capacity;        // changes to new capacity
    p_values = new T[capacity];     // old arry to new capacity array. 
    for (int i = 0; i < size(); i++)  // for loop to assign old value being held by pointer p, to new capacity array 
        p_values[i] = p[i];
    delete[] p;                //deletes pointer, for memory. 
}

template <typename T> ////uses template because value to be inserted can be in multiple datatypes
void DynArray<T>::insert(int pos, T value) { 
  T *p = p_values;          //template pointer holds current array. 
  cur_size++;               // increases current size of array. 
  if (cur_size == capacity){  //if the current size goes over capacity, increases capacity
     expand (capacity+10);}    
  p_values = new T[capacity];    // array become new larger capacity array. using template for possible differnt data types. 
  
  for (int i=0; i<pos; i++){  //uses for loop to assign old values being held by pointer to new array, but uses i<pos for all value below the desired position of insertion. 
    p_values[i]=p[i];        
  }
  for (int i=(pos+1); i<cur_size; i++){ // uses for loop to assign value to new array that were above specific position of insertion. 
    p_values[i]=p[i-1];  
  }
  p_values[pos] = value; //assigns position in new array to desire value. 
  delete[] p;
} 

template<typename T>
void DynArray<T>::remove(int pos){
  T *p = p_values;
  p_values = new T[capacity];
  for (int i=0; i<pos; i++){     // new array keeps all values below it the same in new array 
    p_values[i]=p[i];              
  }
  for (int i=(pos); i<cur_size; i++){ // shifts all value to the right and above of position in array being removed, down one, to fill the gap caused by removed value. 
    p_values[i]=p[i+1]; 
  }
  cur_size --;  // decreaments the current size of the array. 
  delete[] p;
}

template<typename T>
void DynArray<T>::resize (int size){  //changes capacity of array. 

  if (size ==cur_size) {   // if the desired array is already current size, do nothing. 
    return; }
  if (size > capacity) {   // if the desired size is above current size, expands to desired size. 
		expand(size);}
  if (size < cur_size) {  // if desired size is below the curren size, removes values untill that curernt size matches the desired value by using a while loop and calling remove function. 
      do {
        remove(cur_size-1);
      } while ( cur_size!= size);}
}