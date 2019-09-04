#ifndef RADIX_H
#define RADIX_H

#include "sort.h"

class RadixSort : public Sort {       
    public:
        RadixSort(int *elements, size_t size) : Sort(elements, size) {}

        int getMax() {
            int max = elements[0];
            for (int i = 1; i < size; ++i)
                if (elements[i] > max)
                    max = elements[i];
            return max;
        }

        void countingSort(int exponente) {
            int arr_out[size];
            int i, arr_count[10] = {0};
            for (i = 0; i < size; ++i)
                arr_count[(elements[i] / exponente) % 10]++;
            for (i = 1; i < 10; ++i)
                arr_count[i] += arr_count[i - 1];
            for (i = size - 1; i >= 0; --i) {
                arr_out[arr_count[(elements[i] / exponente) % 10] - 1] = elements[i];
                arr_count[(elements[i] / exponente) % 10]--;
            }
            for (i = 0; i < size; ++i)
                elements[i] = arr_out[i];
        }

        void execute() override{
            int maximo =  getMax();
            for (int exponente=1; maximo/exponente > 0; exponente *= 10) {
                countingSort(exponente);
            }
        }

        inline string name() { return "RadixSort"; }
};

#endif