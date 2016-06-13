@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=myxcorr
set MEX_NAME=myxcorr
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for myxcorr > myxcorr_mex.mki
echo COMPILER=%COMPILER%>> myxcorr_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> myxcorr_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> myxcorr_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> myxcorr_mex.mki
echo LINKER=%LINKER%>> myxcorr_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> myxcorr_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> myxcorr_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> myxcorr_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> myxcorr_mex.mki
echo BORLAND=%BORLAND%>> myxcorr_mex.mki
echo OMPFLAGS= >> myxcorr_mex.mki
echo OMPLINKFLAGS= >> myxcorr_mex.mki
echo EMC_COMPILER=lcc64>> myxcorr_mex.mki
echo EMC_CONFIG=optim>> myxcorr_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f myxcorr_mex.mk
