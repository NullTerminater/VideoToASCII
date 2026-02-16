#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"


int main(void) {
    // const char *brightness = " .:-=+*#%@";
    const char *cmd = "ffmpeg -f avfoundation -video_size 640x480 -framerate 30 -i \"0\" -vf \"format=gray\" -vframes 60 test.mp4";
    system(cmd);
    const char *extract = "ffmpeg -i test.mp4 -r 1 frame%d.bmp";
    system(extract);
    int width, height, bpp;

    uint8_t* rgb_image = stbi_load("frame1.bmp", &width, &height, &bpp, 3);
    printf("properties %s \n", rgb_image);
    stbi_image_free(rgb_image);

    // avdevice_register_all();

    // AVInputFormat *fmt = av_find_input_format("avfoundation");

    // AVFormatContext *ctx = NULL;
    // if (avformat_open_input(&ctx, "0", fmt, NULL) != 0) {
    //     // Handle error
    //     puts("somethings trucked");
    // }

    return 0;
}
