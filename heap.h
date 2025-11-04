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

        // inserting idx as the last element in data
        data[size] = idx;

        // restores heap order with upheap
        upheap(size, weightArr);

        // increase size
        size++;


    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()

        if (size == 0) {
            cout << "Heap is empty" << endl;
            return -1;
        }

        int smallest = data[0];

        // replaces root with the last element
        data[0] = data[size - 1];
        size--;

        downheap(0, weightArr); // reorganizes heap after the pop

        return smallest; // returns root (smallest)
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent

        if (pos == 0) { // pos is the root so return function
            return;
        }

        while (pos > 0) {
            int parent = (pos - 1) / 2; // establishes parent position (binary heap so pos-1 / 2)

            // if pos is smaller than the parent node, it swaps with the parent so it moves up
            if (weightArr[data[pos]] < weightArr[data[parent]]) {
                swap(data[pos], data[parent]);
                pos = parent;
            }
            else {
                break;
            }
        }

    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child


        while (true) {
            int left = 2 * pos + 1; // left child node index
            int right = 2 * pos + 2; // right child node index
            int smallest = pos; // sets pos to smallest

            // determines if left is smaller than current smallest
            if (left < size && weightArr[data[left]] < weightArr[data[smallest]]) {
                smallest = left;
            }

            // determines if right is smaller than current smallest
            if (right < size && weightArr[data[right]] < weightArr[data[smallest]]) {
                smallest = right;
            }

            // swaps pos with the smallest node is the pos is no longer the smallest
            if (smallest != pos) {
                swap(data[pos], data[smallest]);
                pos = smallest;
            }
            else {
                break; // needed to end loop
            }
        }

    }
};

#endif