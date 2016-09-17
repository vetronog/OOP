set PROGRAM="OOP lab1 replace.exe"

rem Проверим пустой файл
%PROGRAM% emptystring.txt %TEMP%\empty.txt "some string" "some another string"
if %ERRORLEVEL% NEQ 1 goto err

rem Проверим несколько строк
%PROGRAM% somelines.txt %TEMP%\somelines.txt dog cat
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\somelines.txt somelines.txt
if %ERRORLEVEL% EQU 0 goto err

rem Проверим несколько вхождений слов на одной строке
%PROGRAM% one_line-someobject.txt %TEMP%\one_line-someobject.txt ma mama
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\one_line-someobject.txt one_line-someobject.txt
if %ERRORLEVEL% EQU 0 goto err

rem Проверка простого ввода
%PROGRAM% simple.txt %TEMP%\simple.txt down high
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\simple.txt simple.txt
if %ERRORLEVEL% EQU 0 goto err

rem Русский набор
%PROGRAM% rus_text.txt %TEMP%\rus_text.txt привет пока
if %ERRORLEVEL% EQU 1 goto err                               
fc.exe %TEMP%\multiline-multiword.txt multiline-multiword.txt
if %ERRORLEVEL% EQU 0 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
