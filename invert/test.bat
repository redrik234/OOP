set PROGRAM="%~1"

rem вывод ошибки, когда нет аргуметов программы
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem вывод ошибки, когда на входе несуществующий файл 
%PROGRAM% unknow.txt
if NOT ERRORLEVEL 1 goto err

rem проверяем программу, когда детерминант матрицы не равен 0
%PROGRAM% firstMatrix.txt > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt firstMatrix_out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% secondMatrix.txt > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt secondMatrix_out.txt
if ERRORLEVEL 1 goto err

rem вывод ошибки, когда детерминант матрицы равен 0
%PROGRAM% zeroDeterminant.txt > output.txt
if NOT ERRORLEVEL 1 goto err
fc.exe output.txt zeroDeterminant_out.txt
if ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1