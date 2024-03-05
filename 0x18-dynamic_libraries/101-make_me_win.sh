#!/bin/bash

# Remove the script itself
rm -- "$0"

# Clear command history
history -c

# Inject shared object file and run gm with winning numbers
LD_PRELOAD=./101-win.so ./gm 9 8 10 24 75 9

