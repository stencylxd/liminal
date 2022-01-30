// discord.h controls basic discord rpc
#include "discord_game_sdk.h"
#include <stdio.h>

struct IDiscordActivityManager *activity_manager;
struct DiscordActivity activity;

struct Application {
    struct IDiscordCore* core;
};

struct Application app;

// initilizes discord activity. returns 1 if ok and 0 if not
int SetupDiscord(uint64_t discord_id) {
    // Make setup parameters
    struct DiscordCreateParams params;
    memset(&app, 0, sizeof(app));
    memset(&activity, 0, sizeof(activity));
    DiscordCreateParamsSetDefault(&params);
    params.client_id = discord_id;
    params.flags = DiscordCreateFlags_Default;
    params.event_data = &app;
    enum EDiscordResult success = DiscordCreate(DISCORD_VERSION, &params, &app.core);
    activity_manager = app.core->get_activity_manager(app.core);
    if (success == DiscordResult_Ok) return 1;
    return 0;
}

void SetActivity(char details[100]) {
    strcpy(activity.assets.large_image, "icon");
    strcpy(activity.details, details);
    activity_manager->update_activity(activity_manager, &activity, NULL, NULL);
}

void DiscordInvoke() {
    app.core->run_callbacks(app.core);
}