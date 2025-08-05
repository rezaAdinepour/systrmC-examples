#!/bin/bash

# ========== USER CONFIGURATION ==========
OUTPUT_FILE="adder_test"   # Name of the compiled output binary
# ========================================

# Detect system architecture
ARCH=$(uname -m)

echo "🔍 Detecting architecture and compiling source files..."

# Determine library path
if [[ "$ARCH" == "x86_64" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux64"
elif [[ "$ARCH" == "i686" || "$ARCH" == "i386" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux"
else
    echo "❌ Unsupported architecture: $ARCH"
    exit 1
fi

# Compile all .cpp files in the current directory
CPP_FILES=(*.cpp)

g++ -std=c++98 -I. -I"$SYSTEMC_HOME/include" -L. -L"$SYSTEMC_LIB" \
    -Wl,-rpath="$SYSTEMC_LIB" -o "$OUTPUT_FILE" "${CPP_FILES[@]}" -lsystemc -lm

# Run if successful
if [[ -f "$OUTPUT_FILE" ]]; then
    echo "✅ Compilation successful. Running '$OUTPUT_FILE'..."
    ./"$OUTPUT_FILE"
else
    echo "❌ Compilation failed."
fi
