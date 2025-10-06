@echo off
REM Ścieżka do narzędzia Coverity (zmień jeśli zainstalowane gdzie indziej)
set COV_PATH="c:\Projects_training\cov-analysis"

REM Ścieżka do projektu
set PROJECT_PATH="c:\Projects_training\FlySimulator"

REM Katalog wyjściowy analizy
set OUTPUT_DIR="cov-int"

REM Przejdź do katalogu projektu
cd /d %PROJECT_PATH%

REM Utwórz katalog 'build' jeśli nie istnieje
if not exist build mkdir build

REM Budowanie projektu z analizą Coverity
%COV_PATH%\bin\cov-build.exe --dir %OUTPUT_DIR% gcc src/main.c src/silnik.c src/lot.c src/kokpit.c src/sterowanie.c -I header -o build/samolot.exe

REM Spakowanie wyników analizy
tar -czvf flysimulator.tgz %OUTPUT_DIR%

echo Analiza zakończona. Wyniki zapisane w flysimulator.tgz
pause
