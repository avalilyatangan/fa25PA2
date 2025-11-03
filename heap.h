//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size == 0) {
            weightArr[0] = idx;
            size++;
        }

        weightArr[size] = weightArr[idx];

        upheap(size, weightArr);

    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return 1;
        }

        int smallest = weightArr[0];

        weightArr[0] = weightArr[size - 1];
        size--;

        downheap(0, weightArr);

        return smallest;
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        if (pos == 0) { // pos is the root so return function
            return;
        }

        int parent = (pos - 1) / 2; // establishes parent position (binary heap so pos-1 / 2)

        // swaps pos and parent node is pos is less than the parent
        if (weightArr[pos] < weightArr[parent]) {
            swap(weightArr[pos], weightArr[parent]);
            upheap(pos, weightArr); // recursive call
        }


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child



    }
};

#endif