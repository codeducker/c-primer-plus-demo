#!/bin/bash
cd build
cmake -DEXECUTE_FILE_NAME=$1 ..
cmake --build .
./c_primer_plus_demo
