/// class that stores global variables
/// 14.03.2020 Alex Kritov

////================================================================================================================

//COLORREF  REDIT_CONTAINER_BKGR= RGB(125,170,164);

class CColors
{
public:

	CColors ()
	{
    setColors(0);
	};

//==================================================================================================================

void setColors(int scheme)
{
    if (scheme==0)
    {
        //te("colors are set");
                                                        TREE_BACKGRCLR =RGB(72,84,108); //RGB(142,168,216)// we do it as almost insidearea RGB(125,170,164)
                                                        TREE_TEXT_COLOR =RGB(53,195,120); //RGB(53,195,120)
                                                        BKGR_INSIDEAREA= RGB(72,84,108);
                                                        REDIT_CONTAINER_BKGR= RGB(125,170,164);
                                                        WV_WINDOW_BKGR =RGB(125,170,164) ;///wv window color itself
                                                        WV_BKRG_CLR= RGB(72,84,108);///waveform background color
                                                        //WV_WINDOW_BKGR =RGB(125,170,164) ;
                                                        //W_BKGR =RGB(125,170,164) ; /// Rich Edit window container background
                                                        ST_BKGR =RGB(148,189,189);
                                                        EDIT_BKGR =RGB (148,179,189);
                                                        FONT_BKGR =RGB(19,19,22);
                                                        LBUTTON_COLOR= RGB(148,189,189);

                                                        COMMENTS_TEXT_COLOR =RGB(114, 117,113); //text color (code comments) in REdit
                                                        REDIT_TEXT_COLOR =RGB(24,27,33);

                                                        KEYWORDS_TEXT_COLOR   =RGB(6,10,166); ////
                                                        KEYWORDS_TEXT_COLOR1   =RGB(6,10,166); //// sin cos dsf
                                                        KEYWORDS_TEXT_COLOR2   =RGB(244,75,113); //// skobki
                                                        KEYWORDS_TEXT_COLOR3   =RGB(128,143, 242); /// RGB(37,118,80) - nice green

                                                        REDIT_BKGR_COLOR =RGB(208,230,213); // (172,215,157)<--- was your previous  //RGB(24,27,33)
                                                        DIALOGS_BGCOLOR =RGB(218,225,239);
                                                    /// buttons
                                                       BKGR_CBTN=RGB(111,149,135); ////BACKGROUND
                                                       BKGR_CBTN_PRESSED=RGB(101,139,115); ////BACKGROUND PRESSED
                                                       BKGR_CBTN_MOUSED=RGB(141,179,165);
                                                       CBNT_TXTCLR=RGB(22,25,26);
                                                       /// menus
                                                        BKGR_NFOBIG=RGB(111,149,135); ////BACKGROUND
                                                        NFBANK_TXTCLR=RGB(22,25,26);
                                                        /// digits (note)
                                                        BKGR_FLDG =RGB(111,149,135);// /// RGB(110,120,110) ///(0,30,108) //////BACKGROUND COLOR (178,199,192)
                                                        TXTCLR =RGB(22,25,26); ///RGB(137,201,186)     ////TEXT COLOR (5,54,6)
                                                        RE_WND_STATIC_TEXT_COLOR  =RGB(74, 87,93); //note nearby
                                                        /// slider
                                                        BKGR_CZSLIDER =RGB(79,103,127); //// BACKGROUND
                                                        CZSLIDER_COLOR=  RGB(66,193,82);
                                                        /// waveform line color
                                                        WV_WAVELINE_CLR=RGB(0,198,80);

                                                        SPEC_LINE_CLR1= RGB(0,198,80);/// line for spectrum color
                                                        SPEC_LINE_CLR2=RGB(198,80,90);/// line for frozen spectrum color

    }
     if (scheme==1)
    {
                                                        TREE_BACKGRCLR =RGB(181,181,181); //RGB(142,168,216)// we do it as almost insidearea RGB(125,170,164)
                                                        TREE_TEXT_COLOR =RGB(3,5,1);
                                                        BKGR_INSIDEAREA= RGB(141,141,141);
                                                        REDIT_CONTAINER_BKGR= RGB(181,181,181);

                                                        WV_WINDOW_BKGR =RGB(181,181,181) ; ///wv window color itself
                                                        WV_BKRG_CLR=RGB(131,131,131) ;///waveform background color
                                                        //W_BKGR =RGB(104,104,104); /// Rich Edit window container background
                                                        ST_BKGR =RGB(148,189,189);
                                                        EDIT_BKGR =RGB (48,79,89);
                                                        FONT_BKGR =RGB(19,19,22);
                                                        LBUTTON_COLOR= RGB(148,149,149);

                                                        COMMENTS_TEXT_COLOR =RGB(114, 117,113); //text color (code comments) in REdit
                                                        REDIT_TEXT_COLOR =RGB(0,0,0);

                                                        KEYWORDS_TEXT_COLOR   =RGB(6,10,166); ////
                                                        KEYWORDS_TEXT_COLOR1   =RGB(6,10,166); //// sin cos dsf
                                                        KEYWORDS_TEXT_COLOR2   =RGB(244,75,113); //// skobki
                                                        KEYWORDS_TEXT_COLOR3   =RGB(128,143, 242); /// RGB(37,118,80) - nice green

                                                        REDIT_BKGR_COLOR =RGB(255,255,255); // (172,215,157)<--- was your previous  //RGB(24,27,33)
                                                        DIALOGS_BGCOLOR =RGB(171,171,171);
                                                        //WS_WINDOW_BKGR =RGB(125,170,164);    /// spectrum view window background
                                                       /// buttons
                                                       BKGR_CBTN=RGB(141,149,149); ////BACKGROUND
                                                       BKGR_CBTN_PRESSED=RGB(171,179,175); ////BACKGROUND PRESSED
                                                       BKGR_CBTN_MOUSED=RGB(125,125,125);
                                                       CBNT_TXTCLR=RGB(22,25,26);
                                                       /// menus
                                                        BKGR_NFOBIG=RGB(149,149,149); ////BACKGROUND
                                                        NFBANK_TXTCLR=RGB(22,25,26);
                                                         ///digits (note)
                                                        BKGR_FLDG =RGB(149,149,149);// /// RGB(110,120,110) ///(0,30,108) //////BACKGROUND COLOR (178,199,192)
                                                        TXTCLR =RGB(22,25,26);
                                                        RE_WND_STATIC_TEXT_COLOR  =RGB(22,25,26);//note nearby
                                                        /// slider
                                                        BKGR_CZSLIDER =RGB(129,129,129); //// BACKGROUND
                                                        CZSLIDER_COLOR=  RGB(86,86,102);

                                                        /// waveform line color
                                                        WV_WAVELINE_CLR=RGB(103,103,149);

                                                        SPEC_LINE_CLR1= RGB(198,80,146);/// line for spectrum color
                                                        SPEC_LINE_CLR2=RGB(198,80,90);/// line for frozen spectrum color

    }



}
//==================================================================================================================
public:
COLORREF WV_WINDOW_BKGR;
COLORREF  TREE_BACKGRCLR ;
COLORREF TREE_TEXT_COLOR;
 COLORREF  BKGR_INSIDEAREA;
COLORREF  REDIT_CONTAINER_BKGR;
COLORREF  W_BKGR;
COLORREF  ST_BKGR;
COLORREF  EDIT_BKGR;
COLORREF  FONT_BKGR;
COLORREF  LBUTTON_COLOR;

COLORREF  COMMENTS_TEXT_COLOR;
COLORREF  REDIT_TEXT_COLOR;
COLORREF  RE_WND_STATIC_TEXT_COLOR;

COLORREF  KEYWORDS_TEXT_COLOR;
COLORREF  KEYWORDS_TEXT_COLOR2;
COLORREF  KEYWORDS_TEXT_COLOR1;
COLORREF  KEYWORDS_TEXT_COLOR3 ;

COLORREF  REDIT_BKGR_COLOR ;
COLORREF  DIALOGS_BGCOLOR;
COLORREF  WV_BKRG_CLR;
//Cbuttons
COLORREF BKGR_CBTN;// RGB(111,149,135) ////BACKGROUND
COLORREF BKGR_CBTN_PRESSED;// RGB(101,139,115) ////BACKGROUND PRESSED
COLORREF BKGR_CBTN_MOUSED;// RGB(141,179,165)
COLORREF CBNT_TXTCLR;
//menus
COLORREF BKGR_NFOBIG;// RGB(111,149,135) ////BACKGROUND
COLORREF NFBANK_TXTCLR;// RGB(22,25,26)
//digits
COLORREF BKGR_FLDG;// RGB(111,149,135) /// RGB(110,120,110) ///(0,30,108) //////BACKGROUND COLOR (178,199,192)
COLORREF TXTCLR;// RGB(22,25,26)
//slider
COLORREF BKGR_CZSLIDER;// RGB(79,103,127) //// BACKGROUND
COLORREF CLASSID;// 5454645             ////
COLORREF CZSLIDER_COLOR;//            RGB(66,193,82)
COLORREF WV_WAVELINE_CLR;

COLORREF SPEC_LINE_CLR1;/// line for spectrum color
COLORREF SPEC_LINE_CLR2;/// line for frozen spectrum color

private:


};
////================================================================================================================
