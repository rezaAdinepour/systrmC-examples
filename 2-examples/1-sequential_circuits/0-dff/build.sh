#!/bin/bash

# ========== USER CONFIGURATION ==========
OUTPUT_FILE="dff_test"          # Name of the compiled output binary
LOG_DIR="./logs"                  # Directory for saving logs
GTKWAVE_TRACE="waveform.vcd"      # Trace file to open in GTKWave (optional)
# ========================================

# Detect system architecture
ARCH=$(uname -m)

echo "Detecting architecture and compiling source files..."

# Determine SystemC library path
if [[ "$ARCH" == "x86_64" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux64"
elif [[ "$ARCH" == "i686" || "$ARCH" == "i386" ]]; then
    SYSTEMC_LIB="$SYSTEMC_HOME/lib-linux"
else
    echo "Unsupported architecture: $ARCH"
    exit 1
fi

# Create logs directory if it doesn't exist
mkdir -p "$LOG_DIR"

# Generate timestamped log filename
TIMESTAMP=$(date +"%Y-%m-%d_%H-%M-%S")
LOG_FILE="$LOG_DIR/output_$TIMESTAMP.log"

# Collect all .cpp files in current directory
CPP_FILES=(*.cpp)

# Compile with warnings, debug symbols, and optimizations
g++ -std=c++98 -Wall -g -O2 \
    -I. -I"$SYSTEMC_HOME/include" \
    -L. -L"$SYSTEMC_LIB" \
    -Wl,-rpath="$SYSTEMC_LIB" \
    -o "$OUTPUT_FILE" "${CPP_FILES[@]}" -lsystemc -lm

# Run and save output to log if compilation succeeded
if [[ -f "$OUTPUT_FILE" ]]; then
    echo "Compilation successful. Running '$OUTPUT_FILE'..."
    echo "Output will be saved to: $LOG_FILE"
    echo "Timestamp: $TIMESTAMP"
    echo "---------------------------------------" | tee "$LOG_FILE"
    ./"$OUTPUT_FILE" 2>&1 | tee -a "$LOG_FILE"
    echo "---------------------------------------" >> "$LOG_FILE"

    # Open waveform trace in GTKWave if it exists
    if [[ -f "$GTKWAVE_TRACE" ]]; then
        echo "Opening waveform: $GTKWAVE_TRACE"
        gtkwave "$GTKWAVE_TRACE" &
    else
        echo "No trace file ($GTKWAVE_TRACE) found."
    fi
else
    echo "Compilation failed."
fi
