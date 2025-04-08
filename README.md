#Pipex

The goal of this project is to rebuild the behavior of the pipe : | as it works in a bash command. 

With the bonus part, the program has to handle an undetermined number of pipes, creating a pipeline between command, turning the output of each one into the input of the next one untill the last one outputs its return value to the terminal.
This seems easy at first. The problem is that when you try to execute a shell command in a C program, the execve() function replaces the process with the execution of the command, returns its output and exits. Making it imposible to execute other commands or do anything else by using only one process. 

The trick is to use child processes. By forking the program and creating a entirely new process, we can execute every command and return their outputs to the main process to pass them on to the next child until the pipeline reaches the sea. 
This involves using pipes to communicate between processes, hence the name : pipex.

This project was instructive but it took me some time and 2 retries. 
