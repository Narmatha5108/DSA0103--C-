@echo off
setlocal
for %%T in (Task01 Task02 Task03 Task04 Task05 Task06 Task07 Task08 Task09 Task10 Task11 Task12) do (
  echo.
  echo ===== Compiling %%T =====
  g++ -std=c++17 -Wall -Wextra %%T\%%T.cpp -o %%T\%%T.exe
  if errorlevel 1 (
    echo Compilation failed for %%T
    exit /b 1
  )
)
echo.
echo All source files compiled successfully. Run each program and save your own screenshots.
