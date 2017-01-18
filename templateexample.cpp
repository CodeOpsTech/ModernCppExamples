#include <iostream> 
#include <exception> 
using namespace std; 

struct not_found_exception : public std::exception 
{
	const char* what() 
	{
		return "Not Found Exception"; 
	}
};
 
template <class T>
class Array
{
public:
	T* array;
	int array_size;
	int alloc_size;

	// default constructor: by default initialize the members to zero 
	Array() : array(0), array_size(0), alloc_size(0)
	{ }

	~Array()
	{
		remove_all();
	}

	int size() const
	{
		return array_size;
	}
	
	void add(T t)
	{
		if(array_size == alloc_size)
		{
			T* temp;
			int new_alloc_size = (alloc_size == 0) ? 1 : (alloc_size * 2);
			temp = (T*) realloc (array, new_alloc_size * sizeof(T));
			if(temp == NULL)
				throw new std::bad_alloc; 
			alloc_size = new_alloc_size;
			array = temp;
		}
		array_size ++;
		set_at(array_size - 1, t);
	}

	void set_at(int index, T& t)
	{
		new(&array[index]) T(t);
	}

	void remove(T& t)
	{
		int index = find(t);
		if(index == -1)
			throw new not_found_exception; 
		return remove_at(index);
	}

	void remove_at(int index)
	{
		if(index != (array_size - 1))
		{
			array[index].~T();
			// explicitly call the destructor for the container member 
			memmove((void*)&array[index], (void*)&array[index + 1], (array_size - 

(index + 1)) * sizeof(T));
		}
		array_size--;
	}

	void remove_all()
	{
		if(array != NULL)
		{
			for(int i = 0; i < array_size; i++)
				array[i].~T();
			free(array);
			array = NULL;
		}
		array_size = 0;
		alloc_size = 0;
	}

	T operator[] (int index) const
	{
		// for accesses outside the array range and for negative indices, 
		// throw out_of_range exception 
		if((index > array_size) || (index < 0))
			throw new std::out_of_range("out of range"); 
		return array[index];
	}

	T* get_data() const // return pointer to base - raw data pointer 
	{
		return array;
	}

	int find(T& t) const
	{
		for(int i = 0; i < array_size; i++)
		{
			if(array[i] == t)
				return i;
		}
		return -1;  // not found
	}
};

int main()
{
	Array<int> books;
	books.add(10); 
	int size = books.size(); 
    	for(int i = 0; i < size; i++)
		std::cout<<books[i];
	return 0; 
}
