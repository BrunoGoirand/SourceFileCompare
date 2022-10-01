# Source File Compare

Source File Compare (sfc) is a simple code to compare source code files.
It helps to find the difference between two files that are supposed to be identical.

## Usage

```bash
./sfc dir1 dir2 filename
```

- `dir1` - The name of the directory where the first file to compare is located
- `dir2` - The name of the directory where the second file to compare to is located
- `filename` - the file name to be compared

## Description

The file name to be compared should be the same but located in two different directories

The code is looking for:

`dir1/filename`
and
`dir2/filename`

On the first difference between the two files, the execution stops and print out where it is located in both files

In order to compare each lines of code, the algorithm removes:

- all 'spaces'
- C++ comments

### All 'spaces'

The 'spaces' that are taken into accounts are the ones treated by `isspace()`.
It includes:

- ` ` (0x20) space (SPC)
- `\t` (0x09) horizontal tab (TAB)
- `\n` (0x0a) newline (LF)
- `\v` (0x0b) vertical tab (VT)
- `\f` (0x0c) feed (FF)
- `\r` (0x0d) carriage return (CR)

## C++ comments

Every thing after double slash characters: `//`)

## External Libraries

The code is using the string library [NeatString](https://github.com/BrunoGoirand/NeatString.git).

## To Do

- Add C style comments removal `/* ... */`
- Add comments line starting with `#`
