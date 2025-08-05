## Compiling SystemC Program

To generate the executable, use the appropriate command below based on your system architecture (64-bit or 32-bit):

### For 64-bit systems:

(Note: The command is long—scroll horizontally if needed)

```bash
g++ -std=c++98 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 \
    -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o <your_output_name> <program_name>.cpp -lsystemc -lm
```

### For 32-bit systems:

```bash
g++ -std=c++98 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux \
    -Wl,-rpath=$SYSTEMC_HOME/lib-linux -o <your_output_name> <program_name>.cpp -lsystemc -lm

```

Once the command completes successfully, an executable file named `<your_output_name>` will be created in the current directory.

To run the program, use:

```bash
./<your_output_name>
```


## Compiling Your SystemC Programs (Easy Setup)

To compile and run any SystemC program with a single script:

### 1. Open the `compile_and_run.sh` file

### 2. Edit the following two lines to match your program:

```bash
SRC_FILE="your_source.cpp"       # The name of your C++ source file
OUTPUT_FILE="your_program_name"  # The desired name of the compiled binary
```

### 3. Make the script executable (you only need to do this once):

```bash
chmod +x compile_and_run.sh
```

### 4. Run the script:

```bash
./compile_and_run.sh
```

The script will:

* Automatically detect your system architecture (64-bit or 32-bit)

* Use the correct SystemC library path

* Compile the program with `g++`

* Run the resulting binary
