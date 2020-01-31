#pragma once
#include "object.h"
#include "string.h"
#include <stdlib.h>

/**
 * Array: this class represents an array of Objects or Strings
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class Array : public Object
{
public:
    Object** array_;
    size_t a_size_;


    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    Array(size_t size)
    {
        array_= new Object*[size];
        a_size_ = size;
    }

    /**
     * Destructor for the array.
     */
    ~Array()
    {
        delete[] array_;
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        return a_size_;
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        a_size_ = a_size_ * 2;
        Object** temp = new Object*[a_size_];
        for(size_t i = 0; i < a_size_; ++i) {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(Object *obj) {
        size_t current_size = a_size_;
        allocate_space();
        array_[current_size] = obj;
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, Object *obj)
    {   
        if (index > a_size_) {
            exit(1);
        }
        if (index == a_size_) {
            allocate_space();
        }
        array_[index] = obj;
    
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    Object* remove(size_t index)
    {
        if (index >= a_size_) {
            exit(1);
        }
        if (array_[index]) {
            Object* result = array_[index];
            array_[index] = NULL;
            return result;
        }
        return NULL;
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    Object *get(size_t index)
    {
        if (index < a_size_) {
            return array_[index];
        }
        exit(1);
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        Array* o = dynamic_cast<Array*>(other);
        if (o) {
            size_t o_size = o->size();
            int counter = 0;
            while(counter < a_size_ && counter < o_size) {
                if (!array_[counter]->equals(o->array_[counter])) {
                    return false;
                }
                ++counter;
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        size_t result = 0;
        for (size_t counter = 0; counter < a_size_; ++counter) {
            result += array_[counter]->hash() * counter;
        }
        return result;
    }
};

/**
 *  IMPLEMENTATIONS OUTSIDE OF API DESIGN
 */ 

class StringArray : public Object
{
public:
    String** array_;
    size_t a_size_;


    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    StringArray(size_t size)
    {
        array_= new String*[size];
        a_size_ = size;
    }

    /**
     * Destructor for the array.
     */
    ~StringArray()
    {
        delete[] array_;
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        return a_size_;
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        a_size_ = a_size_ * 2;
        String** temp = new String*[a_size_];
        for(size_t i = 0; i < a_size_; ++i) {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(String *obj) {
        size_t current_size = a_size_;
        allocate_space();
        array_[current_size] = obj;
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, String *obj)
    {   
        if (index > a_size_) {
            exit(1);
        }
        if (index == a_size_) {
            allocate_space();
        }
        array_[index] = obj;
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    String* remove(size_t index)
    {
        if (index >= a_size_) {
            exit(1);
        }
        if (array_[index]) {
            String* result = array_[index];
            array_[index] = NULL;
            return result;
        }
        return NULL;
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    String *get(size_t index)
    {
        if (index < a_size_) {
            return array_[index];
        }
        exit(1);
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        StringArray* o = dynamic_cast<StringArray*>(other);
        if (o) {
            size_t o_size = o->size();
            int counter = 0;
            while(counter < a_size_ && counter < o_size) {
                if (!array_[counter]->equals(o->array_[counter])) {
                    return false;
                }
                ++counter;
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        size_t result = 0;
        for (size_t counter = 0; counter < a_size_; ++counter) {
            result += array_[counter]->hash() * counter;
        }
        return result;
    }
};

class IntArray : public Object
{
public:
    int* array_;
    size_t a_size_;


    /**
     * Builds an IntArray of the given size.
     * 
     * @arg size  the size of the IntArray
     */
    IntArray(size_t size)
    {
        array_= new int[size];
        a_size_ = size;
    }

    /**
     * Destructor for the IntArray.
     */
    ~IntArray()
    {
        delete[] array_;
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        return a_size_;
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        a_size_ = a_size_ * 2;
        int* temp = new int[a_size_];
        for(size_t i = 0; i < a_size_; ++i) {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(int obj) {
        size_t current_size = a_size_;
        allocate_space();
        array_[current_size] = obj;
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, int obj)
    {   
        if (index > a_size_) {
            exit(1);
        }
        if (index == a_size_) {
            allocate_space();
        }
        array_[index] = obj;
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    int remove(size_t index)
    {
        if (array_[index]) {
            int result = array_[index];
            array_[index] = nullptr;
            return result;
        }
        return NULL;
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    int get(size_t index)
    {
        if (index >= a_size_) {
            exit(1);
        }
        return array_[index];
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        IntArray* o = dynamic_cast<IntArray*>(other);
        if (o) {
            size_t o_size = o->size();
            size_t counter = 0;
            while(counter < a_size_ && counter < o_size) {
                printf("%d, %d\n", this->array_[counter], o->get(counter));
                if (this->array_[counter] != o->array_[counter]) {
                    return false;
                }
                ++counter;
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        size_t result = 0;
        for (size_t counter = 0; counter < a_size_; ++counter) {
            result += array_[counter] * counter;
        }
        return result;
    }
};

class FloatArray : public Object
{
public:
    float* array_;
    size_t a_size_;


    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    FloatArray(size_t size)
    {
        array_= new float[size];
        a_size_ = size;
    }

    /**
     * Destructor for the array.
     */
    ~FloatArray()
    {
        delete[] array_;
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        return a_size_;
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        a_size_ = a_size_ * 2;
        float* temp = new float[a_size_];
        for(size_t i = 0; i < a_size_; ++i) {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(float obj) {
        size_t current_size = a_size_;
        allocate_space();
        array_[current_size] = obj;
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, float obj)
    {   
        if (index > a_size_) {
            exit(1);
        }
        if (index == a_size_) {
            allocate_space();
        }
        array_[index] = obj;
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    float remove(size_t index)
    {
        if (array_[index]) {
            float result = array_[index];
            array_[index] = NULL;
            return result;
        }
        return NULL;
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
     float get(size_t index)
    {
        if (index < a_size_) {
            return array_[index];
        }
        exit(1);
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        FloatArray* o = dynamic_cast<FloatArray*>(other);
        if (o) {
            size_t o_size = o->size();
            int counter = 0;
            while(counter < a_size_ && counter < o_size) {
                if (array_[counter] != o->array_[counter]) {
                    return false;
                }
                ++counter;
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        size_t result = 0;
        for (size_t counter = 0; counter < a_size_; ++counter) {
            result += array_[counter] * counter;
        }
        return result;
    }
};

class BoolArray : public Object
{
public:
    bool* array_;
    size_t a_size_;


    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    BoolArray(size_t size)
    {
        array_= new bool[size];
        a_size_ = size;
    }

    /**
     * Destructor for the array.
     */
    ~BoolArray()
    {
        delete[] array_;
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        return a_size_;
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        a_size_ = a_size_ * 2;
        bool* temp = new bool[a_size_];
        for(size_t i = 0; i < a_size_; ++i) {
            temp[i] = array_[i];
        }
        delete[] array_;
        array_ = temp;
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(bool obj) {
        size_t current_size = a_size_;
        allocate_space();
        array_[current_size] = obj;
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, bool obj)
    {   
        if (index > a_size_) {
            exit(1);
        }
        if (index == a_size_) {
            allocate_space();
        }
        array_[index] = obj;
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    bool remove(size_t index)
    {
        if (array_[index]) {
            bool result = array_[index];
            array_[index] = nullptr;
            return result;
        }
        return NULL;
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    bool get(size_t index)
    {
        if (index < a_size_) {
            return array_[index];
        }
        exit(1);
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        BoolArray* o = dynamic_cast<BoolArray*>(other);
        if (o) {
            size_t o_size = o->size();
            int counter = 0;
            while(counter < a_size_ && counter < o_size) {
                if (array_[counter] != o->array_[counter]) {
                    return false;
                }
                ++counter;
            }
            return true;
        } else {
            return false;
        }
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        size_t result = 0;
        for (size_t counter = 0; counter < a_size_; ++counter) {
            result += array_[counter] * counter;
        }
        return result;
    }
};