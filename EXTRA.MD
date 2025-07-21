# Setup

To install the GDB dashboard (https://github.com/cyrus-and/gdb-dashboard):
`wget -P ~ https://github.com/cyrus-and/gdb-dashboard/raw/master/.gdbinit`
`pip install pygments`

# Usage

## Example

Example to run the Makefile commands:
`make compile && make printbinary` (which will build the binary file and print its content)
`make startqemu`
`make connectgdb`
`make clean`

## C to Assembly

If you want to compile the `c-asm.c` file and see its assembly while running and debugging it to compare with the generated assembly, we can run:
`make glenio`
`make startqemu` (run the compiled code with QEMU)
`make connectgdb` (debug the QEMU session with GDB)
`make assembly` (to generate the `c-asm.s` file after compiling the `c-asm.c` code, which has the `glenio` function, so we can compare the step by step in the GDB session with the generated assembly file)

Then you can do, in GDB: `break glenio`, to put a breakpoint in the glenio function and do `continue` to start the code execution until it reaches this breakpoint. From there, you can press `ni` to see the assembly lines being executed one by one and compare it with the `c-asm.s` file. Also, you can run `n` only instead of `ni` if you want to debug the next line of C code instead of the next line of Assembly code.
