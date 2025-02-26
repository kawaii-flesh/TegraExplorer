/*
 * Copyright (c) 2018 naehrwert
 * Copyright (c) 2018-2020 CTCaer
 * Copyright (c) 2018 M4xw
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms and conditions of the GNU General Public License,
 * version 2, as published by the Free Software Foundation.
 *
 * This program is distributed in the hope it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef _GFX_H_
#define _GFX_H_

#include <stdarg.h>
#include <utils/types.h>

#define EPRINTF(text) gfx_printf("%k" text "%k\n", 0xFFFF0000, 0xFFCCCCCC)
#define EPRINTFARGS(text, args...) gfx_printf("%k" text "%k\n", 0xFFFF0000, args, 0xFFCCCCCC)
#define WPRINTF(text) gfx_printf("%k" text "%k\n", 0xFFFFDD00, 0xFFCCCCCC)
#define WPRINTFARGS(text, args...) gfx_printf("%k" text "%k\n", 0xFFFFDD00, args, 0xFFCCCCCC)

typedef struct _gfx_ctxt_t {
    u32* fb;
    u32 width;
    u32 height;
    u32 stride;
} gfx_ctxt_t;

typedef struct _gfx_con_t {
    gfx_ctxt_t* gfx_ctxt;
    u32 fntsz;
    u32 x;
    u32 y;
    u32 savedx;
    u32 savedy;
    u32 fgcol;
    int fillbg;
    u32 bgcol;
    bool mute;
} gfx_con_t;

extern gfx_ctxt_t gfx_ctxt;
extern gfx_con_t gfx_con;
#define YLEFT 1279

void gfx_init_ctxt(u32* fb, u32 width, u32 height, u32 stride);
void gfx_clear_grey(u8 color);
void gfx_clear_partial_grey(u8 color, u32 pos_x, u32 height);
void gfx_clear_color(u32 color);
void gfx_con_init();
void gfx_con_setcol(u32 fgcol, int fillbg, u32 bgcol);
void gfx_con_getpos(u32* x, u32* y);
void gfx_con_setpos(u32 x, u32 y);
void gfx_putc(char c);
void gfx_puts(const char* s);
void gfx_printf(const char* fmt, ...);
void gfx_vprintf(const char* fmt, va_list ap);
void gfx_puts_limit(const char* s, u32 limit);
void gfx_puts_small(const char* s);
void gfx_putc_small(char c);

void gfx_set_pixel(u32 x, u32 y, u32 color);
void gfx_set_pixel_horz(int x, int y, u32 color);
void gfx_line(int x0, int y0, int x1, int y1, u32 color);
void gfx_put_small_sep();
void gfx_put_big_sep();
void gfx_set_rect_grey(const u8* buf, u32 size_x, u32 size_y, u32 pos_x, u32 pos_y);
void gfx_set_rect_rgb(const u8* buf, u32 size_x, u32 size_y, u32 pos_x, u32 pos_y);
void gfx_set_rect_argb(const u32* buf, u32 size_x, u32 size_y, u32 pos_x, u32 pos_y);
void gfx_render_bmp_argb(const u32* buf, u32 size_x, u32 size_y, u32 pos_x, u32 pos_y);
void gfx_box(int x0, int y0, int x1, int y1, u32 color);
void gfx_boxGrey(int x0, int y0, int x1, int y1, u8 shade);

/*
#define GFX_SETPOSCORRECTED(x, y) gfx_con_setpos(y - YLEFT, x)
#define GFX_BOXCORRECTED(x0, y0, x1, y1, color) gfx_box_old((y0 - YLEFT), x0, (y1 - YLEFT), x1, color)
#define GFX_BOXGREYCORRECTED(x0, y0, x1, y1, shade) gfx_boxGrey((y0 - YLEFT), x0, (y1 - YLEFT), x1, shade)
*/

// Global gfx console and context.
extern gfx_ctxt_t gfx_ctxt;
extern gfx_con_t gfx_con;

#endif
