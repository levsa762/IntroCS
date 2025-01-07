#!/bin/bash

if [ -z "$1" ]; then
    echo "Usage: $0 folder_name"
    exit 1
fi

folder="$1"

# Change to the specified folder
cd "$folder" || exit 1

# Find a .cpp file and extract the base name without _Q1
file_name=$(ls *.cpp | head -n 1)
zip_name="${file_name%_Q1.cpp}.zip"

# Create the zip file containing all .cpp files
zip "$zip_name" *.cpp

echo "Zip file created: $folder/$zip_name"
