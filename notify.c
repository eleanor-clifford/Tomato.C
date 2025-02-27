/*
//         .             .              .
//         |             |              |           .
// ,-. ,-. |-. ,-. . ,-. |  ,_, ,-. ,-. |-. ,-,-. . |- ,_,
// | | ,-| | | |   | |-' |   /  `-. |   | | | | | | |   /
// `-| `-^ ^-' '   ' `-' `' '"' `-' `-' ' ' ' ' ' ' `' '"'
//  ,|
//  `'
// notify.c
*/
#include "notify.h"

#include <ncurses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "config.h"

/* Send a notification with sound */
void notify(const char *message) {
  /* Autostart work notification */
  if (strcmp(message, "autostartwork") == 0) {
    if (strcmp(ICONS, "nerdicons") == 0 && WSL == 0)
      send_notification("󱣲 A pomodoro has ended!",
                        "Unpause to start the pause");
    else if (strcmp(ICONS, "iconson") == 0 && WSL == 0)
      send_notification("🔄 A pomodoro has ended!",
                        "Unpause to start the pause");
    else
      send_notification("A pomodoro has ended!", "Unpause to start the pause");

    play_audio("dfltnotify.mp3");
  }
  /* Autostart pause notification */
  else if (strcmp(message, "autostartpause") == 0) {
    if (strcmp(ICONS, "nerdicons") == 0 && WSL == 0)
      send_notification("󱣲 A pause has ended!", "Unpause to continue");
    else if (strcmp(ICONS, "iconson") == 0 && WSL == 0)
      send_notification("🔄 A pause has ended!", "Unpause to continue");
    else
      send_notification("A pause has ended!", "Unpause to continue");

    play_audio("pausenotify.mp3");
  }
  /* Work notification */
  else if (strcmp(message, "worktime") == 0) {
    if (strcmp(ICONS, "nerdicons") == 0 && WSL == 0)
      send_notification("󱎫 Work!", "You need to focus");
    else if (strcmp(ICONS, "iconson") == 0 && WSL == 0)
      send_notification("👷 Work!", "You need to focus");
    else
      send_notification("Work!", "You need to focus!");

    play_audio("dfltnotify.mp3");
  }
  /* Short Pause notification */
  else if (strcmp(message, "shortpause") == 0) {
    if (strcmp(ICONS, "nerdicons") == 0)
      send_notification(" Pause Break", "You have some time to chill");
    else if (strcmp(ICONS, "iconson") == 0)
      send_notification("☕ Pause Break", "You have some time to chill");
    else
      send_notification("Pause Break", "You have some time to chill");

    play_audio("pausenotify.mp3");
  }
  /* Long Pause notification */
  else if (strcmp(message, "longpause") == 0) {
    if (strcmp(ICONS, "nerdicons") == 0 && WSL == 0)
      send_notification(" Long Pause Break", "You have some time to chill");
    else if (strcmp(ICONS, "iconson") == 0 && WSL == 0)
      send_notification("🌴 Long Pause Break", "You have some time to chill");
    else
      send_notification("Long Pause Break", "You have some time to chill");

    play_audio("pausenotify.mp3");
  }
  /* End of cycle notification */
  else {
    if (strcmp(ICONS, "nerdicons") == 0 && WSL == 0)
      send_notification(" End of Pomodoro Cycle",
                        "Feel free to start another!");
    else if (strcmp(ICONS, "iconson") == 0 && WSL == 0)
      send_notification("🍅 End of Pomodoro Cycle",
                        "Feel free to start another!");
    else
      send_notification("End of Pomodoro Cycle", "Feel free to start another!");

    play_audio("endnotify.mp3");
  }
}

void send_notification(char *title, char *description) {
  if (NOTIFY == 0) return;

  int max_command_length = 256;

  const char *command[max_command_length];

#ifdef __APPLE__
  snprintf((char *)command, max_command_length,
           "osascript -e \'display notification \"%s\" with title \"%s\"\'",
           title, description);
#else
  snprintf((char *)command, max_command_length,
           "notify-send -u critical -t 30000 -a Tomato.C \"%s\" \"%s\" ", title,
           description);
#endif
  (void)system((char *)command);
}

void play_audio(char *sound_file) {
  if (SOUND == 1 && WSL == 0) {
    int max_audio_cmd_length = 256;

    char *command[max_audio_cmd_length];


    snprintf((char *)command, max_audio_cmd_length,
             "mpv --no-vid --no-input-terminal --volume=70 %s/%s --really-quiet &",
             SOUNDS, sound_file);
    (void)system((char *)command);
  }
}
