@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2015a
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2015a\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=clcOptTrj_tmp_mex
set MEX_NAME=clcOptTrj_tmp_mex
set MEX_EXT=.mexw64
call "C:\PROGRA~1\MATLAB\R2015a\sys\lcc64\lcc64\mex\lcc64opts.bat"
echo # Make settings for clcOptTrj_tmp > clcOptTrj_tmp_mex.mki
echo COMPILER=%COMPILER%>> clcOptTrj_tmp_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> clcOptTrj_tmp_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> clcOptTrj_tmp_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> clcOptTrj_tmp_mex.mki
echo LINKER=%LINKER%>> clcOptTrj_tmp_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> clcOptTrj_tmp_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> clcOptTrj_tmp_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> clcOptTrj_tmp_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> clcOptTrj_tmp_mex.mki
echo BORLAND=%BORLAND%>> clcOptTrj_tmp_mex.mki
echo OMPFLAGS= >> clcOptTrj_tmp_mex.mki
echo OMPLINKFLAGS= >> clcOptTrj_tmp_mex.mki
echo EMC_COMPILER=lcc64>> clcOptTrj_tmp_mex.mki
echo EMC_CONFIG=optim>> clcOptTrj_tmp_mex.mki
"C:\Program Files\MATLAB\R2015a\bin\win64\gmake" -B -f clcOptTrj_tmp_mex.mk
