# pipex

### Program name
`pipex`
### Description
The purpose of this project is the discovery in detail UNIX mechanism - pipe.
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
a
aaa
aa
aaa
aaaa
bb
aaa
cccccccccc
```
Run
```sh
$ ./pipex infile 'grep "aaa"' 'wc -l' "tr -d ' '" outfile
$ ./pipex here_doc LIMITER cat 'grep "Hello"' "awk '{print $3}'" outfile
```
They should be the same:
```sh
$ < infile grep "aaa" | wc -l | tr -d ' ' > outfile
$ cat << LIMITER | grep "Hello" | awk '{print $3}' >> outfile
```
Type in heredocument as below
```sh
$ heredoc> a
$ heredoc> b
$ heredoc> Hello 4 2 Tokyo
$ heredoc> Hello 42 Tokyo
$ heredoc> c
$ heredoc> LIMITER
```
Then the character "4", "2" and "Tokyo" should be written to outfile
