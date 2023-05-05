# A Simple UNIX command-line interpreter (Shell)

## Description

This is a simple UNIX command line interpreter created in C language from scratch that is capable of executing basic commands. It was developed as a project for the ALX Software Engineering program.

## Installation

Clone the repository:

```sh
$ git clone https://github.com/your_username/simple_shell.git
```

Change directory to simple_shell:

```sh
$ cd simple_shell
```

Compile the program:

```sh
$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
```

## Usage

Run the program:

```sh
$ ./hsh
```

The prompt `$ ` will be displayed waiting for a command to be entered.

```sh
$ ls
```

The command `ls` is executed and its output is displayed. The prompt is displayed again waiting for a new command.

### Built-ins

The shell includes the following built-ins:

- `exit`: exits the shell.

### Command Lines with Arguments

Command lines with arguments are supported. For example:

```sh
$ ls -l /tmp
```

### Handling the PATH

The shell handles the `PATH` variable to locate executables. If an executable cannot be found in any of the directories listed in `PATH`, an error message is displayed.

### Buffering and Read System Call

The shell uses a buffer to read many characters at once and call the least possible the read system call, avoiding unnecessary calls to read.

### Variables Replacement

The shell handles variables replacement. The following variables are supported:

- `$?`: displays the exit status of the last command executed.
- `$$`: displays the process ID of the current shell.

### Error Handling

The shell handles errors such as incorrect command syntax, invalid arguments, and command not found, displaying appropriate error messages and returning the appropriate exit status.

## Contributors

- [Abubakr Ali](https://github.com/abubakrali10)
- [Amgad Fikry](https://github.com/amgadfikry)
