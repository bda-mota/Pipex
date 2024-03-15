## Pipex
A 42 project where we have to imitate shell pipelines and input/output file redirections.

### How it works
 It works like in shell: < infile cmd1 | cmd 2 > outfile 
Where:
infile -> is the file for input
cmd1 -> first command 
cmd2 -> second command 
outfile -> the file for outputk 

### How to use 
for example: 
 ./pipex_bonus Makefile "tr A-Z a-z" nl outfile
