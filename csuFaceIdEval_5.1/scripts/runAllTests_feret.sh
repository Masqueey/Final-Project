#!/bin/sh

########## PREAMBLE #########

if [ ! -f scripts/runAllTests_feret.sh ]; then
    echo "Please run this command from the csuEvalFaceRec directory"
    exit 1
fi

run() {
    $@ || { echo "Command failed: $@"; echo; exit 1; }
}

###### End of PREAMBLE ######

run scripts/runPreprocessing_feret.sh
run scripts/EBGMPreprocessing.sh
run scripts/runPCA_feret.sh
run scripts/runLDA_feret.sh
run scripts/EBGM_Standard.sh
run scripts/runBayesian_feret.sh
run scripts/GenerateFeretResults.sh