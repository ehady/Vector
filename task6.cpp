#include <iostream>
#include <stdexcept>

class Vector
{
    int capacity;
    int elements;
    int *mem;

public:
    Vector() : capacity(10), elements(0), mem(new int[capacity]) {}
    void push_back(int value)
    {
        if (elements == capacity)
        {
            int *new_mem = new int[capacity * 2];
            for (int i = 0; i < elements; i++)
            {
                new_mem[i] = mem[i];
            }
            delete[] mem;
            mem = new_mem;
            capacity *= 2;
        }
        mem[elements++] = value;
    }
    bool empty() const
    {
        return elements == 0;
    }
    void pop_back()
    {
        if (elements == 0)
            throw std::out_of_range("Vector is empty");
        elements--;
    }
    int back() const
    {
        if (elements == 0)
            throw std::out_of_range("Vector is empty");
        return mem[elements - 1];
    }

    ~Vector()
    {
        delete[] mem;
    }

    int &at(int x)
    {
        if (x < 0 || x >= elements)
            throw std::out_of_range("Index out of range");
        return mem[x];
    }

    int size() const
    {
        return elements;
    }

    int &operator[](int x)
    {
        return mem[x];
    }

    Vector(const Vector &original) : capacity(original.capacity),
                                     elements(original.elements),
                                     mem(new int[original.capacity])
    {
        for (int i = 0; i < elements; i++)
        {
            mem[i] = original.mem[i];
        }
    }

    Vector &operator=(Vector original)
    {

        if (this != &original)
        {
            if (this != nullptr)
                delete[] mem;
            capacity = original.capacity;
            elements = original.elements;
            mem = new int[original.capacity];
            for (int i = 0; i < elements; ++i)
            {
                mem[i] = original.mem[i];
            }
        }
        return *this;
        /* capacity = cpy.capacity;
        elements = cpy.elements;
        std::swap(mem, cpy.mem);
        return *this; */
    }

    Vector(int value) : capacity(10), elements(value), mem(new int[capacity]) {}

    Vector &operator+(Vector Vec)
    {
        elements = Vec.elements + this.elements;
        capacity = Vec.capacity + this.capacity;
        mem = new int[Vec.capacity + this.capacity];
        for (int i = 0; i < elements; ++i)
            {
                mem[i] = Vec.mem[i];
            }
    }

    void resize(int value) {
        int *new_mem = new int[value];
        delete[] mem;
        mem = new_mem;
        capacity = value;
    }
};

int main()
{
    Vector alpha;
    for (int i = 0; i < 10; i++)
    {
        alpha.push_back(i * i);
    }
    Vector beta;
    for (int i = 0; i < 10; i++)
    {
        beta.push_back(-i * i);
    }
    alpha = beta;
}