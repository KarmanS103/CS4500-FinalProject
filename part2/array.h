#pragma once
#include "object.h"
#include "string.h"
#include <stdlib.h>
#include <math.h>

/**
 * Array: this class represents an array of Objects or Strings
 * 
 * authors: singh.kar@husky.neu.edu and haiber.ow@husky.neu.edu
 */
class Array : public Object
{
public:
    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    Array(size_t size)
    {

    }

    /**
     * Destructor for the array.
     */
    ~Array()
    {

    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {

    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {

    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(Object *obj) {

    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, Object *obj)
    {   
    
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    Object* remove(size_t index)
    {
    
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    Object *get(size_t index)
    {
   
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
    
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        
    }
};

/**
 *  IMPLEMENTATIONS OUTSIDE OF API DESIGN
 */ 

class StringArray : public Object
{
public:

    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    StringArray(size_t size)
    {
       
    }

    /**
     * Destructor for the array.
     */
    ~StringArray()
    {
       
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
        
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {

    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(String *obj) {

    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, String *obj)
    {   
        
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    String* remove(size_t index)
    {
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    String *get(size_t index)
    {
        
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
        
    }
};

class IntArray : public Object
{
public:
    


    /**
     * Builds an IntArray of the given size.
     * 
     * @arg size  the size of the IntArray
     */
    IntArray(size_t size)
    {
        
    }

    /**
     * Destructor for the IntArray.
     */
    ~IntArray()
    {
    
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
   
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
    
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(int obj) {
    
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, int obj)
    {   
        
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    int remove(size_t index)
    {
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    int get(size_t index)
    {
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
    }
};

class FloatArray : public Object
{
public:


    /**
     * Builds an array of the given size.
     * 
     * @arg size  the size of the array
     */
    FloatArray(size_t size)
    {
    }

    /**
     * Destructor for the array.
     */
    ~FloatArray()
    {
        
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
    
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
        
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(float obj) {
        
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, float obj)
    {   
    
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    float remove(size_t index)
    {
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    float get(size_t index)
    {
        
    }

    /**
     * Checks to see if two floats are close by some arbitrary small epsilon
     */

    bool fequals_(float a, float b) {
	    
    }  

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
        
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {

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
    }

    /**
     * Destructor for the array.
     */
    ~BoolArray()
    {
    
    }

    /**
     * Returns the total size of the array. 
     */
    size_t size()
    {
    
    }

    /**
     * Allocates space to allow for growth
     */
    void allocate_space() {
    
    }

    /**
     * Appends the object at the end of the array, making it grow
     */
    void pushback(bool obj) {
    }

    /**
     * Adds the given Object to the array at the given index.
     * 
     * @arg index  the index where the object will be added
     * @arg obj  the Object being added to the array
     */
    void add(size_t index, bool obj)
    {   
    } 

    /**
     * Removes the Object at the given index.
     * 
     * @arg index  the index of the Object being removed
     */
    bool remove(size_t index)
    {
        
    }

    /**
     * Returns the Object at the given index.
     * 
     * @arg index  the index of the Object being returned
     */
    bool get(size_t index)
    {
    }

    /**
     * Checks to see if this array is equal to that one.
     * 
     * @arg other  the second array being compared to this one
     */
    bool equals(Object *other)
    {
    }

    /**
     * Returns the hash value for this Array.
     */
    size_t hash()
    {
    }
};