#ifndef SHELL_H
#define SHELL_H

#include "sort.h"

class ShellSort : public Sort {       
    public:
        ShellSort(int *elements, size_t size) : Sort(elements, size) {}

        void execute() override {
            for (int interv=size/2; interv > 0; interv /= 2) {
                for (int i=interv; i<size; ++i) {
                    int temp = elements[i];
                    int j;
                    for (j = i; j >= interv && elements[j - interv] > temp; j -= interv){
                        elements[j] = elements[j - interv];
                    }
                    elements[j] = temp;
                }
            }
        }

        inline string name() { return "ShellSort"; }
};

#endif