#!/bin/sh

BUILD_DIR='build'
BINARY='cuboidal'

if [ -d "$BUILD_DIR" ]
then
	cd "$BUILD_DIR"
	if [ -f "$BINARY" ]
	then
		./"$BINARY"
	else
		echo "Unable to find executable."
	fi
else
	echo "Unable to find build directory."
	return 1
fi

return 0
