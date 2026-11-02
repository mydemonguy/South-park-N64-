#include "sp_recomp.h"

#ifdef __cplusplus
extern "C" {
#endif

void sp_patches_placeholder(uint8_t* rdram, recomp_context* ctx);
void recomp_update_inputs(uint8_t* rdram, recomp_context* ctx);
void recomp_puts(uint8_t* rdram, recomp_context* ctx);
void recomp_exit(uint8_t* rdram, recomp_context* ctx);
void recomp_get_gyro_deltas(uint8_t* rdram, recomp_context* ctx);
void recomp_get_mouse_deltas(uint8_t* rdram, recomp_context* ctx);
void recomp_powf(uint8_t* rdram, recomp_context* ctx);
void recomp_get_target_framerate(uint8_t* rdram, recomp_context* ctx);
void recomp_get_window_resolution(uint8_t* rdram, recomp_context* ctx);
void recomp_get_target_aspect_ratio(uint8_t* rdram, recomp_context* ctx);
void recomp_get_targeting_mode(uint8_t* rdram, recomp_context* ctx);
void recomp_get_bgm_volume(uint8_t* rdram, recomp_context* ctx);
void recomp_get_se_volume(uint8_t* rdram, recomp_context* ctx);
void recomp_time_us(uint8_t* rdram, recomp_context* ctx);
void recomp_get_autosave_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_load_overlays(uint8_t* rdram, recomp_context* ctx);
void recomp_unload_overlays(uint8_t* rdram, recomp_context* ctx);
void recomp_high_precision_fb_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_get_resolution_scale(uint8_t* rdram, recomp_context* ctx);
void recomp_get_inverted_axes(uint8_t* rdram, recomp_context* ctx);
void recomp_get_analog_inverted_axes(uint8_t* rdram, recomp_context* ctx);
void recomp_get_analog_cam_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_get_camera_inputs(uint8_t* rdram, recomp_context* ctx);
void recomp_set_right_analog_suppressed(uint8_t* rdram, recomp_context* ctx);
void recomp_run_ui_callbacks(uint8_t* rdram, recomp_context* ctx);
void recomp_set_analog_cam_yaw(uint8_t* rdram, recomp_context* ctx);
void recomp_get_analog_cam_sensitivity(uint8_t* rdram, recomp_context* ctx);
void recomp_get_camera_recenter_pressed(uint8_t* rdram, recomp_context* ctx);
void recomp_get_infinite_health_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_get_infinite_money_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_get_infinite_lives_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_get_swap_while_moving_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_set_autosave_in_progress(uint8_t* rdram, recomp_context* ctx);
void recomp_notify_saved(uint8_t* rdram, recomp_context* ctx);
void recomp_get_camera_zoom_held(uint8_t* rdram, recomp_context* ctx);
void recomp_get_attack_while_moving_enabled(uint8_t* rdram, recomp_context* ctx);
void recomp_is_config_menu_open(uint8_t* rdram, recomp_context* ctx);
void recomp_set_field_engine_active(uint8_t* rdram, recomp_context* ctx);

#ifdef __cplusplus
}
#endif
