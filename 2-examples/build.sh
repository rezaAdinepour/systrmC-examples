#!/bin/bash

# ===== USER CONFIGURATION =====
OUTPUT_FILE="systemc_app"   # Name of the compiled binary
# ==============================

# Detect architecture
ARCH=$(uname -m)
if [[ "$ARCH" == "x86_64" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux64"
elif [[ "$ARCH" == "i686" || "$ARCH" == "i386" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux"
else
    echo "Unsupported architecture: $ARCH"
    exit 1
fi

# Find all .cpp files in current directory
CPP_FILES=(*.cpp)
CPP_COUNT=${#CPP_FILES[@]}

# Check if any .cpp files exist
if [[ $CPP_COUNT -eq 0 ]]; then
    echo "No .cpp files found in the current directory."
    exit 1
fi

# Info message
echo "Found $CPP_COUNT source file(s): ${CPP_FILES[*]}"
echo "Compiling into: $OUTPUT_FILE"

# Build compile command
CMD=(
    g++ -std=c++98
    -I. -I"$SYSTEMC_HOME/include"
    -L. -L"$SYSTEMC_LIB"
    -Wl,-rpath="$SYSTEMC_LIB"
    -o "$OUTPUT_FILE"
    "${CPP_FILES[@]}"
    -lsystemc -lm
)

# Run the command
"${CMD[@]}"
STATUS=$?

if [[ $STATUS -ne 0 ]]; then
    echo "Compilation failed."
    exit 1
fi

# Run the output binary
echo "Compilation successful. Running: ./$OUTPUT_FILE"
./"$OUTPUT_FILE"
