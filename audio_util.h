#include <Wire.h>
#include <PT2314.h>

PT2314 audio;

/**
   Send tone control values to the PT2314
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


