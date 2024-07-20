/********************************
 * @Filename:    RawMIsland.c   *
 * @Author:      @classzheng    *
 * @LastCommit:  2024/07/17     *
 * RawMeat Island🥩             *
 ********************************/
#include "RawMIsland.h"
int main(int ac,char* av[], char* ev[]) {
	srand(time(0));
	RgbStore* mtr=GLgrtFillet(40,rand());
	GFDisp(mtr,40,false);
	return 0;
}
