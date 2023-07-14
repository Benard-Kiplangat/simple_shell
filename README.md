# Simple Shell Project

A simple UNIX command interpreter, similar to `sh` command.

## Background context

The challenge is to solidify the concepts of C programming language. Here are the background concepts about The Shell in general:

### What is a UNIX Shell

A shell is a command-line interpreter. A command line interpreter is a program that execute other programs based on the text commands provided to it. A UNIX shell provides a command line interface that allows users to interact and control the operating system and the execution of the system for Unix-like Operating systems.

The first UNIX shell was the Thompson Shell, sh, which was designed and implemented as the original Unix operating system by Ken Thomson at Bell Labs. This shell was distributed in Versions 1 through 6 of UNIX.

From version 7 of UNIX, Stephen Bourne at Bell Labs, created and distributed Bourne Shell in 1979. Later, several other shells were developed that were meant as replacement or improvement of the Bourne Shell. Now, the POSIX standard specifies the Korn Shell as a subset of its standard shell.

### How does a shell work?


### What is a pid and a ppid

Every instance of an executing program has a unique process id, called PID in short. This PID will be used by other functions or system calls to interact and manipulate the process.

PPID means parent process ID, for each process has a parent process that created it. To get PID or PPID for your program, use `getpid` or `getppid` function respectively.

### How to manipulate the environment of the current process


### What is the difference between a function and a system call


### How to create processes


### What are the three prototypes of main


### How does the shell use the PATH to find the programs


### How to execute another program with the execve system call


### How to suspend the execution of a process until one of its children terminates


### What is EOF / “end-of-file”?


