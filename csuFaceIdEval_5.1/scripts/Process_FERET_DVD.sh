#!/bin/bash

useage() {
    echo "This script converts images from the FERET color CD Disk 2."
    echo "    Run this script with the top level DVD as the only argument"
    echo "Example:"
    echo "  cd csuFaceIdBenchmark"
    echo "  ./Process_FERET_DVD.sh  /Volumes/CDROM"
}

check_command() {
    if [ ! -x "$@" ] ; then
        echo "*** ERROR *** The following command could not be found:"
        echo "    $@"
        echo "    Make sure this exicutable is avalible and on your \$PATH."
        exit 1
    fi
}

check_file() {
    printf "    Checking: $@ "
    if [ ! -r "$@" ] ; then
        echo 
        echo
        echo "*** ERROR *** The following file could not be found on the DVD:"
        echo "    $@"
        echo "    Please check this path and make sure the file is readable."
        exit 1
    else
        printf "    <OK> \n"
    fi
}

if [ $# -ne 1 ] ; then
    useage
fi

bzcat=`which bzcat`
check_command $bzcat

convert=`which convert`
check_command $convert

# create the pgm directory
mkdir -p data/FERET/source/pgm

# convert each file to pgm format
for each in `cat imagelists/all_cd1.srt` ; do
    file=`basename $each .sfi`
    source="$@/gray_feret_cd1/data/images/${file}.tif.bz2"
    dest=
    check_file "$source"
    echo "    Convert:  $source"
    $bzcat "$source" > data/FERET/source/pgm/${file}.tif
    $convert +compress data/FERET/source/pgm/${file}.tif data/FERET/source/pgm/${file}.pgm
    if [ ! $? ] ; then
        echo "ERROR: Could not convert file: $source"
        exit
    fi
done
    
for each in `cat imagelists/all_cd2.srt` ; do
    file=`basename $each .sfi`
    source="$@/gray_feret_cd2/data/images/${file}.tif.bz2"
    dest=
    check_file "$source"
    echo "    Convert:  $source"
    $bzcat "$source" > data/FERET/source/pgm/${file}.tif
    $convert +compress data/FERET/source/pgm/${file}.tif data/FERET/source/pgm/${file}.pgm
    if [ ! $? ] ; then
        echo "ERROR: Could not convert file: $source"
        exit
    fi
done
    
    
    
echo "********************************************************************"
echo "  Process completed successfully - Imagery should be ready for use."
echo "********************************************************************"

