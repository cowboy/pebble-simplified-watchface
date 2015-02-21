#include <pebble.h>
#include "face.h"

static void inbox_received(DictionaryIterator *iterator, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "inbox_received");
  Tuple *tuple = dict_read_first(iterator);
  while (tuple) {
    APP_LOG(APP_LOG_LEVEL_DEBUG, "persist_write_int(%i, %i)", (int)tuple->key, tuple->value->uint8);
    persist_write_int(tuple->key, tuple->value->uint8);
    tuple = dict_read_next(iterator);
  }
  update_face();
}

static void inbox_dropped(AppMessageResult reason, void *context) {
  APP_LOG(APP_LOG_LEVEL_DEBUG, "inbox_dropped %d", reason);
}

static void tick_handler(struct tm *tick_time, TimeUnits units_changed) {
  // All the work is done at the bottom of face.c
  update_face();
}

static void init() {
  app_message_register_inbox_received(inbox_received);
  app_message_register_inbox_dropped(inbox_dropped);
  app_message_open(app_message_inbox_size_maximum(), app_message_outbox_size_maximum());

  show_face();

  tick_timer_service_subscribe(MINUTE_UNIT, tick_handler);
  update_face();
}

static void deinit() {
  hide_face();
}

int main(void) {
  init();
  app_event_loop();
  deinit();
}
