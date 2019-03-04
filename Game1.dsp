# Microsoft Developer Studio Project File - Name="Game1" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) External Target" 0x0106

CFG=Game1 - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Game1.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Game1.mak" CFG="Game1 - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Game1 - Win32 Release" (based on "Win32 (x86) External Target")
!MESSAGE "Game1 - Win32 Multiboot" (based on "Win32 (x86) External Target")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "Game1 - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Cmd_Line "NMAKE /f Game1.mak"
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "Game1.exe"
# PROP BASE Bsc_Name "Game1.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Cmd_Line "make"
# PROP Rebuild_Opt "clean"
# PROP Target_File "Matrix.exe"
# PROP Bsc_Name "Game1.bsc"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "Game1 - Win32 Multiboot"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Game1___Win32_Multiboot"
# PROP BASE Intermediate_Dir "Game1___Win32_Multiboot"
# PROP BASE Cmd_Line ""D:\Programming GBA\Game1\Make.BAT""
# PROP BASE Rebuild_Opt "/a"
# PROP BASE Target_File "Game1.exe"
# PROP BASE Bsc_Name "Game1.bsc"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Game1___Win32_Multiboot"
# PROP Intermediate_Dir "Game1___Win32_Multiboot"
# PROP Cmd_Line ""D:\Programming GBA\Game1\multiboot.BAT""
# PROP Rebuild_Opt "/a"
# PROP Target_File "Game1.exe"
# PROP Bsc_Name "Game1.bsc"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "Game1 - Win32 Release"
# Name "Game1 - Win32 Multiboot"

!IF  "$(CFG)" == "Game1 - Win32 Release"

!ELSEIF  "$(CFG)" == "Game1 - Win32 Multiboot"

!ENDIF 

# Begin Group "Matrix"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\matrix\cluster.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\cluster.h
# End Source File
# Begin Source File

SOURCE=.\matrix\cursor.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\cursor.h
# End Source File
# Begin Source File

SOURCE=.\matrix\endless.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\endless.h
# End Source File
# Begin Source File

SOURCE=.\matrix\engine.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\engine.h
# End Source File
# Begin Source File

SOURCE=.\matrix\Entry.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\Entry.h
# End Source File
# Begin Source File

SOURCE=.\matrix\flipTile.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\flipTile.h
# End Source File
# Begin Source File

SOURCE=.\matrix\linker.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\linker.h
# End Source File
# Begin Source File

SOURCE=.\matrix\Makefile
# End Source File
# Begin Source File

SOURCE=.\matrix\paintTile.armcpp
# End Source File
# Begin Source File

SOURCE=.\matrix\pauseEndless.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\pauseEndless.h
# End Source File
# Begin Source File

SOURCE=.\matrix\pauseEngine.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\pauseEngine.h
# End Source File
# Begin Source File

SOURCE=.\matrix\Puzzle.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\Puzzle.h
# End Source File
# Begin Source File

SOURCE=.\matrix\puzzleData.h
# End Source File
# Begin Source File

SOURCE=.\matrix\Score.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\Score.h
# End Source File
# Begin Source File

SOURCE=.\matrix\streak.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\streak.h
# End Source File
# Begin Source File

SOURCE=.\matrix\streakCounter.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\streakCounter.h
# End Source File
# Begin Source File

SOURCE=.\matrix\switchTile.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\switchTile.h
# End Source File
# Begin Source File

SOURCE=.\matrix\text.cpp
# End Source File
# Begin Source File

SOURCE=.\matrix\text.h
# End Source File
# End Group
# Begin Group "Menu"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\Menu\Makefile
# End Source File
# Begin Source File

SOURCE=.\menu\miErasePlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miErasePlayer.h
# End Source File
# Begin Source File

SOURCE=.\menu\miLoadPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miLoadPlayer.h
# End Source File
# Begin Source File

SOURCE=.\menu\miNewPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miNewPlayer.h
# End Source File
# Begin Source File

SOURCE=.\menu\miPlayNow.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miPlayNow.h
# End Source File
# Begin Source File

SOURCE=.\menu\miPuzzleMode.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miPuzzleMode.h
# End Source File
# Begin Source File

SOURCE=.\menu\miSunset.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miSunset.h
# End Source File
# Begin Source File

SOURCE=.\menu\miTopScores.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\miTopScores.h
# End Source File
# Begin Source File

SOURCE=.\menu\mnuBase.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\mnuBase.h
# End Source File
# Begin Source File

SOURCE=.\menu\mnuMain.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\mnuMain.h
# End Source File
# Begin Source File

SOURCE=.\Menu\mnuMainItems.h
# End Source File
# Begin Source File

SOURCE=.\menu\mnuPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\menu\mnuPlayer.h
# End Source File
# Begin Source File

SOURCE=.\Menu\mnuPlayerItems.h
# End Source File
# End Group
# Begin Group "Screens"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\screens\faces.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\faces.h
# End Source File
# Begin Source File

SOURCE=.\screens\Makefile
# End Source File
# Begin Source File

SOURCE=.\screens\scrErasePlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrErasePlayer.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrFinishGame.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrFinishGame.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrLoadPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrLoadPlayer.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrNameEntry.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrNameEntry.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrNewPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrNewPlayer.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrPlayer.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrPlayer.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrSunset.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrSunset.h
# End Source File
# Begin Source File

SOURCE=.\screens\scrTopScores.cpp
# End Source File
# Begin Source File

SOURCE=.\screens\scrTopScores.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\resources\1P.h
# End Source File
# Begin Source File

SOURCE=.\resources\Again.h
# End Source File
# Begin Source File

SOURCE=.\resources\Atta.h
# End Source File
# Begin Source File

SOURCE=.\resources\bar.h
# End Source File
# Begin Source File

SOURCE=.\resources\barPatern.h
# End Source File
# Begin Source File

SOURCE=.\resources\bg_a.h
# End Source File
# Begin Source File

SOURCE=.\resources\bg_b.h
# End Source File
# Begin Source File

SOURCE=.\resources\bg_c.h
# End Source File
# Begin Source File

SOURCE=.\resources\box1.h
# End Source File
# Begin Source File

SOURCE=.\resources\box2.h
# End Source File
# Begin Source File

SOURCE=.\resources\box3.h
# End Source File
# Begin Source File

SOURCE=.\resources\box4.h
# End Source File
# Begin Source File

SOURCE=.\resources\box5.h
# End Source File
# Begin Source File

SOURCE=.\resources\ck.h
# End Source File
# Begin Source File

SOURCE=.\resources\Cre.h
# End Source File
# Begin Source File

SOURCE=.\resources\diamond.h
# End Source File
# Begin Source File

SOURCE=.\resources\dits.h
# End Source File
# Begin Source File

SOURCE=.\resources\eak.h
# End Source File
# Begin Source File

SOURCE=.\resources\ED.h
# End Source File
# Begin Source File

SOURCE=.\resources\er.h
# End Source File
# Begin Source File

SOURCE=.\resources\Era.h
# End Source File
# Begin Source File

SOURCE=.\resources\ErasePlayer.h
# End Source File
# Begin Source File

SOURCE=.\resources\Exit.h
# End Source File
# Begin Source File

SOURCE=.\resources\face1.h
# End Source File
# Begin Source File

SOURCE=.\resources\face2.h
# End Source File
# Begin Source File

SOURCE=.\resources\face3.h
# End Source File
# Begin Source File

SOURCE=.\resources\face4.h
# End Source File
# Begin Source File

SOURCE=.\resources\face5.h
# End Source File
# Begin Source File

SOURCE=.\resources\face6.h
# End Source File
# Begin Source File

SOURCE=.\resources\face7.h
# End Source File
# Begin Source File

SOURCE=.\resources\face8.h
# End Source File
# Begin Source File

SOURCE=.\resources\Fish.h
# End Source File
# Begin Source File

SOURCE=.\resources\fishCursor.h
# End Source File
# Begin Source File

SOURCE=.\resources\Game.h
# End Source File
# Begin Source File

SOURCE=.\resources\GAME2.h
# End Source File
# Begin Source File

SOURCE=.\resources\gamedata.c
# End Source File
# Begin Source File

SOURCE=.\resources\gamedata.h
# End Source File
# Begin Source File

SOURCE=.\resources\gamedata2.h
# End Source File
# Begin Source File

SOURCE=.\resources\Hex.h
# End Source File
# Begin Source File

SOURCE=.\resources\HiSco.h
# End Source File
# Begin Source File

SOURCE=.\resources\le.h
# End Source File
# Begin Source File

SOURCE=.\resources\le2.h
# End Source File
# Begin Source File

SOURCE=.\resources\LE3.h
# End Source File
# Begin Source File

SOURCE=.\resources\Load.h
# End Source File
# Begin Source File

SOURCE=.\resources\LoadPlayer.h
# End Source File
# Begin Source File

SOURCE=.\resources\LOSE.h
# End Source File
# Begin Source File

SOURCE=.\resources\Lv.h
# End Source File
# Begin Source File

SOURCE=.\resources\main.h
# End Source File
# Begin Source File

SOURCE=.\resources\Makefile
# End Source File
# Begin Source File

SOURCE=.\resources\map.c
# End Source File
# Begin Source File

SOURCE=.\resources\matrix.h
# End Source File
# Begin Source File

SOURCE=.\resources\Menu.h
# End Source File
# Begin Source File

SOURCE=.\resources\Mode.h
# End Source File
# Begin Source File

SOURCE=.\resources\Multi.h
# End Source File
# Begin Source File

SOURCE=.\resources\Name.h
# End Source File
# Begin Source File

SOURCE=.\resources\NameEntry.h
# End Source File
# Begin Source File

SOURCE=.\resources\New.h
# End Source File
# Begin Source File

SOURCE=.\resources\NewPlayer.h
# End Source File
# Begin Source File

SOURCE=.\resources\Next.h
# End Source File
# Begin Source File

SOURCE=.\resources\Now.h
# End Source File
# Begin Source File

SOURCE=.\resources\ns.h
# End Source File
# Begin Source File

SOURCE=.\resources\numbers.h
# End Source File
# Begin Source File

SOURCE=.\resources\Optio.h
# End Source File
# Begin Source File

SOURCE=.\resources\PAUS.h
# End Source File
# Begin Source File

SOURCE=.\resources\pctext.h
# End Source File
# Begin Source File

SOURCE=.\resources\Play.h
# End Source File
# Begin Source File

SOURCE=.\resources\Puzz.h
# End Source File
# Begin Source File

SOURCE=.\resources\PUZZ2.h
# End Source File
# Begin Source File

SOURCE=.\resources\re.h
# End Source File
# Begin Source File

SOURCE=.\resources\re2.h
# End Source File
# Begin Source File

SOURCE=.\resources\res.h
# End Source File
# Begin Source File

SOURCE=.\resources\Resources.cpp
# End Source File
# Begin Source File

SOURCE=.\Resources\Resources.h
# End Source File
# Begin Source File

SOURCE=.\resources\Resources2.h
# End Source File
# Begin Source File

SOURCE=.\resources\Retu.h
# End Source File
# Begin Source File

SOURCE=.\resources\rn.h
# End Source File
# Begin Source File

SOURCE=.\resources\Sco.h
# End Source File
# Begin Source File

SOURCE=.\resources\Sco2.h
# End Source File
# Begin Source File

SOURCE=.\resources\score.h
# End Source File
# Begin Source File

SOURCE=.\resources\se.h
# End Source File
# Begin Source File

SOURCE=.\resources\sprite.h
# End Source File
# Begin Source File

SOURCE=.\resources\sprite2.h
# End Source File
# Begin Source File

SOURCE=.\resources\Str.h
# End Source File
# Begin Source File

SOURCE=.\resources\sunset.h
# End Source File
# Begin Source File

SOURCE=.\resources\text.h
# End Source File
# Begin Source File

SOURCE=.\resources\TextCursor.h
# End Source File
# Begin Source File

SOURCE=.\resources\tileset.h
# End Source File
# Begin Source File

SOURCE=.\resources\Time.h
# End Source File
# Begin Source File

SOURCE=.\resources\Timer.h
# End Source File
# Begin Source File

SOURCE=.\resources\TitleScreen.h
# End Source File
# Begin Source File

SOURCE=.\resources\titlescreen2.h
# End Source File
# Begin Source File

SOURCE=.\resources\To.h
# End Source File
# Begin Source File

SOURCE=.\resources\Top.h
# End Source File
# Begin Source File

SOURCE=.\resources\topscores.h
# End Source File
# Begin Source File

SOURCE=.\resources\web.h
# End Source File
# Begin Source File

SOURCE=.\resources\WIN.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\make.inc
# End Source File
# Begin Source File

SOURCE=.\Makefile
# End Source File
# End Target
# End Project
