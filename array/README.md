# C Array Implementations

A clean set of standalone `.c` files covering the Array chapter topics from basic arrays through sparse matrices and applications.

## Files

| File | Coverage |
|---|---|
| `01_basic_arrays.c` | Declaration, access, address calculation, length |
| `02_traversing_array.c` | Array traversal |
| `03_insert_element.c` | Insertion |
| `04_delete_element.c` | Deletion |
| `05_merge_two_arrays.c` | Merging arrays |
| `06_pass_arrays_to_functions.c` | Passing elements and arrays to functions |
| `07_pointers_and_arrays.c` | Pointers and arrays |
| `08_array_of_pointers.c` | Array of pointers |
| `09_two_dimensional_arrays.c` | 2D declaration, initialization, access |
| `10_two_dimensional_operations.c` | 2D operations: addition and transpose |
| `11_pass_2d_array_to_function.c` | Passing 2D arrays to functions |
| `12_pointers_and_2d_arrays.c` | Pointers and 2D arrays |
| `13_multidimensional_arrays.c` | 3D arrays |
| `14_pointers_and_3d_arrays.c` | Pointers and 3D arrays |
| `15_sparse_matrix.c` | Sparse matrix using triplet representation |
| `16_array_applications.c` | Search, min/max, average |

## Compile

Using GCC:

```bash
gcc -std=c17 -Wall -Wextra -Wpedantic 01_basic_arrays.c -o basic_arrays
./basic_arrays
```

Replace the source filename and output name for any other file.

## Style

The examples use fixed, readable programs, `size_t` for array sizes, `const` for read-only inputs, small helper functions, and basic bounds validation where an operation changes array size.
