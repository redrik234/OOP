set PROGRAM="%~1"

rem ����� ������, ����� ��� ��������� ���������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem ����� ������, ����� �� ����� �������������� ���� 
%PROGRAM% unknow.txt
if NOT ERRORLEVEL 1 goto err

rem ��������� ���������, ����� ����������� ������� �� ����� 0
%PROGRAM% firstMatrix.txt > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt firstMatrix_out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% secondMatrix.txt > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt secondMatrix_out.txt
if ERRORLEVEL 1 goto err

rem ����� ������, ����� ����������� ������� ����� 0
%PROGRAM% zeroDeterminant.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe output.txt zeroDeterminant_out.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1