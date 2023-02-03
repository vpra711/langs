delete_dir(pwd)

function delete_dir($path)
{
    $directory = (Get-ChildItem -Directory | Select-Object -ExpandProperty Name)
  
    foreach($dir in $directory)
    {
        if((Get-ChildItem $dir -Recurse -File).Count)
        {
            Remove-Item $dir -Recurse -Force
        }
        else 
        {
            delete_dir($dir) 
        }
    }
}
