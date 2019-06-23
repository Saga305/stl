#include <iostream>
#include <limits>

using namespace std;
/*
 * @func :: Overload the global new operator to allocate a clean memory.
 */
void* operator new(size_t size) {
	char * p = (char *) malloc(size);
	for (size_t index = 0; index < size; index++) {
		p[index] = '\0';
	}
	return (void *) p;
}
/*
 * STL vector class implementation.
 * It is templated version.
 */
template<typename T>
class vector {
private:
	T* _elements;
	int _size;   //number of _elements pushed into the vector
	int _reservedSize; //vector array _size

public:

	/*
	 * @func: used to create vector object with the default values.
	 */
	vector() :
			_elements(nullptr), _size(0), _reservedSize(0) {
	}

	/*
	 * @func: used to create the vector object.
	 */
	vector(int n, int value = 0) :
			_elements(new T[n]), _size(0), _reservedSize(n) {
		for (int index = 0; index < _reservedSize; index++) {
			_elements[index] = value;
		}
	}

	/*
	 * @func: print all the elements values of the vector array.
	 */
	void print() {
		for (int index = 0; index < _reservedSize; index++) {
			cout << _elements[index] << " ";
		}
		cout << endl;
	}

	/*
	 * @func: used to delete the heap allocated memory.
	 */
	~vector() {
		delete[] _elements;
	}

	/*
	 * @func: Returns the number of elements in the vector.
	 */
	int size() const {
		return _size;
	}

	/*
	 * @func:  Returns the size of the storage space currently allocated to the vector expressed as number of elements.
	 */
	int capacity() const {
		return _reservedSize;
	}

	/*
	 * @func: Resizes the container so that it contains ‘n’ elements.
	 */
	void resize(int n, T val = T()) {
		reserve(n);

		for (int index = _size; index < n; ++index)
		{
			_elements[index] = val;
		}

		_size = n;
	}

	/*
	 * @func: Requests that the vector capacity be at least enough to contain n elements.
	 */
	void reserve(int newalloc) {
		if (newalloc <= _reservedSize) {
			return;
		}

		T* p = new T[newalloc];

		for (int index = 0; index < _size; ++index)
			p[index] = _elements[index];

		delete[] _elements;

		_elements = p;

		_reservedSize = newalloc;
	}

	/*
	 * @func: It push the elements into a vector from the back.
	 */
	void push_back(T ele) {
		if (_reservedSize == 0)
			reserve(1);
		else if (_size == _reservedSize)
			reserve(2 * _reservedSize);

		_elements[_size] = ele;

		++_size;
	}

	/*
	 * @func: used to achieve the deep copy.
	 */
	vector(const vector<T>& v):_size(v._size), _elements(new T[v._size]) {

		for (int index = 0; index < v.size(); index++) {
			_elements[index] = v._elements[index];
		}
		_reservedSize = v.size();
	}

	/*
	 * @func: assignment operator overloaded.
	 */
	vector<T>& operator=(const vector<T>& v) {
		//avoid self assignment.
		if (this != &v)
		{
			return *this;
		}

		if(_reservedSize >= v.size())
		{
			for (int index = 0; index < v._size; ++index)
			{
				_elements[index] = v._elements[index];
				_size = v._size;
			}
			return *this;
		}

		T* temp = _elements;
		_elements = new T[v.size()];
		for (int index = 0; index < v.size(); index++) {
			_elements[index] = v._elements[index];
		}
		_size = v.size();
		_reservedSize = v.size();
		delete[] temp;
		return *this;
	}

	class Iterator {
	private:
		T* current;
	public:
		Iterator(T* ptr) {
			current = ptr;
		}

		bool operator!=(const Iterator& it) {
			return current != it.current;
		}

		bool operator==(const Iterator& it) {
			return current == it.current;
		}

		T& operator*() {
			return *current;
		}

		T& operator++() {
			current++;
			return *this;
		}

		T operator++(int unused) {
			(void) unused;
			T* temp = current;
			current++;
			return *temp;
		}
	};

	class reverse_Iterator {
	private:
		T* current;
	public:
		reverse_Iterator(T* ptr) {
			current = ptr;
		}

		bool operator!=(const reverse_Iterator& it) {
			return current != it.current;
		}

		bool operator==(const reverse_Iterator& it) {
			return current == it.current;
		}

		T& operator*() {
			return *current;
		}

		T& operator++() {
			current--;
			return *this;
		}

		T operator++(int unused) {
			(void) unused;
			T* temp = current;
			current--;
			return *temp;
		}
	};

	/*
	 * @func: Returns an Iterator pointing to the first element in the vector
	 */
	Iterator begin() {
		return Iterator(_elements);
	}

	/*
	 * @func: Returns a reverse Iterator pointing to the last element in the vector (reverse beginning). It moves from last to first element
	 */
	reverse_Iterator rbegin() {
		return reverse_Iterator(_elements + _size - 1);
	}

	/*
	 * @func: Returns an Iterator pointing to the theoretical element that follows the last element in the vector
	 */
	Iterator end() {
		return Iterator(_elements + _size);
	}

	/*
	 * @func: Returns a reverse Iterator pointing to the theoretical element preceding the first element in the vector (considered as reverse end)
	 */
	reverse_Iterator rend() {
		return reverse_Iterator(_elements - 1);
	}

	/*
	 * @func: Returns a reference to the element at position ‘i’ in the vector
	 */
	T& operator[](int i) {
		return _elements[i];
	}

	/*
	 * @func: Returns a reference to the element at position ‘i’ in the vector
	 */
	T& at(int i) {
		return _elements[i];
	}

	/*
	 * @func: Returns whether the container is empty.
	 */
	bool empty() {
		return _size == 0;
	}

	/*
	 * @func: Returns the maximum number of elements that can be held by the vector container.
	 */
	size_t max_size() const {
		return (std::numeric_limits<size_t>::max() / sizeof(T));
	}

	/*
	 * @func: Reduces the capacity of the container to fit its size and destroys all elements beyond the capacity.
	 */
	void shrink_to_fit()
	{
		T* p = new T[size()];

		for(int index=0; index < size(); index++)
		{
			p[index] = _elements[index];
		}

		delete[] _elements;
		_elements = p;
		_reservedSize = size();
		p = nullptr;
	}

};

int main() {

	vector<int> vec;

	// 5 elements are inserted
	// in the vector
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3);
	vec.push_back(4);
	vec.push_back(5);

	cout<<"vec.size() "<<vec.size()<<"\n"<<"vec.capacity()"<<vec.capacity()<<endl;

	vec.shrink_to_fit();

	cout<<"vec.size() "<<vec.size()<<"\n"<<"vec.capacity()"<<vec.capacity()<<endl;

	cout << "Contents of vector before resizing:" << endl;

	// displaying the contents of the
	// vector before resizing
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";

	cout << endl;



}
