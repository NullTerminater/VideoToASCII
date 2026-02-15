#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>

int main(void) {
    const char *brightness = " .:-=+*#%@";
    const char *cmd = "ffmpeg -f avfoundation -video_size 640x480 -framerate 30 -i \"0\" -vf \"format=gray\" -vframes 60 test.mp4";
    system(cmd);
    const char *extract = "ffmpeg -i test.mp4 -r 1 frame%d.bmp";
    system(extract);

    // avdevice_register_all();

    // AVInputFormat *fmt = av_find_input_format("avfoundation");

    // AVFormatContext *ctx = NULL;
    // if (avformat_open_input(&ctx, "0", fmt, NULL) != 0) {
    //     // Handle error
    //     puts("somethings trucked");
    // }

    return 0;
}
