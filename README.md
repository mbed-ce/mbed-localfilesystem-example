# Mbed LocalFileSystem Example
This project shows how to use the LocalFileSystem feature unique to the Mbed LPC1768 board.  This feature allows you to store files on a dedicated flash memory which are also visible to the host PC.


## How to set up this project:

1. Clone it to your machine.  Don't forget to use `--recursive` to clone the submodules: `git clone --recursive https://github.com/mbed-ce/mbed-localfilesystem-example.git`
2. Set up the GNU ARM toolchain (and other programs) on your machine using [the toolchain setup guide](https://github.com/mbed-ce/mbed-os/wiki/Toolchain-Setup-Guide).
3. Set up the CMake project for editing.  Use `MBED_TARGET=LPC1768`.  We have three ways to do this:
    - On the [command line](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-Command-Line)
    - Using the [CLion IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-CLion)
    - Using the [VS Code IDE](https://github.com/mbed-ce/mbed-os/wiki/Project-Setup:-VS-Code)
4. Build the `flash-mbed-example-localfilesystem` target to upload the code to a connected device.

## Example Behavior

This example is an extended version of the example code given in the [LocalFileSystem docs](https://mbed-ce.github.io/mbed-os/classmbed_1_1_local_file_system.html).  It performs three tasks in order:

1. Create or append to a file, "out.txt", on the local file system.  The line "Hello World!" is added to the end.
2. Open out.txt for reading and print its contents.  You should see a number of "Hello World!" messages equal to the number of times you've run the example.
3. Print all the file names on the LocalFileSystem.  You should see "out.txt" show up, plus any additional files you've added.

After running the example, you should be able to see out.txt from the computer, with the correct contents.  Note that you might have to unplug and replug the board before you can see it (seems to be some sort of bug in the interface).

