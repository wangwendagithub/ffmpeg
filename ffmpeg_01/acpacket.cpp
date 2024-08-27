#include "avpacket.h"

#define MEM_ITEM_SIZE (20*1024*102)
#define AVPACKET_LOOP_COUNT 1000

void av_packet_test1()
{
	AVPacket* ptk = NULL;
	int ret = 0;
	ptk = av_packet_alloc();
	ret = av_new_packet(ptk,MEM_ITEM_SIZE);//引用计数初始化为1
	memcpy(ptk->data,(void*)&av_packet_test1,MEM_ITEM_SIZE);
	av_packet_unref(ptk);
}