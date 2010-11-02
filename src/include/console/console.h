#ifndef __CONSOLE_H__
#define __CONSOLE_H__

#include <configs.h>
#include <default.h>

#define	UNICODE_SPACE				0x0020
#define	UNICODE_CR					0x000d
#define	UNICODE_LF					0x000a
#define	UNICODE_TAB					0x0009

/*
 * console color enum type.
 */
enum console_color {
	CONSOLE_NONE,
	CONSOLE_BLACK,
	CONSOLE_RED,
	CONSOLE_GREEN,
	CONSOLE_YELLOW,
	CONSOLE_BULE,
	CONSOLE_MAGENTA,
	CONSOLE_CYAN,
	CONSOLE_WHITE
};

/*
 * define the struct of console
 */
struct console
{
	/* the name of console */
	char * name;

	/* get console's width and height */
	x_bool(*getwh)(struct console * console, x_s32 * w, x_s32 * h);

	/* get cursor position */
	x_bool(*getxy)(struct console * console, x_s32 * x, x_s32 * y);

	/* set cursor position */
	x_bool(*gotoxy)(struct console * console, x_s32 x, x_s32 y);

	/* turn on/off the cursor */
	x_bool(*setcursor)(struct console * console, x_bool on);

	/* set console's front color and background color */
	x_bool(*setcolor)(struct console * console, enum console_color f, enum console_color b);

	/* get console front color and background color */
	x_bool(*getcolor)(struct console * console, enum console_color * f, enum console_color * b);

	/* clear screen */
	x_bool(*cls)(struct console * console);

	/* update the screen */
	x_bool(*refresh)(struct console * console);

	/* get a unicode character */
	x_u32(*getchar)(struct console * console);

	/* put a unicode character */
	x_bool(*putchar)(struct console * console, x_u32 c);

	/* private data */
	void * priv;
};

/*
 * the list of console.
 */
struct console_list
{
	struct console * console;
	struct list_head entry;
};


struct console * search_console(const char *name);
x_bool register_console(struct console * console);
x_bool unregister_console(struct console * console);
x_bool console_color_to_rgba(enum console_color c, x_u8 * r, x_u8 * g, x_u8 * b, x_u8 * a);

#endif /* __CONSOLE_H__ */
