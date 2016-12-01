@echo off
setlocal enabledelayedexpansion
         
rem download new ts_files from ftp
rem call ./allts/downloadTs.bat

cd %~dp0
rem create all ts_files
rem lupdate AutoNester.pro -ts AutoNester_zh_cn.ts
set languages=pl fr de ko zh_cn zh_tw ja es
for %%i in (*.pro) do (
    cd %~dp0
    echo %%i
	set info=%%i
	
	for %%j in (%languages%) do (
	    set var=!info:.pro=_%%j.ts!
	    lupdate %%i -ts ./allts/!var!
	)	
)

cd %~dp0
rem upload all ts_files to ftp
rem call ./allts/uploadToftp.bat

set /p tmp=Press enter key to end...