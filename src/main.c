#include <pebble.h>
#include "face.h"

  /*
static Window *s_main_window;
static TextLayer *s_time_layer;
static GFont s_time_font;

static void update_time() {
  time_t temp = time(NULL);
  struct tm *tick_time = localtime(&temp);
  static char buffer[] = "00:00";
  if (clock_is_24h_style() == true) {
    strftime(buffer, sizeof("00:00"), "%H%M", tick_time);
  } else {
    strftime(buffer, sizeof("00:00"), "%I%M%p", tick_time);
  }
  text_layer_set_text(s_time_layer, buffer);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

static void main_window_load(Window *window) {
  s_time_layer = text_layer_create(GRect(0, 0, 144, 168));
  text_layer_set_background_color(s_time_layer, GColorClear);
  text_layer_set_text_color(s_time_layer, GColorBlack);
  
  s_time_font = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_MPLUS_REGULAR_42));
  text_layer_set_font(s_time_layer, s_time_font);
  text_layer_set_text_alignment(s_time_layer, GTextAlignmentCenter);
  layer_add_child(window_get_root_layer(window), text_layer_get_layer(s_time_layer));
}

static void main_window_unload(Window *window) {
  text_layer_destroy(s_time_layer);
  fonts_unload_custom_font(s_time_font);
}

static void init() {
  s_main_window = window_create();
  window_set_window_handlers(s_main_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload
  });
  window_stack_push(s_main_window, true);
  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  update_time();
}

static void deinit() {
  window_destroy(s_main_window);
}
*/


static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  update_time();
}

int main(void) {
  //init();
  show_face();

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  update_time();

  app_event_loop();
  hide_face();
  //deinit();
}

/*
0917
WEDN
17TH
MARC
*/