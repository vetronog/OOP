set PROGRAM="%~1"

rem �஢�ਬ ���⮩ 䠩�
%PROGRAM% emptystring.txt %TEMP%\empty.txt "some string" "some another string"
if %ERRORLEVEL% NEQ 1 goto err

rem �஢�ਬ ��᪮�쪮 ��ப
%PROGRAM% somelines.txt %TEMP%\somelines.txt dog cat
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\somelines.txt somelinesOut.txt
if %ERRORLEVEL% EQU 1 goto err

rem �஢�ਬ ��᪮�쪮 �宦����� ᫮� �� ����� ��ப�
%PROGRAM% one_line-someobject.txt %TEMP%\one_line-someobject.txt ma mama
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\one_line-someobject.txt one_line-someobjectOut.txt
if %ERRORLEVEL% EQU 1 goto err

rem �஢�ઠ ���⮣� �����
%PROGRAM% simple.txt %TEMP%\simple.txt down high
if %ERRORLEVEL% EQU 1 goto err
fc.exe %TEMP%\simple.txt simpleOut.txt
if %ERRORLEVEL% EQU 1 goto err

rem ���᪨� �����
%PROGRAM% rus_text.txt %TEMP%\rus_text.txt �ਢ�� ����
if %ERRORLEVEL% EQU 1 goto err                               
fc.exe %TEMP%\rus_text.txt rus_textOut.txt
if %ERRORLEVEL% EQU 1 goto err

rem ��᪮�쪮 �몮� �����
%PROGRAM% somelanguages.txt %TEMP%\somelanguages.txt stars ������
if %ERRORLEVEL% EQU 1 goto err                               
fc.exe %TEMP%\somelanguages.txt somelanguagesOut.txt
if %ERRORLEVEL% EQU 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1
