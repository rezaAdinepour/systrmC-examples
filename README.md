# systrmC-examples
A comprehensive collection of SystemC examples progressing from foundational modules to advanced system-level simulations. This repository is intended for students, engineers, and researchers interested in learning and applying SystemC for digital hardware design and modeling.

[Live Link to Repository](https://github.com/rezaAdinepour/systrmC-examples.git)


---

## Contents

### Step 1: Foundational Modules
Basic building blocks written using `SC_MODULE`, each in its own header/source/testbench:
- MUX (2:1)
- DEMUX (1:2)
- Comparator
- Decoder (2-to-4)
- Encoder (4-to-2)
- Priority Encoder (4-to-2)
- Up-Down Counter
- Shift Register
- FSM: Sequence Detector

### Step 2: Communication Interfaces
Modeling various synchronization and communication mechanisms:
- Ready/Valid Handshake
- FIFO Channel (blocking and non-blocking)
- Multi-stage FIFO Stream Pipeline

### Step 3: Memory-Mapped I/O System
Simulating register access via memory-mapped interfaces:
- Register Devices with Address Decoding
- Bus Arbiter (multiple master access)

### Step 4: AXI4-Lite Bus System
A complete simulation of AXI4-lite memory-mapped components:
- AXI4-Lite Master
- AXI4-Lite Slave Memory
- Basic Read/Write Transactions
- VCD waveform tracing via `gtkwave`

---

## Getting Started

### 1. Install SystemC (v2.3.1a)

You can install manually or use the automated script provided.

```bash
cd scripts/
chmod +x build.sh
./build.sh
```

## Requirements

* SystemC 2.3.1a
* g++ with C++98 support
* GTKWave (for waveform viewing)
* Linux OS (Ubuntu recommended)


## License
This project is open source and licensed under the MIT License.




## Contributions

Contributions are welcome and appreciated!

If you'd like to contribute to this project — whether it's fixing bugs, improving documentation, adding new SystemC examples, or refactoring code — please follow the steps below:

### How to Contribute

1. **Fork the repository**  
   Click the “Fork” button in the top right corner of the repo page.

2. **Clone your forked repository**
   ```bash
   git clone https://github.com/rezaAdinepour/systrmC-examples.git
   cd systrmC-examples
    ```

3. **Create a new branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

4. **Make your changes and commit them**
   ```bash
   git add .
   git commit -m "Add: your description of the change"
   ```

5. **Push to your fork**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Create a Pull Request**
* Go to the original repository (this one).
* Click “Compare & pull request”.
* Add a meaningful description and submit.