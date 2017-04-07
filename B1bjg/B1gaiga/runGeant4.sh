#!/bin/bash
sourcefolder=$(pwd)
buildfolder=${sourcefolder}/build
installfolder=${sourcefolder}/install
mkdir -p ${buildfolder}
rm -rf ${buildfolder}/*
cd ${buildfolder}
cmake ${sourcefolder} -DCMAKE_INSTALL_PREFIX=${installfolder} -DCMAKE_BUILD_TYPE=Release 
make -j4
./exampleB1

