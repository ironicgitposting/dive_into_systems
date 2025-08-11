
## Abstract Syntax Tree (AST) — The Compiler’s Mental Model of Your Code

When you write a C program, you’re thinking in **source code**.
When your CPU runs it, it’s thinking in **machine code**.
The compiler’s job is to translate between the two — and the **AST** is the compiler’s internal “thinking language.”

---

### **1. What is an AST?**

An **Abstract Syntax Tree** is a **tree-shaped data structure** that represents the **hierarchical, logical structure** of your program after parsing.

* **Abstract**: It ignores details irrelevant to program meaning (e.g., extra parentheses, formatting, comments).
* **Syntax**: It’s based on the grammar of the programming language.
* **Tree**: Each node represents a construct (function, statement, expression, etc.), and edges represent “is part of” relationships.

Think of it as the **skeleton** of your program’s logic.

---

### **2. Why Compilers Use ASTs**

The AST is the **middle-man** between raw text and generated code.

Steps:

1. **Lexing (Tokenization)**:
   Breaks source code into tokens (keywords, identifiers, literals, operators).

   ```
   int main() { return 42; }
   → ["int", "main", "(", ")", "{", "return", "42", ";", "}"]
   ```

2. **Parsing**:
   Analyzes tokens according to the grammar to produce a **tree structure**.

   ```
   Function
    ├── Return type: int
    ├── Name: main
    └── Body
         └── Return statement
              └── Constant: 42
   ```

3. **Semantic Analysis**:
   Adds meaning — type checking, symbol table, scope rules — to the tree.

The AST becomes the foundation for **optimization** and **code generation**.

---

### **3. AST vs. Concrete Syntax Tree (CST)**

* **Concrete Syntax Tree (Parse Tree)**: Preserves **every** detail from the grammar, including punctuation and parentheses.
* **AST**: Simplified, focuses only on **semantic structure**.
  Example:
  `(a + b)` and `a + b` produce the **same AST** because parentheses aren’t semantically needed here.

---

### **4. Real Example — From C to AST**

Source:

```c
int add(int a, int b) {
    return a + b;
}
```

Tokens:

```
[int] [add] [(] [int] [a] [,] [int] [b] [)] [{] [return] [a] [+] [b] [;] [}]
```

AST (simplified):

```
FunctionDecl "add"
 ├── ReturnType: int
 ├── Parameters
 │    ├── VarDecl: int a
 │    └── VarDecl: int b
 └── Body
      └── ReturnStmt
           └── BinaryOp "+"
                ├── VarRef a
                └── VarRef b
```

---

### **5. How to See ASTs Yourself**

For GCC:

```bash
gcc -fdump-tree-all file.c
```

(Produces many files, each showing AST transformations during optimization passes.)

For Clang (nicer output):

```bash
clang -Xclang -ast-dump -fsyntax-only file.c
```

Example output:

```
FunctionDecl 0x7fd4b140 "add" 'int (int, int)'
|-ParmVarDecl 0x7fd4b158 'a' 'int'
|-ParmVarDecl 0x7fd4b160 'b' 'int'
`-ReturnStmt
   `-BinaryOperator '+'
      |-DeclRefExpr 'a'
      `-DeclRefExpr 'b'
```

---

### **6. Why ASTs Matter Beyond Compilers**

* **Static analysis tools** (e.g., Clang-Tidy, ESLint) inspect ASTs to find bugs.
* **Code formatters** (e.g., clang-format) rebuild source from AST.
* **Security analysis** tools scan ASTs for vulnerable patterns.
* **Language servers** use ASTs for autocompletion, go-to-definition, etc.

---

### **Summary Table**

| Step           | Input       | Output           | Purpose                       |
| -------------- | ----------- | ---------------- | ----------------------------- |
| Lexing         | Source text | Tokens           | Break into symbols            |
| Parsing        | Tokens      | AST              | Capture program structure     |
| Semantic check | AST         | Annotated AST    | Add types, scope info         |
| Codegen        | AST         | Assembly/Machine | Translate to CPU instructions |

---

If you’d like, I can make you a **diagram showing the path from source → tokens → AST → binary**, so it matches the GCC stages lesson and ties them together visually. That way you’ll have a complete mental map from high-level C to final executable.
