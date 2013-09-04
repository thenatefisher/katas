#include "stdio.h"
#include "gtest/gtest.h"

// fwd declare prototype
void selection_sort(int*, int);
void quick_sort(int*, int);

// run quick sort test
TEST(Sort, quicksort) {

  int list_size = 10;
  int *list = new int[list_size];

  int value = 0;
  for (int i = (list_size-1); i >= 0; i--) {
    list[i] = value++;
  }
  
  // run the algo
  quick_sort(list, list_size);
  
  // did we get correct path?
  for (int i=0; i < list_size; i++) {
    EXPECT_EQ(list[i], i);
  }

}

// run selection sort test
TEST(Sort, selection) {

  int list_size = 10;
  int *list = new int[list_size];

  int value = 0;
  for (int i = (list_size-1); i >= 0; i--) {
    list[i] = value++;
  }
  
  // run the algo
  selection_sort(list, list_size);
  
  // did we get correct path?
  for (int i=0; i < list_size; i++) {
    EXPECT_EQ(list[i], i);
  }

}

void selection_sort(int *list, int size) {

    int min_pos;
    
    // iterate through entire list once
    for(int j = 0; j < size; j++) {
    
        // the position of smallest number is first estimated to be current element
        min_pos = j;
        
        // start from j and look forward for something smaller
        for(int k = j+1; k < size; k++) {
        
            // if there is something smaller than what we've seen so far, record it
            if (list[k] < list[min_pos]) {
                min_pos = k;
            }
        
        }
    
        // swap the values of current position and smallest element
        int val_store   = list[j];
        int min         = list[min_pos];
        list[j]         = min;
        list[min_pos]   = val_store;
        
    }

}

void quick_sort(int *list, int size) {
    
    if (size <= 1) {
        // return list of one item
        return;
    }
    
    int pivot_pos = (int)(size/2);
    int pivot_val = list[pivot_pos];
    int *lower = new int[size];
    int *upper = new int[size];

    int lower_index = 0, upper_index = 0;
    for(int i = 0; i < size; i++) {
        if (list[i] < pivot_val) {
            // add list[i] to lower
            lower[lower_index++] = list[i];
        } else if (list[i] > pivot_val) {
            // add list[i] to upper
            upper[upper_index++] = list[i];
        }
    }
    
    // recursively sort each list
    quick_sort(lower, lower_index);
    quick_sort(upper, upper_index);
    
    // return concat lower + pivot + upper
    int sorted_list_index = 0;
    for(int i = 0; i < lower_index; i++) {
            list[sorted_list_index++] = lower[i];
    }
    list[sorted_list_index++] = pivot_val;
    for(int i = 0; i < upper_index; i++) {
            list[sorted_list_index++] = upper[i];
    }
    
    return;
}
