@echo off
cd "%~dp0"
echo [-----------------------------------------------------------]
echo [----Putting all ts_files to ftp server---
echo [-----------------------------------------------------------]

echo -----------Creating ftpUpload.txt-----------------

set file=ftpUpload.txt
set "y=%date:~,4%"
set "m=%date:~5,2%"
set "d=%date:~8,2%"

if exist %file% del %file%

echo open 192.168.50.55>> %file%
echo pad>> %file%
echo pad>> %file%
echo binary>> %file%
echo cd "test/ts/translations/ts/PAD7">> %file%
echo mkdir %y:~2,2%%m%%d%>> %file%
echo cd %y:~2,2%%m%%d%>> %file%
echo prompt>> %file%
echo mput "*.ts">> %file%
echo bye>> %file%

echo -------Creating ftpUpload.txt ok-----------------

ftp -s:ftpUpload.txt

if errorlevel 0 (echo upload to ftp ok) ^
else (echo upload failed)

