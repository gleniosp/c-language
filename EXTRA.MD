To install the GDB dashboard (https://github.com/cyrus-and/gdb-dashboard):
wget -P ~ https://github.com/cyrus-and/gdb-dashboard/raw/master/.gdbinit
pip install pygments

Then run the Makefile commands, like:
make compile && make printbinary (which will build the binary file and print its content)
make startqemu
make connectgdb
make clean
