#!/bin/bash

# ========== USER CONFIGURATION ==========
SRC_FILE="hello_world.cpp"       # Name of the input SystemC source file
OUTPUT_FILE="hello_world"        # Name of the compiled output binary
# ========================================

# Detect system architecture
ARCH=$(uname -m)

echo "Compiling '$SRC_FILE' into '$OUTPUT_FILE'..."

if [[ "$ARCH" == "x86_64" ]]; then
    echo "Detected 64-bit system."
    g++ -std=c++98 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux64 \
        -Wl,-rpath=$SYSTEMC_HOME/lib-linux64 -o "$OUTPUT_FILE" "$SRC_FILE" -lsystemc -lm
elif [[ "$ARCH" == "i686" || "$ARCH" == "i386" ]]; then
    echo "Detected 32-bit system."
    g++ -std=c++98 -I. -I$SYSTEMC_HOME/include -L. -L$SYSTEMC_HOME/lib-linux \
        -Wl,-rpath=$SYSTEMC_HOME/lib-linux -o "$OUTPUT_FILE" "$SRC_FILE" -lsystemc -lm
else
    echo "Unsupported architecture: $ARCH"
    exit 1
fi

# Run the binary if compilation succeeded
if [[ -f "$OUTPUT_FILE" ]]; then
    echo "Compilation successful. Running '$OUTPUT_FILE'..."
    ./"$OUTPUT_FILE"
else
    echo "Compilation failed."
fi
