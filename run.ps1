Clear-Host
g++ main.cpp -o main.exe
if ($?) {
    ./main.exe
} else {
    Write-Host "Compilation failed."
}