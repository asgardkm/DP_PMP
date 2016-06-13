@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=ButterFilt
set MEX_NAME=ButterFilt
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for ButterFilt > ButterFilt_mex.mki
echo COMPILER=%COMPILER%>> ButterFilt_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> ButterFilt_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> ButterFilt_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> ButterFilt_mex.mki
echo LINKER=%LINKER%>> ButterFilt_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> ButterFilt_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> ButterFilt_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> ButterFilt_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> ButterFilt_mex.mki
echo BORLAND=%BORLAND%>> ButterFilt_mex.mki
echo OMPFLAGS= >> ButterFilt_mex.mki
echo OMPLINKFLAGS= >> ButterFilt_mex.mki
echo EMC_COMPILER=lcc64>> ButterFilt_mex.mki
echo EMC_CONFIG=optim>> ButterFilt_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f ButterFilt_mex.mk
