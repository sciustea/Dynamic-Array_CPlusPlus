// Stefana Ciustea
// Dynamic Arrays

// this code defines a template class named DynamicArray
/* this class is created to be able to represent a dynamic 
array(resizable array) which can contain elements of any 
data type, which T, the template parameter, specifies */

#include <iostream>

template <class T>
class DynamicArray
{
	public:
		/* Constructor: the class contains a constructor dynamically allocates an array
		of the T type by t*/
		DynamicArray(int size) : m_data(new T[size]), m_size(size), m_firstEmptyElement(0), m_usedElements(0)
		{
		}

		/* Destructor: deallocates the dynamically allocated array */
		~DynamicArray()
		{
			delete[] m_data;
		}

		/* Adds one element of T type to our dynamic array */
		void add(T data)
		{
			try
			{
				// Checks if there's space in our array
				if (m_firstEmptyElement < m_size)
				{
					m_data[m_firstEmptyElement] = data;
					m_firstEmptyElement++;
					m_usedElements++; // add 1 to m_usedElements for every element added
				}
				else
				{
					throw m_firstEmptyElement;
				}
			}
			catch (int m_firstEmptyElement)
			{
				std::cout << "Index " << m_firstEmptyElement << " is out of bounds." << std::endl;
			}
		}

		// Removes an element from our dynamic array by using index
		void removeByElement(int index)
		{
			try
			{
				if (index < m_size)
				{
					// shifts all elements to the left to fill the gap in the array
					for (int i = index; i < m_usedElements - 1; ++i)
					{
						m_data[i] = m_data[i + 1];
					}
					m_usedElements--;

					// resizes the array once its been checked if it's too large
					decreaseArraySize();
				}
				else
				{
					throw index;
				}
			}
			catch (int index)
			{
				std::cout << "Index " << index << " is out of bounds." << std::endl;
			}
		}

		// Gets an element from our dynamic array by using index
		T getByElement(int index)
		{
			try
			{
				if (index < m_size)
				{
					return m_data[index];
				}
				else
				{
					throw index;
				}
			}
			catch (int index)
			{
				std::cout << "Index " << index << " is out of bounds." << std::endl;
			}

		}

		// Increases our array's size when it's utilized a fair amount
		void increaseArraySize()
		{
			if (m_usedElements >= m_size * 0.85)
			{
				int newSize = m_size * 2;
				T* newArray = new T[newSize];

				for (int i = 0; i < m_usedElements; ++i)
				{
					newArray[i] = m_data[i];
				}

				delete[] m_data;
				m_data = newArray;
				m_size = newSize;
			}
		}

		// Decreases our array's size when it's not utilized a fair amount
		void decreaseArraySize()
		{
			if (m_usedElements < m_size * 0.2 && m_size > 12)
			{
				int newSize = std::max(m_size / 2, 12);
				T* newArray = new T[newSize];

				for (int i = 0; i < m_usedElements; ++i)
				{
					newArray[i] = m_data[i];
				}

				delete[] m_data;
				m_data = newArray;
				m_size = newSize;
			}
		}

	private:
		T* m_data;
		int m_size;
		int m_firstEmptyElement;
		int m_usedElements; // added this variable to keep track of number of elements in use, in order to resize the array properly
};

/* 
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
*/
