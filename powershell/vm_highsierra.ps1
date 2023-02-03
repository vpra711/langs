#currently not working#
$vmname =  "high sierra"
Set-Location "C:\Program Files\Oracle\VirtualBox"
./VBoxManage modifyvm $vmname --cpuidset 00000001 000306a9 04100800 7fbae3ff bfebfbff
./VBoxManage setextradata $vmname "VBoxInternal/Devices/efi/0/Config/DmiSystemProduct" "MacBookPro11,3"
./VBoxManage setextradata $vmname "VBoxInternal/Devices/efi/0/Config/DmiSystemVersion" "1.0"
./VBoxManage setextradata $vmname "VBoxInternal/Devices/efi/0/Config/DmiBoardProduct" "Mac-2BD1B31983FE1663"
./VBoxManage setextradata $vmname "VBoxInternal/Devices/smc/0/Config/DeviceKey" "ourhardworkbythesewordsguardedpleasedontsteal(c)AppleComputerInc"
./VBoxManage setextradata $vmname "VBoxInternal/Devices/smc/0/Config/GetKeyFromRealSMC" 1