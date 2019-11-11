//
// Created by Jason Torrence on 11/1/2019.
// Updated by Jason Torrence on 11/9/2019: Added functionality: insertAtHead,
//                                          moveAllElementsUpOneStep.
//
// This was designed in place of the "Vector" class, as the use
// of the vector class was disallowed. The professor didn't mind
// if I made this class.
//
// Feel free to use this in any way you please as long as
// these comments are left alone.
//


#ifndef REAL_ESTATE_TYCOON_TOTALLYNOTAVECTOR_H
#define REAL_ESTATE_TYCOON_TOTALLYNOTAVECTOR_H

#include <typeinfo>

template <class e>
class TotallyNotAVector{
protected:
    /**
     * copyALlElements: copies all elements into a new pointer.
     *
     * @param orig : the original array
     * @param origL : original array's length
     * @param copy : the copy
     * @param copyL : the copy's length
     */
    void CopyAllElements(e* orig, int origL, e* copy, int copyL){
        if(origL>copyL){
            return;
        }
        for(int i = 0; i < origL; i++){
            copy[i] = orig[i];
        }
    }

    /**
     * CopyAllButOneElement: copies all elements but skips one.
     *
     * @param orig the original array to copy
     * @param origL the original array's length
     * @param copy the copy array
     * @param copyL the copy array's length
     * @param index the index to skip
     */
    void CopyAllButOneElement(e* orig, int origL, e* copy, int copyL, int index){
        if(origL>copyL){
            return;
        }
        for(int i = 0, j = 0; i < origL; i++, j++){
            if(i != index){
                copy[j] = orig[i];
            }else{
                j--;
            }
        }
    }

    /**
     * moveAllElementsUpOneStep: moves all elements up by one index (i = i+1). Used by insertAtHead(e).
     *
     * @param orig the original array to copy
     * @param origL the original array's length
     * @param copy the copy array
     * @param copyL the copy array's length
     */
    void moveAllElementsUpOneStep(e* orig, int origL, e* copy, int copyL){
        if(origL>copyL){
            return;
        }
        for(int i = 0, j = 1; i < size; i++, j++){
            copy[j] = orig[i];
        }
    }

    int buffer;
    int size;
    e* NotAVector;
    std::string type = typeid(e).name();

public:
    /**
     * TotallyNotAVector constructor
     */
    TotallyNotAVector();
    /**
     * TotallyNotAVector constructor
     *
     * @param eArray : the array to make the array for this TotallyNotAVector
     * @param size : the size of the array
     */
    TotallyNotAVector(e* eArray, int size){
        NotAVector = eArray;
        this->size = size;
        buffer = 100;
        while(size > buffer){
            buffer *= 2;
        }
    }

    /**
     * TotallyNotAVector deconstructor
     */
    ~TotallyNotAVector();

    /**
     * append: adds an elements and ensures the array is large enough. If not
     * it creates a new array of double the size of the original.
     *
     * @param anotherElement : the element to add
     */
    void append(e anotherElement){
        if(size+1 < buffer) {
            NotAVector[size] = anotherElement;
        }else{
            buffer *= 2;
            e* newNotAVector = new e[buffer];
            CopyAllElements(NotAVector, size, newNotAVector, buffer);
            delete[] NotAVector;
            NotAVector = newNotAVector;
        }
        size++;
    }

    /**
     * insertAtHead: inserts a new element at the head of the NotAVector
     *
     * @param anotherElement : the element to add
     */
    void insertAtHead(e anotherElement){
        e* newNotAVector = new e[buffer];
        if(size+1 < buffer) {
            moveAllElementsUpOneStep(NotAVector, size, newNotAVector, buffer);
        }else{
            buffer *= 2;
            delete[] newNotAVector;
            newNotAVector = new e[buffer];
            moveAllElementsUpOneStep(NotAVector, size, newNotAVector, buffer);
        }
        delete[] NotAVector;
        NotAVector = newNotAVector;
        NotAVector[0] = anotherElement;
        size++;
    }

    /**
     * remove: removes an element from the end of the array
     * @return the removed element
     */
    e remove(){
        e* newNotAVector = new e[buffer];
        e copyOfRemovedElement = NotAVector[size-1];
        CopyAllElements(NotAVector, size - 1, newNotAVector, buffer);
        delete[] NotAVector;
        NotAVector = newNotAVector;
        size--;
        return copyOfRemovedElement;
    }

    /**
     * remove: removes a specific element
     *
     * @param index : the element to remove
     * @return the removed element
     */
    e remove(int index){
        e* newNotAVector = new e[buffer];
        e copyOfRemovedElement = NotAVector[index];
        CopyAllButOneElement(NotAVector, size, newNotAVector, buffer, index);
        delete[] NotAVector;
        NotAVector = newNotAVector;
        size--;
        return copyOfRemovedElement;
    }

    /**
     * replace: replaces an object with a new object. Returns the replaced object
     *
     * @param index : the index of the object to be replaced
     * @param newObject : the object ot replace the index with.
     * @return the replaced object
     */
    e replace(int index, e newObject){
        e returnedObject = NotAVector[index];
        NotAVector[index] = newObject;
        return  returnedObject;
    }

    /**
     * length: returns the size value, which is the number of elements in the code.
     * @return size
     */
    int length(){
        return size;
    }

    /**
     * get: gets an elements from the array
     *
     * @param index : the index of the element to get
     * @return the element at the index
     */
    e get(int index){
        return NotAVector[index];
    }

    /**
     * getReference: gets a reference to a specific object in the array
     *
     * @param index : the index to get the reference of
     * @return a reference to an object in the array
     */
    e* getReference(int index){
        return &NotAVector[index];
    }

    /**
     * clear: clears all data in the array and resets size
     */
    void clear(){
        delete[] NotAVector;
        delete &NotAVector;
        size = 0;
        NotAVector = new e[buffer];
    }

    std::string getType(){
        return type;
    }

    TotallyNotAVector(TotallyNotAVector<int> *pVector);
};

template<class e>
TotallyNotAVector<e>::~TotallyNotAVector(){
    delete[] NotAVector;
    delete &NotAVector;
};

template<class e>
TotallyNotAVector<e>::TotallyNotAVector(){
    buffer = 100;
    size = 0;
    NotAVector = new e[buffer];
}

template<class e>
TotallyNotAVector<e>::TotallyNotAVector(TotallyNotAVector<int> *right) {
    if (right == this) {
        return;
    }
    buffer = right->buffer;
    size = right->size;
    NotAVector = right->NotAVector;

};

#endif //REAL_ESTATE_TYCOON_TOTALLYNOTAVECTOR_H
