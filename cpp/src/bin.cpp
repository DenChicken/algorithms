#include "../include/bin.h"

namespace algs
{
    int lbinsearch(int* arr, int size, int val)
    {
        if (size < 2)
        {
            if ((size == 1) && (arr[0] == val))
            {
                return 0;
            }

            return -1;
        }
        else if ((arr[size - 1] == val) && (arr[size - 2] < val))
        {
            return (size - 1);
        }

        int l = 0;
        int r = size - 1;
        int m = 0;

        while (l < r) {
            m = (l + r) >> 1;

            if (arr[m] >= val)
            {
                r = m;
            }
            else
            {
                l = m + 1;
            }
        }

        return l;
    }


    int rbinsearch(int* arr, int size, int val)
    {
        if (size < 2)
        {
            if ((size == 1) && (arr[0] == val))
            {
                return 0;
            }

            return -1;
        }
        else if ((arr[size - 1] == val) && (arr[size - 2] < val))
        {
            return (size - 1);
        }

        int l = 0;
        int r = size - 1;
        int m = 0;

        while (l < r) {
            m = (l + r + 1) >> 1;

            if (arr[m] > val)
            {
                r = m - 1;
            }
            else
            {
                l = m;
            }
        }

        return l;
    }


} // algs