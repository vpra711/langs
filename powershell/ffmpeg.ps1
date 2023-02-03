# this script will create a new mkv container 
# with a video, audio in aac, subtitle from the input container
# copies the video and subtitle, codes the audio in aac

$total_count = (Get-ChildItem *.mkv).Count
$current_count = 0

Get-ChildItem *.mkv | ForEach-Object {
    $current_count = $current_count + 1
    $name = $_.Name
    $converted = $name + "-converted.mkv"

    Write-Host "+++++++++++++++++++++++++++++++++++++++++++++"
    Write-Host "converting $current_count out of $total_count"
    Write-Host "+++++++++++++++++++++++++++++++++++++++++++++"

    ffmpeg -i $name -c:v copy -map 0:v:0 -map 0:2 -map 0:1 -c:a aac -b:a 192k $converted
}