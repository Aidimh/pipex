# pipex
A low-level systems project from the 42 Network (1337) that replicates the Unix pipe mechanism (&lt; file1 cmd1 | cmd2 > file2). Implemented multiprocess creation using fork, inter-process communication via pipes, environment path parsing, file descriptor manipulation, and precise POSIX-compliant error handling.

# Pipex — Pipeline Inter-Process Communication & Command Execution

An intensive systems programming project from the **1337 / 42 Network** curriculum. The objective of this project is to simulate the exact behavior of the Unix pipeline mechanism (`< infile cmd1 | cmd2 > outfile`) within a C program. 

This project delves deep into low-level POSIX systems engineering, exploring multiprocess synchronization, file descriptor redirection, pipeline streams, and environment parsing.

---

## 🛠️ Key Architectural Focus Areas

* **Process Forking (`fork`):** Managing parallel program execution by spawning concurrent child processes from a parent driver process, ensuring proper lifecycle management.
* **Inter-Process Communication (`pipe`):** Opening unidirectional data channels via pipe file descriptors to stream the standard output (`stdout`) of an upstream process into the standard input (`stdin`) of a downstream command.
* **Stream Redirection (`dup2`):** Manipulating system file descriptor tables to redirect file reads and writes seamlessly into standard input/output channels.
* **Environment Path Parsing:** Extracting and parsing the global `envp` array to locate the precise absolute system binaries (e.g., `/bin/ls` or `/usr/bin/grep`) for executing shell commands via `execve`.
* **Robust Error Handling:** Ensuring leak-free failure isolation by closing unused pipe ends across child boundaries, preventing process deadlocks, and replicating standard shell error exit codes (e.g., Command Not Found).

---

## 📋 Theoretical Workflow Structure

The engine processes file descriptors and standard input/output mapping using the following low-level system design:

```text
       ┌───────────┐                                      ┌───────────┐
       │  Infile   │                                      │  Outfile  │
       └─────┬─────┘                                      └─────▲─────┘
             │ (fd open)                                        │ (fd open)
             ▼                                                  │
       ┌───────────┐          ┌────────────────┐          ┌─────┴─────┐
       │   cmd1    │─────────►│  pipe[1] (write)│          │   cmd2    │
       │ (child 1) │          └────────────────┘          │ (child 2) │
       └───────────┘                  │                   └─────▲─────┘
                                      ▼                         │
                              ┌────────────────┐                │
                              │  pipe[0] (read)│────────────────┘
                              └────────────────┘
```

---

## 🚀 Compilation & Usage

The project features a strict `Makefile` designed to compile the pipeline engine cleanly under compiler flags.

### Build Commands:
```bash
# Compile the main pipex executable
make

# Remove binary object components (.o)
make clean

# Full clean: Clear object files and the final executable
make fclean

# Perform a clean rebuild
make re
```

### Execution Example:
Run the executable by mimicking standard shell arguments:

```bash
# How to run pipex:
./pipex infile "grep hello" "wc -l" outfile

# This achieves the exact same operational result as the terminal command:
< infile grep hello | wc -l > outfile
```

---

## ⚡ Bonus Architecture (Multiple Pipelines & Here_Doc)
The bonus deployment dramatically scales the execution engine to replicate advanced shell mechanics:
* **Multiple Pipes:** Supports infinite sequential pipelines to handle complex command execution chains (`./pipex infile cmd1 cmd2 cmd3 ... cmdN outfile`).
* **Here_Doc Redirection:** Integrates the standard input literal delimiter functionality (`<<`), simulating the shell pipeline behavior of `./pipex here_doc LIMITER cmd1 cmd2 outfile`.
