#!/bin/bash

# Convert all .ppm images in subdirectories to greyscale using mogrify.
# Based on script posted at http://www.imagemagick.org/discourse-server/viewtopic.php?f=1&t=23424&p=98519&hilit=recursive#p98555

list=`find ~/Documents/git/P/colorferet/colorferet/dvd1/data/images -type d`    # Get all subdirectories
for directory in $list; do                                                      # In each subdirectory
cd $directory
mogrify -format pgm *.ppm                                                       # Convert all .ppm to .pgm
cd ..
done