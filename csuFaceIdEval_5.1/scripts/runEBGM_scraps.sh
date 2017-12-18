#!/bin/bash

PATH=$PATH:bin/`arch`
export PATH

EYE_COORDS="imagelists/coords.scraps"
FERET_PGM_SOURCE="data/csuScrapShots/source/pgm"
NOVEL_IMAGE_LIST="imagelists/scrap_all.srt"

FERET_SFI_DIR="data/scraps/normSep2002sfi"
FERET_PGM_DIR="data/scraps/normSep2002pgm"

EBGM_SFI_DIR="data/scraps/EBGMSep2002sfi"
EBGM_PGM_DIR="data/scraps/EBGMSep2002pgm"

GABOROPTIONS="-size 128 128 -mask NO -preNorm YES -pixelNorm YES -hist NONE -eye-target 52 64 76 64 -postEdge 30 -preEdge 30 "

WAVELET="ebgmdata/GaborMaskWiskott.wavelet"
MODEL_GRAPH_DIR="data/csuScrapShots/source/auto_landmarks"
MODEL_LIST="imagelists/scrap_bunch.srt"
NOVEL_GRAPH_DIR="data/scraps/EBGM_Standard_NG"
FACE_GRAPH_DIR="data/scraps/EBGM_Standard_FG"
EBGM_DIR="distances/scraps/EBGM"

echo "Creating normalized imagery for EBGM algorithm..."
mkdir -p $EBGM_SFI_DIR $EBGM_PGM_DIR
csuPreprocessNormalize $GABOROPTIONS $EYE_COORDS $FERET_PGM_SOURCE -sfi $EBGM_SFI_DIR -pgm $EBGM_PGM_DIR

mkdir -p $NOVEL_GRAPH_DIR
csuEBGMGraphFit $MODEL_LIST $NOVEL_IMAGE_LIST $WAVELET $EBGM_SFI_DIR  $MODEL_GRAPH_DIR DEPredictiveIter $NOVEL_GRAPH_DIR 

mkdir -p $FACE_GRAPH_DIR
csuEBGMFaceGraph $NOVEL_IMAGE_LIST $EBGM_SFI_DIR $NOVEL_GRAPH_DIR $WAVELET $FACE_GRAPH_DIR

mkdir -p $EBGM_DIR
csuEBGMMeasure $NOVEL_IMAGE_LIST $FACE_GRAPH_DIR FGPredictiveIter $EBGM_DIR

