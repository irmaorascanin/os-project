# Shell Project

## Members
- Irma Orascanin
- Adela Kovac


## Task Overview

### Task 1.1: Shell Interface

**Objective**: Implement a basic shell interface that supports the execution of commands.

- Implemented a shell that displays `prompt$` and executes built-in commands (`cp`, `history`, `free`, `fortune`).
- Advanced version: Displays the prompt as `machinename@username:~$`, using the system's hostname and username.

**Implemented**:  
- Created the `main.c` file that starts the shell interface and processes user input.
- Implemented the `parse_input()` function to split commands into arguments and the `execute_command()` function to handle command execution, including forking new processes for each command.

### Task 1.2: Shell Programs/Commands

**Objective**: Implement basic commands `cp`, `history`, `free`, and `fortune`.

- **cp**: Copies a file from source to destination.
- **history**: Displays the history of commands entered.
- **free**: Displays memory information from `/proc/meminfo`.
- **fortune**: Displays a random fortune from a predefined list.

**Implemented**:  
- Created `cp.c` to implement file copy functionality using `open()`, `read()`, and `write()` system calls.
- Created `history.c` to save commands to a history file and display the history on demand.
- Created `free.c` to read and display memory information from `/proc/meminfo`.
- Created `fortune.c` to display a random fortune from a predefined array.

### Task 1.3: System Calls

**Objective**: Implement system calls like `fork()`, `exec()`, and `wait()`.

- The program uses `fork()` to create child processes for executing commands.
- Used `execvp()` to run external programs and `wait()` to wait for processes to finish.

**Implemented**:  
- `fork()` is used in `execute_command()` to create a new process for each command.
- `execvp()` is used to execute external commands like `cp`, `history`, `free`, and `fortune`.
- `wait()` ensures that the parent process waits for the child process to finish.

### Task 1.4: Add Colors to the Shell

**Objective**: Add color to the shell prompt.

**Implemented**:  
- Used ANSI escape codes to change the color of the shell prompt.
- Modified `display_prompt()` function to include dynamic hostname and username using `gethostname()` and `getlogin()`.

```c
void display_prompt() {
    char hostname[128];
    gethostname(hostname, sizeof(hostname));
    char *username = getlogin();
    printf("%s@%s:~$ ", username, hostname);  // Colored prompt
}

Task 1.5: Answering Questions
1.5.1: Do the following actions require the OS to use kernel mode or user mode is sufficient? Explain.
A program wants to read from disk: Kernel mode is required for disk operations, as accessing hardware resources like disk needs to be done by the kernel for protection and control.

Reading the current time from the hardware clock: Kernel mode is required since reading system time typically involves accessing hardware and is a privileged operation handled by the kernel.

1.5.2: Explain the purpose of a system call. List them and give at least 2 examples for each category.
Purpose of System Calls: System calls provide an interface between user programs and the operating system. They allow programs to request services such as file handling, process control, memory allocation, etc.

Categories and Examples:

Process control:

fork(): Creates a new process.

exec(): Replaces the current process image with a new one.

File management:

open(): Opens a file.

read(): Reads from a file.

1.5.3: What are the possible outputs printed from this program?
This depends on the scenario. The program checks for valid commands like cp, history, free, and fortune:

If a command exists, it prints the output of the command.

If not, it prints Command not found.

If an error occurs while forking or executing a command, an error message is printed using perror().

Task 1.6: Challenges Faced
Challenge 1: Implementing pipelining and redirecting output.

Solution: Used pipe() and dup2() to redirect output from one command to another.

Challenge 2: Managing child processes and avoiding zombies.

Solution: Used wait() to ensure the parent waits for the child to complete.

