#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>

int main(void) {
    const char *cmd = "ffmpeg -f avfoundation -video_size 640x480 -framerate 30 -i \"0\" -vframes 60 test.mp4";
    system(cmd);

    // avdevice_register_all();

    // AVInputFormat *fmt = av_find_input_format("avfoundation");

    // AVFormatContext *ctx = NULL;
    // if (avformat_open_input(&ctx, "0", fmt, NULL) != 0) {
    //     // Handle error
    //     puts("somethings trucked");
    // }

    return 0;
}
