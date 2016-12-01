@echo off
cd %~dp0
setlocal enabledelayedexpansion

echo [---------------------------------------------------------------------]
echo [----download all ts_file from ftp server. Please wait----]
echo [---------------------------------------------------------------------]
echo.
echo --------Creating ftdownload.txt-------------------

set file=ftdownload.txt
if exist %file% del %file%
for %%i in (*.ts) do (
    if exist %%i del %%i
)

echo open 192.168.50.55>> %file%
echo pad>> %file%
echo pad>> %file%
echo binary>> %file%
echo cd "test/ts/translated/PAD7">> %file%
echo cd "allts">> %file%
echo prompt>> %file%
echo mget "*.ts">> %file%
echo bye>> %file%

echo --------Creating ftdownload.txt ok------------------

ftp -s:ftdownload.txt

if errorlevel 0 (echo Successful to download) ^
else (echo Failed to download)




