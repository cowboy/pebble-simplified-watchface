#include <pebble.h>
#include "face.h"

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  // All the work is done at the bottom of face.c
  update_time();
}

int main(void) {
  show_face();

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  update_time();

  app_event_loop();

  hide_face();
}