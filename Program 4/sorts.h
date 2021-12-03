/* Creating and sorting a vector 
* Implementing sort functions 
* demonstrating the cost of O(n^2) v. O(n logn) algorithm 
*/

#ifndef SORTS_H_
#define SORTS_H_
#include <iostream> 
#include <vector> 
#include <string> 
//#include <windows.h> 
using namespace std; 

/* BUBBLE SORT
Worst case: O(n^2)
Average case: O(n^2)
*/
void BubbleSort(vector<int>& items, int first, int last)
{
    for (int i = first; i < last; i++)
    {
        for (int j = first; j < last; j++)
        {
            if (items[j] > items[j+1])
            {
                swap(items[j], items[j+1]);
            }
        }
    }
}

/* INSERTION SORT
Worst case: O(n^2)
Average case: O(n^2)
*/
void InsertionSort(vector<int>& items, int first, int last)  
{
    for (int place = first; place <= last; place++)
    {
        int temp = items[place];
        int i = place;

        while ((i > first) && (items[i - 1] > temp))
        {
            items[i] = items[i - 1];
            i--;
        }

        items[i] = temp;
    }
}

/* MERGE SORT 
Worst case: O(n log n)
Average case: O(n log n)
*/
void Merge(vector<int>& vec, int first, int mid, int last)
{
    //size of the vector 
    int size = last - first + 1;
    //temp array - extra memory
    int* tmp_arr;
    tmp_arr = new int[size];
    //first half
    int first1 = first;
    int last1 = mid;
    //second half
    int first2 = mid + 1;
    int last2 = last;
    //tracking index 
    int index = 0;
    //Sorting and Merging 
    while ((first1 <= last1) && (first2 <= last2))
    {
        if (vec[first1] < vec[first2])
        {
        tmp_arr[index] = vec[first1];
        first1++;
        }
        else
        {
        tmp_arr[index] = vec[first2];
        first2++;
        }
        index++;
    }
    
    while (first1 <= last1)
    {
        tmp_arr[index] = vec[first1];
        first1++;
        index++;
    }
    while (first2 <= last2)
    {
        tmp_arr[index] = vec[first2];
        first2++;
        index++;
    }
    for (index = 0; index < size; index++)
    {
        vec[first] = tmp_arr[index];
        first++;
    }
    delete[] tmp_arr;
}

void MergeSort(vector<int>& items, int first, int last)
{
    if (first < last)
    {
        //find mid 
        int mid = (first + last) / 2;
        //first half 
        MergeSort(items, first, mid);
        //second half
        MergeSort(items, mid + 1, last);
        Merge(items, first, mid, last);
    }
}

/* ITERATIVE MERGE SORT
* merge data from the original vector into 
* the additional vector and alternatively copy back and forth 
* between the original and the additional temporary vector. 

Worst case: O(n log n)
Average case: O(n log n)
*/
void IterativeMerge(vector<int>& vec, vector<int>& temp, int first, int mid, int last)
{
    //Assign to temp vector 
    for (int i = first; i <= last; i++)
    {
        temp[i] = vec[i];
    }

    //merge 
    int i = first;
    int j = mid + 1;

    for (int k = first; k <= last; k++)
    {
        if (i > mid)
        {
            vec[k] = temp[j];
            j++;
        }
        else if (j > last)
        {
            vec[k] = temp[i];
            i++;
        }
        else if (temp[j] < temp[i])
        {
            vec[k] = temp[j];
            j++;
        }
        else
        {
            vec[k] = temp[i];
            i++;
        }
    }
}

void IterativeMergeSort(vector<int>& vec, int first, int last)
{
    //temp vector same size as original vector
    vector<int> temp(vec.size());
    for (int i = 1; i <= last + 1; i *= 2)
    {
        for (int low = first; low < last + 1 - i; low += i + i)
        {
            int mid = low + i - 1;
            int high = min(low + i + i - 1, last);
            IterativeMerge(vec, temp, low, mid, high);
        }
    }
}

/* QUICK SORT 
Worst case: O(n^2)
Average case: O(n log n)
*/
void QuickSort(vector<int>& vec, int first, int last)
{
    if ((last - first) < 5)
    {
        InsertionSort(vec, first, last);
        return;
    }
    //Sort first, mid, last elements
    int mid = (first + last) / 2;
    if (vec[first] > vec[last])
    {
        swap(vec[first], vec[last]);
    }
    if (vec[first] > vec[mid])
    {
        swap(vec[first], vec[mid]);
    }
    if (vec[mid] > vec[last])
    {
        swap(vec[mid], vec[last]);
    }
    //pivot is median 
    int pivot = vec[mid];
    swap(vec[mid], vec[last - 1]);
    //left and right index 
    int left = first + 1;
    int right = last - 2;
    bool done = false;

    while (!done)
    {
        while (vec[left] < pivot)
        {
            left++;
        }
        while (vec[right] > pivot)
        {
            right--;
        }

        //check if right and left cross 
        if (right > left)
        {
            swap(vec[left], vec[right]);
            right--;
            left++;
        }
        else
        {
            done = true;
        }
    }
    //place pivot back in correct position
    swap(vec[left], vec[last - 1]);
    //Recursively sort both sides
    QuickSort(vec, first, left - 1);
    QuickSort(vec, left + 1, last);
}

/* SHELL SORT 
Worst case: O(n^2)
Average case: O(n^(3/2))
*/
void ShellSort(vector<int>& items, int first, int last)
{
    //size
    int size = last - first + 1;

    //In shell sort, we will sort by getting the gap between each elements
    for (int gap = size / 2; gap > 0; gap /= 2)
    {
        //do Insertion sort for this gap 
        for (int i = gap; i < size; i++)
        {
            int temp = items[i];
            int j;
             for (j = i; j >= gap && items[j - gap] > temp; j -= gap)
            {
                items[j] = items[j - gap];
                
            }
            items[j] = temp;
        }
    }
}


#endif 