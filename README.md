# Auto fetch raspberry MAC address
Arduino micro rubber ducky to auto fetch MAC address into a raspberry without screen and keyboard

# Setup
- Open `fetch_mac_address.ino` in Arduino IDE and flash it on a 32u4 or SAMD micro based boards
- Format an USB key in FAT
- Connect the USB key into the raspberry
- Power on the Raspberry and wait aproximatly 2 min
- Connect the arduino and wait until the LED on the arduino board shutdown

# What did the script type ?

```shell
- ctrl + alt + F1
- sudo sed 's/XKBLAYOUT="gb"/XKBLAYOUT="us"/' -i /etc/default/keyboard
- sudo setupcon -k
- sudo mount /dev/sda1 /mnt
- ifconfig eth0 | grep ether | awk -F \" \" '{print $2}' >> /mnt/MAC_address.txt
- sudo umount /mnt
- reboot
```
