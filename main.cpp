/*

CAedit is the only global class that is built at the beginning.
(alone with CIniFile *cini class wich is available to every one)

All other child Controls classes are private member inside.
Some of the child classes are provided with pointer to global (CAedit) caedit.
So they can call some of the CAedit's function declared in GenCAedit.h class.

Alex K 08-02-2020 Salou Spain

*/
//#define PATTERN_VERSION //(see Project options)
//#define SINGLE_VERSION

#define _WIN32_IE 0x0400
#define _WIN32_WINNT_WIN7
//#define _WIN32_WINNT 0x0400

#define THIS_VERSION 1.0

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
//#include <dwmapi.h>

#include <math.h>
#include <string.h>
#include <stdio.h>

//#include "pelock.h"

#include "macro.h"

#include "ccolors.hpp"
static CColors *ccolors=0;//
#include "Files\iniFile.hpp"
static CIniFile *cini=0;
static char *text_made=0;/// ready for fast processing text
static char *pre_proccessed_text=0;///as RE holds it

//#include "Interface/GenAEditor.h"

HWND hWG=0;
#ifdef PATTERN_VERSION
#include "Interface/CAEditor_p.hpp"
#else
#include "Interface/CAEditor.hpp"
#endif

static CAedit *caedit=0;

#include "Engine/wavehandler.hpp"

#ifdef SINGLE_VERSION
#include "Files/halion.hpp" /// it needs an access to caedit class directly
#endif

////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
int WINAPI WinMain(HINSTANCE hinst, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{

	 cini  = new CIniFile();

     cini->ReadFile();
     current_gui_scheme=cini->GetValueI("GUI", "ColorScheme");///
     isTreeRightHandSided=cini->GetValueI("GUI", "isTreeRightHandSided");///
     //test(current_gui_scheme);

     ccolors= new CColors();/// create colorizer class
     ccolors->setColors(current_gui_scheme);/// set current color scheme

     caedit=new CAedit();

     hWG= caedit->CreateEditor((HWND)NULL,(long) hinst);

     MSG Msg;
     ///////////////////////////////////////////////////////////

    while(GetMessage(&Msg, NULL, 0, 0))
   {
      TranslateMessage(&Msg);
      DispatchMessage(&Msg);
   }
   return Msg.wParam;

}
////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////
