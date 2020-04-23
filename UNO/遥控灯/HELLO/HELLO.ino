#include "U8glib.h"
U8GLIB_SSD1306_128X64 u8g(U8G_I2C_OPT_NONE); // I2C / TWI
void draw(void) {
// graphic commands to redraw the complete screen should be placed here
u8g.setFont(u8g_font_unifont);
//u8g.setFont(u8g_font_osb21);
u8g.drawStr( 0, 22, "Hello World!");
}
void setup(void) {
}
void loop(void) {
// picture loop
u8g.firstPage();
do {
draw();
} while( u8g.nextPage() );
// rebuild the picture after some delay
delay(50);
}
