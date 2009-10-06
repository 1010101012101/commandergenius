/*
 * CPassive.h
 *
 *  Created on: 24.09.2009
 *      Author: gerstrong and pizza2004
 *
 *
 * TODO: Comment about this class
 */
#ifndef CMENU_H_
#define CMENU_H_

#include <vector>
#include <string>
#include <SDL/SDL.h>
#include "../dialog/CDialog.h"

#define TWIRL_SPEED_SLOW        100
#define TWIRL_SPEED_FAST        20

#define MENUS_Y                 32
#define MAINMENU_X              32

#define STORYBOARD_X			672
#define STORYBOARD_Y			32

#define FONT_TWIRL              9
#define TWIRL_SPEED             30
#define TWIRL_NUM_FRAMES        5

/*char controlsmenu();
char configmenu(stCloneKeenPlus *pCKP,int ingame);
void keensleft(int episode);
int getDifficulty(stCloneKeenPlus *pCKP);
void showPage(const std::string& str_text, int textsize);*/

class CMenu {

public:
	// Which Menu has to be shown?
	enum menutypes{
		MAIN, START, LOAD, DIFFICULTY, OPTIONS, QUIT
	};

	// Active means, when the player is playing, PASSIVE when the Player is not playing
	enum menumodes{
		ACTIVE, PASSIVE
	};

	CMenu( char menu_mode );
	virtual ~CMenu();

	bool init( char menu_type = MAIN );

	void process();
	void processMainMenu();
	void processNumPlayersMenu();

	void cleanup();

	// Getters
	char getNumPlayers() { return m_NumPlayers; }
	char getDifficulty() { return m_Difficulty; }
	bool mustEndGame() { return m_Endgame; }
	bool mustStartGame() { return (m_NumPlayers > 0); }
	bool getExitEvent() { return (m_menu_type==QUIT); }
	bool mustBeClosed() { return m_goback; }

private:
	void initMainMenu();
	void initNumPlayersMenu();

	CDialog *mp_Dialog;
	SDL_Surface *mp_MenuSurface;

	bool m_goback;
	bool m_Endgame;
	char m_selection;
	char m_menu_type;
	char m_menu_mode;
	char m_NumPlayers;
	char m_Difficulty;
};

#endif /* CMENU_H_ */