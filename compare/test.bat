set PROGRAM="%~1"

rem �������� ���������, ����� �� ����� 1 ��������
%PROGRAM% not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem �������� ���������, ����� ����������� ������� ��� �����
%PROGRAM% unknow.txt not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem �������� ��������� �� ������� ����� � ����� �����
%PROGRAM% not_empty.txt not_empty.txt
if ERRORLEVEL 1 goto err

rem �������� ��������� ���� ������ ��������� �� ������ ������
%PROGRAM% difference_two_line1.txt difference_two_line2.txt
if NOT ERRORLEVEL 1 goto err

rem �������� ��������� ���� ������, ����� � 1-�� ����� 3 ������, � �� ������ 2-�
%PROGRAM% three_line.txt two_line.txt                      
if NOT ERRORLEVEL 1 goto err

%PROGRAM% two_line.txt three_line.txt                      
if NOT ERRORLEVEL 1 goto err

rem �������� ��������� ���� ������, ����� � 1-�� ����� ������� ������, � �� ������ ��������
%PROGRAM% long_line.txt short_line.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1