# PowerShell Script to Compile and Verify all 7 Circlet tasks

$tasks = 1..7
$allSuccess = $true

Write-Host "=========================================" -ForegroundColor Cyan
Write-Host "Compiling and Running Circlet Tasks..." -ForegroundColor Cyan
Write-Host "=========================================" -ForegroundColor Cyan

foreach ($t in $tasks) {
    $cppFile = "task$t.cpp"
    $exeFile = "task$t.exe"
    
    Write-Host "Compiling $cppFile..." -ForegroundColor Yellow
    & g++ $cppFile -o $exeFile
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "----------------------------- Task $t Output -----------------------------" -ForegroundColor Green
        & .\$exeFile
        Write-Host "--------------------------------------------------------------------------" -ForegroundColor Green
        # Clean up exe
        Remove-Item $exeFile -ErrorAction SilentlyContinue
    } else {
        Write-Host "Failed to compile $cppFile" -ForegroundColor Red
        $allSuccess = $false
    }
    Write-Host ""
}

if ($allSuccess) {
    Write-Host "All tasks compiled and executed successfully!" -ForegroundColor Green
} else {
    Write-Host "Some tasks failed to compile." -ForegroundColor Red
}
