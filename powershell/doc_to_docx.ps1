$SaveFormat = "microsoft.office.interop.word.WdSaveFormat"
$word = New-Object -ComObject word.application
$word.visible = $false
$folderpath = "D:\Temp\New folder\pen drive\TRANCEND\*"
$fileType = "*doc"
Get-ChildItem -path $folderpath -include $fileType |
foreach-object `
{
    $path = ($_.fullname).substring(0,($_.FullName).lastindexOf("."))
    $doc = $word.documents.open($_.fullname)
    $doc.saveas([ref] $path, [ref]$SaveFormat::wdFormatDocumentDefault)
    $doc.close()
}
$word.Quit()
$word = $null
[gc]::collect()
[gc]::WaitForPendingFinalizers()