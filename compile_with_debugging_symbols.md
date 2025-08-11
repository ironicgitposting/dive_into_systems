1. 64-bit NASM (Linux / WSL / macOS)

    Install:
        nasm
        gdb (GNU Debugger)

    Extensions:

        CodeLLDB (cross-platform) or
        Native Debug (GDB & LLDB front-end in VS Code)

    Workflow:
        Compile with debugging symbols:

nasm -f elf64 -g -F dwarf main.asm -o main.o
ld main.o -o main

Add a launch.json in .vscode:

        {
          "version": "0.2.0",
          "configurations": [
            {
              "name": "Debug NASM (GDB)",
              "type": "cppdbg",
              "request": "launch",
              "program": "${workspaceFolder}/main",
              "stopAtEntry": true,
              "cwd": "${workspaceFolder}",
              "MIMode": "gdb",
              "miDebuggerPath": "/usr/bin/gdb"
            }
          ]
        }

        You can now hit F5 to get a debugging window with registers, stack, disassembly, breakpoints, etc., similar to C in Visual Studio.

2. Windows 64-bit

    Use MinGW-w64 GDB or Windows Subsystem for Linux (WSL) with the same setup as above.

    Alternatively, use Visual Studio Community with MASM integration for a full native debugger, but that’s not NASM.