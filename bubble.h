#ifndef BUBBLE_H
#define BUBBLE_H

#include "sort.h"
#include <algorithm>

class BubbleSort : public Sort {       
    public:
        BubbleSort(int *elements, size_t size) : Sort(elements, size) {}

        void swap(int *x,int *y){
            int temp = *x;
            *x = *y;
            *y = temp;
        }
        void execute() override {
            for(int i=0; i<size; i++){
                for(int j=0; j<size-i-1;j++){
                    if(elements[j] > elements[j+1]){
                        swap(&elements[j], &elements[j+1]);
                    }
                }
            }
        }

        inline string name() { return "BubbleSort"; }
};

#endif