# Essential C Standard Library Headers: Quick Reference

This guide summarizes the most important C standard library headers, their main features, and what you’ll use them for in real-world C programming.

---

## `<stdio.h>` — Standard Input/Output
 - `printf`, `scanf`, `puts`, `gets`, `fopen`, `fclose`, `fread`, `fwrite`, `fprintf`, `fscanf`, `fseek`, `ftell`, etc.
 - **Purpose:** Console and file I/O (printing, reading, writing files)

```c
#include <stdio.h>
int main() {
    printf("Hello, world!\n");
    FILE *f = fopen("file.txt", "w");
    fprintf(f, "data\n");
    fclose(f);
    return 0;
}
```

## `<stdlib.h>` — Standard Library Functions
 - `malloc`, `calloc`, `realloc`, `free`, `exit`, `atoi`, `atof`, `rand`, `srand`, `qsort`, `bsearch`, `abs`, etc.
 - **Purpose:** Memory allocation, process control, conversions, random numbers, sorting/searching

```c
#include <stdlib.h>
int *arr = malloc(10 * sizeof(int));
arr[0] = abs(-5);
free(arr);
```

## `<string.h>` — String and Memory Functions
 - `strcpy`, `strncpy`, `strcat`, `strcmp`, `strlen`, `strchr`, `strstr`, `memcpy`, `memset`, `memcmp`, etc.
 - **Purpose:** Manipulate C strings and memory blocks

```c
#include <string.h>
char s[20];
strcpy(s, "abc");
size_t len = strlen(s);
```

## `<math.h>` — Math Functions
 - `sin`, `cos`, `tan`, `sqrt`, `pow`, `log`, `exp`, `fabs`, `ceil`, `floor`, etc.
 - **Purpose:** Common math operations (floating point)

```c
#include <math.h>
double r = sqrt(16.0);
double s = sin(3.14);
```

## `<ctype.h>` — Character Classification
 - `isalpha`, `isdigit`, `isspace`, `tolower`, `toupper`, etc.
 - **Purpose:** Test and convert character types

```c
#include <ctype.h>
char c = 'A';
if (isalpha(c)) c = tolower(c);
```

## `<time.h>` — Date and Time
 - `time`, `clock`, `difftime`, `mktime`, `strftime`, `localtime`, `gmtime`, etc.
 - **Purpose:** Get and manipulate time/date values

```c
#include <time.h>
time_t now = time(NULL);
printf("%ld\n", now);
```

## `<errno.h>` — Error Codes
 - `errno`, `perror`, `strerror`
 - **Purpose:** Standard error reporting

```c
#include <errno.h>
#include <stdio.h>
FILE *f = fopen("nofile.txt", "r");
if (!f) perror("open failed");
```

## `<assert.h>` — Assertions
 - `assert`
 - **Purpose:** Debugging checks (abort if condition fails)

```c
#include <assert.h>
int x = 5;
assert(x > 0);
```

## `<limits.h>` — Integer Limits
 - `INT_MAX`, `INT_MIN`, `CHAR_BIT`, etc.
 - **Purpose:** Get platform-specific integer limits

```c
#include <limits.h>
int max = INT_MAX;
```

## `<float.h>` — Floating Point Limits
 - `FLT_MAX`, `DBL_MIN`, etc.
 - **Purpose:** Get platform-specific float/double limits

```c
#include <float.h>
float fmax = FLT_MAX;
```

## `<stddef.h>` — Common Types
 - `size_t`, `ptrdiff_t`, `NULL`, `offsetof`
 - **Purpose:** Standard types and macros

```c
#include <stddef.h>
size_t n = 10;
```

## `<stdint.h>` — Fixed-Width Integer Types (C99+)
 - `int8_t`, `uint32_t`, `int64_t`, etc.
 - **Purpose:** Portable integer types

```c
#include <stdint.h>
int32_t n = 123456;
```

## `<stdbool.h>` — Boolean Type (C99+)
 - `bool`, `true`, `false`
 - **Purpose:** Use boolean values in C

```c
#include <stdbool.h>
bool flag = true;
```

---

## Data Structures in the Standard Library
C’s standard library does not include high-level data structures (like lists, maps, sets) as in C++/Java/Python. You must implement them yourself or use third-party libraries. However, you can use:
- `qsort` and `bsearch` (from `<stdlib.h>`) for generic sorting and searching arrays
- Arrays, structs, and pointers to build your own data structures

```c
#include <stdlib.h>
int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}
int arr[4] = {3,1,4,2};
qsort(arr, 4, sizeof(int), cmp);
```

---

## Other Useful Headers
- `<signal.h>` — Signal handling
- `<setjmp.h>` — Non-local jumps (advanced error handling)
- `<locale.h>` — Localization
- `<stdarg.h>` — Variadic functions (e.g., `va_list`)
- `<unistd.h>` — POSIX functions (not standard C, but common on Unix/Linux)

```c
#include <stdarg.h>
int sum(int n, ...) {
    va_list args;
    va_start(args, n);
    int total = 0;
    for (int i = 0; i < n; i++)
        total += va_arg(args, int);
    va_end(args);
    return total;
}
```
. GLib

    Website: https://developer.gnome.org/glib/

    What it offers:

        GList, GSList (linked lists)

        GHashTable (hash maps)

        GTree (balanced binary trees)

        Dynamic arrays, queues, string utilities, memory management helpers

    Pros: Widely used, stable, very mature.

    Cons: Dependency on GLib may be overkill if you only need a small subset.

2. uthash

    Website: https://troydhanson.github.io/uthash/

    What it offers:

        Header-only hash table and linked list macros.

        Very easy to integrate — just drop in the .h file.

    Pros: Zero dependencies, single header, popular in embedded and systems programming.

    Cons: Macro-based — can be harder to debug.

3. klib

    GitHub: https://github.com/attractivechaos/klib

    What it offers:

        Dynamic arrays, hash tables, sorted maps/sets, string utilities.

        Lightweight and fast.

    Pros: Simple, header-only, high performance.

    Cons: Minimal documentation.

4. libavl

    Website: http://adtinfo.org/libavl.html/

    What it offers:

        AVL trees, red-black trees, treaps, and other balanced BSTs.

    Pros: Very academic and thorough.

    Cons: Overkill if you just need a basic map.

5. c-containers

    GitHub: https://github.com/tylov/c-containers

    What it offers:

        Vectors, hash maps, linked lists, stacks, queues.

    Pros: Clean API, C11 features, MIT license.

    Cons: Less battle-tested than GLib/uthash.

If you want maximum flexibility with minimal boilerplate and don’t mind macros → uthash or klib are your best bets.
If you want a full, feature-rich, well-documented library → GLib is the standard choice.
---

For more, see: [C Standard Library Reference](https://en.cppreference.com/w/c/header)
