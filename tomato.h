/*
//         .             .              .
//         |             |              |           .
// ,-. ,-. |-. ,-. . ,-. |  ,_, ,-. ,-. |-. ,-,-. . |- ,_,
// | | ,-| | | |   | |-' |   /  `-. |   | | | | | | |   /
// `-| `-^ ^-' '   ' `-' `' '"' `-' `-' ' ' ' ' ' ' `' '"'
//  ,|
//  `'
// tomato.h
*/
#ifndef TOMATO_H_
#define TOMATO_H_
#include <ncurses.h>
#include <time.h>
#ifdef MPV
#include <mpv/client.h>
#endif

/* Defining some limits */
#define MAXLINES       20
#define MAXINPUTLENGTH 32

// Defining the notes struct
typedef struct note note;
struct note {
  char *note;
  char type;
};

// Defining the Notepad
typedef struct notepad notepad;
struct notepad {
  note *lines[MAXLINES];
};

/* Defining the app struct */
typedef struct appData appData;
struct appData {
  int insertCursory;
  int insertCursorx;
  int cursory;
  int cursorx;
  notepad notes;
  int currentNote;
  int emptyNotepad;
  int notesAmount;
  int inputLength;
  char inputMode;
  int editingNote;
  int editingTask;
  int addingNote;
  int addingTask;
  int currentPID;
  int rainNoisePID;
  int fireNoisePID;
  int windNoisePID;
  int thunderNoisePID;
  int runRainOnce;
  int runFireOnce;
  int runWindOnce;
  int runThunderOnce;
  int playNoise;
  int playRainNoise;
  int playFireNoise;
  int playWindNoise;
  int playThunderNoise;
  int printVolume;
  int printRainVolume;
  int printFireVolume;
  int printWindVolume;
  int printThunderVolume;
  char rainVolume[4];
  char fireVolume[4];
  char windVolume[4];
  char thunderVolume[4];
  char *mpvCmd;
  char *logPrefix;
  char *logFile;
  char *tmpFile;
  char *timerFile;
  char *notepadFile;
  int pomodorosLevels;
  int workTimeLevels;
  int shortPauseLevels;
  int longPauseLevels;
  int pomodoros;
  int workTime;
  int shortPause;
  int longPause;
  int menuPos;
  int pomodoroCounter;
  int lastMode;
  int helpLastMode;
  int runHelpOnce;
  int runNotepadOnce;
  int currentMode;
  int needMainMenu;
  int frameTimer;
  int timer;
  int timerTime;
  struct timespec timerWallTimeStart;
  double sfps;
  int framems;
  int logoFrame;
  int coffeeFrame;
  int machineFrame;
  int beachFrame;
  int bannerFrame;
  int helpFrame;
  int notepadFrame;
  int userInput;
  int lastInput;
  int pausedTimer;
  int cycles;
  int needToLog;
  int autostartWork;
  int autostartPause;
  int unfinishedPomodoroCounter;
  int unfinishedPomodoros;
  int unfinishedTimer;
  int unfinishedFullTimer;
  int needResume;
  int resume;
  int newDay;
  int runOnce;
  char date[50];
  int middlex;
  int middley;
  int x;
  int y;
};

/* Initialize variables */
extern void initApp(appData *);

/* Update variables */
extern void doUpdate(appData *);

/* Print at screen */
extern void drawScreen(appData *);

/* Putting it all together */
extern int main(int, char *[]);

#endif
