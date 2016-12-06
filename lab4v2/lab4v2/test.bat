set PROGRAM="%~1"

echo search the maximum area and minimum perimeter
%PROGRAM% input\input.txt > output\out.txt
if ERRORLEVEL 1 goto err
fc /b output\out.txt references\reference.txt
IF ERRORLEVEL 1 GOTO err

echo Invalid number of parameters
%PROGRAM% input\input2.txt > output\output2.txt
if ERRORLEVEL 1 goto err
fc /b output\output2.txt references\reference2.txt
IF ERRORLEVEL 1 GOTO err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1