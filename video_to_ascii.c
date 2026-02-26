#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <stdint.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define LENGTH 10
#define CHUNK_SIZE 8


int main(void) {
    const char *brightness = " .:-=+*#%@";

    // const char *cmd = "ffmpeg -f avfoundation -video_size 640x480 -framerate 30 -i \"0\" -vf \"format=gray\" -vframes 60 test.mp4";
    // system(cmd);
    // const char *extract = "ffmpeg -i test.mp4 -r 1 frame%d.bmp";
    // system(extract);
    int width, height, bpp;
    // FILE *file = fopen("frame1.bmp", "r");
    // FILE *file = fopen("frame1_compressed.bmp", "r");
    uint8_t* rgb_image = stbi_load("frame1.bmp", &width, &height, &bpp, 3);
    if (rgb_image == NULL) {
        printf("Error: Could not load image\n");
        return 1;
    }

    FILE *file_pointer = fopen("ascii.txt", "w");
    for (int y = 0; y < height; y += CHUNK_SIZE){
        for(int x = 0; x < width; x += CHUNK_SIZE){


            uint8_t* pixel = rgb_image + (y * width + x) * 3;
            uint8_t r = pixel[0];
            uint8_t g = pixel[1]; //since this is a greyscale, we do not care about these yet
            uint8_t b = pixel[2];
            int index = (r * (LENGTH - 1)) / 255;
            char ascii = brightness[index];
            fputc(ascii, file_pointer);
        }
        fputc('\n', file_pointer);
    }
    fclose(file_pointer);

    // long pos = ftell(file);
    // printf("pos from ftell is %ld\n" , pos);
    // printf("properties %d %d %d \n", width, height, bpp);
    stbi_image_free(rgb_image);

    return 0;
}
