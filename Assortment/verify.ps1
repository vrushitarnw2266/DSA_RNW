# PowerShell Script to Compile and Verify all 4 Assortment tasks

$tasks = 1..4
$allSuccess = $true

Write-Host "=========================================" -ForegroundColor Cyan
Write-Host "Compiling and Running Assortment Tasks..." -ForegroundColor Cyan
Write-Host "=========================================" -ForegroundColor Cyan

foreach ($t in $tasks) {
    $cppFile = "task$t.cpp"
    $exeFile = "task$t.exe"
    
    Write-Host "Compiling $cppFile..." -ForegroundColor Yellow
    & g++ $cppFile -o $exeFile
    
    if ($LASTEXITCODE -eq 0) {
        Write-Host "Successfully compiled $cppFile." -ForegroundColor Green
        # Clean up exe
        Remove-Item $exeFile -ErrorAction SilentlyContinue
    } else {
        Write-Host "Failed to compile $cppFile" -ForegroundColor Red
        $allSuccess = $false
    }
    Write-Host ""
}

if ($allSuccess) {
    Write-Host "All tasks compiled successfully!" -ForegroundColor Green
} else {
    Write-Host "Some tasks failed to compile." -ForegroundColor Red
}
