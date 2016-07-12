@echo off
set MATLAB=C:\PROGRA~1\MATLAB\R2014b
set MATLAB_ARCH=win64
set MATLAB_BIN="C:\Program Files\MATLAB\R2014b\bin"
set ENTRYPOINT=mexFunction
set OUTDIR=.\
set LIB_NAME=clcDP_port_mex
set MEX_NAME=clcDP_port_mex
set MEX_EXT=.mexw64
call setEnv.bat
echo # Make settings for clcDP_port > clcDP_port_mex.mki
echo COMPILER=%COMPILER%>> clcDP_port_mex.mki
echo COMPFLAGS=%COMPFLAGS%>> clcDP_port_mex.mki
echo OPTIMFLAGS=%OPTIMFLAGS%>> clcDP_port_mex.mki
echo DEBUGFLAGS=%DEBUGFLAGS%>> clcDP_port_mex.mki
echo LINKER=%LINKER%>> clcDP_port_mex.mki
echo LINKFLAGS=%LINKFLAGS%>> clcDP_port_mex.mki
echo LINKOPTIMFLAGS=%LINKOPTIMFLAGS%>> clcDP_port_mex.mki
echo LINKDEBUGFLAGS=%LINKDEBUGFLAGS%>> clcDP_port_mex.mki
echo MATLAB_ARCH=%MATLAB_ARCH%>> clcDP_port_mex.mki
echo BORLAND=%BORLAND%>> clcDP_port_mex.mki
echo OMPFLAGS= >> clcDP_port_mex.mki
echo OMPLINKFLAGS= >> clcDP_port_mex.mki
echo EMC_COMPILER=msvc100>> clcDP_port_mex.mki
echo EMC_CONFIG=optim>> clcDP_port_mex.mki
"C:\Program Files\MATLAB\R2014b\bin\win64\gmake" -B -f clcDP_port_mex.mk
