# Sorting-Algorithm-
University of Washington Bothell  
CSS 342: Data Structures, Algorithms, and Discrete Mathematics 
Program 4:  Sorting* *this lab was patterned after a lab by Munehiro Fukuda 
 
 
Purpose 
 
This lab will serve two purposes.  First, it will provide hands-on experience for utilizing many of 
the sorting algorithms we will introduce in the class.  Second, it will viscerally demonstrate the 
cost of O(n2) v. O(n logn) algorithms.  It will also clearly show that algorithms with the same 
complexity may have different running times. 
 
Problem:  
 
You will write a program which implements the following sorts and compares the performance 
for operations on vectors of integers of growing sizes 10, 100, 1000, 5000, 10000, 25000, etc....  
You will graph the performance of the different sorts as a function of the size of the vector. 
 
1) BubbleSort 
2) InsertionSort 
3) MergeSort 
4) Non-Recursive, one extra vector<int> MergeSort (We’ll call this improved version, 
IterativeMergeSort from here on out in this homework) 
5) QuickSort 
6) ShellSort 
 
 
Details: 
 
IterativeMergeSort 
 
 In-place sorting refers to sorting that does not require extra memory vectors.   For 
example, QuickSort performs partitioning operations by repeating a swapping operation on two 
data items in a given vector.  This does not require an extra vector. 
MergeSort as shown in Carrano allocates a temporary vector at each recursive call.  Due 
to this MergeSort is slower than QuickSort even though their running time is upper-bounded to 
O(n log n).  
We can improve the performance of MergeSort by utilizing a non-recursive method and 
using only one additional vector (instead of one vector on each recursive call).   In this improved 
version of MergeSort, IterativeMergeSort, one would merge data from the original vector into 
the additional vector and alternatively copy back and forth between the original and the 
additional temporary vector.   Please re-read the last sentence as it is critical to the grading of 
the lab. 
For the IterativeMergeSort we still need to allow data items to be copied between the 
original and this additional vector as many times as O(log n).  However, given the iterative 
nature we are not building up state on the stack. 
  
 
Other Sorts 
 BubbleSort, InsertionSort, MergeSort, and QuickSort are well documented and you 
should implement them with the aid of examples in the Carrano book and class.   We have gone 
over Shell Sort in class. 
 
 
Runtime Details 
 Your program, called sorter, will take in two parameters:  
1) sort type as a string of characters  
2) an vector size as an integer.   
 
Your program will create and sort an vector<int> of the size with the specified sort:  
MergeSort, BubbleSort, InsertionSort, QuickSort, ShellSort or IterativeMergeSort.  The driver 
functions below will help with the creation. 
 
 Examples: 
  sorter MergeSort 100  (creates and sorts a vector<int> of size 100 using 
MergeSort) 
 
  sorter QuickSort 1000 (creates and sorts a vector<int> of size 1000 using 
QuickSort) 
 
  sorter IterativeMergeSort 10000 (creates and sorts a vector<int> of 10000 using 
the newly implemented non-recursive semi-in-place MergeSort) 
 
What to turn in: 
 
Turn in, in a .zip (not gz, etc..): 
(1)  Your sorts.h file which has implementations of all of the sorts 
(2)  Your sorter.exe file or linux sorter executable 
(3)  A separate report in word or pdf which includes:  Graphs that compares the 
performance among the different sorting algorithms with increasing data size.  You 
should increase the data size to clearly show the difference in performance of the 
different sorts. 
 
 
A few words about the report 
 
The report will make up a part of the overall grade.  Please make sure your graphs show a clear 
differentiation between the sorts.  Your goal is to illustrate to the reader which sorts are fastest 
in graphical format.  Make sure this is clear from the data and you have enough data points and 
use a large enough data size to show this.   
 
You should also address the bigO of each of the sorts. 
  
 
 
Driver Code 
 
 Use the code below as driver code to test and time the different Sort functions.  Notice 
the sort definitions are in the sorts.h file that is included at the top of the driver file.  This is the 
file you will turn in.  Please make sure to spell each of the sorts by the exact name signature 
below. 
 
#include <iostream> 
#include <vector> 
#include <string> 
#include "sorts.h" 
#include <windows.h> 
using namespace std; 
 
void InitVector(vector<int>& item_vector, int size); 
void PrintVector(const vector<int>& item_vector, string name); 
 
int main(int argc, char* argv[]) 
{ 
 int size = 0; 
 string sort_name = ""; 
 bool print_out = true; 
 
 if ((argc != 3) && (argc != 4)) 
 { 
  cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl; 
  return -1; 
 } 
 
 sort_name = string(argv[1]); 
 size = atoi(argv[2]); 
 
 if (size <= 0) 
 { 
  cerr << "Vector size must be positive" << endl; 
  return -1; 
 } 
 if (argc == 4) 
 { 
  string print_arr = string(argv[3]); 
  if (print_arr == "NO") 
  { 
   print_out = false; 
  } 
  else if (print_arr == "YES") 
  { 
   print_out = true; 
  } 
  else 
  { 
   cerr << "Usage: Sorter SORT_TYPE VECTOR_SIZE [YES|NO]" << endl; 
   return -1; 
  } 
 } 
 
 srand(1); 
 vector<int> items(size); 
 InitVector(items, size); 
 
 if (print_out) 
 { 
  cout << "Initial:" << endl; 
  PrintVector(items, string("items")); 
 } 
 // GetTickCout is windows specific.     
 // For linux use gettimeofday.  As shown:: 
 //  struct timeval startTime, endTime; 
 //  gettimeofday(&startTime, 0); 
 int begin = GetTickCount(); 
 
 //  
 // PLACE YOUR CODE HERE 
 //   ...Determine which sort to call on the vector 
 //   ...The code below only looks for QuickSort 
 // Other Signatures: 
 //  BubbleSort(items, 0, size - 1) 
 //  InsertionSort(items, 0, size – 1) 
 //  MergeSort(items, 0, size – 1) 
 //  IterativeMergeSort(items, 0, size – 1) 
 //  ShellSort(items, 0, size – 1) 
 // PLACE YOUR CODE HERE;  for instance: 
 if (sort_name == "QuickSort") 
 { 
  QuickSort(items, 0, size - 1); 
 } 
 
 int end = GetTickCount(); 
 // Linux timer: 
 // gettimeofday(&endTime, 0); 
 
 if (print_out) 
 { 
  cout << "Sorted:" << endl; 
  PrintVector(items, string("item")); 
 } 
 
 int elapsed_secs = end - begin; 
 cout << "Time (ms): " << elapsed_secs << endl; 
 return 0; 
} 
 
void InitVector(vector<int>& item_vector, int rand_max) 
{ 
 if (rand_max < 0) 
 { 
  return; 
 } 
 vector<int> pool(rand_max); 
 for (int i = 0; i < rand_max; i++) 
 { 
  pool[i] = i; 
 } 
 
 int spot; 
 for (int i = 0; i < rand_max; i++) 
 { 
  spot = rand() % (pool.size()); 
  item_vector[i] = pool[spot]; 
  pool.erase(pool.begin() + spot); 
 } 
} 
 
void PrintVector(const vector<int>& item_vector, string name) 
{ 
 int size = item_vector.size(); 
 
 for (int i = 0; i < size; i++) 
  cout << name << "[" << i << "] = " << item_vector[i] << endl; 
} 
 
// Function to calculate elapsed time if using gettimeofday (linux) 
// int elapsed( timeval &startTime, timeval &endTime )  
// { 
// return ( endTime.tv_sec - startTime.tv_sec ) * 1000000  
//  + ( endTime.tv_usec - startTime.tv_usec ); 
// } 
