/* Emacs style mode select   -*- C++ -*-
 *-----------------------------------------------------------------------------
 *
 *
 *  PrBoom: a Doom port merged with LxDoom and LSDLDoom
 *  based on BOOM, a modified and improved DOOM engine
 *  Copyright (C) 1999 by
 *  id Software, Chi Hoang, Lee Killough, Jim Flynn, Rand Phares, Ty Halderman
 *  Copyright (C) 1999-2006 by
 *  Jess Haas, Nicolas Kalkhof, Colin Phipps, Florian Schulze
 *  Copyright 2005, 2006 by
 *  Florian Schulze, Colin Phipps, Neil Stevens, Andrey Budko
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License
 *  as published by the Free Software Foundation; either version 2
 *  of the License, or (at your option) any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA
 *  02111-1307, USA.
 *
 * DESCRIPTION:
 *   All the global variables that store the internal state.
 *   Theoretically speaking, the internal state of the engine
 *    should be found by looking at the variables collected
 *    here, and every relevant module will have to include
 *    this header file.
 *   In practice, things are a bit messy.
 *
 *-----------------------------------------------------------------------------*/

#ifndef __D_STATE__
#define __D_STATE__

// We need the playr data structure as well.
#include "d_player.h"

#ifdef __GNUG__
#pragma interface
#endif

// ------------------------
// Command line parameters.
//

extern  boolean nomonsters; // checkparm of -nomonsters
extern  boolean respawnparm;  // checkparm of -respawn
extern  boolean fastparm; // checkparm of -fast
extern  boolean devparm;  // DEBUG: launched with -devparm

// -----------------------------------------------------
// Game Mode - identify IWAD as shareware, retail etc.
//

extern GameMode_t gamemode;
extern GameMission_t  gamemission;

// Set if homebrew PWAD stuff has been added.
extern  boolean modifiedgame;


// -------------------------------------------
// Language.
extern  Language_t   language;

// -------------------------------------------
// Selected skill type, map etc.
//

// Defaults for menu, methinks.
extern  const skill_t   startskill;
extern  int             startepisode;
extern  int   startmap;

extern  boolean   autostart;

// Selected by user.
extern  skill_t         gameskill;
extern  int   gameepisode;
extern  int   gamemap;

// Nightmare mode flag, single player.
extern  boolean         respawnmonsters;

// Netgame? Only true if >1 player.
extern  boolean netgame;

// Flag: true only if started as net deathmatch.
// An enum might handle altdeath/cooperative better.
extern  boolean deathmatch;

// ------------------------------------------
// Internal parameters for sound rendering.
// These have been taken from the DOS version,
//  but are not (yet) supported with Linux
//  (e.g. no sound volume adjustment with menu.

// These are not used, but should be (menu).
// From m_menu.c:
//  Sound FX volume has default, 0 - 15
//  Music volume has default, 0 - 15
// These are multiplied by 8.
extern int snd_SfxVolume;      // maximum volume for sound
extern int snd_MusicVolume;    // maximum volume for music

// -------------------------
// Status flags for refresh.
//

enum automapmode_e {
  am_active = 1,  // currently shown
  am_overlay= 2,  // covers the screen, i.e. not overlay mode
  am_rotate = 4,  // rotates to the player facing direction
  am_follow = 8,  // keep the player centred
  am_grid   =16,  // show grid
};
extern enum automapmode_e automapmode; // Mode that the automap is in

extern  boolean menuactive;    // Menu overlayed?
extern  boolean paused;        // Game Pause?
extern  boolean nodrawers;
extern  boolean noblit;

// This one is related to the 3-screen display mode.
// ANG90 = left side, ANG270 = right
extern  int viewangleoffset;

// Player taking events, and displaying.
extern  int consoleplayer;
extern  int displayplayer;

// -------------------------------------
// Scores, rating.
// Statistics on a given map, for intermission.
//
extern  int totalkills, totallive;
extern  int totalitems;
extern  int totalsecret;

// Timer, for scores.
extern  int basetic;    /* killough 9/29/98: levelstarttic, adjusted */
extern  int leveltime;  // tics in game play for par

// --------------------------------------
// DEMO playback/recording related stuff.

extern  boolean usergame;
extern  boolean demoplayback;
extern  boolean demorecording;
extern  int demover;

// Quit after playing a demo from cmdline.
extern  boolean   singledemo;
// Print timing information after quitting.  killough
extern  boolean   timingdemo;
// Run tick clock at fastest speed possible while playing demo.  killough
extern  boolean   fastdemo;

extern  gamestate_t  gamestate;

//-----------------------------
// Internal parameters, fixed.
// These are set by the engine, and not changed
//  according to user inputs. Partly load from
//  WAD, partly set at startup time.

extern  int   gametic;


// Bookkeeping on players - state.
extern  player_t  players[MAXPLAYERS];

// Alive? Disconnected?
extern  boolean   playeringame[MAXPLAYERS];
extern  boolean   realplayeringame[MAXPLAYERS];

extern  mapthing_t *deathmatchstarts;     // killough
extern  size_t     num_deathmatchstarts; // killough

extern  mapthing_t *deathmatch_p;

// Player spawn spots.
extern  mapthing_t playerstarts[];

// Intermission stats.
// Parameters for world map / intermission.
extern wbstartstruct_t wminfo;

//-----------------------------------------
// Internal parameters, used for engine.
//

// File handling stuff.
extern  FILE   *debugfile;

// wipegamestate can be set to -1
//  to force a wipe on the next draw
extern  gamestate_t     wipegamestate;

// debug flag to cancel adaptiveness
extern  boolean         singletics;

extern  int             bodyqueslot;

// Needed to store the number of the dummy sky flat.
// Used for rendering, as well as tracking projectiles etc.

extern int    skyflatnum;

extern  int        maketic;

// Networking and tick handling related.
#define BACKUPTICS              12

extern  ticcmd_t   netcmds[][BACKUPTICS];
extern  int        ticdup;

//-----------------------------------------------------------------------------

/* killough 8/8/98: distance friendly monsters tend to stay from player */
extern int distfriend, default_distfriend;

extern int HelperThing;          // type of thing to use for helper

#endif