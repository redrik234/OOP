set PROGRAM="%~1"

rem проверка программы, когда на входе 1 аргумент
%PROGRAM% not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem проверка программы, когда неправильно введено имя файла
%PROGRAM% unknow.txt not_empty.txt
if NOT ERRORLEVEL 1 goto err

rem проверка сравнения не пустого файла с самим собой
%PROGRAM% not_empty.txt not_empty.txt
if ERRORLEVEL 1 goto err

rem проверка сравнения двух файлов различных во второй строке
%PROGRAM% difference_two_line1.txt difference_two_line2.txt
if NOT ERRORLEVEL 1 goto err

rem проверка сравнения двух файлов, когда в 1-ом файле 3 строки, а во втором 2-е
%PROGRAM% three_line.txt two_line.txt                      
if NOT ERRORLEVEL 1 goto err

%PROGRAM% two_line.txt three_line.txt                      
if NOT ERRORLEVEL 1 goto err

rem проверка сравнения двух файлов, когда в 1-ом файле длинная строка, а во втором короткая
%PROGRAM% long_line.txt short_line.txt
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1