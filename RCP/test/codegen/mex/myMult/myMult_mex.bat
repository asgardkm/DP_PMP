@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=myMult_mex
set MEX_NAME=myMult_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for myMult > myMult_mex.mki
echo COMPILER=%COMPILER%>> myMult_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> myMult_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> myMult_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> myMult_mex.mki
echo LINKER=%LINKER%>> myMult_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> myMult_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> myMult_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> myMult_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> myMult_mex.mki
echo BORLAND=%BORLAND%>> myMult_mex.mki
echo OMPFLAGS= >> myMult_mex.mki
echo OMPLINKFLAGS= >> myMult_mex.mki
echo EMC_COMPILER=lcc64>> myMult_mex.mki
echo EMC_CONFIG=optim>> myMult_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f myMult_mex.mk
