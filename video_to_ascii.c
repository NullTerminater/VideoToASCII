#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <stdint.h>
#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#include <bmp.h>


int main(void) {
    // const char *brightness = " .:-=+*#%@";

    // const char *cmd = "ffmpeg -f avfoundation -video_size 640x480 -framerate 30 -i \"0\" -vf \"format=gray\" -vframes 60 test.mp4";
    // system(cmd);
    // const char *extract = "ffmpeg -i test.mp4 -r 1 frame%d.bmp";
    // system(extract);
    int width, height, bpp;
    FILE *file = fopen("frame1.bmp", "r");

    uint8_t* rgb_image = stbi_load("frame1.bmp", &width, &height, &bpp, 3);
    long pos = ftell(file);
    printf("pos from ftell is %ld\n" , pos);
    printf("properties %d %d %d \n", width, height, bpp);
    stbi_image_free(rgb_image);

    return 0;
}
