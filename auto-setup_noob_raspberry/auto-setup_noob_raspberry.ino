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

  Keyboard.println("sudo sed 's/XKBLAYOUT=@gb@/XKBLAYOUT=@us@/' -i /etc/default/keyboard");
  delay(500); // change keyboard layout in /etc/default/keyboard
  
  Keyboard.println("sudo setupcon -k");
  delay(3000); // reload keyboard layout
  
  Keyboard.println("sudo mount /dev/sda1 /mnt");
  delay(500); // wait mount USB key

  Keyboard.println("ifconfig eth0 | grep ether | awk -F \" \" '{print $2}' >> /mnt/MAC_address.txt");
  delay(500); // save MAC address of the raspberry

  Keyboard.println("sudo umount /mnt");
  delay(1000);

  Keyboard.println("reboot");
}

void loop() {

}
