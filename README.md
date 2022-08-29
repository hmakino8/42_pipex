# pipex

### Program name
`pipex`
### Description
A project that implements pipes and redirects to mimic unix commands
- Allowed external functions are below
  - `access`
  - `open`
  - `unlink`
  - `close`
  - `read`
  - `write`
  - `malloc`
  - `waitpid`
  - `wait`
  - `free`
  - `pipe`
  - `dup`
  - `dup2`
  - `execve`
  - `fork`
  - `perror`
  - `strerror`
  - `exit`

## How it works
1. ### Compile
```sh
$ make
```
2. ### Handle multiple pipes
  file1 and file2 are file names, cmd1 and cmd2 are shell commands with their parameters. 
```sh
$ ./pipex file1 cmd1 cmd2 cmd3 ... cmdn file2
```
It should be equivalent to:
```sh
$ < file1 cmd1 | cmd2 | cmd3 ... | cmdn > file2
```
3. ### Support << and >> when the first parameter is "here_doc"
```sh
$ ./pipex here_doc LIMITER cmd cmd1 cmd3 ... cmdn file
```
It should be equivalent to:
```sh
$ cmd << LIMITER | cmd1 | cmd2 | cmd3 ... cmdn >> file
```
## Examples
Prepare a file like below
- infile
```
a↩️
aaa↩️
aa↩️
aaa↩️
aaaa↩️
bb↩️
aaa↩️
cccccccccc↩️
```
```sh
$ ./pipex infile 'grep aaa' 'wc -l' outfile
```
It should be the same as:
```sh
$ < infile ls -l | wc -l > outfile
```
$ ./pipex
```sh
$ ./pipex here_doc cat 'grep "Hello"' "awk '{print \$2}'" outfile
```
Type in heredocument as below
```sh
$ heredoc> a
$ heredoc> b
$ heredoc> Hello 42$
$ heredoc> c
$ heredoc> LIMITER
```
Then the character "4" and "42" should be written to outfile
