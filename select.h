#ifndef SELECT_H
#define SELECT_H

#include "sort.h"

class SelectSort : public Sort {       
    public:
        SelectSort(int *elements, size_t size) : Sort(elements, size) {}

        void swap(int* x,int* y){
            int temp = *x;
            *x = *y;
            *y = temp;
        }

        void execute() {
            int i, j, min_index;
            //start from the first element of the array
            for(i=0; i<size-1; ++i){
                min_index = i;
                for(j=i+1; j<size; ++j){    // go for the rest of element finding the minimum value
                    if(elements[j] < elements[min_index]){
                        min_index = j;
                    }
                }
                swap(&elements[i],&elements[min_index]);
            }
        }

        inline string name() { return "SelectSort"; }
};

#endif