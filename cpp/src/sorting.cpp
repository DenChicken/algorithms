#include "../include/sorting.h"

#include <algorithm>

namespace algs
{
    void bubble_sort(int* arr, int size)
    {
        for (int i = 0; i < size - 1; ++i)
        {
            for (int j = i; j < size; ++j)
            {
                if (arr[i] > arr[j])
                {
                    std::swap(arr[i], arr[j]);
                }
            }
        }
    }

    void qsort(int* arr, int size)
    {
        if (size <= 1)
        {
            return;
        }

        int l = 0;
        int r = size - 1;
        int mid = arr[size / 2];

        do
        {
            while (arr[l] < mid)
            {
                ++l;
            }
            while (arr[r] > mid)
            {
                --r;
            }
            if (l <= r)
            {
                std::swap(arr[l++], arr[r--]);
            }
        } while (l <= r);

        qsort(arr, r + 1);
        qsort(&arr[l], size - l);
    }


    void merge(int* arr, int mid, int size)
    {
        if (size <= 1)
        {
            return;
        }

        int* temp = new int[size];
        int l = 0;
        int r = mid;

        int total = 0;

        while (l < mid && r < size)
        {
            if (arr[l] < arr[r])
            {
                temp[total++] = arr[l++];
            }
            else
            {
                temp[total++] = arr[r++];
            }
        }

        if (r == size)
        {
            memcpy(&temp[total], &arr[l], sizeof(int) * (mid - l));
        }
        else
        {
            memcpy(&temp[total], &arr[r], sizeof(int) * (size - r));
        }

        memcpy(arr, temp, size * sizeof(int));

        delete[] temp;
    }

    void merge_sort(int* arr, int size)
    {
        if (size <= 1)
        {
            return;
        }

        int mid = (size) >> 1;

        merge_sort(arr, mid);
        merge_sort(&arr[mid], size - mid);
        merge(arr, mid, size);
    }

} // algs
