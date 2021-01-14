# Dynamic Modules Array and Linked List

Dynamically growing array and linked list of a custom struct "Module"

## Build

### cmake

`cmake .`

`make`

## Run

### dynamic array

Run the executable, use the given modules.csv data to initialize the 
module structs passed to the array.

`build/dynamicarray < input/modules.csv`

### listed lists

Run the executable, use the given modules.csv data to initialize the 
module structs passed to the linked list.

`build/linkedlist < input/modules.csv`