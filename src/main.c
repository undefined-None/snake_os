/* Kernel of TicTacToe OS */

#include <main.h>
#include <display.h>
#include <field.h>
#include <keyboard.h>
#include <util.h>

void start_screen()
{
	clear_screen();
	print_centered(START_SCREEN_TITLE, START_SCREEN_TITLE_LEN, 38, 11);
	print_centered(START_SCREEN_SUBTITLE, START_SCREEN_SUBTITLE_LEN, 38, 15);
}

void main()
{
	u8 set = get_scancode_set();
	init_keyboard();
	start_screen();
	u8 scancode = get_scancode();
	clear_screen();

	char scancode_string[10];
	int_to_ascii((int)scancode, scancode_string);
	print_left(scancode_string, 0, 24); // print it in the lower left corner
	int_to_ascii((int)set, scancode_string);
	print_left(scancode_string, 10, 24);
	print_centered("Tic-Tac-Toe Time!", 17, TITLE_COL, TITLE_ROW);
	init_field();
	insert_mark(PLAYER_X_MARK, 4);

	while(1);
}