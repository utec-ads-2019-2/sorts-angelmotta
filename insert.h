#ifndef INSERT_H
#define INSERT_H

#include "sort.h"

class InsertSort : public Sort {       
    public:
        InsertSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() {
            for(int i=1; i<size; ++i){      // start since the second number so the first unsorted element
                int unsorted_element = elements[i];
                int j = i -1;
                while(j >= 0 && elements[j] > unsorted_element){
                    elements[j+1] = elements[j];
                    j -= 1;
                }
                elements[j+1] = unsorted_element;
            }
        }
        inline string name() { return "InsertSort"; }
};

#endif