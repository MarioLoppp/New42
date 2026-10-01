*This project has been created as part of the 42 curriculum by /<marlope3>.*

## Description

`ft_printf` is a C implementation of selected features of libc's `printf`.
It introduces variadic arguments and builds a static library, `libftprintf.a`,
without implementing the original function's buffer management.

The mandatory conversions are `%c`, `%s`, `%p`, `%d`, `%i`, `%u`, `%x`, `%X`
and `%%`. The bonus sources implement parsing and formatting for flags `-`,
`0`, `#`, `+`, space, minimum field width and precision where applicable.

## Instructions

Requirements: `make`, a C compiler available as `cc`, and `ar`.

```sh
make                 # Build the mandatory library
make bonus           # Build the bonus library
make clean           # Remove object files and the bonus marker
make fclean          # Also remove the library
make re              # Rebuild mandatory from scratch
```

Run `make fclean` before switching between mandatory and bonus builds.
To use the library, include `ft_printf.h` and link your program:

```sh
cc -Wall -Wextra -Werror main.c -I. -L. -lftprintf -o example
```

The function accepts a format string followed by its arguments and returns
the number of characters printed during a successful call.

## Algorithm And Data Structure

The function scans the format string from left to right. Ordinary characters
are written directly; a `%` starts a conversion. `va_list` and `va_arg` provide
the argument corresponding to the conversion type.

For bonus formatting, a `t_flags` structure stores alignment, zero filling,
prefix and sign options, width, and precision. A separate `dot` field
distinguishes missing precision from an explicit precision of zero. The parser
reads flags, width, precision and the conversion in that order, then applies
precedence rules such as `-` overriding `0`.

Each printer calculates the content length before adding spaces or zeroes.
Signed and unsigned decimal printers share string-formatting helpers;
hexadecimal output uses recursive digit printing. This separation keeps parsing
independent from output and makes formatting logic reusable. Temporary decimal
strings are freed after printing.

## Resources

- [printf(3)](https://man7.org/linux/man-pages/man3/printf.3.html): conversions,
  flags, precision and return values.
- [stdarg(3)](https://man7.org/linux/man-pages/man3/stdarg.3.html): variadic arguments.
- [GNU Make Manual](https://www.gnu.org/software/make/manual/make.html): build rules.
- [Francinette](https://github.com/xicodomingues/francinette) and
  [printfTester](https://github.com/Tripouille/printfTester): testing resources.

AI assistance was used to explain formatting rules and pointers, review code,
propose and adapt decimal and hexadecimal formatting helpers, edit headers and
the Makefile, troubleshoot the tester's Valgrind/DWARF compatibility, and draft
this README. Its suggestions required review and comparison with the subject
and libc behavior; some suggestions were corrected during development.
