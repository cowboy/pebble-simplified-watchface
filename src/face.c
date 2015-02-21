#include "face.h"
#include <pebble.h>
#include <ctype.h>
#include <string.h>

// BEGIN AUTO-GENERATED UI CODE; DO NOT MODIFY
static Window *s_window;
static GFont s_res_font_mplus_light_18;
static GFont s_res_font_mplus_bold_64;
static GFont s_res_font_mplus_light_40;
static GFont s_res_font_mplus_light_64;
static TextLayer *s_month_3;
static TextLayer *s_month_2;
static TextLayer *s_month_1;
static TextLayer *s_date_2;
static TextLayer *s_date_1;
static TextLayer *s_ampm_2;
static TextLayer *s_ampm_1;
static TextLayer *s_year;
static InverterLayer *s_day_line_2;
static InverterLayer *s_day_line_1;
static TextLayer *s_day;
static TextLayer *s_day_single;
static TextLayer *s_date;
static TextLayer *s_date_single;
static TextLayer *s_time;
static InverterLayer *s_invert;

static void initialise_ui(void) {
  s_window = window_create();
  window_set_background_color(s_window, GColorBlack);
  window_set_fullscreen(s_window, true);
  
  s_res_font_mplus_light_18 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_MPLUS_LIGHT_18));
  s_res_font_mplus_bold_64 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_MPLUS_BOLD_64));
  s_res_font_mplus_light_40 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_MPLUS_LIGHT_40));
  s_res_font_mplus_light_64 = fonts_load_custom_font(resource_get_handle(RESOURCE_ID_FONT_MPLUS_LIGHT_64));
  // s_month_3
  s_month_3 = text_layer_create(GRect(128, 145, 16, 30));
  text_layer_set_background_color(s_month_3, GColorClear);
  text_layer_set_text_color(s_month_3, GColorWhite);
  text_layer_set_text(s_month_3, "X");
  text_layer_set_text_alignment(s_month_3, GTextAlignmentCenter);
  text_layer_set_font(s_month_3, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_month_3);
  
  // s_month_2
  s_month_2 = text_layer_create(GRect(128, 129, 16, 30));
  text_layer_set_background_color(s_month_2, GColorClear);
  text_layer_set_text_color(s_month_2, GColorWhite);
  text_layer_set_text(s_month_2, "X");
  text_layer_set_text_alignment(s_month_2, GTextAlignmentCenter);
  text_layer_set_font(s_month_2, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_month_2);
  
  // s_month_1
  s_month_1 = text_layer_create(GRect(128, 113, 16, 30));
  text_layer_set_background_color(s_month_1, GColorClear);
  text_layer_set_text_color(s_month_1, GColorWhite);
  text_layer_set_text(s_month_1, "X");
  text_layer_set_text_alignment(s_month_1, GTextAlignmentCenter);
  text_layer_set_font(s_month_1, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_month_1);
  
  // s_date_2
  s_date_2 = text_layer_create(GRect(128, 72, 16, 30));
  text_layer_set_background_color(s_date_2, GColorClear);
  text_layer_set_text_color(s_date_2, GColorWhite);
  text_layer_set_text(s_date_2, "X");
  text_layer_set_text_alignment(s_date_2, GTextAlignmentCenter);
  text_layer_set_font(s_date_2, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_2);
  
  // s_date_1
  s_date_1 = text_layer_create(GRect(128, 56, 16, 30));
  text_layer_set_background_color(s_date_1, GColorClear);
  text_layer_set_text_color(s_date_1, GColorWhite);
  text_layer_set_text(s_date_1, "X");
  text_layer_set_text_alignment(s_date_1, GTextAlignmentCenter);
  text_layer_set_font(s_date_1, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_1);
  
  // s_ampm_2
  s_ampm_2 = text_layer_create(GRect(128, 34, 16, 30));
  text_layer_set_background_color(s_ampm_2, GColorClear);
  text_layer_set_text_color(s_ampm_2, GColorWhite);
  text_layer_set_text(s_ampm_2, "X");
  text_layer_set_text_alignment(s_ampm_2, GTextAlignmentCenter);
  text_layer_set_font(s_ampm_2, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_ampm_2);
  
  // s_ampm_1
  s_ampm_1 = text_layer_create(GRect(128, 18, 16, 30));
  text_layer_set_background_color(s_ampm_1, GColorClear);
  text_layer_set_text_color(s_ampm_1, GColorWhite);
  text_layer_set_text(s_ampm_1, "X");
  text_layer_set_text_alignment(s_ampm_1, GTextAlignmentCenter);
  text_layer_set_font(s_ampm_1, s_res_font_mplus_light_18);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_ampm_1);
  
  // s_year
  s_year = text_layer_create(GRect(2, 100, 170, 77));
  text_layer_set_background_color(s_year, GColorClear);
  text_layer_set_text_color(s_year, GColorWhite);
  text_layer_set_text(s_year, "8888");
  text_layer_set_font(s_year, s_res_font_mplus_bold_64);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_year);
  
  // s_day_line_2
  s_day_line_2 = inverter_layer_create(GRect(6, 106, 56, 2));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_day_line_2);
  
  // s_day_line_1
  s_day_line_1 = inverter_layer_create(GRect(6, 61, 56, 2));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_day_line_1);
  
  // s_day
  s_day = text_layer_create(GRect(4, 59, 65, 53));
  text_layer_set_background_color(s_day, GColorClear);
  text_layer_set_text_color(s_day, GColorWhite);
  text_layer_set_text(s_day, "XXX");
  text_layer_set_font(s_day, s_res_font_mplus_light_40);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_day);
  
  // s_day_single
  s_day_single = text_layer_create(GRect(2, 44, 170, 77));
  text_layer_set_background_color(s_day_single, GColorClear);
  text_layer_set_text_color(s_day_single, GColorWhite);
  text_layer_set_text(s_day_single, "XXX");
  text_layer_set_font(s_day_single, s_res_font_mplus_light_64);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_day_single);
  
  // s_date
  s_date = text_layer_create(GRect(66, 44, 64, 77));
  text_layer_set_background_color(s_date, GColorClear);
  text_layer_set_text_color(s_date, GColorWhite);
  text_layer_set_text(s_date, "88");
  text_layer_set_font(s_date, s_res_font_mplus_bold_64);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date);
  
  // s_date_single
  s_date_single = text_layer_create(GRect(98, 44, 34, 77));
  text_layer_set_background_color(s_date_single, GColorClear);
  text_layer_set_text_color(s_date_single, GColorWhite);
  text_layer_set_text(s_date_single, "8");
  text_layer_set_font(s_date_single, s_res_font_mplus_bold_64);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_date_single);
  
  // s_time
  s_time = text_layer_create(GRect(2, -12, 170, 77));
  text_layer_set_background_color(s_time, GColorClear);
  text_layer_set_text_color(s_time, GColorWhite);
  text_layer_set_text(s_time, "8888");
  text_layer_set_font(s_time, s_res_font_mplus_bold_64);
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_time);
  
  // s_invert
  s_invert = inverter_layer_create(GRect(0, 0, 144, 168));
  layer_add_child(window_get_root_layer(s_window), (Layer *)s_invert);
}

static void destroy_ui(void) {
  window_destroy(s_window);
  text_layer_destroy(s_month_3);
  text_layer_destroy(s_month_2);
  text_layer_destroy(s_month_1);
  text_layer_destroy(s_date_2);
  text_layer_destroy(s_date_1);
  text_layer_destroy(s_ampm_2);
  text_layer_destroy(s_ampm_1);
  text_layer_destroy(s_year);
  inverter_layer_destroy(s_day_line_2);
  inverter_layer_destroy(s_day_line_1);
  text_layer_destroy(s_day);
  text_layer_destroy(s_day_single);
  text_layer_destroy(s_date);
  text_layer_destroy(s_date_single);
  text_layer_destroy(s_time);
  inverter_layer_destroy(s_invert);
  fonts_unload_custom_font(s_res_font_mplus_light_18);
  fonts_unload_custom_font(s_res_font_mplus_bold_64);
  fonts_unload_custom_font(s_res_font_mplus_light_40);
  fonts_unload_custom_font(s_res_font_mplus_light_64);
}
// END AUTO-GENERATED UI CODE

static void handle_window_unload(Window* window) {
  destroy_ui();
}

void show_face(void) {
  initialise_ui();
  window_set_window_handlers(s_window, (WindowHandlers) {
    .unload = handle_window_unload,
  });
  window_stack_push(s_window, true);
}

void hide_face(void) {
  window_stack_remove(s_window, true);
}


// BEGIN COWBOY-GENERATED-CODE


// From the interwebs
char *upcase(char *str) {
  char *s = str;
  while (*s) {
    *s++ = toupper((int)*s);
  }
  return str;
}

// Helper structure that ties a TextLayer together with a
// string and parsing instructions.
struct TextItem {
  int length;
  int move;
  TextLayer *layer;
  char text[5];
};

// Helper for initializing TextItem instances.
void init_text_item(struct TextItem texts[], int index, int length, int move, TextLayer *layer) {
  texts[index].length = length;
  texts[index].move = move;
  texts[index].layer = layer;
}

// These constants are defined in appinfo.json, face.c, pebble-js-app.js
#define LIGHT_BACKGROUND_KEY 0
#define TWO_DIGIT_DATE_KEY   1

// Get int value from persistent storage or the default value of 0.
int get_persist_int(int key) {
  if (persist_exists(key)) {
    return persist_read_int(key);
  } else {
    return 0;
  }
}

// Magic
void update_face(void) {
  bool show_light_background = get_persist_int(LIGHT_BACKGROUND_KEY) == 1;
  bool show_two_digit_date = get_persist_int(TWO_DIGIT_DATE_KEY) == 1;

  bool is_clock_24h = clock_is_24h_style();

  time_t temp = time(NULL);

  // For taking screenshots.
  // pebble clean && pebble build && pebble install && pebble screenshot
  switch (0) {
    case 1:
      // 1248PM THU29TH 2015JAN
      temp = 1422535680;
      is_clock_24h = false;
      show_light_background = false;
      break;
    case 2:
      // 0706AM TUE3RD  2015FEB
      temp = 1422947160;
      is_clock_24h = false;
      show_two_digit_date = false;
      show_light_background = false;
      break;
    case 3:
      // 2349   SUN01ST 2015MAR
      temp = 1425253740;
      is_clock_24h = true;
      show_two_digit_date = true;
      show_light_background = true;
      break;
  }

  struct tm *tick_time = localtime(&temp);

  // Format one long time string, then split it up as-needed.
  char format_string[20] = "%Y%b%d%a%p";
  if (is_clock_24h) {
    strcat(format_string, "%H%M");
  } else {
    strcat(format_string, "%I%M");
  }
  // "2015FEB20FRIAM0905"
  static char formatted_time[20];
  strftime(formatted_time, sizeof(formatted_time), format_string, tick_time);
  upcase(formatted_time);
  APP_LOG(APP_LOG_LEVEL_DEBUG, "formatted_time <%s>", formatted_time);

  // Initialize all text items whose text will be parsed from
  // the formatted time string.
  static struct TextItem texts[11];
  const int YEAR   = 0;
  const int MONTH1 = 1;
  const int MONTH2 = 2;
  const int MONTH3 = 3;
  const int DATE   = 4;
  const int DATE_S = 5;
  const int DAY    = 6;
  const int DAY_S  = 7;
  const int AMPM1  = 8;
  const int AMPM2  = 9;
  const int TIME   = 10;

  // Using a helper function was easier than doing all these
  // assignments manually. Is there a better way?
  init_text_item(texts, YEAR,   4, 4, s_year);
  init_text_item(texts, MONTH1, 1, 1, s_month_1);
  init_text_item(texts, MONTH2, 1, 1, s_month_2);
  init_text_item(texts, MONTH3, 1, 1, s_month_3);
  init_text_item(texts, DATE,   2, 1, s_date);
  init_text_item(texts, DATE_S, 1, 1, s_date_single);
  init_text_item(texts, DAY,    3, 0, s_day);
  init_text_item(texts, DAY_S,  3, 3, s_day_single);
  init_text_item(texts, AMPM1,  1, 1, s_ampm_1);
  init_text_item(texts, AMPM2,  1, 1, s_ampm_2);
  init_text_item(texts, TIME,   4, 1, s_time);

  // Parse text from formatted time string and update the
  // appropriate TextLayer.
  char *ptr = formatted_time;
  int length = sizeof(texts) / sizeof(texts[0]);
  int i = 0;
  for (i = 0; i < length; i++) {
    int size = texts[i].length;
    strncpy(texts[i].text, ptr, size);
    texts[i].text[size] = '\0';
    ptr += texts[i].move;
    //APP_LOG(APP_LOG_LEVEL_DEBUG, "texts[%d] = <%s>", i, texts[i].text);
    text_layer_set_text(texts[i].layer, texts[i].text);
  }

  // Hide/show certain layers based on whether the date is
  // single- or double-digit.
  bool is_single_digit_date = !show_two_digit_date && texts[DATE].text[0] == '0';

  layer_set_hidden((Layer *)s_day, is_single_digit_date);
  layer_set_hidden((Layer *)s_date, is_single_digit_date);
  layer_set_hidden((Layer *)s_day_line_1, is_single_digit_date);
  layer_set_hidden((Layer *)s_day_line_2, is_single_digit_date);
  layer_set_hidden((Layer *)s_day_single, !is_single_digit_date);
  layer_set_hidden((Layer *)s_date_single, !is_single_digit_date);

  // Hide/show AM/PM if the clock mode is 24h.
  layer_set_hidden((Layer *)s_ampm_1, is_clock_24h);
  layer_set_hidden((Layer *)s_ampm_2, is_clock_24h);

  // Compute and display numeric date superscript suffix.
  char d1 = texts[DATE].text[0];
  char d2 = texts[DATE].text[1];
  static char date1[2];
  static char date2[2];

  if (d2 == '1' && d1 != '1') {
    strcpy(date1, "S");
    strcpy(date2, "T");
  } else if (d2 == '2' && d1 != '1') {
    strcpy(date1, "N");
    strcpy(date2, "D");
  } else if (d2 == '3' && d1 != '1') {
    strcpy(date1, "R");
    strcpy(date2, "D");
  } else {
    strcpy(date1, "T");
    strcpy(date2, "H");
  }
  text_layer_set_text(s_date_1, date1);
  text_layer_set_text(s_date_2, date2);

  // Hide inversion layer if show_light_background isn't set.
  layer_set_hidden((Layer *)s_invert, !show_light_background);
}
