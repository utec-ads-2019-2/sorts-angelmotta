#ifndef COUNTING_H
#define COUNTING_H

#include "sort.h"
#include <algorithm>

class CountingSort : public Sort {       
    public:
        CountingSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            int max = *max_element(elements, elements+size);
            int min = *min_element(elements, elements+size);
            int range = max - min + 1;
            //cout << "max: " << max << " min: " << min << " range: " << range << '\n';
            //int* count = new int[range];
            int count[range];
            int sortedInput[size];
            memset(count, 0, sizeof(count));

            // count how many times appear each element of the input
            for(int i=0; i<size; ++i){
                count[elements[i]-min]++;
            }

            // Update each value of count array adding the value of the previous element
            for(int i=1; i<range; ++i){
                count[i] += count[i-1];
            }
            //Sorting
            for(int i=size-1; i>=0; --i){	//iterate each number of the input
                sortedInput[count[elements[i]-min]-1] = elements[i];
                count[elements[i]-min]--;
            }
            for(int i=0; i<size; ++i){
                elements[i] = sortedInput[i];
            }
        }

        inline string name() { return "CountingSort"; }
};

#endif