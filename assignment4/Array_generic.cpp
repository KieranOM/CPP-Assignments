template<typename T>
class Array {

private:
    unsigned int array_size;        // Number of elements in Array
    unsigned int array_capacity;    // Capacity of Array
    T *buffer;                      // Buffer where elements are stored


public:
    typedef T *iterator;            // used to access elements of Array

    Array<T>();                     // default constructor
    Array<T>(unsigned int capacity);

    Array<T>(const Array<T> &);     // Copy constructor

    ~Array<T>();

    unsigned int capacity();        // Returns capacity of Array
    unsigned int size();            // Returns number of elements in Array
    iterator begin();               // Returns start of Array
    iterator end();                 // Returns end of Array
    T &front();                     // Front element
    T &back();                      // End element
    void push_back(const T &value);     // Inserts new element in the end
    void pop_back();                    // Pop end element and decrement array_size

    void reserve(unsigned int capacity);    // Used to modify capacity of Array
    void resize(unsigned int size);         // Used to resize array

    T &operator[](unsigned int index);      // Overloaded [] for array-like access
    Array<T> &operator=(const Array<T> &);  // Overloaded assignment operator; You need to define this operator
    void insert(unsigned int position, T value);    // Inserts an element with 'value' in the 'begin()+position' index
    void clear();                                   // Clears Array
};

template<typename T>
Array<T>::Array() {
    array_capacity = 0;
    array_size = 0;
    buffer = 0;
}

template<typename T>
Array<T>::Array(unsigned int capacity) {
    array_capacity = capacity;
    array_size = 0;
    buffer = new T[capacity];
}

template<typename T>
Array<T>::Array(const Array<T> &v) {
    // Copy size and capacity
    array_size = v.array_size;
    array_capacity = v.array_capacity;
    // Copy values over
    buffer = new T[array_capacity];
    for (unsigned int i = 0; i < array_size; ++i)
        buffer[i] = v.buffer[i];
}

/* 
 * You need to define assignment operator in Array_generic.cpp.
*/
template<typename T>
Array<T> &Array<T>::operator=(const Array<T> &v) {
    // If it's not possible to fit v's elements in here
    if (array_capacity < v.array_size) {
        // Make a new buffer of the required size, setting capacity to the number of elements needed
        delete[] buffer;
        buffer = new T[array_capacity = v.array_size];
    }
    // Copy the size and elements over
    array_size = v.array_size;
    for (unsigned int i = 0; i < array_size; ++i)
        buffer[i] = v.buffer[i];

    return *this;
}


/* 
 * array-like selection operator '[]'
 * E.g. Array A;  A[n-1] returns the n th element from the front. 
*/
template<typename T>
T &Array<T>::operator[](unsigned int index) {
    return buffer[index];
}

template<typename T>
typename Array<T>::iterator Array<T>::begin() {
    return buffer;
}

template<typename T>
typename Array<T>::iterator Array<T>::end() {
    return buffer + size();
}

template<typename T>
T &Array<T>::front() {
    return buffer[0];
}

template<typename T>
T &Array<T>::back() {
    return buffer[array_size - 1];
}

template<typename T>
void Array<T>::push_back(const T &v) {
    if (array_size >= array_capacity)
        reserve(array_capacity + 10);
    buffer[array_size++] = v;
}

template<typename T>
void Array<T>::pop_back() {
    array_size--;
}

template<typename T>
void Array<T>::reserve(unsigned int capacity) {
    // If the capacity is already the same as the current capacity, there's no need to do anything
    if (capacity == array_capacity)
        return;
    else if (buffer == 0) {
        array_size = 0;
        array_capacity = 0;
    }
    T *Newbuffer = new T[capacity];
    unsigned int new_Size = capacity < array_size ? capacity : array_size;

    for (unsigned int i = 0; i < new_Size; i++)
        Newbuffer[i] = buffer[i];

    array_capacity = capacity;
    delete[] buffer;
    buffer = Newbuffer;
}

template<typename T>
unsigned int Array<T>::size() {
    return array_size;
}

template<typename T>
void Array<T>::resize(unsigned int size) {
    reserve(size);
    array_size = size;
}

template<typename T>
unsigned int Array<T>::capacity() {
    return array_capacity;
}

/* You need to define this function in Array_generic.cpp.
 * Inserts an element with 'value' in the 'begin()+position' index.
 * E.g. Existing Array A={1,3,9,12}. 
 * After insert(2,7) it becomes A={1,3,7,9,12}. 	
*/
template<typename T>
void Array<T>::insert(unsigned int position, T value) {
    // Check if this would leave empty elements
    if (position > array_size)
        return;
    // Reserve more space if it has run out
    if (array_size >= array_capacity)
        reserve(array_capacity + 10);
    // Shift all elements up 1, increasing size
    for (unsigned int i = array_size++; i > position; --i)
        buffer[i] = buffer[i - 1];
    // Insert at the correct position and increase size due to new element
    buffer[position] = value;
}

template<typename T>
void Array<T>::clear() {
    array_capacity = 0;
    array_size = 0;
    // Delete the elements, replace the pointer with null
    delete[] buffer;
    buffer = 0;
}

template<typename T>
Array<T>::~Array() {
    delete[] buffer;
}


