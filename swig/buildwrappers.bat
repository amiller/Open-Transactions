@ECHO OFF
:: A batch file that generates and renames intop swig
:: files for connecting OT to other langurages.
ECHO.

ECHO Checking if ..\..\swigwin-2.0.4\swig.exe exist: 
IF NOT EXIST "..\..\swigwin-2.0.4\swig.exe" (
	ECHO cannot find swigwin-2.0.4...
	GOTO END
)

ECHO.
ECHO swigwin-2.0.4 exits! Good :)
ECHO.
ECHO.

FOR %%x IN (csharp java perl5 php python ruby tcl) DO (

ECHO.
ECHO Generating for %%x ...

RMDIR /S /Q "%%x"
MKDIR "%%x"

IF NOT %%x == java (
	ECHO ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -outdir %%x OTAPI.i
	..\..\swigwin-2.0.4\swig.exe -c++ -%%x -outdir %%x OTAPI.i
)

IF %%x == java (
	ECHO ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -package org.ot.wrapper.jni -outdir %%x OTAPI.i
	 ..\..\swigwin-2.0.4\swig.exe -c++ -%%x -package org.ot.wrapper.jni -outdir %%x OTAPI.i
)


IF EXIST OTAPI_wrap.cxx    MOVE /Y OTAPI_wrap.cxx    ..\src\otapi\OTAPI_%%x.cxx
IF EXIST OTAPI_wrap.cpp    MOVE /Y OTAPI_wrap.cpp    ..\src\otapi\OTAPI_%%x.cpp
IF EXIST OTAPI_wrap.h      MOVE /Y OTAPI_wrap.h      ..\include\otapi\OTAPI_%%x.h

)

ECHO.
ECHO Done!
ECHO.
:END