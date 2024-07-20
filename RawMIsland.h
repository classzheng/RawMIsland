/********************************
 * @Filename:    RawMIsland.h   *
 * @Author:      @classzheng    *
 * @LastCommit:  2024/07/17     *
 * RawMeat Island🥩             *
 ********************************/
#include "FoundMeat.h"
typedef enum {
  BlaLine,HgIsland,Blood,Sky,Island,
} StagMode;
RgbStore* greateWorld(short wt,long long seed,StagMode stag) {
	RgbStore* mtr;
	switch(stag) {
	  case BlaLine:
	  	mtr=(RgbStore*)malloc(sizeof(RgbStore)*wt*wt);
	  	for(i=wt-10; i<wt; i++)
	  	  for(j=0; j<wt; j++)
	  		mtr[i*wt+j]=blood;
		for(i=0; i<wt; i++)
			for(j=0; j<wt; j++) if(RgbEqual(mtr[i*wt+j],emp))mtr[i*wt+j]=sky;
		return mtr;
	  case HgIsland:
		srand(seed),mtr=GFQcirc(wt,wt/4+rand()%7,wt*3/10,wt/40,rawm,rrm);
		for(i=wt-10; i<wt; i++)
		  for(j=0; j<wt; j++)
		  	if(RgbEqual(mtr[i*wt+j],emp))
		  		mtr[i*wt+j]=blood;
		  	else {
		  		mtr[i*wt+j].red+=20;
		  		if(!(rand()%7)) mtr[(i-1)*wt+j].red++;
		  	}
		for(i=0; i < wt; i++) {
			if(rand()%2) {
				for(j=0; j < wt; j++) {
					if(RgbEqual(mtr[j*wt+i],rawm))     { mtr[j*wt+i]=emp; break; }
					else if(RgbEqual(mtr[j*wt+i],blood)) break;
				}
			}
		}
		for(i=0; i < wt; i++) {
			if(rand()%2) {
				for(j=wt-1; j >= 0; j--) {
					if(RgbEqual(mtr[j*wt+i],qrm))     { mtr[j*wt+i]=blood; break; }
					else if(RgbEqual(mtr[j*wt+i],rawm)||RgbEqual(mtr[j*wt+i],emp)||RgbEqual(mtr[j*wt+i],rawm)) break;
				}
			}
		}
		for(i=0; i < wt; i++) {
			for(j=0; j < wt; j++) {
				if(RgbEqual(mtr[j*wt+i],rawm)&&rand()%10) {
					bool reach=false;
					if(true)     mtr[j*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[j*wt+i],emp)) mtr[j*wt+i]=mtr[j*wt+i-1];
					if(rand()%5&&RgbEqual(mtr[j*wt+i],rawm)) reach=false;
					if(rand()%5&&reach) mtr[(j+1)*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[(j+1)*wt+i],emp)) mtr[(j+1)*wt+i]=mtr[(j+1)*wt+i-1];
					if(rand()%5&&reach) mtr[(j+2)*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[(j+2)*wt+i],emp)) mtr[(j+2)*wt+i]=mtr[(j+2)*wt+i-1];
					break;
				}
				else if(RgbEqual(mtr[j*wt+i],blood)) break;
			}
		}
		for(i=0; i<wt; i++)
			for(j=0; j<wt; j++) if(RgbEqual(mtr[i*wt+j],emp))mtr[i*wt+j]=sky;
		for(i=0; i<wt; i++)
			for(j=0; j<wt; j++)
				if((!RgbEqual(mtr[i*wt+j],sky))&&RgbEqual(mtr[(i+1)*wt+j],sky)) mtr[(i+1)*wt+j]=rawm;
		return mtr;
	  case Blood:
	  	mtr=(RgbStore*)malloc(sizeof(RgbStore)*wt*wt);
  	  	for(i=0; i<wt; i++)
  	  	  for(j=0; j<wt; j++)
  	  		mtr[i*wt+j]=blood;
  	  	return mtr;
	  case Sky:
	  	mtr=(RgbStore*)malloc(sizeof(RgbStore)*wt*wt);
  	  	for(i=0; i<wt; i++)
  	  	  for(j=0; j<wt; j++)
  	  		mtr[i*wt+j]=sky;
  	  	return mtr;
	  case Island:
		srand(seed),mtr=GFQcirc(wt,(wt/4+rand()%7)/2,wt*3/20,wt/40,rawm,rrm);
		for(i=wt-10; i<wt; i++)
		  for(j=0; j<wt; j++)
		  	if(RgbEqual(mtr[i*wt+j],emp))
		  		mtr[i*wt+j]=blood;
		  	else {
		  		mtr[i*wt+j].red+=20;
		  		if(!(rand()%7)) mtr[(i-1)*wt+j].red++;
		  	}
		for(i=0; i < wt; i++) {
			if(rand()%2) {
				for(j=0; j < wt; j++) {
					if(RgbEqual(mtr[j*wt+i],rawm))     { mtr[j*wt+i]=emp; break; }
					else if(RgbEqual(mtr[j*wt+i],blood)) break;
				}
			}
		}
		for(i=0; i < wt; i++) {
			if(rand()%2) {
				for(j=wt-1; j >= 0; j--) {
					if(RgbEqual(mtr[j*wt+i],qrm))     { mtr[j*wt+i]=blood; break; }
					else if(RgbEqual(mtr[j*wt+i],rawm)||RgbEqual(mtr[j*wt+i],emp)||RgbEqual(mtr[j*wt+i],rawm)) break;
				}
			}
		}
		for(i=0; i < wt; i++) {
			for(j=0; j < wt; j++) {
				if(RgbEqual(mtr[j*wt+i],rawm)&&rand()%10) {
					bool reach=false;
					if(true)     mtr[j*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[j*wt+i],emp)) mtr[j*wt+i]=mtr[j*wt+i-1];
					if(rand()%5&&RgbEqual(mtr[j*wt+i],rawm)) reach=false;
					if(rand()%5&&reach) mtr[(j+1)*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[(j+1)*wt+i],emp)) mtr[(j+1)*wt+i]=mtr[(j+1)*wt+i-1];
					if(rand()%5&&reach) mtr[(j+2)*wt+i]=cdm,reach=true;
					if(!(rand()%3)&&!RgbEqual(mtr[(j+2)*wt+i],emp)) mtr[(j+2)*wt+i]=mtr[(j+2)*wt+i-1];
					break;
				}
				else if(RgbEqual(mtr[j*wt+i],blood)) break;
			}
		}
		for(i=0; i<wt; i++)
			for(j=0; j<wt; j++) if(RgbEqual(mtr[i*wt+j],emp))mtr[i*wt+j]=sky;
		for(i=0; i<wt; i++)
			for(j=0; j<wt; j++)
				if((!RgbEqual(mtr[i*wt+j],sky))&&RgbEqual(mtr[(i+1)*wt+j],sky)) mtr[(i+1)*wt+j]=rawm;
		return mtr;
	};
}
