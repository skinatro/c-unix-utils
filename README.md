GITHUB VERSION IS A MIRROR
https://github.com/skinatro/c-unix-utils.g


# coreutils

My Version of the unix command‑line utilities.

## Requirements
- Compiler: gcc/clang (C)
- Make

## Install
From source:
```
git clone https://codeberg.com/skinatro/c-unix-utils.git it
cd c-unix-utils
make all         
```

## Compatibility
- Linux, macOS (untested), Windows via msys2 (untested)
- Native Windows (TODO)

# ToDo
- Add a style guide
- Write tests
- Write Docs
- Add a proper make file

## Utils List

[X] true
[X] false
[X] echo 
[X] pwd
[X] yes
[ ] sleep

### Pending (for now , might add more later)

whoami: Prints the current user name (fetches user info).
id: Shows user and group IDs.
tty: Prints the filename of the terminal connected to standard input.
hostname: Prints the system's hostname.
basename: Strips directory path and suffix from file names (string manipulation).
dirname: Removes the last filename part from a path.
touch: Creates empty files or updates timestamps.
mkdir: Creates directories (simple API call).
rmdir: Removes empty directories.
cat: Concatenates and prints files.
head / tail: Prints first or last N lines of a file.
wc: Counts lines, words, and bytes in files