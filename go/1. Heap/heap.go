package main

import "fmt"

// MaxHeap struct has a slice that holds the array
type MaxHeap struct {
	array []int
}

// Create new MaxHeap object
func NewMaxHeap() *MaxHeap {
	return &MaxHeap{}
}

// Insert adds an element to the heap
func (h *MaxHeap) Insert(key int) {
	h.array = append(h.array, key)
	h.MaxHeapifyUp(len(h.array) - 1)
}

// Extract returns the largest key, removes it from the heap
func (h *MaxHeap) Extract() int {
	extracted := h.array[0]
	length := len(h.array) - 1

	// When the array is empty
	if len(h.array) == 0 {
		fmt.Println("cannot extract because array length is 0")
		return -1
	}

	// take out the last index and put it in the root
	h.array[0] = h.array[length]
	h.array = h.array[:length]

	h.MaxHeapifyDown(0)

	return extracted
}

// MaxHeapifyUp will heapify from bottom to top
func (h *MaxHeap) MaxHeapifyUp(index int) {
	for h.array[parent(index)] < h.array[index] {
		h.Swap(parent(index), index)
		index = parent(index)
	}
}

// MaxHeapifyDown will heapify top to bottom
func (h *MaxHeap) MaxHeapifyDown(index int) {
	lastIndex := len(h.array) - 1
	l, r := left(index), right(index)
	childToCompare := 0

	// Loop while index has at least one child
	for l <= lastIndex {
		// When left child is the only child
		if l == lastIndex {
			childToCompare = l
		} else if h.array[l] > h.array[r] {
			// When left child is larger
			childToCompare = l
		} else {
			// When right child is larger
			childToCompare = r
		}
		// Compare array value of current index to larger child and swap if smaller
		if h.array[index] < h.array[childToCompare] {
			h.Swap(index, childToCompare)
			index = childToCompare
			l, r = left(index), right(index)
		} else {
			return
		}
	}
}

// Swap keys in the array
func (h *MaxHeap) Swap(i1, i2 int) {
	h.array[i1], h.array[i2] = h.array[i2], h.array[i1]
}

// Get the parent index
func parent(i int) int {
	return (i - 1) / 2
}

// Get the left child index
func left(i int) int {
	return i*2 + 1
}

// Get the right child index
func right(i int) int {
	return i*2 + 2
}

func main() {
	maxHeap := NewMaxHeap()
	fmt.Println(maxHeap)

	buildHeap := []int{10, 20, 30, 5, 7, 9, 11, 13, 15, 17}
	for _, v := range buildHeap {
		maxHeap.Insert(v)
		fmt.Println("Insert:", *maxHeap)
	}

	for i := 0; i < 5; i++ {
		maxHeap.Extract()
		fmt.Println("Extract:", *maxHeap)
	}
}
