#!/bin/bash
echo "$BuildString"
cd $BuildDirectory
$SourceDirectory/configure $BuildArguments
make -j
