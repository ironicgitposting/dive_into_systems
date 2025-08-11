# **Computer Architecture Fundamentals — Lesson 1**

## 1. What Is Computer Architecture?

* **Definition:** The *design and organization* of a computer’s components and how they work together to execute instructions.
* **Two key perspectives:**

  1. **Instruction Set Architecture (ISA):** The *programmer’s view* — the set of instructions, registers, and memory model available to software. Examples: x86-64, ARM, RISC-V.
  2. **Microarchitecture:** The *hardware implementation* of that ISA — pipelines, ALUs, caches, etc.

---

## 2. The CPU (Central Processing Unit)

The CPU is the **brain** of the computer. It:

* Fetches instructions from memory
* Decodes them
* Executes them
* Writes back results

### **Key CPU Components**

1. **Registers** — the fastest storage available.

   * Located *inside* the CPU.
   * Hold temporary data, addresses, and control information.
   * Types:

     * **General-purpose registers (GPRs):** For data manipulation. Example: `eax`, `r0`, `x1`
     * **Special-purpose registers:**

       * **Program Counter (PC) / Instruction Pointer (IP):** Address of the next instruction.
       * **Stack Pointer (SP):** Points to the top of the stack in memory.
       * **Status/Flags Register:** Stores condition flags (zero flag, carry flag, overflow, etc.).
       * **Base/Index Registers:** Used for addressing modes.
   * **Speed:** Accessed in 1 CPU cycle (nanoseconds or less).

2. **Arithmetic Logic Unit (ALU)**

   * Executes integer arithmetic (add, subtract, AND, OR, XOR, shifts).
   * Works directly with registers.

3. **Floating-Point Unit (FPU)**

   * Specialized hardware for decimal/real-number calculations.

4. **Control Unit**

   * Orchestrates the fetch-decode-execute cycle.
   * Manages the flow of instructions and data.

---

## 3. Memory Hierarchy

Memory in computers is **layered by speed and size** — the closer to the CPU, the faster and smaller it is.

| Level                  | Location        | Speed       | Size       | Volatile? |
| ---------------------- | --------------- | ----------- | ---------- | --------- |
| **Registers**          | CPU             | \~1 cycle   | Dozens     | Yes       |
| **Cache (L1, L2, L3)** | CPU chip        | Few cycles  | KB–MB      | Yes       |
| **Main Memory (RAM)**  | Motherboard     | 100+ cycles | GBs        | Yes       |
| **Storage (SSD/HDD)**  | Separate device | ms          | 100s GB–TB | No        |

### **Cache**

* **L1:** Fastest, smallest (\~32–64KB).
* **L2:** Slower, larger (\~256KB–1MB).
* **L3:** Shared across cores (\~4–64MB).
* **Purpose:** Store recently accessed data/instructions to reduce RAM access.

---

## 4. The Bus System

Buses are **communication highways** connecting CPU, memory, and peripherals.

* **Data Bus:** Transfers actual data.
* **Address Bus:** Specifies where in memory to read/write.
* **Control Bus:** Sends control signals (read, write, clock).

Modern systems often use **point-to-point links** (e.g., Intel’s QPI, AMD’s Infinity Fabric) instead of classic shared buses.

---

## 5. The Fetch–Decode–Execute Cycle

This is the **heartbeat** of a CPU:

1. **Fetch** — Load the next instruction from memory (address in PC).
2. **Decode** — Determine what operation and operands are needed.
3. **Execute** — Perform the operation (ALU/FPU, memory access, branch).
4. **Write Back** — Store the result (in a register or memory).
5. **Increment PC** — Move to the next instruction (unless a jump/branch happens).

---

# **Computer Architecture Fundamentals — Lesson 2**

## 6. Pipelining — Assembly Line for Instructions

**Idea:** Break the fetch–decode–execute cycle into stages so multiple instructions are in-flight at once.

**Example 5-stage pipeline:**

1. **IF** — Instruction Fetch
2. **ID** — Instruction Decode / Register Fetch
3. **EX** — Execute / ALU operation
4. **MEM** — Memory Access (if needed)
5. **WB** — Write Back to register

**Without pipelining:**

* Each instruction takes 5 cycles → Throughput = 1 instruction / 5 cycles.

**With pipelining:**

* Once the pipeline is full, you complete **1 instruction per cycle** (ideal case).

---

## 7. Hazards — When Pipelining Breaks

Real CPUs face **hazards** that stall the pipeline.

1. **Data Hazards** — An instruction depends on a result not yet ready.

   * Example:

     ```
     add r1, r2, r3   ; r1 = r2 + r3
     sub r4, r1, r5   ; needs r1 immediately
     ```

     Solution: **Forwarding/Bypassing** or **Stalls**.

2. **Control Hazards** — Caused by branches and jumps.

   * Solution: **Branch Prediction**.

3. **Structural Hazards** — Two operations need the same hardware resource.

   * Solution: Duplicate resources or schedule carefully.

---

## 8. Branch Prediction — Guessing the Future

Branches can ruin pipelining because the CPU doesn’t know where to fetch next.

**Naïve:** Always guess “not taken” → reload pipeline if wrong.
**Modern:** Dynamic branch predictors use history tables and pattern recognition to achieve **>95% accuracy**.

Mispredictions = pipeline flush = wasted cycles.

---

## 9. Superscalar Execution — Multiple Pipelines

A **superscalar CPU** has multiple execution units so it can issue **multiple instructions per cycle**.

* Example: **2-way superscalar** can execute two instructions per clock if independent.
* Modern desktop CPUs can issue **4–8 instructions per cycle**.

---

## 10. Out-of-Order Execution (OoOE)

Instead of running strictly in the program’s order, the CPU reorders instructions to keep execution units busy.

* **Scheduler:** Finds independent instructions that can be run early.
* **Reorder Buffer:** Ensures results are committed in the correct program order.

Example:

```
; Original
A: load r1, [mem1]  
B: add  r2, r3, r4  
C: mul  r5, r1, r6  ; depends on A
```

* OoOE will run **B** while waiting for memory in **A**, instead of stalling.

---

## 11. SIMD & Vector Processing

**Single Instruction, Multiple Data** — Perform the same operation on multiple data points at once.

* SSE, AVX (x86), NEON (ARM).
* Example: Add 8 integers in parallel.

---

## 12. Hyper-Threading / SMT

**Simultaneous Multithreading** — Present 2+ “logical” CPUs per core to the OS.

* Hides stalls by running another thread’s instructions while the first is waiting.
* Doesn’t double performance — usually 20–30% boost.

# **Computer Architecture Fundamentals — Lesson 3**

## 13. Main Memory — RAM

* **Volatile**: Loses data when power is off.
* **DRAM (Dynamic RAM)**:

  * Stores bits as charges in capacitors.
  * Needs constant refreshing (\~every few ms).
  * High density, cheap, but slower than SRAM.
* **SRAM (Static RAM)**:

  * Stores bits in flip-flops.
  * No refresh needed, much faster.
  * Used for **CPU caches**.

### Memory Latency Reality Check

| Location   | Latency (cycles) | Approx time (3GHz CPU) |
| ---------- | ---------------- | ---------------------- |
| L1 cache   | \~4 cycles       | \~1.3 ns               |
| L2 cache   | \~12 cycles      | \~4 ns                 |
| L3 cache   | \~40 cycles      | \~13 ns                |
| RAM        | \~100–300 cycles | \~33–100 ns            |
| SSD (NVMe) | \~100,000 cycles | \~30 μs                |
| HDD        | \~30,000,000+    | \~10 ms                |

---

## 14. Cache — Your CPU’s Secret Weapon

Caches exploit **temporal locality** (reusing recent data) and **spatial locality** (nearby data likely used soon).

### **Cache Organization**

* **Lines (Blocks):** Usually 64 bytes.
* **Sets & Associativity:**

  * Direct-mapped: 1 possible location per memory block.
  * N-way set-associative: Block can be in N different slots.
  * Fully associative: Block can go anywhere (slow to search).

### **Cache Write Policies**

* **Write-Through:** Write to cache and memory at the same time.
* **Write-Back:** Write to cache, mark as “dirty,” update memory later.

---

## 15. Virtual Memory — Illusion of Huge Continuous Memory

The OS + CPU’s **Memory Management Unit (MMU)** gives each process:

* **Own virtual address space** → prevents processes from corrupting each other.
* **Mapping from virtual to physical memory** via **page tables**.

### **Paging Basics**

* Memory split into **pages** (commonly 4KB).
* Virtual address → (page number, offset).
* MMU translates page number to physical frame number using **page table entries (PTEs)**.

### **Page Table Caching**

* **TLB (Translation Lookaside Buffer)**:

  * Small cache of recent address translations.
  * Miss = extra memory lookup → *very* expensive.

---

## 16. Memory Protection & Privilege Levels

* **Ring 0:** Kernel mode, full access.
* **Ring 3:** User mode, restricted.
* MMU enforces read/write/execute permissions on pages (important for exploit dev: NX-bit, DEP).

---

## 17. Memory-Mapped I/O

Instead of special instructions for devices, **device registers are mapped into address space**.

* Writing to certain addresses → sends commands to hardware.
* Used heavily in embedded and OS dev.

---

## 18. Why Cache Misses Kill Performance

Example:
If L1 hit = 1ns, RAM access = 100ns, then **one RAM load takes as long as 100 cache hits**.
That’s why modern compilers, CPUs, and hackers optimize for cache locality.

---

# **Computer Architecture Fundamentals — Lesson 4**

## 19. Instruction Set Architecture (ISA)

The **ISA** defines:

* Available instructions
* Registers and their purpose
* Memory model & addressing modes
* Binary encoding format

**Examples:**

* **x86-64** — Complex Instruction Set Computer (CISC), variable-length instructions (1–15 bytes).
* **ARM / RISC-V** — Reduced Instruction Set Computer (RISC), fixed-length instructions (typically 4 bytes).

---

## 20. Instruction Types

1. **Data Movement** — `MOV`, `LDR`, `STR`
2. **Arithmetic/Logic** — `ADD`, `SUB`, `AND`, `OR`, `XOR`
3. **Control Flow** — `JMP`, `CALL`, `RET`, conditional branches
4. **System** — privileged instructions for OS/kernel (`HLT`, `INT`)

---

## 21. Addressing Modes

How an instruction specifies where data is:

1. **Immediate** — value inside instruction:
   `MOV R0, #5`  (R0 ← 5)
2. **Register** — from another register:
   `MOV R0, R1`
3. **Direct Memory** — absolute address:
   `MOV R0, [0x1000]`
4. **Register Indirect** — address stored in a register:
   `MOV R0, [R1]`
5. **Base + Offset** — address = register + constant:
   `MOV R0, [R1+8]`
6. **Scaled Index** — often for arrays:
   `MOV R0, [R1 + R2*4]`

---

## 22. CPU Modes & Privilege Levels

* **User Mode:** Restricted, cannot directly access hardware.
* **Kernel Mode:** Full system access.
* Switching modes requires **interrupts**, **system calls**, or exceptions.

---

## 23. The Stack

The **stack** is a LIFO memory region used for:

* Function call bookkeeping
* Local variables
* Return addresses

### Stack Operations:

* **PUSH** — Decrease SP, store value.
* **POP** — Load value, increase SP.

---

## 24. Calling Conventions

Define how functions pass parameters and return values:

* **x86-64 System V (Linux/Unix):**

  * First 6 integer args in: `RDI, RSI, RDX, RCX, R8, R9`
  * Return in: `RAX`
  * Stack grows downward.
* **Windows x64:**

  * First 4 args in: `RCX, RDX, R8, R9`
  * Return in: `RAX`

Knowing this is critical for **reverse engineering** and **exploit dev**.

---

## 25. Example — x86-64 Function Call

```asm
; int add(int a, int b) { return a + b; }

add:
    mov eax, edi      ; a → eax
    add eax, esi      ; eax += b
    ret               ; return eax

; Caller:
    mov edi, 5        ; arg1 = 5
    mov esi, 3        ; arg2 = 3
    call add          ; result in eax
```

---

## 26. Endianness

* **Little-endian:** Least significant byte at lowest address (x86, ARM default).
* **Big-endian:** Most significant byte first (some networking, old CPUs).

Example (32-bit `0x12345678`):

* Little-endian in memory: `78 56 34 12`
* Big-endian in memory: `12 34 56 78`

Got it — Lesson 5 will cover **parallel architectures** and end with a **reverse-engineering field checklist** so you can directly map the theory to real binary work.

---

# **Computer Architecture Fundamentals — Lesson 5**

## 27. Parallelism Basics

Parallelism means **doing more work at the same time** — but there are different levels:

1. **Instruction-Level Parallelism (ILP)** — Multiple instructions in the same core at once (pipelining, superscalar, out-of-order).
2. **Data-Level Parallelism (DLP)** — Same operation on many data points (SIMD, vectorization).
3. **Thread-Level Parallelism (TLP)** — Multiple threads or processes running simultaneously.
4. **Task-Level Parallelism** — Completely separate tasks running independently.

---

## 28. Multicore CPUs

* **Each core**: Has its own ALUs, registers, L1/L2 cache.
* **Shared**: L3 cache and memory controller.
* Communication between cores happens over a high-speed interconnect (Intel QPI, AMD Infinity Fabric).

**Benefits:**

* True parallel execution of multiple threads.
* Ideal for workloads that can be split into independent tasks.

**Challenge:** Amdahl’s Law — parallel speedup is limited by the fraction of code that must run sequentially.

---

## 29. Symmetric vs Asymmetric Multicore

* **SMP (Symmetric Multiprocessing)**: All cores are identical.
* **AMP (Asymmetric)**: Some cores are high-performance, others are low-power (e.g., ARM big.LITTLE in mobile chips).

---

## 30. GPU Architecture

* **CPU**: Few powerful cores optimized for low-latency, branching workloads.
* **GPU**: Thousands of simple cores optimized for throughput, massively parallel workloads.
* Uses **SIMT** (Single Instruction, Multiple Threads) — threads grouped into warps/wavefronts.
* Perfect for:

  * Graphics
  * Machine learning
  * Cryptanalysis & password cracking
  * Data-parallel OSINT tasks

---

## 31. Specialized Processors

* **DSP (Digital Signal Processor)** — Optimized for continuous data streams (audio, radar, etc.).
* **FPGA (Field-Programmable Gate Array)** — Customizable hardware, often used for hardware-level exploits.
* **ASIC (Application-Specific IC)** — Fixed-function chip, maximum performance for a single task.

---

## 32. Memory Coherency & Synchronization

In multicore systems:

* **Cache coherency protocols** (MESI, MOESI) ensure all cores see the same memory values.
* Synchronization primitives (locks, barriers, atomic ops) prevent race conditions.

---

## 33. Scalability Bottlenecks

* **Memory bandwidth**: All cores share main memory.
* **Interconnect latency**: Cores on different sockets have higher latency (NUMA — Non-Uniform Memory Access).
* **Synchronization overhead**: Too much locking kills parallel performance.

---

## 34. Reverse-Engineering Field Checklist

When analyzing binaries or debugging at the hardware level, here’s what you’ll actually apply:

| Concept                                    | Why it matters                                                                             |
| ------------------------------------------ | ------------------------------------------------------------------------------------------ |
| **Registers**                              | Watch register usage during disassembly (`RAX`, `EIP/RIP`, `RSP`) to understand data flow. |
| **Calling conventions**                    | Identify arguments, returns, and stack layout for function tracing.                        |
| **Endianness**                             | Correctly interpret multi-byte values in memory dumps.                                     |
| **Instruction formats & addressing modes** | Understand how code fetches and manipulates data.                                          |
| **Stack mechanics**                        | Spot return address overwrites (buffer overflows).                                         |
| **Virtual memory & paging**                | Know how addresses map in exploits (ROP chains, shellcode).                                |
| **Privilege levels**                       | Kernel vs user mode exploits, syscall analysis.                                            |
| **Pipelining & branch prediction**         | Relevant in side-channel attacks (Spectre, Meltdown).                                      |
| **Caches**                                 | Critical in timing attacks (Flush+Reload, Prime+Probe).                                    |
| **SIMD**                                   | Recognize vectorized code paths and possible acceleration of brute force/decryption.       |
| **Multithreading**                         | Spot race-condition vulnerabilities.                                                       |

---

Alright — let’s close the series with the **security angle**: how architectural features can be exploited or used for defense.
This will be the bridge between **pure computer architecture** and **offensive security**.

---

# **Computer Architecture Fundamentals — Lesson 6 — Security Features & Vulnerabilities**

## 35. Hardware Security Features

Modern CPUs have built-in protections to make exploitation harder:

1. **NX-bit / DEP (Data Execution Prevention)**

   * Certain memory pages marked **non-executable**.
   * Prevents running shellcode from the stack/heap.
   * Exploit counter: Return-Oriented Programming (ROP) to reuse existing executable code.

2. **ASLR (Address Space Layout Randomization)**

   * Randomizes memory layout (stack, heap, libraries) each run.
   * Makes hardcoded addresses unreliable.
   * Weakness: Info leaks can reveal memory addresses → defeat ASLR.

3. **SMEP / SMAP (Supervisor Mode Execution/Access Prevention)**

   * Blocks kernel from executing or accessing user memory.
   * Prevents privilege escalation via jumping to user-mode code.

4. **Supervisor Mode Access Prevention (SMAP)**

   * Specifically stops the kernel from accidentally reading/writing user-space memory.

5. **Intel CET / Shadow Stack**

   * Maintains a protected copy of return addresses to detect tampering.

---

## 36. Side-Channel Vulnerabilities

Some CPU optimizations leak information indirectly:

1. **Spectre** — Exploits branch prediction and speculative execution to leak data from other processes.
2. **Meltdown** — Reads kernel memory from user space by abusing out-of-order execution.
3. **Foreshadow, Zombieload, Fallout** — Other speculative execution data leaks.
4. **Cache Timing Attacks** (Flush+Reload, Prime+Probe) — Measure cache hit/miss timing to infer secrets.

---

## 37. Memory Corruption & Exploits

These directly involve architecture concepts:

1. **Stack Buffer Overflow**

   * Overwrite saved return address on stack → redirect execution.
   * Countered by: Stack canaries, NX-bit, ASLR.

2. **Heap Exploitation**

   * Corrupt heap metadata to control memory allocation/free behavior.
   * Countered by: Safe unlinking, heap hardening.

3. **Use-After-Free**

   * Access freed memory → attacker replaces with controlled data.

4. **Integer Overflows / Underflows**

   * Miscalculate buffer sizes → memory corruption.

---

## 38. Privilege Escalation Vectors

* **Ring Escalation:** Abuse syscall vulnerabilities to go from Ring 3 → Ring 0.
* **Kernel Exploits:** Overwrite function pointers, manipulate page tables.
* **Firmware Exploits:** Inject malicious code in BIOS/UEFI, often persistent across OS reinstalls.

---

## 39. Hardware Debugging & Exploitation Tools

* **JTAG / SWD** — Hardware debugging interfaces, used in embedded RE.
* **Intel PT (Processor Trace)** — Records instruction flow (can be used for malware analysis).
* **Performance Counters** — Can be abused to measure cache timings for side channels.

---

## 40. Exploit Dev Mindset — Mapping to Architecture

When developing an exploit:

1. **Identify architecture** (x86-64, ARM, RISC-V) and **endianness**.
2. **Map calling convention** — Know where args/returns are stored.
3. **Understand memory layout** — Stack, heap, globals, mmap’d regions.
4. **Check protections** — NX, ASLR, SMEP, SMAP, CET.
5. **Leverage CPU quirks** — Speculative exec, cache timing, TLB behavior.
6. **Adapt payloads** to CPU features — ROP chains, JOP (Jump-Oriented Programming), shellcode encoding.

---

## 41. Takeaways

* CPU design affects both **attack surface** and **defense**.
* Many security features are *workarounds* for performance-oriented design choices (like speculation).
* Understanding microarchitecture details (pipelines, caches, MMU) is critical for advanced exploit development.

---

Alright — here’s your **one-page “Architecture for Hackers” reference sheet** distilled from the 6 lessons.
This is designed for **OSCP/OSED-style exploit dev and reverse engineering**.

---

# 🛠 **Architecture for Hackers — Quick Reference**

*(x86-64 / ARM focus, OS dev & exploit dev relevant)*

---

## 1️⃣ Registers & Calling Conventions

**x86-64 SysV (Linux)**

* **Args:** RDI, RSI, RDX, RCX, R8, R9
* **Return:** RAX
* **Stack:** RSP (↓ growth), RBP (frame base)

**x86-64 Windows**

* **Args:** RCX, RDX, R8, R9
* **Return:** RAX

**Common special regs**

* **RIP**: Instruction pointer
* **RSP**: Stack pointer
* **RBP**: Base/frame pointer
* **FLAGS**: Status flags (ZF, CF, OF, etc.)

---

## 2️⃣ Memory Layout (Typical Linux x86-64)

```
High addr  →  [Kernel Space]  (Ring 0)
              -------------------------
              [Stack]         (↓ grows)
              [Heap]          (↑ grows)
              [BSS / Data]    (globals)
              [Text]          (code, read-only)
Low addr   →  NULL
```

**Exploit targets**: stack return addr, heap metadata, function ptrs, GOT/PLT.

---

## 3️⃣ Memory Hierarchy

| Level | Latency (cycles) | Size     | Notes               |
| ----- | ---------------- | -------- | ------------------- |
| L1    | 4                | \~64 KB  | Per-core, split I/D |
| L2    | 12               | \~512 KB | Per-core            |
| L3    | 40+              | MBs      | Shared              |
| RAM   | 100–300          | GBs      | Slow!               |

💡 **Cache attacks**: Flush+Reload, Prime+Probe.

---

## 4️⃣ Security Features & Counters

| Feature      | Purpose                           | Bypass                 |
| ------------ | --------------------------------- | ---------------------- |
| NX-bit       | No exec on stack/heap             | ROP/JOP                |
| ASLR         | Randomize addresses               | Info leak              |
| Stack Canary | Detect ret addr overwrite         | Info leak, brute force |
| SMEP/SMAP    | Block kernel exec of user mem     | Ret2kernel gadgets     |
| CET          | Protect ret addr via shadow stack | JOP/Syscall abuse      |

---

## 5️⃣ Common Bug → Exploit Mapping

| Bug              | Exploit Path                                 |
| ---------------- | -------------------------------------------- |
| Stack overflow   | Overwrite RIP → shellcode/ROP                |
| Heap overflow    | Corrupt allocator metadata → arbitrary write |
| UAF              | Replace freed chunk with controlled data     |
| Integer overflow | Allocate too small buffer → overflow         |
| Race condition   | Exploit thread timing for inconsistent state |

---

## 6️⃣ Side-Channel Vulnerabilities

* **Spectre/Meltdown**: Speculative exec leaks.
* **Cache timing**: Extract secrets from victim processes.
* **Rowhammer**: Flip DRAM bits to escalate privileges.

---

## 7️⃣ Reverse Engineering Hotspots

When looking at disassembly:

* First 6 args in registers (SysV) or 4 (Windows).
* Watch stack pushes/pops — function frames & saved RIP.
* Memory reads/writes via `[reg+offset]` — look for buffer boundaries.
* Indirect calls/jumps — possible ROP/JOP chains.
* Syscalls — pivot from user → kernel.

---

## 8️⃣ Checklist Before Exploiting

1. Identify **ISA** (x86-64, ARM, etc.) & **endianness**.
2. Map **calling convention**.
3. Dump **memory layout** & check protections (NX, ASLR, etc.).
4. Find **bug class** (overflow, UAF, race).
5. Select payload type (ROP, JOP, shellcode).
6. Test in **debugger** (GDB, WinDbg, LLDB) with breakpoints & watchpoints.

---

📌 **Pro Tip:** Many advanced exploits come down to **turning performance features (speculation, caching) into information leaks**. Always think: *what does this hardware do in parallel that I can measure?*