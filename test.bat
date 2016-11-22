set PROGRAM="%~1"

rem вывод ошибки, когда нет аргуметов программы
%PROGRAM%
if NOT ERRORLEVEL 1 goto err

rem вывод ошибки, когда 2-а аргумента программы
%PROGRAM% 12 43
if NOT ERRORLEVEL 1 goto err

rem вывод ошибки, когда агрумент за пределами диапазона [0..255]
%PROGRAM% 256
if NOT ERRORLEVEL 1 goto err

rem вывод 0, когда на входе 0
%PROGRAM% 0 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_0.txt
if ERRORLEVEL 1 goto err

rem вывод 6, когда на входе 96
%PROGRAM% 96 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_96.txt
if ERRORLEVEL 1 goto err

rem вывод 255, когда на входе 255
%PROGRAM% 255 > output.txt
if ERRORLEVEL 1 goto err
fc.exe output.txt flipbyte_for_255.txt
if ERRORLEVEL 1 goto err

rem вывод ошибки, когда аргумент является строкой
%PROGRAM% aa
if NOT ERRORLEVEL 1 goto err


echo Program testing succeeded
exit 0

:err
echo Program testing failed
exit 1