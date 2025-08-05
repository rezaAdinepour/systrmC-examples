# SystemC installation:


### 1. Prerequisites

Before you begin, run the command below in your terminal to ensure all required tools for compiling SystemC files are installed.

```bash
sudo apt-get install build-essential
```


### 2. Download

You can download SystemC-2.3.1a by bellow command:

```bash
wget http://accellera.org/images/downloads/standards/systemc/systemc-2.3.1a.tar.gz
```

The downloaded file will be named `systemc-2.3.1a.tar.gz`. To extract it, make sure you're in the same directory as the file, then run the following command:

```bash
tar -xvf systemc-2.3.1a.tar.gz
```

### 3. Building

Now, navigate to the `systemc-2.3.1a/` directory. Inside it, create a new folder named `objdir`, and then move into that folder.

```bash
cd systemc-2.3.1a/

mkdir objdir
```

Next, run the following command from within the `objdir` directory.

```bash
sudo ../configure --prefix=/usr/local/systemc-2.3.1/
```

If everything has been set up correctly, execute the following command from inside the `objdir` directory. Please be patient — this step may take some time to complete.

```bash
sudo make -j$(nproc)
```

Once the build process is complete, run the following command to install it.

```bash
sudo make install
```

Congratulations! The setup is now complete.


### 3. Add systemC PATH

After the installation is finished, don’t forget to set the installation path by adding the following line to your shell configuration file (e.g., `~/.bashrc` or `~/.zshrc`):

```bash
export SYSTEMC_HOME=/usr/local/systemc-2.3.1/
```

```bash
source ~/.bashrc
```
(Or `source ~/.zshrc` if you’re using Zsh)

