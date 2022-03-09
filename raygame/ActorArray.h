#pragma once
#include <exception>
class Actor;

template <typename T>
class DynamicArray
{
public:
	DynamicArray();
	~DynamicArray();

	void addItem(T item);

	void addItems(T item[], int size);

	bool removeItem(T item);

	void sortItems();

	T getItem(int index);

	int getLength() { return m_length; }

	/// <summary>
	/// Checks if the item is in the array
	/// </summary>
	/// <param name="item">A reference to the item to use to check</param>
	/// <returns>False if the item is not in the array</returns>
	bool contains(T item);

	T operator[](int index);

private:
	T* m_items;
	int m_length;
};

template<typename T>
inline DynamicArray<T>::DynamicArray()
{
	m_length = 0;
	m_items = nullptr;
}

template<typename T>
inline DynamicArray<T>::~DynamicArray()
{
}

template<typename T>
inline void DynamicArray<T>::addItem(T item)
{
	//Create a new array with a size one greater than our old array
	T* tempArray = new T[getLength() + 1];
	//Copy the values from the old array to the new array
	for (int i = 0; i < getLength(); i++)
	{
		tempArray[i] = m_items[i];
	}

	//Set the last value in the new array to be the actor we want to add
	tempArray[getLength()] = item;

	delete[] m_items;
	//Set old array to hold the values of the new array
	m_items = tempArray;
	m_length++;
}

template<typename T>
inline void DynamicArray<T>::addItems(T item[], int size)
{
	T* tempArray = new T[getLength() + size];

	int j = 0;
	for (int i = 0; i < getLength(); i++) {
		tempArray[j] = m_items[i];
		j++;
	}
	for (int i = 0; i < size; i++) {
		tempArray[j] = item[i];
		j++;
	}

	m_length += size;
	m_items = tempArray;
}

template<typename T>
inline bool DynamicArray<T>::removeItem(T item)
{
	//Check to see if the actor was null 
	if (!item || getLength() <= 0)
	{
		return false;
	}

	bool itemRemoved = false;
	//Create a new array with a size one less than our old array
	T* tempArray = new T[getLength() - 1];
	//Create a variable to access tempArray index  
	int j = 0;
	//Copy values from the old array to the new array  
	for (int i = 0; i < getLength(); i++)
	{
		if (item != m_items[i] || itemRemoved)
		{
			tempArray[j] = m_items[i];
			j++;
		}
		else
		{
			itemRemoved = true;
		}
	}
	//Set the old array to the new array  
	if (itemRemoved)
	{
		delete[] m_items;
		m_items = tempArray;
		m_length--;
	}
	//Return whether or not the removal was successful  
	return itemRemoved;
}

template<typename T>
inline void DynamicArray<T>::sortItems()
{
	T key;
	int j = 0;

	for (int i = 1; i < getLength(); i++)
	{
		key = m_items[i]; //Sets key to current index
		j = i - 1;//sets j to pervious index
		while (j >= 0 && m_items[j] > key)//While j is greater than oe equal to o and the value at j is greater than key
		{
			m_items[j + 1] = m_items[j];//Set array at the index of j + 1 to be the value at index of j
			j--;//Decrments
		}

		m_items[j + 1] = key;//Set array at the index of j+1 to be the key
	}
}

template<typename T>
inline T DynamicArray<T>::getItem(int index)
{
	//Return false if the index is out of bounds
	if (index < 0 || index >= getLength())
		return T();

	return m_items[index];
}

template<typename T>
inline bool DynamicArray<T>::contains(T value)
{
	//Iterate through item array
	for (int i = 0; i < m_length; i++)
	{
		//return the current item if it matches the argument
		if (m_items[i] == value)
			return true;
	}

	return false;
}

template<typename T>
inline T DynamicArray<T>::operator[](int index)
{
	if (index > 0 || index < getLength()) {
		return m_items[index];
	}

	throw std::exception("Index was outside the bounds of the array.");
}