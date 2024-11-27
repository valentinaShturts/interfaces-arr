#pragma once
#include <iostream>

using namespace std;

struct IOutput 
{
	virtual void Show() = 0;
	virtual void Show(const string& info) = 0;
};

struct IMath
{
    virtual int Max() = 0;
    virtual int Min() = 0;
    virtual float Avg() = 0;
    virtual bool Search(int valueToSearch) = 0;
};

struct ISort
{
    virtual void SortAsc() = 0;
    virtual void SortDesc() = 0;
    virtual void SortByParam(bool isAsc) = 0;
};

class Array : public IOutput, public IMath, public ISort
{
private:
    int* array; 
    int size;
public:
    Array(int* arr, int s) 
    {
        size = s;
        array = new int[size]; 
        for (int i = 0; i < size; i++) 
        {
            array[i] = arr[i];
        }
    }

    ~Array() 
    {
        delete[]array;
    }

    void Show()  
    {
        for (int i = 0; i < size; i++) 
        {
            cout << array[i] << " ";
        }
        cout << endl;
    }

    void Show(const string& info)  
    {
        cout << info << endl;
        Show();
    }

    int Max()  
    {
        int max = INT_MIN;
        for (int i = 0; i < size; i++) 
        {
            if (array[i] > max) 
            {
                max = array[i];
            }
        }
        return max;
    }

    int Min() 
    {
        int min = INT_MAX;
        for (int i = 0; i < size; i++)
        {
            if (array[i] < min)
            {
                min = array[i];
            }
        }
        return min;
    }

    float Avg()  
    {
        if (size == 0) return 0;

        int sum = 0;
        for (int i = 0; i < size; i++) 
        {
            sum += array[i];
        }
        float  avg = static_cast<float> (sum) / size;
        return avg;
    }

    bool Search(int valueToSearch)  
    {
        for (int i = 0; i < size; i++) 
        {
            if (array[i] == valueToSearch) 
            {
                return true;
            }
        }
        return false;
    }

    void SortAsc()  
    {
        for (int i = 0; i < size - 1; i++) 
        {
            for (int j = 0; j < size - i - 1; j++) 
            {
                if (array[j] > array[j + 1]) 
                {
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void SortDesc()  
    {
        for (int i = 0; i < size - 1; i++)
        {
            for (int j = 0; j < size - i - 1; j++)
            {
                if (array[j] < array[j + 1])
                {
                    swap(array[j], array[j + 1]);
                }
            }
        }
    }

    void SortByParam(bool isAsc)  
    {
        if (isAsc) SortAsc();
        else 
        {
            SortDesc();
        }
    }
};