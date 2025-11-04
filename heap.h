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
        // originally wrong code, i should be using data[]
        /* if (size == 0) {
            weightArr[0] = idx;
            size++;
        }

        weightArr[size] = weightArr[idx];

        upheap(size, weightArr);
        */

        // set idx to last element in data
        data[size] = idx;

        // upheap idx in weightArr[]
        upheap(idx, weightArr);

        // increase size
        size++;


    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size == 0) {
            cout << "Heap is empty" << endl;
            return 1;
        }

        int smallest = data[0];

        // replaces root with the last element
        data[0] = data[size - 1];
        size--;

        downheap(0, data); // reorganizes heap after the pop

        return smallest; // returns root (smallest)
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        if (pos == 0) { // pos is the root so return function
            return;
        }

        int parent = (pos - 1) / 2; // establishes parent position (binary heap so pos-1 / 2)

        // swaps pos and parent node if pos is less than the parent
        if (weightArr[data[pos]] < weightArr[data[parent]]) {
            swap(data[pos], data[parent]);
            upheap(parent, weightArr); // recursive call to traverse upward
        }


    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child

        if (pos == size) {
            return;
        }

        int left = 2 * pos + 1; // left child node index
        int right = 2 * pos + 2; // right child node index
        int smallest = pos; // sets pos to smallest

        // compares weights of pos and left child
        if (left < size && weightArr[data[pos]] < weightArr[data[left]]) {
            smallest = left;
        }

        // compares weights of pos and right child
        if (right < size && weightArr[pos] < weightArr[right]) {
            smallest = right;
        }

        // swaps pos with the smallest node
        if (smallest != pos) {
            swap(data[pos], data[smallest]);

            // recursive call to shift node downward if it is not the smallest in the next weight
            downheap(smallest, weightArr);
        }

    }
};

#endif