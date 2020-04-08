/*
ALEX K JAN-2003
Ellegant way to free class constructor
Two methods: try which is faster
*/
//-----------------------------------------------------------------------------------------
#ifndef __CLEAR_CLASS__
#define __CLEAR_CLASS__

#define ALGNTYPE char
#define _BEGINCLASSDATA_ ALGNTYPE _algn_strt;

//#define TEMPPPMACRO memset(&_algn_strt,0,(&_algn_end-&_algn_strt)+sizeof(ALGNTYPE))
#define TEMPPPMACRO char *ptr=&_algn_strt;for(int c=0;c<(&_algn_end-&_algn_strt+sizeof(ALGNTYPE));++c){ptr[c]=0;};

#define _CLEARCLASSDATA TEMPPPMACRO
/*the same macro but assignes uniq id to classID -  used for callback functions*/
#define _CLEARCLASSDATA_ID TEMPPPMACRO classID=CLASSID


#define _ENDCLASSDATA_ ALGNTYPE _algn_end;

#define  test(val)    char drak[16]; ltoa(val,drak,10); MessageBox(0,drak,"Value",0);

#define  test2(val)    char frak[16]; ltoa(val,frak,10); SetWindowText(hwnD,frak);
//-----------------------------------------------------------------------------------------

#define  te(str)  MessageBox(0,str,"Value",0);

#define _GET_CLASS_POINTER_a_     CONTROLCLS * a = (CONTROLCLS*)GetWindowLong(hWlb, GWL_USERDATA); if (!a) return 0;

//-----------------------------------------------------------------------------------------
#endif //__CLEAR_CLASS__

//============================================================
#define ADD_BUTTONW(hhw,x,y,w,h,id,lptxt)  SendMessage(CreateWindow ("BUTTON", (LPSTR) lptxt,\
                          WS_CHILD | WS_VISIBLE | WS_BORDER|BS_FLAT ,\
						  x,y,w,h,\
                          (HWND)hhw,(HMENU) (int) id,\
						  (HINSTANCE) GetWindowLong((HWND)hhw, GWL_HINSTANCE),(LPVOID) NULL)\
,WM_SETFONT,(WPARAM) (HANDLE) GetStockObject(ANSI_VAR_FONT),TRUE)

#define ADD_TEXT(hP,  x,y,w,h,id,lptxt) SendMessage(CreateWindowEx (0,"STATIC", (LPSTR) lptxt,\
                          WS_CHILD | WS_VISIBLE,\
			      			  x,y,w,h,\
                          (HWND)hP,(HMENU) (int) 550+ id,\
						  (HINSTANCE) GetWindowLong ((HWND)hP, GWL_HINSTANCE),\
						  (LPVOID) NULL),WM_SETFONT, (WPARAM) & font_vw,TRUE)

#define ADD_EDIT(hP,  x,y,w,h,id,lptxt) SendMessage(CreateWindowEx (0,"EDIT", (LPSTR) lptxt,\
                          WS_CHILD | WS_VISIBLE,\
			      			  x,y,w,h,\
                          (HWND)hP,(HMENU) (int) id,\
						  (HINSTANCE) GetWindowLong ((HWND)hP, GWL_HINSTANCE),\
						  (LPVOID) NULL),WM_SETFONT, (WPARAM) (HANDLE) GetStockObject(ANSI_VAR_FONT),TRUE)

//#define  COMPARE3(s,i,n)      if  ((dak[i]='s')&&(dak[i+1]=='i')&&(dak[i+2]=='n')) { colorKeyWord(&dak[i],i, i +3, 1); i+=2; };
//#define SPLIT (sin) s,i,n
//#define MAXIMUM (a,b)
//============================================================
#include <sys/stat.h>
bool FileExists(char* filename)
{
    struct stat fileInfo;
    return stat(filename, &fileInfo) == 0;
}
static double PRECISION = 0.00000000000001;
static int MAX_NUMBER_STRING_SIZE = 32;

/**
 * Double to ASCII
 */
 //===========================================
char * dtoa(char *s, double n) {
    // handle special cases
    if (isnan(n)) {
        strcpy(s, "nan");
    } else if (isinf(n)) {
        strcpy(s, "inf");
    } else if (n == 0.0) {
        strcpy(s, "0");
    } else {
        int digit, m, m1;
        char *c = s;
        int neg = (n < 0);
        if (neg)
            n = -n;
        // calculate magnitude
        m = log10(n);
        int useExp = (m >= 14 || (neg && m >= 9) || m <= -9);
        if (neg)
            *(c++) = '-';
        // set up for scientific notation
        if (useExp) {
            if (m < 0)
               m -= 1.0;
            n = n / pow(10.0, m);
            m1 = m;
            m = 0;
        }
        if (m < 1.0) {
            m = 0;
        }
        // convert the number
        while (n > PRECISION || m >= 0) {
            double weight = pow(10.0, m);
            if (weight > 0 && !isinf(weight)) {
                digit = floor(n / weight);
                n -= (digit * weight);
                *(c++) = '0' + digit;
            }
            if (m == 0 && n > 0)
                *(c++) = '.';
            m--;
        }
        if (useExp) {
            // convert the exponent
            int i, j;
            *(c++) = 'e';
            if (m1 > 0) {
                *(c++) = '+';
            } else {
                *(c++) = '-';
                m1 = -m1;
            }
            m = 0;
            while (m1 > 0) {
                *(c++) = '0' + m1 % 10;
                m1 /= 10;
                m++;
            }
            c -= m;
            for (i = 0, j = m-1; i<j; i++, j--) {
                // swap without temporary
                c[i] ^= c[j];
                c[j] ^= c[i];
                c[i] ^= c[j];
            }
            c += m;
        }
        *(c) = '\0';
    }
    return s;
}
//-----------------------------------------------------------------------------------------

static    long decad[8]={10,100,1000,10000,100000,1000000,10000000};
void ftoa(float flval, char *text, int num_digits)
{
      //sprintf(text, "%.2f", flval); //%02d
int a;////total number of digits with only 2 after RADIX
int minu='-';///
char lpRT1[8]={0,0,0,0,0,0,0,0};;
long 	nb[8]={0,0,0,0,0,0,0,0};
long 	nbk[8]={0,0,0,0,0,0,0,0};
	int e;//index
	float miniml= pow(10,-num_digits+1);

                  for (e=1;e<num_digits;++e)
                  {
                  nb[e] = (long) fabs(fmod(flval,(double)1.0)*decad[e-1]);
                  nbk[e]=nb[e]-(10*nb[e-1]);
                  itoa(nbk[e],&lpRT1[e-1],10);
                  }
			for (e=num_digits-1;e>1;--e)
			{
		        if (nbk[e]==0) lpRT1[e-1]=' ';
		        if (nbk[e]!=0) break;
		        }
	  if (flval<0) //(-miniml))
	  {
	  text[0]='-';///minus
	  itoa((long) fabs(flval),&text[2],10);
	  }
	  else
        {
		  ///strcat(text,(char*)&bksp);////backspace instead of minus --optional
		  itoa((long) fabs(flval),text,10);
		}

		  strcat(text,".");
          strcat(text,lpRT1);

return ;
}
//======================================================================================
//======================================================================================
#define TWOPI 6.28318530717958647692
//------------------------------------------------------/////
/*

  Fast sinus and cos calc in loop with size of TABLESIZE
  This macroses writen by Alex K. on February 2002

  USAGE:
  INIT_FASTSIN(1.0,2);
  loop:
     double s=FASTSIN(2);  //// we get sin(1.0*TWOPI/TABLESIZE*index);
*/
//------------------------------------------------------/////

#define INIT_FASTSIN(N,id) double wrek##id=N*TWOPI/TABLESIZE; double brek##id=2.0\
*cos(wrek##id);double ygo##id=0; double ygn##id=-sin(wrek##id); double ygd##id=\
-sin(2.0*wrek##id)

#define FASTSIN(id) ygo##id = brek##id*ygn##id - ygd##id; ygd##id\
= ygn##id ; ygn##id = ygo##id

#define INIT_FASTCOS(N,id) double wreck##id= N*TWOPI/TABLESIZE; double breck##id = 2.0\
* cos(wreck##id); double ygco##id=0; double icp##id= M_PI*0.5; double ygcn##id=\
sin(icp##id-wreck##id); double ygcd##id=sin(icp##id-2.0*wreck##id)

#define FASTCOS(id) ygco##id = breck##id*ygcn##id - ygcd##id; ygcd##id =\
ygcn##id ; ygcn##id = ygco##id

#include <stdint.h>
//------------------------------------------------------/////
/*typedef union _LARGE_INTEGER {
    struct {
        DWORD LowPart;
        LONG HighPart;
    } DUMMYSTRUCTNAME;
    struct {
        DWORD LowPart;
        LONG HighPart;
    } u;
    LONGLONG QuadPart;
}LARGE_INTEGER;*/

/*inline unsigned X86_RDTSC()
{
 // unsigned res;
 // asm("rdtsc" :"=eax" (res) : : "eax", "edx");
  return __rdtsc();
}*/
/*
#define PERF_DECLARE         \
  __int64 MSRB, MSRE;        \
  void *mrsb = &MSRB;    \
  void *mrse = &MSRE;    \
  char perfmtrbuf[100];

#define PERF_START          \
  asm("\
  mov eax, 0          \
  cpuid                \
  rdtsc                \
  mov ebx, mrsb        \
  mov dword ptr [ebx], eax    \
  mov dword ptr [ebx+4], edx  \
  mov eax, 0           \
  sm cpuid")

#define PERF_STOP           \
  asm("\
  mov eax, 0          \
  cpuid                \
  rdtsc                \
  mov ebx, mrse        \
  mov dword ptr [ebx], eax   \
  mov dword ptr [ebx+4], edx \
  mov eax, 0           \
  cpuid")

#define PERF_REPORT          \
  {_ui64toa(MSRE-MSRB, perfmtrbuf, 10);    \
  UpdateStatusBar(perfmtrbuf, 2, 0);}

  //MessageBox(0,perfmtrbuf,"Cycles needed: ", 0);}

*/



