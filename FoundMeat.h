/********************************
 * @Filename:    FoundMeat.c    *
 * @Author:      @classzheng    *
 * @LastCommit:  2024/07/17     *
 * RawMeat Island🥩 Foundation  *
 ********************************/
 
// IncludeHeaders: {
#include <math.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h> // C99
// } ===============

// GraphicsLibrary:{
typedef struct {
	unsigned char red;
	unsigned char green;
	unsigned char blue;
} RgbStore;
#define RgbEqual(a,b) (a.red==b.red && a.green==b.green && a.blue==b.blue)
#define xyvalid(x,y,wt) (0 <= x && x < wt && 0 <= y && y < wt)

RgbStore       // Palette
  blood={222,28,28},   rawm={232,158,98},   sfrawm={252,158,98},
  rawrIm={227,137,98}, cookdm={201,122,87}, rwsm={250,158,98},
  mudm={105,63,45},    sky={222,202,198},   rainysk={212,177,173};
RgbStore
  player={76,190,190}, rnclr={222,91,81},   thund={236,238,255},
  emp={0,0,0};

short i,j,k=0; // GlobalCounter

char* GFrgbx1Bstr(RgbStore pxl,bool wit){
	char* str=(char*)malloc(sizeof(char)*114);
	if(wit==0) {
		sprintf(str,"\x1b[48;2;%d;%d;%dm",pxl.red,pxl.green,pxl.blue);
	} else {
		sprintf(str,"\x1b[38;2;%d;%d;%dm",pxl.red,pxl.green,pxl.blue);
	}
	return str;
}

//  MathFunctions: {
  	  float MFInvSqrt(float x) {
	      float xhalf = 0.5f*x;
	      int i = *(int*)&x;
	      i = 0x5f3759df - (i >> 1);
	      x = *(float*)&i;
	      x = x*(1.5f - xhalf*x*x);
	      return x;
	  }
	  double MFgetXYDis(double x1,double y1,double x2,double y2) {
		  return 1/MFInvSqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	  }
//  } ==============

void GFcuthalf(RgbStore* rs,short wt) {
	RgbStore *nwi=(RgbStore*)malloc(sizeof(RgbStore)*(wt+1)*(wt+1));
	for(k=0,i=0; i<wt; i+=2,k++) {
		for(j=0; j<wt; j++) nwi[(wt-k)*wt+j]=rs[i*wt+j],rs[i*wt+j]=emp;
	}
	memcpy(rs,nwi,sizeof(RgbStore)*wt*wt),free(nwi);
	return ;
}
RgbStore* GFQcirc(short wt,short bdr,short rad,short cnt,RgbStore bdrfill,RgbStore fill) {
	RgbStore *rs=(RgbStore*)malloc(sizeof(RgbStore)*(wt+1)*(wt+1));
	for(i=0; i<wt; i++) {
		for(j=0; j<wt; j++) {
			if(MFgetXYDis(i,j,wt/2,wt/2)>=(rad-bdr/2)&&MFgetXYDis(i,j,wt/2,wt/2)<=(rad+bdr/2)) rs[i*wt+j]=bdrfill;
			if(MFgetXYDis(i,j,wt/2,wt/2)<(rad-bdr/2)) rs[i*wt+j]=fill;
		}
	}
	while(cnt--)
	  GFcuthalf(rs,wt);
	return rs;
}

void GFDisp(RgbStore* matrix, unsigned wt, bool mode) {
	if(!mode) {
		if(wt%2) return ;
		for(i=0; i<wt; i+=2) {
		  for(j=0; j<wt; j++)
		  	printf("%s%s▄",GFrgbx1Bstr(matrix[wt*i+j],false),GFrgbx1Bstr(matrix[wt*(i+1)+j],true));
		  puts("\x1b[0m");
		}
	} else {
		for(i=0; i<wt; i++) {
		  for(j=0; j<wt; j++)
		  	printf("%s  ",GFrgbx1Bstr(matrix[wt*i+j],false));
		  puts("\x1b[0m");
		}
	}
	return ;
}
// } ================

// GameLogic:       {
typedef RgbStore MeatBlc;
typedef struct {
	short    crdx;
	short    crdy;
	short    crdz;
	RgbStore cor;
} GLplayer;
typedef MeatBlc*  GLmap;
typedef GLmap*    GLworld;
MeatBlc
  Bblood={222,28,28},   Brawm={232,158,98},   Bsfrawm={252,158,98},
  BrawrIm={227,137,98}, Bcookdm={201,122,87}, Brwsm={250,158,98},
  Bmudm={105,63,45},    Bsky={222,202,198},   Brainysk={212,177,173};
GLmap   grtFillet(short,long long);
GLworld grtIsland(short,long long);
// } ================
