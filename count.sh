#!/bin/bash
read -p "Enter the directory you wish to count all files in: "
VAL="$(find "$REPLY" -type f | wc -l)"
echo "Directory $REPLY has $VAL files"


