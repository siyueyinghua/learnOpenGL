#ifndef __ffmepg_h_
#define __ffmepg_h_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <GL/gl.h>
#include <libavcodec/avcodec.h>
#include <libavutil/imgutils.h>
#include <libavutil/opt.h>
#include <libswscale/swscale.h>

void common_generate_rgb(int width, int height, int pts, uint8_t **rgbp);
void ffmpeg_encoder_set_frame_yuv_from_rgb(AVCodecContext *c, struct SwsContext *sws_context, uint8_t *rgb, AVFrame *frame);
void ffmpeg_encoder_start(AVCodecContext **c, FILE **file, const char *filename, AVFrame **frame, int codec_id, int fps, int width, int height);
void ffmpeg_encoder_finish(AVCodecContext *c, AVPacket pkt, AVFrame *frame, FILE *file);
void ffmpeg_encoder_encode_frame(AVCodecContext *c, struct SwsContext *sws_context, uint8_t *rgb, AVPacket pkt, AVFrame *frame, FILE *file);
void ffmpeg_encoder_glread_rgb(uint8_t **rgb, GLubyte **pixels, unsigned int width, unsigned int height);

#ifdef __cplusplus
}
#endif

#endif
