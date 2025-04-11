#include QMK_KEYBOARD_H
#include "version.h"
#include "i18n.h"
#define MOON_LED_LEVEL LED_LEVEL
#define ML_SAFE_RANGE SAFE_RANGE

enum custom_keycodes {
  RGB_SLD = ML_SAFE_RANGE,
  ST_MACRO_0,
  ST_MACRO_1,
  ST_MACRO_2,
  ST_MACRO_3,
};



enum tap_dance_codes {
  DANCE_0,
  DANCE_1,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_voyager(
    KC_ESCAPE,      KC_1,           KC_2,           KC_3,           KC_4,           KC_5,                                           KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_MINUS,       
    KC_TAB,         KC_B,           KC_Y,           KC_O,           KC_U,           KC_SCLN,                                        KC_X,           KC_L,           KC_D,           KC_P,           KC_F,           MT(MOD_RGUI, KC_BSLS),
    MT(MOD_LSFT, KC_BSPC),MT(MOD_LGUI, KC_C),MT(MOD_LALT, KC_I),MT(MOD_LCTL, KC_E),MT(MOD_LSFT, KC_A),KC_COMMA,                                       KC_K,           MT(MOD_RSFT, KC_H),MT(MOD_RCTL, KC_T),MT(MOD_RALT, KC_N),MT(MOD_RGUI, KC_S),MT(MOD_RSFT, KC_ENTER),
    KC_LEFT_GUI,    MT(MOD_LALT, KC_SLASH),KC_EQUAL,       KC_QUOTE,       KC_DOT,         KC_MINUS,                                       KC_J,           KC_M,           KC_G,           KC_W,           MT(MOD_RALT, KC_V),KC_RIGHT_CTRL,  
                                                    LT(1,KC_SPACE), LT(3,KC_TAB),                                   MT(MOD_LSFT, KC_BSPC),LT(2,KC_R)
  ),
  [1] = LAYOUT_voyager(
    KC_ESCAPE,      KC_F1,          KC_F2,          KC_F3,          KC_F4,          KC_F5,                                          KC_F6,          KC_F7,          KC_F8,          KC_F9,          KC_F10,         KC_F11,         
    LGUI(KC_D),     OSM(MOD_LSFT),  LCTL(KC_Y),     LCTL(KC_Z),     LCTL(KC_X),     KC_PC_CUT,                                      KC_PC_CUT,      KC_BSPC,        KC_PC_UNDO,     RCTL(KC_Y),     OSM(MOD_RSFT),  KC_F12,         
    KC_TRANSPARENT, KC_LEFT_GUI,    KC_LEFT_ALT,    KC_LEFT_CTRL,   KC_LEFT_SHIFT,  KC_PC_COPY,                                     KC_PC_COPY,     KC_LEFT,        KC_DOWN,        KC_UP,          KC_RIGHT,       TD(DANCE_0),    
    KC_TRANSPARENT, LCTL(KC_A),     ST_MACRO_1,     ST_MACRO_2,     LCTL(KC_F),     KC_PC_PASTE,                                    KC_PC_PASTE,    KC_HOME,        KC_PGDN,        KC_PAGE_UP,     KC_END,         KC_RIGHT_CTRL,  
                                                    KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
  [2] = LAYOUT_voyager(
    KC_GRAVE,       KC_LBRC,        KC_LPRN,        KC_RPRN,        KC_RBRC,        KC_DOT,                                         KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, QK_BOOT,        
    KC_EXLM,        KC_COMMA,       KC_LCBR,        KC_RCBR,        KC_SCLN,        KC_QUES,                                        KC_GRAVE,       KC_HOME,        KC_UP,          KC_END,         KC_TRANSPARENT, KC_TRANSPARENT, 
    KC_HASH,        KC_CIRC,        KC_EQUAL,       KC_UNDS,        KC_DLR,         KC_ASTR,                                        KC_DQUO,        KC_LEFT,        KC_DOWN,        KC_RIGHT,       KC_ENTER,       KC_TRANSPARENT, 
    KC_TILD,        KC_LABK,        KC_PIPE,        KC_MINUS,       KC_RABK,        KC_SLASH,                                       KC_QUOTE,       LCTL(LSFT(KC_TAB)),LCTL(KC_TAB),   ST_MACRO_3,     KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    KC_BSLS,        KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT
  ),
  [3] = LAYOUT_voyager(
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_COLN,        KC_PERC,        
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_7,           KC_8,           KC_9,           KC_MINUS,       TD(DANCE_1),    
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_4,           KC_5,           KC_6,           KC_ENTER,       KC_ENTER,       
    KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT, KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_1,           KC_2,           KC_3,           KC_TRANSPARENT, KC_TRANSPARENT, 
                                                    LALT(KC_TAB),   KC_TRANSPARENT,                                 KC_TRANSPARENT, KC_0
  ),
};

const uint16_t PROGMEM combo0[] = { KC_EQUAL, KC_QUOTE, COMBO_END};
const uint16_t PROGMEM combo1[] = { KC_QUOTE, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo2[] = { KC_G, KC_W, COMBO_END};
const uint16_t PROGMEM combo3[] = { KC_M, KC_G, COMBO_END};
const uint16_t PROGMEM combo4[] = { LT(1,KC_SPACE), LT(3,KC_TAB), COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo0, KC_Z),
    COMBO(combo1, ST_MACRO_0),
    COMBO(combo2, ES_NTIL),
    COMBO(combo3, ES_ACUT),
    COMBO(combo4, LALT(KC_TAB)),
};



bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case ST_MACRO_0:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_Q)SS_DELAY(100)  SS_TAP(X_U));
    }
    break;
    case ST_MACRO_1:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME)SS_DELAY(100)  SS_LSFT(SS_TAP(X_END)));
    }
    break;
    case ST_MACRO_2:
    if (record->event.pressed) {
      SEND_STRING(SS_LCTL(SS_TAP(X_LEFT))SS_DELAY(100)  SS_LCTL(SS_LSFT(SS_TAP(X_RIGHT))));
    }
    break;
    case ST_MACRO_3:
    if (record->event.pressed) {
      SEND_STRING(SS_TAP(X_HOME)SS_DELAY(20)  SS_LSFT(SS_TAP(X_END)));
    }
    break;

    case RGB_SLD:
      if (record->event.pressed) {
        rgblight_mode(1);
      }
      return false;
  }
  return true;
}


typedef struct {
    bool is_press_action;
    uint8_t step;
} tap;

enum {
    SINGLE_TAP = 1,
    SINGLE_HOLD,
    DOUBLE_TAP,
    DOUBLE_HOLD,
    DOUBLE_SINGLE_TAP,
    MORE_TAPS
};

static tap dance_state[2];

uint8_t dance_step(tap_dance_state_t *state);

uint8_t dance_step(tap_dance_state_t *state) {
    if (state->count == 1) {
        if (state->interrupted || !state->pressed) return SINGLE_TAP;
        else return SINGLE_HOLD;
    } else if (state->count == 2) {
        if (state->interrupted) return DOUBLE_SINGLE_TAP;
        else if (state->pressed) return DOUBLE_HOLD;
        else return DOUBLE_TAP;
    }
    return MORE_TAPS;
}


void on_dance_0(tap_dance_state_t *state, void *user_data);
void dance_0_finished(tap_dance_state_t *state, void *user_data);
void dance_0_reset(tap_dance_state_t *state, void *user_data);

void on_dance_0(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
        tap_code16(KC_ENTER);
    }
    if(state->count > 3) {
        tap_code16(KC_ENTER);
    }
}

void dance_0_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[0].step = dance_step(state);
    switch (dance_state[0].step) {
        case SINGLE_TAP: register_code16(KC_ENTER); break;
        case DOUBLE_TAP: register_code16(KC_ENTER); register_code16(KC_ENTER); break;
        case DOUBLE_HOLD: register_code16(KC_RIGHT_GUI); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_ENTER); register_code16(KC_ENTER);
    }
}

void dance_0_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[0].step) {
        case SINGLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_TAP: unregister_code16(KC_ENTER); break;
        case DOUBLE_HOLD: unregister_code16(KC_RIGHT_GUI); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_ENTER); break;
    }
    dance_state[0].step = 0;
}
void on_dance_1(tap_dance_state_t *state, void *user_data);
void dance_1_finished(tap_dance_state_t *state, void *user_data);
void dance_1_reset(tap_dance_state_t *state, void *user_data);

void on_dance_1(tap_dance_state_t *state, void *user_data) {
    if(state->count == 3) {
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
        tap_code16(KC_PLUS);
    }
    if(state->count > 3) {
        tap_code16(KC_PLUS);
    }
}

void dance_1_finished(tap_dance_state_t *state, void *user_data) {
    dance_state[1].step = dance_step(state);
    switch (dance_state[1].step) {
        case SINGLE_TAP: register_code16(KC_PLUS); break;
        case SINGLE_HOLD: register_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: register_code16(KC_PLUS); register_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: tap_code16(KC_PLUS); register_code16(KC_PLUS);
    }
}

void dance_1_reset(tap_dance_state_t *state, void *user_data) {
    wait_ms(10);
    switch (dance_state[1].step) {
        case SINGLE_TAP: unregister_code16(KC_PLUS); break;
        case SINGLE_HOLD: unregister_code16(KC_LEFT_SHIFT); break;
        case DOUBLE_TAP: unregister_code16(KC_PLUS); break;
        case DOUBLE_SINGLE_TAP: unregister_code16(KC_PLUS); break;
    }
    dance_state[1].step = 0;
}

tap_dance_action_t tap_dance_actions[] = {
        [DANCE_0] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_0, dance_0_finished, dance_0_reset),
        [DANCE_1] = ACTION_TAP_DANCE_FN_ADVANCED(on_dance_1, dance_1_finished, dance_1_reset),
};
