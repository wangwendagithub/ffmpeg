#include <stdio.h>
#include "avpacket.h"

extern "C"
{
	#include <libavcodec\avcodec.h>
	#include <libavformat\avformat.h>
	#include <libswscale\swscale.h>
	#include <libavdevice\avdevice.h>
	#include <libavutil\opt.h>	
}

#pragma comment(lib,"avcodec.lib")
#pragma comment(lib,"avformat.lib")
#pragma comment(lib,"avdevice.lib")
#pragma comment(lib,"swscale.lib")
#pragma comment(lib,"avutil.lib")

//AVFormatContext* pFormat = NULL;
//AVDictionary* opt = NULL;
AVPacket* packet = NULL;
SwsContext* swsCtx = NULL;
AVFrame* frame = NULL;
AVFrame* frameYUV = NULL;
const char* path = "11.mp4";

void dshow_device()
{
	AVFormatContext*  pFormat = avformat_alloc_context();
	AVDictionary* opt = NULL;
	av_dict_set(&opt,"list_devices","true",0);
	const AVInputFormat* ifmt = av_find_input_format("dshow");
	avformat_open_input(&pFormat,"video = dummy",ifmt,&opt);

}

void dshow_option()
{
	AVFormatContext* pFormat = avformat_alloc_context();
	AVDictionary* opt = NULL;
	av_dict_set(&opt, "list_options", "true", 0);
	const AVInputFormat* ifmt = av_find_input_format("dshow");
	avformat_open_input(&pFormat, "video = Integrated Webcam", ifmt, &opt);

}

int main()
{
	/*AVFormatContext* pFormat = NULL;
	AVDictionary* opt = NULL;

	printf("%s\n", avcodec_configuration());
	avformat_network_init();
	avdevice_register_all();

	dshow_device();
	dshow_option();

	const AVInputFormat* ifmt = av_find_input_format("dshow");
	if (avformat_open_input(&pFormat, "video = Integrated Webcam", ifmt, &opt))
	{
		printf("avformat_open_input failed \n");
	}
	printf("avformat_open_input success \n");*/
	av_packet_test1();
	return 0;
}