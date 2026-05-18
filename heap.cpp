// heap.cpp
// Diba Mirza
//Ryan Sun 
#include "heap.h"
#include <iostream>
using std::cout;

// Builds a heap from the range [start, end) using the heapify algorithm
// Should run in O(n) time
Heap::Heap(std::vector<int>::iterator start, std::vector<int>::iterator end){
  while(start != end){
    vdata.push_back(*start);
    start++;
  }
  int n = vdata.size(); 
  for (int i = n/2 - 1; i >= 0; i--){
    bubbleDown(i); 
  }
}

// Pushes a value into the heap, then ensures
// the heap is correctly arranged
void Heap::push(int value){
  if (vdata.size() == 0){
    vdata.push_back(value); 
    return; 
  } 
  vdata.push_back(value); 
  bubbleUp(vdata.size() - 1); 
}

void Heap::bubbleUp(int i){
  while(i > 0){
    int parent = (i - 1) / 2; 
    if (vdata[i] >= vdata[parent]) break; 
    std::swap(vdata[i], vdata[parent]); 
    i = parent; 
  }
}

void Heap::bubbleDown(int i){
  while(true){
    int left = 2*i + 1; 
    int right = 2*i + 2; 
    int smallest = i; 

    //check for existing children 
    //compare current to left, then left to right (if either/both exist)
    //if neither exist or neither are greater than current, then current is in the right place 
    //if the smallest is not current, then swap current with the smallest
    if (left < vdata.size() && vdata[left] < vdata[smallest]){
      smallest = left;
    }
    if (right < vdata.size() && vdata[right] < vdata[smallest]){
      smallest = right; 
    }
    if (smallest == i) break; 

    std::swap(vdata[i], vdata[smallest]);
    i = smallest; 
  }
}
// Pops the minimum value off the heap
// (but does not return it), then ensures
// the heap is correctly arranged
void Heap::pop(){
  std::swap(vdata[0], vdata.back());
  vdata.pop_back(); 
  bubbleDown(0); 
}

// Returns the minimum element in the heap
int Heap::top(){
  return vdata[0];
}

// Returns true if the heap is empty, false otherwise
bool Heap::empty(){
  return vdata.empty(); 
}
    