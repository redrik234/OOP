set PROGRAM="%~1"

rem ����� ������, ����� ��� ��������� ���������
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem ����� ������, ����� 2-� ��������� ���������
%PROGRAM% 12 43
if NOT ERRORLEVEL 1 goto err

rem ����� ������, ����� �������� �� ��������� ��������� [0..255]
%PROGRAM% 256
if NOT ERRORLEVEL 1 goto err

rem ����� 0, ����� �� ����� 0
%PROGRAM% 0 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_0.txt
if ERRORLEVEL 1 goto err

rem ����� 6, ����� �� ����� 96
%PROGRAM% 96 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_96.txt
if ERRORLEVEL 1 goto err

rem ����� 255, ����� �� ����� 255
%PROGRAM% 255 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_255.txt
if ERRORLEVEL 1 goto err

rem ����� ������, ����� �������� �������� �������
%PROGRAM% aa
if NOT ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1