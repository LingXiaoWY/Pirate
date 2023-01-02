#ifndef PACKDEF_H
#define PACKDEF_H

#define BACKGROUND_WIDTH  (1215)
#define BACKGROUND_HEIGHT (567)

#define BOX_WIDTH       (77)
#define BOX_HEIGHT      (67)
#define BOMB_WIDTH      (40)
#define BOMB_HEIGHT     (57)
#define CAPTAIN1_WIDTH  (57)
#define CAPTAIN1_HEIGHT (62)
#define CAPTAIN2_WIDTH  (62)
#define CAPTAIN2_HEIGHT (62)
#define SAILOR1_WIDTH   (53)
#define SAILOR1_HEIGHT  (52)
#define SAILOR2_WIDTH   (53)
#define SAILOR2_HEIGHT  (51)
#define DEF_TIME        (15) //回合时间
#define DEF_BOX_TIME    (10) //箱子间隔出现时间
#define DEF_PERSON      (5)  //人数

//红方、蓝方
enum REDORBLUE{Red=0,Blue};

//人物类型
enum BOXTYPE{bomb=0,Captain1,Captain2,Sailor1,Sailor2,Soil1,Soil2};

#endif // PACKDEF_H
