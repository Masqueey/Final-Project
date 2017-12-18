#!/bin/sh

########## PREAMBLE #########

if [ ! -f scripts/runPreprocessing_feret.sh ]; then
    echo "Please run this command from the csuEvalFaceRec directory"
    exit 1
fi

run() {
    $@ || { echo "Command failed: $@"; echo; exit 1; }
}

###### End of PREAMBLE ######

PATH=$PATH:bin/`arch`
export PATH

FERET_PGM_SOURCE="~/normalised_faces"
#FERET_SFI_DIR="data/FERET/normSep2002sfi"
#FERET_NRM_DIR="data/FERET/normSep2002nrm"
FERET_PGM_DIR="~/normalised_faces/cropped"
EYE_COORDS="~/normalised_faces/eye_coords.txt"

mkdir -p $FERET_PGM_DIR

echo "Running Preprocessing on FERET images. Using CSU Defaults for Optional Settings"
run csuPreprocessNormalize $EYE_COORDS $FERET_PGM_SOURCE  -pgm $FERET_PGM_DIR -mask no -hist none -geometric yes -eye-target 30.0 45.0 100.0 45.0 -size 130 160


    
