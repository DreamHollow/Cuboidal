#!/bin/sh

BUILD_DIR='build'
BINARY='cuboidal'

if [ -f 'CMakeLists.txt' ]
then
	echo "CMakeLists found."
else
	echo "ERROR: No CMakeLists to operate from!"
	return 1
fi

cmake -S . -B build

if [ -d $BUILD_DIR ]
then
	cd $BUILD_DIR
	make

	if [ -f $BINARY ]
	then
		echo "Binary built successfully."
	else
		echo "ERROR: Binary failed to build or is corrupt!"
		return 1
	fi
else
	echo "Build directory not found!"
	return 1
fi

return 0
