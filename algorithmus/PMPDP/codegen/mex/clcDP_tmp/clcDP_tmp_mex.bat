@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=clcDP_tmp_mex
set MEX_NAME=clcDP_tmp_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for clcDP_tmp > clcDP_tmp_mex.mki
echo COMPILER=%COMPILER%>> clcDP_tmp_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> clcDP_tmp_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> clcDP_tmp_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> clcDP_tmp_mex.mki
echo LINKER=%LINKER%>> clcDP_tmp_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> clcDP_tmp_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> clcDP_tmp_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> clcDP_tmp_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> clcDP_tmp_mex.mki
echo BORLAND=%BORLAND%>> clcDP_tmp_mex.mki
echo OMPFLAGS= >> clcDP_tmp_mex.mki
echo OMPLINKFLAGS= >> clcDP_tmp_mex.mki
echo EMC_COMPILER=lcc64>> clcDP_tmp_mex.mki
echo EMC_CONFIG=optim>> clcDP_tmp_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f clcDP_tmp_mex.mk
