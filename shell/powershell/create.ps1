for($i = 101; $i -le 10000; $i++)
{
    # New-Item -Name ("mytext" + $i) -ItemType "file"
    # Move-Item -Path ('D:\Documents\My Programs\Script\Shell\Powershell\mytext' + $i) -Destination ('D:\Documents\My Programs\Script\Shell\cmd\mytext' + $i)
}