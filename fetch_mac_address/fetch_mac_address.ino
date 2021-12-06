#include "Keyboard.h"

void setup() {
  Keyboard.begin();
  delay(2000);

  Keyboard.press(KEY_LEFT_CTRL);
  delay(100);
  Keyboard.press(KEY_LEFT_ALT);
  delay(100);
  Keyboard.press(KEY_F1);
  delay(1000);
  Keyboard.releaseAll();
  delay(5000); // wait until switch to shell

  Keyboard.println("sudo sed 's/XKBLAYOUT=@gb@/XKBLAYOUT=@us@/' -i /etc/default/keyboard"); // '@' is '"' because the raspberry is by default in gb layout
  delay(500); // change keyboard layout in /etc/default/keyboard
  
  Keyboard.println("sudo setupcon -k");
  delay(4000); // reload keyboard layout
/*
  Keyboard.println("sudo mount /dev/sda1 /mnt >> output.txt");
  delay(2000); // wait mount USB key

  Keyboard.println("ifconfig eth0 | grep ether | awk -F \" \" '{print $2}' >> /mnt/MAC_address.txt >> output.txt");
  delay(3000); // save MAC address of the raspberry

  Keyboard.println("sudo umount /mnt >> output.txt");
  delay(1000);

  Keyboard.println("reboot");
*/
  Keyboard.println("echo \"sudo mount /dev/sda1 /mnt\r\necho -n - >> /mnt/MAC_address.txt\r\nifconfig eth0 | grep ether | awk '{print \\$2}' >> /mnt/MAC_address.txt\r\nsudo umount /mnt\r\nreboot\" > setup.sh");
  delay(1000); // do everything in comment but put in setup.sh
  Keyboard.println("chmod +x setup.sh");
  delay(1000); // make setup.sh executable
  Keyboard.println("sudo ./setup.sh > output.txt 2>&1");
  // execute and log stdout ans stderr
}

void loop() {

}
