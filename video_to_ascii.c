#include <stdio.h>
#include <libavdevice/avdevice.h>
#include <libavformat/avformat.h>
#include <stdint.h>
#include <stdlib.h>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"
#define LENGTH 10
#define CHUNK_SIZE 8
#define WIDTH 640
#define HEIGHT 480


int main(void) {
    const char *brightness = " .:-=+*#%@";
    // if (getenv("ASCII_VIDEO_MODE") == NULL) {
    //     // This code only runs in the ORIGINAL terminal
    //     const char *cmd = "osascript -e 'tell application \"Terminal\" to do script \"export ASCII_VIDEO_MODE=1; stty cols 80 rows 60; ~/personal/projects/VideoToAscii/./a.out\"'";
    //     system(cmd);
    //     return 0; // Close the original terminal's process
    // }
    uint8_t *buffer = malloc(WIDTH * HEIGHT);
    FILE *pipe = popen("ffmpeg -f avfoundation -framerate 30 -video_size 640x480 -i \"0\" -f rawvideo  -pix_fmt gray - -loglevel quiet -stats -vf \"transpose=2,transpose=2\"", "r");
    printf("\e[8;60;80t");
    while (fread(buffer, 1, WIDTH * HEIGHT, pipe) == WIDTH * HEIGHT){
        printf("\033[H");
        size_t bytes_read = fread(buffer, 1, WIDTH * HEIGHT, pipe);
        if (bytes_read < WIDTH * HEIGHT) {
            break;
        }
        for (int y = 0; y < HEIGHT; y+= CHUNK_SIZE){
            for(int x = 0; x < WIDTH; x+= CHUNK_SIZE){
                int value = buffer[y * WIDTH + x];
                int index = (value * (LENGTH - 1)) / 255;
                putchar(brightness[index]);
            }
            putchar('\n');
        }
        fflush(stdout);
    }
    pclose(pipe);
    free(buffer);
    return 0;
}
