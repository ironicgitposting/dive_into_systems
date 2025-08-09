# C Pointers and Memory Management Tutorial

This tutorial introduces pointers and memory management in C, with examples and explanations for beginners.

---

## 1. What is a Pointer?
A pointer is a variable that stores the memory address of another variable.

### Declaration and Initialization
```c
int x = 10;
int *p = &x; // p stores the address of x
```
- `int *p;` declares a pointer to an int.
- `p = &x;` assigns the address of `x` to `p`.

### Dereferencing
Access the value pointed to by a pointer using `*`:
```c
printf("%d\n", *p); // prints 10
```

---

## 2. Pointer Types
- `int *p;` — pointer to int
- `char *c;` — pointer to char
- `float *f;` — pointer to float

---

## 3. Null Pointers
A pointer that points to nothing:
```c
int *p = NULL;
```
Always initialize pointers. Dereferencing a NULL or uninitialized pointer causes crashes.

---

## 4. Pointers and Arrays
Arrays and pointers are closely related:
```c
int arr[3] = {1, 2, 3};
int *p = arr; // points to arr[0]
printf("%d\n", *(p+1)); // prints 2
```

---

## 5. Dynamic Memory Allocation
C does not have garbage collection. You must manually allocate and free memory.

### malloc, calloc, free
```c
#include <stdlib.h>

int *arr = malloc(5 * sizeof(int)); // allocates space for 5 ints
if (arr == NULL) { /* handle error */ }

// Use arr[0] ... arr[4]

free(arr); // release memory
```
- `malloc(size)`: Allocates uninitialized memory
- `calloc(n, size)`: Allocates zero-initialized memory
- `free(ptr)`: Frees allocated memory

---

## 6. Common Mistakes
- Forgetting to free memory (memory leak)
- Using memory after `free` (undefined behavior)
- Dereferencing uninitialized or NULL pointers
- Buffer overflows (writing past array bounds)

---

## 7. Example: Swapping Two Integers Using Pointers
```c
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int x = 5, y = 10;
    swap(&x, &y);
    // x is now 10, y is now 5
}
```

---

## 8. Example: Dynamic Array
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter array size: ");
    scanf("%d", &n);
    int *arr = malloc(n * sizeof(int));
    if (!arr) return 1;
    for (int i = 0; i < n; i++) arr[i] = i*i;
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    free(arr);
    return 0;
}
```

---

## 9. Summary
- Pointers store addresses, use `*` to dereference, `&` to get address
- Always free dynamically allocated memory
- Be careful with pointer initialization and array bounds

---

For more, see: [C Pointers (GeeksforGeeks)](https://www.geeksforgeeks.org/pointers-in-c/)
