template <typename T>
Array<T>::Array()
{
    size = 0;
    array = new T[0];
}

template <typename T>
Array<T>::Array(const unsigned int n)
{
    size = n;
    array = new T[n];
    for (unsigned int i = 0; i < n ; i++)
        array[i] = T();
}

template <typename T>
Array<T>::Array(const Array& other): array(NULL)
{
    *this = other;
}


template <typename T>
Array<T>&   Array<T>::operator=(const Array& other)
{
    if (this != &other)
    {
        size = other.size;
        if (array)
            delete[] array;
        array = new T[size];
        for (unsigned int i = 0; i < size ; i++)
            array[i] = other.array[i];
    }
    return (*this);
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}

template <typename T>
T&  Array<T>::operator[](int index)
{
    if (index < 0 || (unsigned int)index >= size)
        throw   std::out_of_range("index out of range");
    return (array[index]);
}

template <typename T>
const T&  Array<T>::operator[](int index) const
{
    if (index < 0 || index >= size)
        throw   std::out_of_range("index out of range");
    return (array[index]);
}

template <typename T>
const unsigned int&   Array<T>::getSize() const
{
    return (size);
}
