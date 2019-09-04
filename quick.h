#ifndef QUICK_H
#define QUICK_H

#include "sort.h"

class QuickSort : public Sort {       
    public:
        QuickSort(int *elements, size_t size) : Sort(elements, size) {}

        int Partition(int *elements, int start, int end){
            int pivot = elements[end];
            int partitionIndex = start; 	// we set partition index equal to start index (initially)
            for(int i=start; i<end; ++i){
                if(elements[i] <= pivot){
                    swap(elements[i], elements[partitionIndex]);
                    partitionIndex++;
                }
            }
            swap(elements[partitionIndex], elements[end]);
            //cout << "partition index: " << partitionIndex << '\n';
            //for(int i=start; i<end; ++i) cout << elements[i] << " ";
            //cout << "\n";
            return partitionIndex;
        }

        void QSort(int *elements, int start, int end){
            if(start < end){
                int partitionIndex = Partition(elements, start, end); //Call function Partition() and receive the partition Index ordered left elements and right elements.
                QSort(elements, start, partitionIndex-1);
                QSort(elements, partitionIndex+1, end);
            }
        }

        void execute() override {
            QSort(elements, 0, size);
        }

        inline string name() { return "QuickSort"; }
};

#endif