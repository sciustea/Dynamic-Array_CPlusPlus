# Dynamic-Array_CPlusPlus


This code defines a template class named DynamicArray.

This class is created to be able to represent a dynamic 
array(resizable array) which can contain elements of any 
data type, which T, the template parameter, specifies.

------------------------------------------------------------------------------------------------------------------------------------

Q: When you increased the size of the array, how much did you increase it by and why did you choose to increase it by that amount?
A: For the increaseArraySize() method, I doubled the size of the array when it was almost full (85% full, 0.85 in decimal). 
   When inserting an element while the array isn't full, the insertion operation is usually very fast. 
   Once the array is full, a resizing operation begins, which is more time-consuming.
   However, despite the occasional additional time cost for resizing the array, over many insertions, 
   the average time per individual insertion remains constant because resizing happens infrequently. 
   Therefore, I thought it's best to double the array for efficiency purposes.
* 
Q: When you decreased the size of the array, how much did you decrease it by and why did you choose to decrease it by that amount?
A: For the decreaseArraySize() method, I decreased the array size if it was utilized less than 20% (0.2 in decimal). 
   Also, I set a constraint of minimum size of 12 elements to make sure the array doesn't become too small. 
   I did this in order to prevent resizing the array often, in order to help save memory.
