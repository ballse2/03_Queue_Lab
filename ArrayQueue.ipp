//You will need this so you can make a string to throw in
// remove
#include <string>

//Syntax note: This uses the pre-processor to create a constant
// You could also use "const static" to make a constant, as in Java.
// Notice, however, that START_SIZE is NOT a variable! Instead, any
// place that the pre-processor sees "START_SIZE" it will replace it with
// 10 ... so this is like a global "find and replace".
#define START_SIZE 10

//Syntax note: C++ is not very good at figuring out which methods belong
// to which classes. That is why we have to use the scope operator to
// tell the compiler that this ArrayQueue() method belongs to the
// ArrayQueue<T> class.
template <class T>
ArrayQueue<T>::ArrayQueue(){
	numItems = 0;
	backingArray = new T[numItems]; 
}

template <class T>
ArrayQueue<T>::~ArrayQueue() {

}

template <class T>
void ArrayQueue<T>::add(T toAdd){
	numItems++;

	//make a new array, put in new item
	T* myNewArr = new T[numItems];
	myNewArr[numItems-1] = toAdd;

	//copy over old items
	for(unsigned int i=0;i<numItems-1;i++){
		myNewArr[i] = backingArray[i];
	}

	//This is delete[], not delete, need to delete old backingArray
	delete[] backingArray;

	//update backingArray to new Arr
	backingArray = myNewArr;
}

template <class T>
T ArrayQueue<T>::remove(){
	numItems--;

	//make a new array, put in new item
	T* myNewArr = new T[numItems];

	T retVal = backingArray[0];

	for(unsigned int i=0;i<numItems;i++){
		myNewArr[i] = backingArray[i+1];
	}

	delete[] backingArray;
	backingArray = myNewArr;

	return retVal;
}

template <class T>
unsigned long ArrayQueue<T>::getNumItems(){
	return numItems;
}

template <class T>
void ArrayQueue<T>::grow(){

}
