#!/bin/bash

# in a given directory path, list all contents.
# if content is file, print its length.
# if content is directory, print its user.

# to check if path exists: test -e path
# to check if path is of directory: test -d path
# to check if path is of file: test -f path
# to check if file/dir is readable: test -r path
# to check if file/dir is writable: test -w path
# to check if file/dir is executable: test -x path

# to print length of file: stat -c %s path 
# to print user of file: stat -c %U path

echo -n "enter a path: "
read path

if [ ! -e $path ]
then
	echo "path doesn't exists."
	exit
fi

if [ -d $path ]
then
	cd $path
	for entry in `ls $path`
	do
		if [ -f $entry ]
		then
			res=`stat -c %s $entry`
			echo "file: $entry (length: $res bytes)"
		else
			res=`stat -c %U $entry`
			echo "dir : $entry (user: $res)"
		fi
	done
else
	echo "path is not of a directory"
fi

