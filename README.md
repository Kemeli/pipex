# pipex

This project should simulate the following usage of pipe ( | ) in terminal:

```< infile cmd1 | cmd2 > outfile ``` 

Where infile should be the standard input and outfile the standard output

cmd1 should write to the input of pipe and cmd2 should read from the output of pipe and write to outfile

run:

```make```

```./pipex infile "ls -a" "grep o" outfile``` 
