#include <Wire.h>
#include <PT2314.h> // https://github.com/andykarpov/PT2314

PT2314 audio;

/**
   Send tone control values to the PT2314
https://github.com/andykarpov/PiRadio-OLED/tree/master/ino/src
*/
void sendPT2314() {
  audio.volume(60);
  audio.bass(0);
  audio.treble(0);
  audio.channel(3);
  //  if (power_on) {
  audio.loudnessOn();
  audio.muteOff();
  //  } else {
  //    audio.loudnessOff();
  //    audio.muteOn();
  //  }
}

void init_audio( ) {
  Wire.begin(13, 14);

  audio.init();
  sendPT2314();

}

<<<<<<< HEAD

=======

>>>>>>> 3b9c9224140ba2a94abf8578b61a21a387c0ccc5
