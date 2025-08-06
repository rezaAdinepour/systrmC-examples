#!/bin/bash

set -e  # Exit on error

# === CONFIGURATION ===
SYSTEMC_VERSION="2.3.1a"
INSTALL_DIR="/usr/local/systemc-2.3.1"
ARCHIVE_NAME="systemc-${SYSTEMC_VERSION}.tar.gz"
SOURCE_DIR="systemc-${SYSTEMC_VERSION}"
DOWNLOAD_URL="http://accellera.org/images/downloads/standards/systemc/${ARCHIVE_NAME}"

# === DETECT SHELL CONFIG FILE ===
if [[ $SHELL == */zsh ]]; then
    SHELL_CONFIG="$HOME/.zshrc"
else
    SHELL_CONFIG="$HOME/.bashrc"
fi

echo "=== [1/8] Installing dependencies ==="
sudo apt update
sudo apt install -y build-essential gcc g++ make wget

echo "=== [2/8] Downloading SystemC ${SYSTEMC_VERSION} ==="
wget -O "$ARCHIVE_NAME" "$DOWNLOAD_URL"

echo "=== [3/8] Extracting ${ARCHIVE_NAME} ==="
tar -xzf "$ARCHIVE_NAME"

echo "=== [4/8] Creating build directory and configuring ==="
cd "$SOURCE_DIR"
mkdir -p objdir && cd objdir
../configure --prefix="$INSTALL_DIR"

echo "=== [5/8] Building SystemC (this may take a while) ==="
make -j"$(nproc)"

echo "=== [6/8] Installing SystemC to $INSTALL_DIR ==="
sudo make install

echo "=== [7/8] Adding environment variables to $SHELL_CONFIG ==="
if ! grep -q "export SYSTEMC_HOME=" "$SHELL_CONFIG"; then
    {
        echo -e "\n# SystemC configuration"
        echo "export SYSTEMC_HOME=$INSTALL_DIR"
        echo 'export LD_LIBRARY_PATH=$SYSTEMC_HOME/lib-linux64:$LD_LIBRARY_PATH'
        echo 'export CPLUS_INCLUDE_PATH=$SYSTEMC_HOME/include:$CPLUS_INCLUDE_PATH'
    } >> "$SHELL_CONFIG"
    echo "Environment variables added."
else
    echo "Environment variables already present in $SHELL_CONFIG"
fi

echo "=== [8/8] Reloading shell configuration ==="
source "$SHELL_CONFIG" || echo "Please restart your terminal to apply the changes."

echo -e "\nSystemC ${SYSTEMC_VERSION} has been installed successfully!"
