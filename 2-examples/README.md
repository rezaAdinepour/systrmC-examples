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

### 1. Open the `build.sh` file

### 2. Edit the following line to match your program:

```bash
OUTPUT_FILE="my_output"
```

### 3. Make the script executable (you only need to do this once):

```bash
chmod +x build.sh
```

### 4. Run the script:

```bash
./build.sh
```

The script will:

* Automatically detect your system architecture (64-bit or 32-bit)

* Use the correct SystemC library path

* Compile the program with `g++`

* Run the resulting binary.

* Output of each run is saved in the `logs/` directory with a timestamp.

    + Example: `logs/output_2025-08-05_14-30-22.log`

    + If your SystemC simulation generates a `waveform.vcd` file, it will be automatically opened in GTKWave (if installed).


You must have GTKWave installed, If you don't have install it, you can install as bellow:

```bash
sudo apt install gtkwave
```